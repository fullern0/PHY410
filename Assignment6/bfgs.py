import scipy.optimize as opt
import math

r = lambda x: math.sqrt(x[0]**2 + x[1]**2)
V = lambda x: -(r(x)**2)/2. + (r(x)**4)/4.

x0 = (1., 1.)

minm = opt.minimize(V, x0, method='BFGS')

print minm
