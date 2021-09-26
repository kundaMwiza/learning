## Summary

### linear regression

Assumptions:

- gaussian distributed errors
- error terms are iid
- linear decision boundary. Assumes $f(x)$ is well approximated by a globally linear function
- the model fitted via $Y = f(X) + e = XB + e$
  - $\hat{Y}$ is the projection of Y in the colspace of X, with projection matrix
  - $X(X^TX)^{-1}X^T$
  - For this geometric interpretation, note that the projection of $Y$ into the colspace of $X$ must satisfy:
    - $X^T(Y - X\beta) = 0$, $Y - X\beta$ is orthogonal ot every vector in the colspace of $X$, and therefore the scalar products have to be zero. We therefore arrive with the solution that $\hat{\beta} = (X^TX)^{-1}X^Ty$

Consequence:

- low variance, high (bias). Model specificity is strict
- relative to nested models of lower complexity, the general OLS has a _lower_ bias
  and a _higher_ variance. To increase prediction accuracy, sometimes we can increase bias and reduce variance by setting some coefficients to zero:
  - (this falls under model selection approaches)
  - increases bias, but reduces variance
  - increases model interpretability - this results in Ridge, lasso & elastic net regression detailed below.

#### Lasso regression

Consequence:

- in the $p > n$ case, lasso selects at most $n$ variables before it saturates, because of the nature of the convex problem
- lasso does not care about which var to select amonst a set of correlated variables
- for $n >p$, empirical observations are that ridge is typically better.

#### Subset selection methods vs Shrinkage methods

Subset Selection methods:

- forward stepwise (add var with highest improvement in performance or use z score)
- backward stepwise (remove var with lowest improvement in performance or use z score)
- forward stagewise selection (augments the residual in the direction of the strongest predictor at a particular step)

Shrinkage methods:

- Ridge
  - helps with correlated variables by imposing a size restriction on the parameters. Without shrinkage, one correlated variable may have a large positive coefficient, whilst another may have a large negative coefficient, so as to cancel out the effect of the large positive coefficient.
  - also note that the addition of the quadratic penalty term adds a scaled identity to the least squares solution. So that even if $X^TX$ is not full rank, $X^TX + \lambda I$ is non singular, and has an inverse that exists. This is one of the motivations for using Ridge regression over OLS.
  - Ridge regression is also equivalent to bayesian framework with normally distributed data, and normally distributed parameters for a prior. And the solution is equal to the posterior mode/ mean (normal implies mode = mean)
  - Ridge is also related to principal component analysis. The prediction hat(y) is chosen to be affect most by the principal components that have the highest variance, and the effect of principal components that have the lowest variance is shrunk, in comparison to OLS.
- Lasso
  - similar to Ridge, but with an L1 penalty imposed on the predictors. Reformulating it into a constrained problem, the equality constraint behaves as follows:
    - setting t = sum of absolute least square parameters, then the solution is the same as the least squares solution
    - setting t = 1/2 sum of abs (least square parameters), then the solution is roughly equivalent to halving the coefficient size (due to the nature of the L1 penalty, it is linear in some regions)
    - setting t = 0, then the solution is equal to setting all params = 0
  - the value of t should be chosen based on expected prediction error, e.g. via cross validation.
- Elastic net

Subset selection vs Shrinkage:

- subset selection & continuous shrinkage penalty methods can be formulated as
  $$ \text{argmin}\_{\Beta_0, \Beta} \sum L(f(x, y)) + \sum |b_j|^p $$
- for $p = 0$, we have subset selection, meaning that the penalty method includes a value of 1 for each parameter that is included in the model.
- for $p > 0$, we have continuous shrinkage. The coefficients are _shrunk_, but are not necessarily zero. This is why shrinkage methods sometimes perform better than subset selection methods, since they don't necessarily discard parameters from the model.
- As $p$ gets larger, the parameters are still shrunk, but are less likely to be shrunk to zero, e.g. difference between $p =1$ (lasso) and $p = 2$ (ridge).
- Subset selection is discrete, that is, either includes a variable or doesnt
  as a result, the model that is chosen can still exhibit high variance
- Shrinkage methods are more continuous. Don't suffer as much from high variability
-

### k-nearest neighbours

Assumptions:

- assumed $f(x)$ is well approximated by a locally constant function
- does not place any assumptions on the nature of the data

Consequence:

- high variance, low bias

#### Knn & lreg

K-nearest neighbours and linear regression spawn a larger set of models,
which are enhancements of the simpler approaches:

- kernel methods use weights that decrease smoothly to zero with distance from the target point (knn), rather than 0/1 weights
- fitting local regression rather than fitting constants globally (lreg)
- basis expansion of linear reg coefficients (lreg)
- projection pursuit and neural network models consist of sums of non-linearly transformed linear models

## Overview

### Statistical decision theory

let $X \in \mathbb{R}^p $ denote a real valued random input vector, and $Y \in \mathbb{R}$ a real valued random output variable, with a probability space $((R_X, R_Y), \Sigma_{X, Y}, Pr(X, Y))$. We seek a function $f(X)$ for predicting $Y$ given values of the input $X$. This theory requires a _loss function_ $L(Y, f(X))$ for penalizing errors in prediction. Here $f(X)$ is a statistic/estimator, and we would like ot evaluate how good the estimator is for $Y$, and that is why we introduce statistical decision theory.

One kind of loss function is the squared error loss. Which leads to asking the question of the expected loss of an estimator, so that we can compare whether one estimator is better than another:

$$ EPE(f) = E[(Y - f(X))^2]$$

which is the expected loss of the estimator $f$.

By conditioning on $X$, we can write:

$$ EPE(f) = E*XE*{Y|X}[(Y-f(X))^2|X]$$

where we evaluate the expected conditional loss first, then average over all possible inputs. So we can see that it suffices to minimize EPE pointwise:

$$ f(x) = argmin*c E*{Y|X}[(Y-c)^2|X = x] $$

And we can arrive at the solution that:

$$ C = E\_{Y|X}[Y|X], f(x) = E[Y|X = x]$$

that is, what is the lowest expected error of $f(X)$ given we know that $X=x$. So the total expected loss is just $$E_X[E_{Y|X}[Y - f(X)^2|X]]$$

So the best prediction of $Y$ when $X =x$ when using the squared loss measure, is just the conditional mean of $Y$. For different loss functions, a different estimator will be best, e.g. it may be the conditional median. And in particular, different estimators $f(X)$, e.g. a linear model, k-nearest neighbours, neural network will achieve different expected losses, and so different estimators will be best.

More generally we want to evalute:
$$E_{Y|X}[l(Y, f(X)) | X] $$ where $l$ is a loss function. And we would like the best estimator given the loss function $l$. Different loss functions have positives/ negativies.

For:

- squared loss. The best estimator is the mean
- L1 loss. The best estimator is the median
- 0-1 loss. the best estimator is the most likely value (related to knn)

We can place additional assumptions on the nature of $f(X)$ to estimate $E[Y|X=x]$, i.e that $f(X) = wTx$, and then we would like to find $w$ such that $f(X)$ is the best estimator to $E[Y|X]$.

Different assumptions, statistics lead to varying performance. For example bias-variance tradeoff. Is the estimator even unbiased?

### Supervised learning

For simplicity we assume the model $Y = f(X) + \epsilon$ where the errors follow a particular distribution.

Instead of constructing a loss function as shown previously, to then determine the best estimator. A more general treatment of finding a statistical estimator is via the use of maximum likelihood estimation.

if we assume that $Y = f_\theta(X) + \epsilon$, we can then maximise $P(X, Y| \theta)$, doing so will allow us to obtain a model for $f_\theta(X)$. However a limitation of the maximum likelihood approach is that it can lead to overfitting.

In fact, using a least squares loss function for the additive error model with $e \sim N(0, \sigma^2)$ is equivalent to maximum likelihood using the conditional likelihood:

$$Pr(Y|X, \theta) = N(f_\theta(X), \sigma^2)$$

Note that in this case, to use the prinicpal of maximum likelihood, it requires an assumption about the form of probability distribution to use for $P(Y|X, \theta)$. This prior information can lead to different results if we use a loss function based appraoch with no explicit assumption about the nature of the probability distribution. The nature of the probability distribution has to be chosen to match what is observed in the data.

The advantage of the mle approach however is that you don't have to construct a loss function.

the problem of trying to find and estimator to fit against $Y$ is one that involves infinitely many solutions. However, we transfer this ambiguity to the constraints imposed of the type of estimator $f(X)$. Of course, there are infinitely many constraints that be imposed.

The type of constraint imposed affects the type of solution. For example, we may assume that locally, the model is constant. Or we may assume that the model should be constant over a large input range. The difference in scale between these two assumptions is a matter of complexity. It is akin to 1nn vs a linear regression model. In particular, the strength of the constraint is dictated by the neighbourhood size.

Models that impose constraints of very small neighbourhoods are likely to have a higher variance in the solution. Whereas models that impose constraints over a wider neighbourhood are likely to have a smaller variance, however an increased bias towards a simpler solution.

Some methods such as kernel and local regresion/ tree-based methods directly specify the metric and size of the neighbourhood.

- knn defines the metric based on k
- splines, neural networks and basis function methods implicitly define define neighbourhoods of local behaviour.

One fact that is therefore clear: any method that attempts to produce locally varying functions in small isotropic neighborhoods will run into problems in high dimensions.

Also, any method that tries to overome the dimensionality problems, have an associated-and often mplicit or adaptive- metric ofr measuring neighborhoods, which basically does not allow the neighborhood to be simultaneously small in al ldirections.

### Classes of Restricted Estimators

Each of these classes have a associated parameters, sometimes called smoothing parameters, to control the effective size of the local neighbourhood.

#### Roughness penalty and bayesian methods

$$ PRSS(f; \lambda) = RSS(f) + \lambda J(f) $$

The user-selected functional $J(f)$ will be large for functions $f$ that vary too rapidly over small regions of input space. This is the case in high dimensions.

cubic smoothing spline for one dimensional inputs

$\operatorname{PRSS}(f ; \lambda)=\sum_{i=1}^{N}\left(y_{i}-f\left(x_{i}\right)\right)^{2}+\lambda \int\left[f^{\prime \prime}(x)\right]^{2} d x$

large values of $\lambda$ dictate that $f(X)$ should be linear in $x$.. that is the solution is globally constant. Whereas for smaller values of $\lambda$, the nature of $f(X)$ is less restricted to being globally constant, for example it may be sin(x_i) instead of just x_i. This type of model therefore has a higher variance.

Penalty functions, or regularization methods, express our prior belief that the type of functions we seek exhibit a certain type of smooth behaviour. The penalty $J$ corresponds to a log prior, and $PRSS(f;\lambda)$ the log posterior distribution.

#### Kernel Methods and Local Regression

Kernel methods work via the use of kernel functions $K_\lambda(x_0, x)$ which assigns weights to points x in a region around x_0:

- kernel functions that very local in assigning weights lead to models that are very local (high variance, low bias) . For example a gaussian kernel with very small variance
- whilst kernels that distribute the wieght over a large range lead to functiosn that are more global (low variance, high bias). For example a gaussian kernel with very high variance.

bias variance tradeoff:

![bias_var_tradeoff](/assets/bias_var_tradeoff.png)

## Linear Models for Regression

linear regression assumes that the regression function $E[Y|X]$ is linear in the inputs $X$.

Linear regression model has the form $f(X) = \beta_0 + \sum_{j = 1}^p X_j\beta_j$

The linear model assumes that either the regression function is linear, or a suitable approximation.

typically linear models do not place specific constraints on the behaviour of a function locally.

The most popular method is least squares, where the coefficients are picked to minimise $E_XE_{Y|X}[(Y - f(X, W))^2| X]$ where the expectation is replaced by a sample average:

$$\frac{1}{n} \sum_i (y_i - f(x_i, w))^2$$

where $f(x_i, w) = E[Y| X = x_i]$ or an approximation.

We must have that the $(x_i, y_i)$ are independent or the $y_i$ are conditionally independent given $x_i$.
