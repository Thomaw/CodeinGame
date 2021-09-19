#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

/* On introduit dans les 5 premières lignes la fonction distance expliquée au-dessus */

int distance(int a, int b, int c, int d)
{
    int resultat;
    resultat = sqrt(pow(a-b,2) + pow(c-d,2));
    return resultat;
}

int main()
{

/* On définit les différentes variables */

    int W; //longueur du plateau de jeu
    int H; //largeur du plateau de jeu
    int R=0; // Numéro du tour dans le jeu
    
    int te = 0; // nombre d'ennemis
    int ta = 0;  // nombre de tours alliées
    
    cin >> W >> H; cin.ignore();
    
/* On créer par la suite des vecteurs qui sont des tableaux dynamiques. On préfèrera des vecteurs plutôt que des tableaux statiques car il n’est pas nécessaire de définir une taille précise de vecteur là où il est nécessaire de donner la taille d’un tableau. De plus, pour un tableau, il est obligatoire de donner l’emplacement précis d’un nombre (par exemple tab[2]=4), là où pour un vecteur, on peut directement ajouter un nombre à la fin du vecteur (avec la fonction push_back)*/

    vector <int> XE;
    vector <int> YE;
    vector <int> XT;
    vector<int> YT;
    vector <int> N;

/* Dans les boucles qui suivent, on regarde chaque case du plateau de jeu. Si la case est un « T », on ajoute les coordonnées de cette case aux vecteurs correspondant à la position des tours (ici « XE » et « YE »). Si la case est un nombre, on associe les coordonnées de cette case aux vecteurs correspondant à la position des ennemis et on associe ce nombre au point de vie de l’ennemi (donc à N). 
Enfin, à chaque ennemi, on ajoute +1 au nombre d’ennemis (donc à te), et pour chaque nouvelle tour, on ajoute +1 au nombre de tours (donc à ta) */
    
    for (int i = 0; i < H; i++) {
        string line;
        cin >> line; cin.ignore();
        
    for (int j = 0; j<W;j++){
            
        if (line[j] != '.') {
            
            if (line[j] =='T'){
            XT.push_back(j);
            YT.push_back(i);
            ta += 1;}
            
            else {
            XE.push_back(j);
            YE.push_back(i);
            te += 1;}
        }
        
        if(line[j]=='0') {N.push_back(0);}
            else if(line[j]=='1') {N.push_back(1);}
            else if(line[j]=='2') {N.push_back(2);}
            else if(line[j]=='3') {N.push_back(3);}
            else if(line[j]=='4') {N.push_back(4);}
            else if(line[j]=='5') {N.push_back(5);}
            else if(line[j]=='6') {N.push_back(6);}
            else if(line[j]=='7') {N.push_back(7);}
            else if(line[j]=='8') {N.push_back(8);}
            else if(line[j]=='9') {N.push_back(9);}
            }
        }

     /*Une fois tous les ennemis et tours déclarés, on créer une boucle tant que qui représente l’organigramme de décision cité plus haut.  */  

        while (te !=0){
         R = R + 1;
            
        for (int k=0; k< ta; k++){ // pour chaque tour
               
            int Ecible_x=999; // position en x de l’ennemi à viser
            int Ecible_y=999; // position en y de l’ennemi à viser
            int Ecible=999; // numéro de l’ennemi à viser
            
        for (int l=0; l<te; l++){ // pour chaque ennemi
                    
           if (distance(XE[l],XT[k],YE[l],YT[k]) <= distance(1,-1,1,-1)){ // si l’ennemi est à porter
                       
               if (YE[l] < Ecible_y) { /* si l’ennemi précédent est plus proche du château que le précédent, alors c’est celui-ci qui est visé */

                 Ecible_y=YE[l];
                 Ecible_x=XE[l];
                 Ecible=l; }
                 
                    else if(YE[l] == Ecible_y){ /* si plusieurs ennemis sont à la même hauteur */ 

                          if (distance(XE[l],XT[k],YE[l],YT[k]) < distance(Ecible_x,XT[k],Ecible_y,YT[k])){ 
/* on regarde quel ennemi est le plus proche de la tour et le plus proche est alors pris pour cible*/

					  Ecible_y=YE[l];
                             Ecible_x=XE[l];
                             Ecible=l; }
                            
                    else if(distance(XE[l],XT[k],YE[l],YT[k]) == distance(Ecible_x,XT[k],Ecible_y,YT[k])){ 
/* Si deux ennemis ont la même distance de la tour, on regarde lequel est le plus à l’Est */
   
                          if (XE[l]>Ecible_x){ 
/* l’ennemi le plus à l’Est est alors ciblé */

                              Ecible_y=YE[l];
                              Ecible_x=XE[l];
                              Ecible=l;}}
                            }
                        }
                    }
                 N[Ecible] -= 1; 
/* pour chaque tour, l’ennemi visé perd 1 point de vie */
                }
          
/* Après que chaque tour est tirée sur une cible, on regarde si les ennemis sont toujours en vie et si oui, il faut qu’il avant d’une case */      
            for(int m=0; m<te; m++){ // pour chaque ennemi
                
                if(N[m] <= 0){ 
/* si leur point de vie d’un ennemi est nul, le nombre d’ennemis diminue de 1 */
                    te -= 1;}
            }
            
            if(te==0){ // il n’y a plus d’ennemi, le château a gagné
                cout<<"WIN ";}
            
            for (int n=0;n<te; n++){ 
/* pour chaque ennemi encore en vie */
            
                if (YE[n]==0){ 
/* si un ennemi est déjà à l’ordonné minimale, il sort de la carte en avançant d’une case et le château a perdu */
                    te -= 1;
                    cout <<"LOSE ";}
                
                YE[n] -= 1; 
/* pour les autres, ils avancent d’une case vers le Nord */
                
                for(int p=0;p<ta; p++){ 
/* Enfin, on vérifie que lorsqu’un ennemi avancent d’une case vers le Nord, il ne rencontre pas une tour. Si c’est le cas, l’ennemi est détruit */
                    
                    if ((XE[n]==XT[p]) && (YE[n]==YT[p])){
                        te -= 1;

                        if(te==0){ 
/* il n’y a plus d’ennemi, le château a gagné */
                            R=R+1;
                            cout<<"WIN ";}
                    }
                }
            }
        }
    cout<<R; 
/* on affiche le nombre de tours nécessaire à gagner ou à perdre */
}

