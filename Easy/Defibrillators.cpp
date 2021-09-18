#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

struct Defib
{
        string numero_du_defibrillateur;
        string emplacement;
        string Adresse;
        string numero_de_telephone;
        float Lon;
        float Lat;
}; // définis tous les caractères de ce qui est fournie dans l'énoncé par un défibrillateur

double Entree(char a) // créer une varaible où l'on insère tout les caractères de type char dedans
{
    string caractere;// rentre tout les caratères qui ne sont pas déjà dans Entree (donc que les coordonnées de latitude et longitude des emplacements)
    getline(cin, caractere, a); //
    
    replace(caractere.begin(), caractere.end(), ',', '.');// du bébut de caractrer à la fin, on remplace la , par un .
    stod(caractere) * M_PI/180; // stod() convertie une variable string en variable double. On convertie les valeurs de longitudes et latitudes en radians
} // on convertie toutes les virgules en points (surtout pour les nombres car la virgules ne fonctionne en C++, seul le point fonctionne

int main()
{
    float lonB, latB;
    float lonA, latA;
    float x, y, d;  
    int N;
    int PlusProche= 9999999999; // asscocie la valeur maximal à une valeur suffisant grande pour ne pas créer d'erreur
    int iPlusProche=0; // on initialise le défibrillateur le plus proche à celui ayant la place 0 dans le tableau
    
    lonB = Entree('\n'); //lis la première ligne d'information puis saute une ligne
    latB = Entree('\n'); //lis la deuxième ligne d'information puis saute une ligne
    
    cout<<lonB<<endl;

    cin >> N; // lis la troisième ligne du tableau et la rentre dans la console
    Defib defibs[N]; // indique le nombre de défibrillateur. on ne le définis que maintenant car ce nombre est seulkement indiqué à la ligne 3 de l'entrée
   
    for (int i=0; i<N; i++) {
        getline(cin, defibs[i].numero_du_defibrillateur,';');
        getline(cin, defibs[i].emplacement,';');
        getline(cin, defibs[i].Adresse,';');
        getline(cin, defibs[i].numero_de_telephone,';');
       lonA= defibs[i].Lon = Entree(';'); // on ne fait pas de getline parce que getline ne fonctionne qu'avec des variables string et ici on utilise une variable float
       latA= defibs[i].Lat = Entree('\n'); // on lis la latitude puis on passe à la ligne suivante
        
    
        x = (lonB - lonA) * cos((latA + latB) / 2);
        y = latB - latA;
        d = sqrt((x*x) + (y*y)) * 6371; // calcul
        
        if (d < PlusProche) { // si la distance est inférieur au PlusProche positionnement
            PlusProche = d; // alors PlusProche prend la valeur d
            iPlusProche = i;
            }
        }  
        cout << defibs[iPlusProche].emplacement; //affiche le nom de déffibrilateur le plus proche
}
