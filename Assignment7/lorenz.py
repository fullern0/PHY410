import scipy.integrate as intg
from scipy.fftpack import fft
import numpy as np
import matplotlib.pyplot as plt
import time

def lorenz(t, w, s, r, b):
    x, y, z = w
    dydt = [s*(y-x), x*(r-z)-y, x*y-b*z]
    return dydt

s = 10.
r = 28.
b = 8./3.

t = np.linspace(0, 100, 1001)

w0 = [1., 1., 10.]

start = time.time()
#sol = intg.odeint(lorenz, w0, t, args=(s, r, b))
solver = intg.ode(lorenz)
solver.set_integrator('dopri5')
solver.set_f_params(s, r, b)
solver.set_initial_value(w0, 0.0)
sol = np.empty((len(t), 3))
sol[0] = w0
k = 1
while solver.successful() and solver.t < t[-1]:
    solver.integrate(t[k])
    sol[k] = solver.y
    k += 1
end = time.time()
print(end-start)

plt.plot(t[:len(t)/2], np.absolute(fft(sol[:, 2]))[:len(t)/2])
plt.xlabel('frequency')
plt.ylabel('z')
plt.show()
