#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int L;
    cin >> L; cin.ignore();
    int H;
    cin >> H; cin.ignore();
    string T;
    getline(cin, T);

    string ans [H];
    string result;
        
    for (int i = 0; i < H; i++) {
        
        string ROW;
        getline(cin, ROW);

        for(int j=0; j<T.length(); j++){
                char Majuscule= toupper(T[j]); 
                
                if (((Majuscule >= 65) && (Majuscule <= 90))) {
                      ans[i] += ROW.substr(L * (Majuscule - 65), L);
                        } else {
                            ans[i] += ROW.substr(L * 26, L);
                            }
                            }
                            }
       for (int i = 0; i < H; i++) {
        result += ans[i];
        result += "\n";
        }
        
     cout << result;
    }
