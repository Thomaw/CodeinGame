#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/


int main()
{
    int width;
    int height;
    cin >> width >> height; cin.ignore();

//cout<<"width : "<<width<<" and height "<<height<<endl;

    string b;
    //string b [height][width];
    


    int tab_size=width*height;

    int tab_val[tab_size];

    for (int i = 0; i < tab_size; i++) {
            tab_val[i]=0;
    }

    for (int i = 0; i < height; i++) {
        string line;
        cin >> line;// cin.ignore();
        //b[i][width]= line;
        //cout<<b[i][height]<<endl;
        b.append(line);
        //b.append(" ");
    }

    //cout<<b<<endl;


   for (int i = 0; i < tab_size; i++) {
        if (b[i]=='#') {
        tab_val[i]=-1;
        }
    }
//cout<<c<<endl;

//cout<<tab_val[4]<<endl;;


int tab_2[height][width];

int k=0;
for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
        tab_2[i][j]=tab_val[k];
        k+=1;
    }
}

/**
cout<<tab_2[0][0]<<","<<tab_2[0][1]<<","<<tab_2[0][2]<<","<<tab_2[0][3]<<","<<tab_2[0][4]<<endl;
cout<<tab_2[1][0]<<","<<tab_2[1][1]<<","<<tab_2[1][2]<<","<<tab_2[1][3]<<","<<tab_2[1][4]<<endl;
cout<<tab_2[2][0]<<","<<tab_2[2][1]<<","<<tab_2[2][2]<<","<<tab_2[2][3]<<","<<tab_2[2][4]<<endl;
**/


for (int i = 0; i < height; i=i+1) {
    for (int j = 0; j < width; j=j+1) {
        
        

        if (tab_2[i][j]==0) {
            int sum=0;


            if (j>0) {
                if (tab_2[i][j-1]>-1)  {
                sum++;
                }
            } 


            if ((j+1)<width) {
                if (tab_2[i][j+1]>-1) {
                sum++;
                }
            } 


            if (i>0) {
                if (tab_2[i-1][j]>-1) {
                sum++;
                }
            } 


            if ((i+1)<height) {
                if (tab_2[i+1][j]>-1) {
                sum++;
                }
            } 

            tab_2[i][j]=sum;

        }
        
    }
}

/**
cout<<tab_2[0][0]<<","<<tab_2[0][1]<<","<<tab_2[0][2]<<","<<tab_2[0][3]<<","<<tab_2[0][4]<<endl;
cout<<tab_2[1][0]<<","<<tab_2[1][1]<<","<<tab_2[1][2]<<","<<tab_2[1][3]<<","<<tab_2[1][4]<<endl;
cout<<tab_2[2][0]<<","<<tab_2[2][1]<<","<<tab_2[2][2]<<","<<tab_2[2][3]<<","<<tab_2[2][4]<<endl;
**/

for (int i = 0; i < height; i=i+1) {
    for (int j = 0; j < width; j=j+1) {
        if (tab_2[i][j] != -1) {
            cout<<tab_2[i][j];
        }

        else {
            cout<<"#";
        }
    }
    cout<<endl;
}

/**
k=0;
int tab_3[height*width];

for (int i = 0; i < height; i=i+1) {
    for (int j = 0; j < width; j=j+1) {
        tab_3[k]=tab_2[i][j];
        k+=1;
    }
}

cout<<tab_3[0]<<","<<tab_3[1]<<","<<tab_3[2]<<","<<tab_3[3]<<","<<tab_3[4]<<endl;
**/
}
