import scipy.integrate as intg
import numpy as np
import matplotlib.pyplot as plt


def pend(y, t, w0, g, F, wD):
    th, w, ph = y
    dydt = [w, -(w0**2)*np.sin(th) - g*w + F*np.cos(ph), wD]
    return dydt

w0 = 1.
g = 0.5
F = np.linspace(1, 1.2, 1001)
wD = 0.6667

y0 = [-np.pi/2., 0., 0.]

t = np.linspace(0, 100, 1001)

bfx = []
bfy = []
for ff in F:
    sol = intg.odeint(pend, y0, t, args=(w0, g, ff, wD))
    a0s = [j for j,x in enumerate(sol[:, 0]) if abs(x)<0.02]
    for a0 in a0s:
        bfx.append(ff)
        bfy.append(sol[a0, 1])

plt.scatter(bfx, bfy, marker=".")
plt.xlabel('F')
plt.ylabel('omega')
plt.show()
