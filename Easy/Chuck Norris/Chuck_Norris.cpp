#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main()
{
    string MESSAGE;
    string message;
    string bits;
    string bits2;
    getline(cin, MESSAGE);

  /* 1ère étape : conversion du message en binaire. On commence par initialiser une variable « ascii » qui représente le nombre en base 10 (décimal) de chaque caractère présent dans le message 
  La boucle tant que se présente ensuite de la manière suivante :
  Si le reste de la division euclidienne de « ascii » par 2 est 0, alors on pose un bit égal à 0
  Si le reste de la division euclidienne est 1, alors on pose un bit égal à 1
  On somme les 0 et les 1 pour obtenir le message en base 2 (binaire)
  */
  
    for (int i = 0; i < MESSAGE.size(); i++) {
        int ascii = (int) MESSAGE[i]; /* force la conversion de messages en binaire (de la table Ascii */
    while (ascii != 0) {
      if (ascii % 2 == 0) {
            bits = bits + "0";
            ascii = floor(ascii) /2;
            } 
      if (ascii % 2 == 1) {
          bits = bits + "1";
          ascii = floor(ascii) / 2;
          }
          }

/* les trois lignes qui suivent servent si un caractère n’est pas codé sur 7 bits. Par exemple, si l’on prend le caractère %, en obtient en binaire avec le code précédant 101001 celui-ci n’étant codé que sur 6 bits. Il est alors nécessaire de rajouter un 0 pour obtenir un code à 7 bits de la forme 1010010 */
    while (bits.size() % 7 != 0) {
        bits = bits + "0";
        }
        }

 /* la boucle suivante permet d'inverser le nombre binaire car lors de la conversion décimale-binaire les bits sont dans le mauvais ordre
 Ainsi le premier bit devient le dernier, le deuxième devient l'avant-dernier...
 */
 
    for (int i = 6; i <= bits.size(); i+=7) {
        for (int j = 0; j <= 6 ; j++) {
            bits2 = bits2 + bits[i-j];
        }
    }
	
  /* On distingue deux cas : le premier bit et les bits suivants. */

    if (bits2[0] == '0') {
        message = "00 0";
    }
    if (bits2[0] == '1') {
        message = "0 0";
    }

/* pour tous les bits (sauf le premier), on raisonne comme nous demande l’énoncé :
-	Tant qu'une suite de bits ne change pas de nombre, on rajoute un "0" dans le message
-	Si le bit est un 1, on rajoute " 0 0" dans le message
-	Si le bit est un 0, on rajoute " 00 0" dans le message
*/

    for (int i = 1; i < bits2.size(); i++) {
        if (bits2[i] == bits2[i-1]) {
            message = message + "0";
        }
        else {
            if (bits2[i] == '1') {
                message = message + " 0 0";
            }
            if (bits2[i] == '0') {
                message = message + " 00 0";
            }
        }
    }
    cout << message << endl;

}
