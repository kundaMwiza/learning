# temp imports
import pandas as pd
import numpy as np
import scipy.special as scs

def proportion_of_deviance_explained(data
                                    ,actual
                                    ,prediction
                                    ,weight # for binomial, this should be the number of trials under consideration
                                    ,family
                                    ,rebasing_features = None # a vector of feature names
                                    ,tweedie_power=1.5):
                                    
    
    #=========================================================
    # Error handling
    #=========================================================

    # -- Bad family -- # 
    if family.upper() in ['P', 'POISSON']:
        family = 'POISSON'
    elif family.upper() in ['G', 'GAMMA']:
        family = 'GAMMA'
    elif family.upper() in ['T', 'TWEEDIE']:
        family = 'TWEEDIE'
    elif family.upper() in ['B', 'BERNOULLI', 'BINOMIAL']:
        family = 'BINOMIAL'
    else:
        sys.exit('family must be one of : Poisson, Gamma, Tweedie or Binomial')

    # -- Bad data -- # 
    if data[prediction].isna().sum()>0 | (~np.isfinite(data[prediction])).sum()>0:
        sys.exit('Predictions cannot be NA, Infinite or missing')
    
    # -- Stop if any of the 'rebasing_features' are not present in the data == #
    data_cols = set(data.columns.values.tolist())
    if rebasing_features != None:
        rebase_missing = [str(ft) for ft in rebasing_features if str(ft) not in data_cols]
        if len(rebase_missing)>0:
            sys.exit('The following rebasing_features are missing on the data: ' + str(rebase_missing))
    
    #=========================================================
    # Data prep
    #=========================================================

    if family in ['GAMMA', 'POISSON', 'TWEEDIE']:
        link_function = np.log
        inverse_link_function = np.exp
    elif family in ['BINOMIAL']:
        link_function = scs.logit
        inverse_link_function = scs.expit

    # -- Restrict to required cols & only keep records with positive weight -- # 
    if rebasing_features != None:
        required_cols = set([actual, prediction, weight] + rebasing_features)
    else:
        required_cols = set([actual, prediction, weight])

    idx_pos = (data[weight]>1e-4) & (~data[weight].isna())
    data = data.loc[idx_pos, required_cols]
    print(data)

    # -- Set NA actuals to 0 -- #
    data[actual].fillna(0, inplace = True) 

    #=========================================================
    # Rebasing of prediction and weight
    #=========================================================
    # -- Get the subsets of the data -- #
    if rebasing_features!=None:
        # -- Calculate a weighted, rebased version of the prediction -- #
        def rebase_function(df):
            # -- Calculate weighted predictions -- # 
            df['weighted_Prediction'] = df[prediction] * df[weight]
            # -- Get the difference in linear predictor between the predicted average and the actual average -- #
            LinearPredictorAdjustment = link_function(df[actual].sum(skipna = True)/ df[weight].sum(skipna = True)) - link_function(df['weighted_Prediction'].sum(skipna = True)/df[weight].sum(skipna = True))
            # -- Make the adjustment -- # 
            df['Prediction_Rebased'] = inverse_link_function(link_function(df[prediction]) + LinearPredictorAdjustment)
            df['weighted_Prediction_Rebased'] = df['Prediction_Rebased'] * df[weight]

            return df
        data = data.groupby(rebasing_features).apply(rebase_function)
        print(data)

    else:
        # -- Calculate weighted predictions -- # 
        data['weighted_Prediction'] = data[prediction]*data[weight]
        # -- Get the difference in linear predictor between the predicted average and the actual average -- #
        LinearPredictorAdjustment = link_function(data[actual].sum(skipna=True)/ data[weight].sum(skipna=True)) - link_function(data['weighted_Prediction'].sum(skipna = True)/data[weight].sum(skipna = True))
        # -- Make the adjustment -- # 
        data['Prediction_Rebased'] = inverse_link_function(link_function(data[prediction]) + LinearPredictorAdjustment)
        data['weighted_Prediction_Rebased'] = data['Prediction_Rebased'] * data[weight]
    
    # -- Calculate a 'null' predictions as a rebased weight -- # 
    data['weight_rebased'] = (data[weight]* data[actual].mean(skipna = True))/data[weight].mean(skipna = True)

    #=========================================================
    # Calculate Deviances
    #=========================================================

    # -- Poisson -- # 
    if family.upper() == 'POISSON':
        # Define poisson deviance function
        def deviance(y, mu):
            deviance_vec = 2*(y * np.where(y==0, 0, np.log(y/mu)) - (y-mu))
            return deviance_vec.sum() 
        # Calculate for model predictions and for null predictions
        deviance_preds = deviance(y=data[actual], mu=data['weighted_Prediction_Rebased'])
        deviance_null = deviance(y=data[actual], mu=data['weight_rebased'])
    
    # -- Binomial -- #
    elif family.upper() == 'BINOMIAL':
        # Define binomial deviance function
        def deviance(y, mu, n):
            deviance_vec = 2*(y*np.where(y==0, 0, np.log(y/mu)) + (n-y)*np.where((n-y) == 0, 0, np.log((n-y)/(n-mu))))
            return deviance_vev.sum()
        
        # Calculate for model predictions and null predictions
        deviance_preds = deviance(y=data[actual], mu=data['weighted_Prediction_Rebased'], n=data[weight])
        deviance_null = deviance(y=data[actual], mu=data['weight_rebased'], n=data[weight])

    # -- Gamma -- # 
    elif family.upper() == 'GAMMA':
        # Define Gamma deviance function
        def deviance(y, mu, n):
            deviance_vec = -2*(np.where(y==0, 0, np.log(y/mu)) - ((y - mu)/mu))
            return deviance_vev.sum()
        
        # Calculate for model predictions and null predictions
        deviance_preds = deviance(y=data[actual], mu=data['weighted_Prediction_Rebased'])
        deviance_null = deviance(y=data[actual], mu=data['weight_rebased'])
    
    # -- Tweedie -- # 

    #=========================================================
    # Calculate PoDE and output the result
    #=========================================================
    # Proportion of deviance explained = (NULL DEVIANCE - MODEL DEVIANCE)/NULL DEVIANCE
    PoDE = 1 - deviance_preds/deviance_null 

    return PoDE


# tests 
# cols = actual, prediction, weight, features (inc rebasing features)
columns = ['actual', 'prediction', 'weight', 'ft_1', 'ft_2']
family = 'POISSON'
if family == 'POISSON':
    dummy_data = [[1, 3, 10, 5, 4, 7, 9, 10],
                  [1, 3, 10, 5, 4, 7, 8, 10],
                  [1, 2, 1, 1.5, 3, 7, 9, 2],
                  [0.3, 0.3, 5.0, 2.0, 1.0, 4.0, 6.0, 7.0],
                  [0.3, 0.3, 3.0, 6.0, 0.5, 3.0, 6.0, 7.0]]
    
    dummy_data_np = np.array(dummy_data).transpose()
    dummy_data_df = pd.DataFrame(dummy_data_np, columns = columns)

    params = {'data': dummy_data_df, 'actual': 'actual',
             'prediction': 'prediction', 'weight': 'weight', 
             'family': 'poisson', 'rebasing_features' : None}
    params = {'data': dummy_data_df, 'actual': 'actual',
            'prediction': 'prediction', 'weight': 'weight', 
            'family': 'poisson', 'rebasing_features' : ['ft_1', 'ft_2']}
    proportion_of_deviance_explained(**params)






