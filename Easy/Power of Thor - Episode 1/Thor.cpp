#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() // Initialisation des paramètres
{
    int lightX; // l'éclair est à la position x
    int lightY; // l'éclair est à la position y
    int initialTX; // Thor commence à la position x
    int initialTY; // Thor commence à la position y
    cin >> lightX >> lightY >> initialTX >> initialTY; cin.ignore(); // On initialise l'emplacement de Thor ainsi que celui de l’éclair dans la console

    string dir; // créer une variable pour la direction des points cardinaux 
    
    // game loop

    while (1) {
        int remainingTurns; // Variable permettant de faire tourner Thor
        cin >> remainingTurns; cin.ignore();

      if (initialTX > lightX && initialTY > lightY) {initialTX -= 1; initialTY -= 1; dir = "NW";} // Thor va dans la direction Nord-Ouest
        
      else if (initialTX> lightX && initialTY < lightY) {initialTX -= 1; initialTY += 1; dir = "SW";} // Thor va dans la direction Sud Ouest
        
      else if (initialTX < lightX && initialTY < lightY) {initialTX += 1; initialTY += 1; dir = "SE";} // Thor va dans la direction Sud Est
        
      else if (initialTX < lightX && initialTY > lightY) {initialTX += 1; initialTY -= 1; dir = "NE";} // Thor va dans la direction Nord Est
        
      else if (initialTX > lightX) {initialTX -= 1; dir = "W";} // Thor va dans la direction Ouest
         
      else if (initialTX < lightX) {initialTX += 1; dir = "E";} // Thor va dans la direction Est
        
      else if (initialTY > lightY) {initialTY -= 1; dir = "N";} // Thor va dans la direction Nord
         
      else if (initialTY < lightY) {initialTY += 1; dir = "S";} // Thor va dans la direction Sud
        
      cout << dir << endl; // affiche la position de Thor après qu'il se soit déplacé d'une case
    }
}
