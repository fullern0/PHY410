from trapezoid import *
from simpson import *
from math import *
import time


n1 = 1
n2 = 0

while n1 % 2 != 0 :
    n1 = int(raw_input( "Enter number of intervals desired for trapezoidal rule (must be even)" ))

a = 0.0
b = 1.0
start1 = time.time()
ans1 = trapezoid(exp, a, b, n1)
end1 = time.time()
print 'Trapezoidal rule = ' + str(ans1)
print 'Time = ' + str(end1-start1)
start2=time.time()
ans2 = simpson(exp, a, b, n1)
end2=time.time()
print 'Simpson\'s rule = ' + str(ans2)
print 'Time = ' + str(end2-start2)
