import scipy as si
import scipy.linalg
import numpy as nm
import pprint

O_m = 2.66*10.**-26
C_m = 1.99*10.**-26
CO_k = 1733
CC_k = 2092

M = si.array([ [O_m, 0., 0., 0., 0.],
               [0., C_m, 0., 0., 0.],
               [0., 0., C_m, 0., 0.],
               [0., 0., 0., C_m, 0.],
               [0., 0., 0., 0., O_m] ])

K = si.array([ [CO_k, -CO_k, 0., 0., 0.],
               [-CO_k, CO_k+CC_k, -CC_k, 0., 0.],
               [0., -CC_k, 2.*CC_k, -CC_k, 0.],
               [0., 0., -CC_k, CC_k+CO_k, -CO_k],
               [0., 0., 0., -CO_k, CO_k] ])

L, D = scipy.linalg.eig(K, M)

w = nm.sqrt(nm.real(L))

pprint.pprint(w)
pprint.pprint(D)
