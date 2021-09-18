#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/


int main()
{
    string Alphabet;
    Alphabet="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    string Operation;
    getline(cin, Operation);
    int pseudoRandomNumber;
    cin >> pseudoRandomNumber; cin.ignore();

    string rotor1;
    string rotor2;
    string rotor3;
    for (int i = 0; i < 3; i++) {
        string rotor;
        getline(cin, rotor);

        if (i==0) {
            rotor1=rotor;
        }

        if (i==1) {
            rotor2=rotor;
        } 

           if (i==2) {
            rotor3=rotor;
        }
    }

    //cout<<rotor1<<endl<<rotor2<<endl<<rotor3<<endl;

    string message;
    getline(cin, message);
/**
    cout<<Operation<<endl;
    cout<<pseudoRandomNumber<<endl;
    **/
   
   //cout<<message<<endl;
int tablesize=message.length();
int tab_nb[tablesize];

//----------------------- Cas de l'encodage-----------------------//
 if (Operation[0]=='E'){
    

    // Ajoute le nombre au message avant de passer dans les rotors
        int k=0;
        for (int i = 0; i < message.length(); i++)
        {
            int p=(int)message[i];
            p-=65;

            //cout<<p<<endl;

            p=(p+pseudoRandomNumber+k)%26;
            k+=1;
        
        
            //cout<<p<<endl;

            p+=65;
            tab_nb[i]=p-65;
            message[i]=(char) p;


            //cout<<tab_nb[i]<<endl; 
            //cout<<message[i]<<endl;
        }

        //cout<<message<<endl;
        //cout<<"pause"<<endl;

        //cout<<tab_nb[0]<<endl;

        //cout<<rotor1[4]<<endl;

        for (int i = 0; i < message.length(); i++)
        {
            message[i]=rotor1[tab_nb[i]];
            int p=(int)message[i];
            tab_nb[i]=p-65;
        }

    //cout<<message<<endl;
    //cout<<tab_nb[0]<<endl;

        for (int i = 0; i < message.length(); i++)
        {
            message[i]=rotor2[tab_nb[i]];
            int p=(int)message[i];
            tab_nb[i]=p-65;
        }

        //cout<<message<<endl;
        //cout<<tab_nb[0]<<endl;


          for (int i = 0; i < message.length(); i++)
        {
            message[i]=rotor3[tab_nb[i]];
            int p=(int)message[i];
            tab_nb[i]=p-65;
        }


        //cout<<"answer:"<<endl;
        cout<<message<<endl;
        //cout<<tab_nb[0]<<endl;
    }
    else

    //------------------------ Cas du décodage ------------------------//
    {

        
        for (int i = 0; i < message.length(); i++)
        {
            for (int j=0; j<rotor3.length();j++) {

                if (message[i]==rotor3[j]) {
                    
                    //cout<<message[i]<<endl;

                tab_nb[i]=j;
                
                message[i]=Alphabet[tab_nb[i]];

                
                //cout<<tab_nb[i]<<endl;
                //cout<<message[i]<<endl;
                break;
                }
            }
        }

        //cout<<message<<endl;


        for (int i = 0; i < message.length(); i++)
        {
            for (int j=0; j<rotor2.length();j++) {

                if (message[i]==rotor2[j]) {
                    
                    //cout<<message[i]<<endl;

                tab_nb[i]=j;
                
                message[i]=Alphabet[tab_nb[i]];

                
                //cout<<tab_nb[i]<<endl;
                //cout<<message[i]<<endl;
                break;
                }
            }
        }

        //cout<<message<<endl;


        for (int i = 0; i < message.length(); i++)
        {
            for (int j=0; j<rotor1.length();j++) {

                if (message[i]==rotor1[j]) {
                    
                    //cout<<message[i]<<endl;

                tab_nb[i]=j;
                
                message[i]=Alphabet[tab_nb[i]];

                
                //cout<<tab_nb[i]<<endl;
                //cout<<message[i]<<endl;
                break;
                }
            }
        }

        //cout<<message<<endl;


        int k=0;
        for (int i = 0; i < message.length(); i++)
        {
            int p=(int)message[i];
            p-=65;

            //cout<<p<<endl;

            p=(p-pseudoRandomNumber-k)%26;
            k+=1;
        
            if (p<0) {
                p+=26;
            }

            //cout<<p<<endl;

            message[i]=Alphabet[p];
            //cout<<message[i]<<endl;

            //cout<<tab_nb[i]<<endl; 
            //cout<<message[i]<<endl;
        }

        cout<<message<<endl;
        //cout<<"pause"<<endl;



    }
}
