#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int river (int k)
{
    // debut sum(décomposition en digits du nb) + nb
    int phi=ceil(log10(k)+pow(10,(-5)));
    int sum_1=k;
    
    //cout<<phi<<endl;

    int const tailledecompo_r1(phi);
    int decompo_r1[tailledecompo_r1];
    
    for (int i=0;i<phi;i=i+1) {
        //cout<<i<< " and "<<phi-i<<endl;
        
        decompo_r1[phi-1-i]=k%10;
        k=floor(k/10);
        sum_1+=decompo_r1[phi-1-i];
        // cout<<k<<" et "<<decompo_r1[phi-1-i]<<endl;
    }
    // cout<<decompo_r1[0]<<','<<decompo_r1[1]<<','<<decompo_r1[2]<<endl;
    // cout<<sum_1<<endl;
    
    return sum_1;
}



int main()
{
    long long r1;
    cin >> r1; cin.ignore();
    long long r2;
    cin >> r2; cin.ignore();


while (r1 != r2) {

    if (r1>r2) {
        r2=river (r2);
    }
    else { 
        r1=river (r1);
    }   

    
}
    cout <<r1<< endl;


}
