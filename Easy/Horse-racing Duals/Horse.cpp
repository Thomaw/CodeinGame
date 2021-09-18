#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N; // initialise le nombre de chevaux
    cin >> N; cin.ignore(); // rentre dans la console le nombre de chevaux
    int P[N]; /* initialise la variable représentant la puissance de chaque cheval */
    for (int i = 0; i < N; i++) { // boucle pour
        cin >> P[i]; cin.ignore(); /* rentre dans la console la puissance de chacun des chevaux jusqu’à que i<N (on va de 0 à N-1 pour avoir une course de N chevaux) */
    }

    sort(P, P + N); /* la fonction sort permet de trier en ordre croissant la puissance de chaque cheval. Dans ce cas, la fonction ordonne les puissances à partir du cheval 0 (pour P) jusqu’au cheval N (pour P+N) */
    
    int D = abs(P[1] - P[0]); /* initialise la différence de puissance entre le cheval 1 et le cheval 0. La valeur absolu est là pour que D>0 */

    for(int i = 0; i < N - 1; i++) { // boucle pour

    	D = min(D, abs(P[i+1] - P[i])); /* indique le minimum entre la différence de puissance des deux premiers chevaux avec celle de deux chevaux consécutifs aléatoires et associe à D la plus petite différence des deux.
Ce test permet de tester la différence de puissance pour tous les chevaux */
    }
    cout << D << endl; // affiche en sortie la plus petite des différence de puissance.
}
