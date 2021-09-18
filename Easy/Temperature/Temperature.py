N = int(input())
if N==0:print("0")
else:
    a=None
    for T in map(int, input().split()):
        if (a==None)or(abs(T)<abs(a))or((T==-a)and(T>0)):
         a=T
    print(a)
