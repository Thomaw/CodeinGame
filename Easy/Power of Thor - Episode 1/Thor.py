a,b,c,d=[int(i) for i in input().split()]
f=c;g=d
while 1:
 e=int(input());h="";m=""
 if g>b:m+="N";g-=1
 elif g<b:m+="S";g+=1
 if f>a:h+="W";f+=1
 elif f<a:h+="E";f-=1
 print(m+h)
