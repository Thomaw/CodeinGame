import sys
import math
import numpy
# Auto-generated code below aims at helping you parse
# the standard input according to the problem statement.

n = int(input())
a = numpy.zeros(n)
for i in range(n):
    pi = int(input())
    a[i]=pi
a.sort()

delta_min=10000000
for i in range(n-1):
    delta=abs(a[i]-a[i+1])

    if delta<delta_min:
        delta_min=delta

print(int(delta_min))
