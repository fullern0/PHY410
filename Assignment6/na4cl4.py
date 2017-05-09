from nacl import *
import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

name="Na4Cl4"       # for output files
nNa = 4
nCl = 4
n = nNa + nCl
a = 0.2
r_Na = [ [ 0, 0, 0 ], [ a, a, 0], [0, a, a], [a, 0, a] ]
r_Cl_set = [ ]

r_Cl_trial = [ [ 0, 0, 0 ], [ 0, 0, 0], [0, 0, 0], [0, 0, 0] ]
def mk_Cl_pos(n):
    global r_Cl_set
    global r_Cl_trial
    for i in range(-1,2):
        if n==3:
            print i
        for j in range(-1,2):
            for k in range(-1,2):
                pos = [a*i,a*j,a*k]
                if pos not in r_Na + r_Cl_trial:
                    r_Cl_trial[n]=pos
                    if n>0:
                        mk_Cl_pos(n-1)
                    else:
                        unq = True
                        for cfg in r_Cl_set:
                            cnt=0
                            for atm in r_Cl_trial:
                                if atm in cfg:
                                    cnt+=1
                            if cnt==nCl:
                                unq=False
                        if unq:
                            r_Cl_set.append(r_Cl_trial[:])
                        r_Cl_trial[n]=[0, 0, 0]

mk_Cl_pos(nCl-1)
           
config_set = [ ]
for r_Cl in r_Cl_set:
    print r_Cl
    print r_Na
# Initialize the cluster, add guesses at the
# minimum arrangement. 
    cluster = Cluster()

    for i in xrange(nNa) :
    #    r = Vector(r_Na[i])
        cluster.add(Na(r_Na[i]))

    for i in xrange(nCl) :
    #    r = Vector(r_Cl[i])
        cluster.add(Cl(r_Cl[i]))

    print " " + name + " cluster"
    print " Initial potential energy = " + str( cluster.potential_energy() )

    # Minimize the function
    accuracy = 1e-6

    res = cluster.minimize( accuracy )

    config_set.append([res[1],cluster])

cluster = config_set[0][1]
pe = config_set[0][0]
minpe = 100000.
for cfg in config_set:
    if cfg[0] < minpe:
        cluster, pe = cfg[1], cfg[0]

# Print out resulting files, and also
# plot the values in matplotlib
print " Minimized potential energy = " + str(pe) + " eV"
print " Binding energy of cluster  = " + str( pe / 2.0 ) + " eV"

file_name = name + ".data"
outfile = open( file_name, 'w' )
for i in xrange( nNa + nCl - 1) :
    for j in range(i+1,nNa+nCl) :
        rij = cluster.ion(i).r - cluster.ion(j).r
        dr = sqrt( np.dot(rij,rij) )
        s =  "(" + cluster.ion(i).name + ")-(" + cluster.ion(j).name + ")"
        print " " + s + " r_" + str(i) + str(j) + " = " + str( dr ) + " nm"

outfile.write( str(cluster) )
outfile.close()

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

[x,y,z] = cluster.convert()
ax.scatter( x,y,z )
plt.show()
