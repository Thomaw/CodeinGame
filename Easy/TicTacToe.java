import java.util.*;
import java.io.*;
import java.math.*;

class Solution {

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        char[][] Tab = new char [3][3];

        for (int i = 0; i < 3; i++) {
            String line = in.nextLine();
            
            for (int j = 0; j < 3; j++) {
                Tab[i][j] = line.charAt(j);
            }
        }

        // Regarder tous les emplacements libres
        Vector<Integer> EmptyXCase = new Vector<Integer>();
        Vector<Integer> EmptyYCase = new Vector<Integer>();
        boolean Winning = false;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (Tab[i][j] == '.'){
                    EmptyXCase.add(i);
                    EmptyYCase.add(j);
                }
            }
        }

        // On place sur chacune de ces cases un 'O'
        for (Integer i = 0; i < EmptyXCase.size(); i++) {
            Tab[EmptyXCase.get(i)][EmptyYCase.get(i)] = 'O';
            
            Winning = WinningCondition(Tab);    // Condition de victoire
            if (Winning){
                AffichageJeu(Tab);
                break;
            }

            // Si pas de victoire 
            Tab[EmptyXCase.get(i)][EmptyYCase.get(i)] = '.';
        }

        if (!Winning){System.out.println("false");}
    }

    public static void AffichageJeu(char[][] Tab){
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                System.out.print(Tab[i][j]);
            }
            System.out.println();
        }
    }

    public static boolean WinningCondition(char[][] Tab){
        //AffichageJeu(Tab);
        if ( (Tab[0][0] == 'O' && Tab[0][1] == 'O' && Tab[0][2] == 'O')
        ||   (Tab[1][0] == 'O' && Tab[1][1] == 'O' && Tab[1][2] == 'O')
        ||   (Tab[2][0] == 'O' && Tab[2][1] == 'O' && Tab[2][2] == 'O')
        ||   (Tab[0][0] == 'O' && Tab[1][0] == 'O' && Tab[2][0] == 'O')
        ||   (Tab[0][1] == 'O' && Tab[1][1] == 'O' && Tab[2][1] == 'O')
        ||   (Tab[0][2] == 'O' && Tab[1][2] == 'O' && Tab[2][2] == 'O')
        ||   (Tab[0][0] == 'O' && Tab[1][1] == 'O' && Tab[2][2] == 'O')
        ||   (Tab[0][2] == 'O' && Tab[1][1] == 'O' && Tab[2][0] == 'O')){
            return true;
        }
        else{return false;}
    }
}
