#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/* On initiale d’abord les variables nécessaires au déroulement du programme : « rom1 » et « rom2 » sont les nombres romains de départ, « decimal1 » est la conversion de « rom1 » en décimal et « decimal2 » est la conversion de « rom2 » en décimale. La variable « decimal » représente le nombre decimal final (la somme de « decimal1 » et « decimal2 »). Enfin, la variable « romain2 » représente le nombre romain final, qui est la somme de « rom1 » et « rom2 » */

int main()
{
    string rom1;
    cin >> rom1; cin.ignore();
    string rom2;
    cin >> rom2; cin.ignore();

int decimal1 = 0;
int decimal2 = 0;
int decimal  = 0;

string romain2 ="";

/* les deux boucles for qui suivent représentent la conversion de « rom1 » puis « rom2 » en decimal. Pour cela, il faut tester chacune des lettres possibles pour un nombre romain, c'est-à-dire « M », « D », « C », « L », « X », « V » et « I » puis on associe le nombre correspondant à la lettre.
Puis on compare deux lettres successives pour vérifier que l’on n’a pas ajouté à l’étape précédente un nombre trop élevé. Par exemple, sans cette étape, on lirait que « CM » est équivalent en décimal à « 1100 » car l’ordinateur va lire « C » puis « M ».
*/

for(int i=0; i<= rom1.size(); i++) {
    
if (rom1[i] == 'M') {decimal1+=1000;}
if (rom1[i] == 'D') {decimal1+=500;}
if (rom1[i] == 'C') {decimal1+=100;}
if (rom1[i] == 'L') {decimal1+=50;}
if (rom1[i] == 'X') {decimal1+=10;}
if (rom1[i] == 'V') {decimal1+=5;}
if (rom1[i] == 'I') {decimal1+=1;}

if (rom1[i] == 'C' && rom1[i+1] == 'M') {decimal1+=-200;}
if (rom1[i] == 'C' && rom1[i+1] == 'D') {decimal1+=-200;}
if (rom1[i] == 'X' && rom1[i+1] == 'C') {decimal1+=-20;}
if (rom1[i] == 'X' && rom1[i+1] == 'L') {decimal1+=-20;}
if (rom1[i] == 'I' && rom1[i+1] == 'X') {decimal1+=-2;}
if (rom1[i] == 'I' && rom1[i+1] == 'V') {decimal1+=-2;}

}


for(int i=0; i<= rom2.size(); i++) {
    
if (rom2[i] == 'M') {decimal2+=1000;}
if (rom2[i] == 'D') {decimal2+=500;}
if (rom2[i] == 'C') {decimal2+=100;}
if (rom2[i] == 'L') {decimal2+=50;}
if (rom2[i] == 'X') {decimal2+=10;}
if (rom2[i] == 'V') {decimal2+=5;}
if (rom2[i] == 'I') {decimal2+=1;}

if (rom2[i] == 'C' && rom2[i+1] == 'M') {decimal2+=-200;}
if (rom2[i] == 'C' && rom2[i+1] == 'D') {decimal2+=-200;}
if (rom2[i] == 'X' && rom2[i+1] == 'C') {decimal2+=-20;}
if (rom2[i] == 'X' && rom2[i+1] == 'L') {decimal2+=-20;}
if (rom2[i] == 'I' && rom2[i+1] == 'X') {decimal2+=-2;}
if (rom2[i] == 'I' && rom2[i+1] == 'V') {decimal2+=-2;}
}

/* Calcul permettant de définir la somme des deux chiffres arabes */

decimal = decimal1 + decimal2;

/*Dernière boucle qui permet de convertir le nombre décimal en nombre romain. Pour cela, on réalise une suite de soustractions jusqu’à ce que le nombre décimal soit nul et à chaque soustraction, on associe la lettre romaine qui lui correspond. Par exemple, si le nombre est « 1100 », on va soustraire à ce nombre « 1000 » et lui associés la lettre « M », puis on va lui soustraire « 100 » et lui associer « C » */

    while (decimal != 0 )
    {
if (decimal >= 1000) {romain2 += "M"; decimal -= 1000;}
else if (decimal >= 900) {romain2 += "CM"; decimal -= 900;}
else if (decimal >= 500) {romain2 += "D"; decimal -= 500;}
else if (decimal >= 400) {romain2 += "CD"; decimal -= 400;}
else if (decimal >= 100) {romain2 += "C"; decimal -= 100;}
else if (decimal >= 90) {romain2 += "XC"; decimal -= 90;}
else if (decimal >= 50) {romain2 += "L"; decimal -= 50;}
else if (decimal >= 40) {romain2 += "XL"; decimal -= 40;}
else if (decimal >= 10) {romain2 += "X"; decimal -= 10;}
else if (decimal >= 9) {romain2 += "IX"; decimal -= 9;}
else if (decimal >= 5) {romain2 += "V"; decimal -= 5;}
else if (decimal >= 4) {romain2 +="IV"; decimal -= 4;}
else                   {romain2 +="I"; decimal -= 1;}

}

/* On finit par afficher le résultat */

cout<<romain2;
}

