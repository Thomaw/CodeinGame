#include <iostream>
#include <string> 
#include <vector> 
#include <algorithm> 
 
using namespace std; 
 
int main() {     int N; // the number of points used to draw the surface of Mars.     
cin >> N; cin.ignore();    
for (int i = 0; i < N; i++) {        
    int LAND_X; // Coordonnée X du point de la surface de Mars.         
    int LAND_Y; // Coordonnée Y du point de la surface de Mars.         
    cin >> LAND_X >> LAND_Y; cin.ignore(); // Initialise le sol de Mars dans la console     
    } 
 
    // game loop 
 
    while (1) {         
        int X; // position de la fusée en x.         
        int Y; // position de la fusée en y.         
        int hSpeed;  // vitesse horizontal (en m/s).         
        int vSpeed; // vitesse vertical (en m/s).         
        int fuel; // quantité de carburant restant.         
        int rotate; // rotation de l'angle (-90° à 90°).         
        int power; // puissance de poussée (0 à 4).         
        cin >> X >> Y >> hSpeed >> vSpeed >> fuel >> rotate >> power; cin.ignore(); // on initialise tous les paramètres de la fusée dans la console                  
        if (rotate == 0)             
        cout << 0<< " " << 5<< endl; /* si la vitesse est inférieur à -39m/s, les propulseurs s'activent pour contrebalancer la gravité de Mars */                      
        else cout << 0 << " " << 0 << endl; /* sinon aucun propulseurs n'est activée */              
        } 
        } 
        
