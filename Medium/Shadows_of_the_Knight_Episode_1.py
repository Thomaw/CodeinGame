
import sys
import math


w, h = [int(i) for i in input().split()]
n = int(input())  # maximum number of turns before game over.
x0, y0 = [int(i) for i in input().split()]

min_w=min_h=0
max_w=w-1
max_h=h-1

# game loop
while True:
    bomb_dir = input()  # the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)

    R=bomb_dir.find("R")
    L=bomb_dir.find("L")
    U=bomb_dir.find("U")
    D=bomb_dir.find("D")

    #print(R,L,U,D)
    if R == 0 or R==1:
        min_w=x0+1
    
    if L == 0 or L==1:
        max_w=x0-1

    if U == 0 or U==1:
        max_h=y0-1

    if D == 0 or D==1:
        min_h=y0+1

    x0 = min_w + math.ceil((max_w  - min_w)/2)
    y0 = min_h + math.ceil((max_h  - min_h)/2)

    x=int(x0)
    y=int(y0)
   
    print(x,y)
    
