#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n; 
    cin >> n; cin.ignore(); 
    int t[n]; 
    for (int i = 0; i < n; i++) { 
        
        cin >> t[i]; cin.ignore(); 
        }

    int min=t[0]; 
    
sort(t, t+n); 

    if (n==0)  {
 cout << 0 << endl; }

    else if (n!=0) 
    {
for (int i = 0; i < n; i++) {
    if (t[i-1] >> t[i]) { 
    
    min=t[i];  
}
}
    cout << min << endl;
}
}
