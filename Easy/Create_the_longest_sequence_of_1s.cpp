#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int longest_1 (string b)
{
  int maxi;
  maxi=1;

    int sum=1;

  for (int i=0;i<b.length()-1;i+=1) { 
      if (b[i]=='1' && b[i+1]=='1') {
          sum+=1;

          maxi=max(maxi,sum);
        }
      else {
      sum=1;
      }
  }

  return maxi;
}



int main()
{
    string b;
    getline(cin, b);

    int maxi=longest_1(b);


 //   cout<<b<<endl;
  //  cout<<maxi<<endl;

        
    int size_tab=b.length();
    int tab[size_tab];

    for (int i=0;i<b.length();i+=1) { 
        tab[i]=-1;
    }

    //cout<<b.length()<<endl;

    int k=0;
    for (int i=0;i<b.length();i+=1) { 

       // cout<<b[i]<<endl;

        if (b[i]=='0') {
            tab[k]=i;
            k+=1;
        }

    }
/**
    cout<<"k="<<k<<endl;
    cout<<tab[2]<<endl;
    cout<<tab[3]<<endl;
**/
    for (int i=0;i<k;i+=1) {
        string c=b;
        c[tab[i]]='1';

        int sum=longest_1(c);

        maxi=max(maxi,sum);
        
    }

    cout<<maxi<<endl;
    //cout<<"maxi="<<maxi<<endl;
}
