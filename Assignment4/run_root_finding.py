from root_finding import *
from math import *
import time

def f ( x ) :
    return tan(x)

print(" 1. Simple search")
x0 = float ( input(" Enter initial guess x_0 : ") )
dx = float ( input(" Enter step dx : ") )
acc = float ( input(" Enter accuracy : ") )
start1=time.time()
answer = root_simple(f, x0, dx, acc,1000,True)
end1=time.time()
print  str ( answer ) + "\n\n"
print "Time = " + str(end1-start1)

print(" 2. Bisection search")
x0 = float ( input(" Enter bracketing guess x_0 : ") )
x1 = float ( input(" Enter bracketing guess x_1 : ") )
acc = float ( input(" Enter accuracy : ") )
start2=time.time()
answer = root_bisection(f, x0, x1, acc,1000,True)
end2=time.time()
print  str ( answer ) + "\n\n"
print "Time = " + str(end2-start2)


