import numpy as np 
import pandas as pd

temp = np.array([[1,1,2,2,3],[2,2,4,4,5], [5,4,2,1,7]]).transpose()
temp_df = pd.DataFrame(temp, columns = ['x', 'y','prediction'])

def ex_func(df):
    df['prediction_mod'] = df['prediction']*5
    return df    
    # !x

temp_df = temp_df.groupby(['x', 'y']).apply(ex_func)
print(temp_df) 
