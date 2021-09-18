
#include <iostream>
#include <string>
#include <vector>


using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
void tri_a_bulle(int *t, int const size) 
{
	bool en_desordre = true;
	for (int i = 0; i < size && en_desordre; ++i)
	{
		en_desordre = false;
		for (int j = 1; j < size - i; ++j)
			if (t[j-1] > t[j])
			{
				swap(t[j], t[j-1]);
				en_desordre = true;
 			}
	}
}

int main()
{
    int const tailleTableau(9); //taille du tableau
        int tableau_sudoku[tailleTableau][tailleTableau];
        int tableau_ligne[tailleTableau]; //déclaration du tableau
        int tableau_colonne[tailleTableau]; //déclaration du tableau
        int tableau_subgrid[tailleTableau]; //déclaration du tableau
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            int n;
            cin >> n; cin.ignore();
            tableau_sudoku[i][j]=n;
        }
    }

    bool answer;

// for row and column

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            tableau_ligne[j]=tableau_sudoku[i][j];
            tableau_colonne[j]=tableau_sudoku[j][i];
        }

        //cout<<tableau_ligne[0]<<","<<tableau_ligne[1]<<","<<tableau_ligne[2]<<","<<tableau_ligne[3]<<","<<tableau_ligne[4]<<","<<tableau_ligne[5]<<","<<tableau_ligne[6]<<","<<tableau_ligne[7]<<","<<tableau_ligne[8]<<endl;
        //cout<<tableau_colonne[0]<<","<<tableau_colonne[1]<<","<<tableau_colonne[2]<<","<<tableau_colonne[3]<<","<<tableau_colonne[4]<<","<<tableau_colonne[5]<<","<<tableau_colonne[6]<<","<<tableau_colonne[7]<<","<<tableau_colonne[8]<<endl;

        tri_a_bulle(tableau_ligne,9);
        tri_a_bulle(tableau_colonne,9);

        //cout<<tableau_ligne[0]<<","<<tableau_ligne[1]<<","<<tableau_ligne[2]<<","<<tableau_ligne[3]<<","<<tableau_ligne[4]<<","<<tableau_ligne[5]<<","<<tableau_ligne[6]<<","<<tableau_ligne[7]<<","<<tableau_ligne[8]<<endl;
        //cout<<tableau_colonne[0]<<","<<tableau_colonne[1]<<","<<tableau_colonne[2]<<","<<tableau_colonne[3]<<","<<tableau_colonne[4]<<","<<tableau_colonne[5]<<","<<tableau_colonne[6]<<","<<tableau_colonne[7]<<","<<tableau_colonne[8]<<endl;

        for (int k=0;k<8;k++) {
            if (tableau_ligne[k]+1==tableau_ligne[k+1] && tableau_colonne[k]+1==tableau_colonne[k+1]) {
                answer=true;
            }
            else {
                answer=false;
                break;
                }
        }

        if (answer==false) {
                break;
                }

    }



// for subgrid
if (answer==1) {

for (int i=0;i<9;i+=3){
    for (int j=0;j<9;j+=3){
        
        //cout<<i<<" and "<<j<<endl;

        int p=0;

        for (int l=i;l<i+4;l+=1) {
            for (int h=j;h<j+3;h+=1) {
                //cout<<l<<"and"<<h<<endl;
                tableau_subgrid[p]=tableau_sudoku[l][h];
                p+=1;
            }
        }

        //cout<<tableau_subgrid[0]<<","<<tableau_subgrid[1]<<","<<tableau_subgrid[2]<<","<<tableau_subgrid[3]<<","<<tableau_subgrid[4]<<","<<tableau_subgrid[5]<<","<<tableau_subgrid[6]<<","<<tableau_subgrid[7]<<","<<tableau_subgrid[8]<<endl;

        tri_a_bulle(tableau_subgrid,9);
        //cout<<tableau_subgrid[0]<<","<<tableau_subgrid[1]<<","<<tableau_subgrid[2]<<","<<tableau_subgrid[3]<<","<<tableau_subgrid[4]<<","<<tableau_subgrid[5]<<","<<tableau_subgrid[6]<<","<<tableau_subgrid[7]<<","<<tableau_subgrid[8]<<endl;

    for (int k=0;k<8;k++) {
        if (tableau_subgrid[k]+1==tableau_subgrid[k+1] && tableau_subgrid[0]==1 ) {
            answer=true;
        }
        else {
            answer=false;
            break;
         }
    }
    
    if (answer==false) {
        break;
    }
} 
if (answer==false) {
        break;
    }
}
}




    if (answer==1) {
        cout << "true" << endl;
    }

    else {
        cout <<"false"<<endl;
    }
    
}
