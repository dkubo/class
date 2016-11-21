import numpy as np
from scipy import stats

n_samples = 100
alpha     = 0.95

data     = np.random.randn(n_samples)

print(data)
mean_val = np.mean(data)
sem_val  = stats.sem(data)  # standared error of the mean
ci       = stats.t.interval(alpha, len(data)-1, loc=mean_val, scale=sem_val)
 
print('mean:', mean_val)
print('confidence interval:', ci)
