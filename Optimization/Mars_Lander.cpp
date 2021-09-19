#include <iostream>
using namespace std;
int main(){int N,a,b,c=0,d=0;cin>>N;
    for (int i=0;i<N;i++){int e,f;cin>>e>>f;
        if(d==f && e-c>=1000){a=(e+c)/2,b=f;}
        d=f;c=e;}
    while (1){int X,Y,H,V,F,R,P,p=0,A=0 ;;cin>>X>>Y>>H>>V>>F>>R>>P;
        int y=Y-b,x=X-a;
        if(V<-30)p=4;double B=x+H*y/40;
        if(y>200){
            if(B<-300)A=-20,p=4;
            else if(B>300)A=20,p=4 ;
            else if(H>20)A=45,p++;
            else if(H<-20)A=-45,p++;
            if(H<-40)A=-20;}
        if (p>4)p=4;cout<<A<<" "<<p<<endl;}}
