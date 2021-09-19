import java.util.*;
import java.io.*;
import java.math.*;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/
class Solution {

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        List<Integer> joueur1 = new ArrayList<>();
        List<Integer> joueur2 = new ArrayList<>();
        Integer nbManche =0;
        Integer joueurWin = 0;
        boolean isFini = false;
        int n = in.nextInt(); // the number of cards for player 1
        for (int i = 0; i < n; i++) {
            String cardp1 = in.next(); // the n cards of player 1
            
            joueur1.add(convertCard(cardp1));
        }
        int m = in.nextInt(); // the number of cards for player 2
        for (int i = 0; i < m; i++) {
            String cardp2 = in.next(); // the m cards of player 2
            joueur2.add(convertCard(cardp2));
        }
        System.err.print("P1 ");
                for (Integer carte : joueur1) System.err.print(carte +" ");
                System.err.println("");
                System.err.print("P2 ");
                for (Integer carte : joueur2) System.err.print(carte+" ");
                System.err.println("");
        //for (Integer carte : joueur1) System.err.println(carte);
        //for (Integer carte : joueur2) System.err.println(carte);
        List<Integer> joueurTmp1 = new ArrayList<>();
        List<Integer> joueurTmp2 = new ArrayList<>();
        
        while(!isFini){
            if (!joueur1.isEmpty() && !joueur2.isEmpty()){
                if (!joueurTmp1.isEmpty()){
                    System.err.print("Tmp1 ");
                    for (Integer carte : joueurTmp1) System.err.print(carte +" ");
                    System.err.println("");
                    System.err.print("Tmp2 ");
                    for (Integer carte : joueurTmp2) System.err.print(carte+" ");
                    System.err.println("");
                }
                
                if( joueur1.get(0) < joueur2.get(0)) {
                    int carte1 = joueur1.get(0);
                    int carte2 = joueur2.get(0);
                    joueur1.remove(0);
                    joueur2.remove(0);
                    joueur2.add(carte1);
                    joueur2.add(carte2);
                    nbManche++;
                    //System.err.println("PP2");
                }else if( joueur1.get(0) > joueur2.get(0)) {
                    int carte1 = joueur1.get(0);
                    int carte2 = joueur2.get(0);
                    joueur1.remove(0);
                    joueur2.remove(0);
                    joueur1.add(carte1);
                    joueur1.add(carte2);
                    nbManche++;
                    //System.err.println("PP1");
                }else{
                    System.err.println("BATAILLE");
                    if(joueur1.size() < 4 || joueur2.size() < 4){
                         System.out.println("PAT");
                        return;
                    }
                    joueurTmp1.addAll(joueur1.subList(0,4));
                    joueurTmp2.addAll(joueur2.subList(0,4));
                    joueur1.remove(0);
                    joueur2.remove(0);
                    joueur1.remove(0);
                    joueur2.remove(0);
                    joueur1.remove(0);
                    joueur2.remove(0);
                    joueur1.remove(0);
                    joueur2.remove(0);
                    if (!joueur1.isEmpty() && !joueur2.isEmpty()){
                        if( joueur1.get(0) < joueur2.get(0)) {
                            int carte1 = joueur1.get(0);
                            int carte2 = joueur2.get(0);
                            joueur1.remove(0);
                            joueur2.remove(0);
                            joueur2.addAll(joueurTmp1);
                            joueur2.add(carte1);
                            joueur2.addAll(joueurTmp2);
                            joueur2.add(carte2);
                            System.err.println("BATAILLE P2");
                            nbManche++;
                            joueurTmp1.clear();
                            joueurTmp2.clear();
                        }else if( joueur1.get(0) > joueur2.get(0)) {
                            int carte1 = joueur1.get(0);
                            int carte2 = joueur2.get(0);
                            joueur1.remove(0);
                            joueur2.remove(0);
                            joueur1.addAll(joueurTmp1);
                            joueur1.add(carte1);
                            joueur1.addAll(joueurTmp2);
                            joueur1.add(carte2);
                            System.err.println("BATAILLE P1");
                            nbManche++;
                            joueurTmp1.clear();
                            joueurTmp2.clear();
                        }
                    }else{
                        System.out.println("PAT");
                        return;
                    }
                    
                    
                }
            }else{
                isFini = true;
                System.err.print("P1 ");
                for (Integer carte : joueur1) System.err.print(carte +" ");
                System.err.println("");
                System.err.print("P2 ");
                for (Integer carte : joueur2) System.err.print(carte+" ");
                System.err.println("");
            }
            
        }
        if (joueur1.isEmpty()) joueurWin = 2;
        if (joueur2.isEmpty()) joueurWin = 1;

        // Write an action using System.out.println()
        // To debug: System.err.println("Debug messages...");

        System.out.println(joueurWin +" "+ nbManche);
    }
    public static int convertCard(String carte){
        String carte1 = carte.substring(0,carte.length()-1);
        if("J".equalsIgnoreCase(carte1)){
            return 11;
        }
        if("Q".equalsIgnoreCase(carte1)){
            return 12;
        }
        if("K".equalsIgnoreCase(carte1)){
            return 13;
        }
        if("A".equalsIgnoreCase(carte1)){
            return 14;
        }
        return Integer.valueOf(carte1);
    }

}
