import sys
import math

# game loop
while True:
    max = 0
    imax = 0

    for i in range(8):
        mountain_h = int(input())  # represents the height of one mountain.
        if mountain_h>max:
            max=mountain_h
            imax=i
    print(imax)
