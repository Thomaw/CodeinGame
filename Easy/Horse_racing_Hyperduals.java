import java.util.*;
class Solution {
    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);
        int N = in.nextInt();
        
        Vector<Integer> vitesse = new Vector<Integer>(N);
        Vector<Integer> elegance = new Vector<Integer>(N);

        for (int i = 0; i < N; i++) {
            int V = in.nextInt();
            vitesse.add(V);
            int E = in.nextInt();
            elegance.add(E);
        }

        int maxi=99999999;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i!=j){
                    maxi = Math.min(Math.abs(vitesse.get(i)-vitesse.get(j)) + Math.abs(elegance.get(i)-elegance.get(j)),maxi);
                }
            }
        }
        System.out.println(maxi);
    }
}
