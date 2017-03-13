#!/usr/bin/python

import sys

class StudentRecord:
     def __init__(self, last_name, first_name, score):
          self.first_name=first_name
          self.last_name=last_name
          self.score=score

def calculate_average(roster):
     sum=0
     for sdnt in roster:
          sum+=sdnt.score
     return sum/len(roster)

def main(fname):
     roster = []
     lns=open(fname).readlines()
     for sdnt in lns:
          sval=sdnt.split(",")
          roster.append(StudentRecord(sval[0],sval[1],float(sval[2])))
     print("Class Average: %f%%" % calculate_average(roster))

if __name__=="__main__":
     main(sys.argv[1])
