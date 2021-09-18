import java.util.*;

class Solution {

    public static void main(final String args[]) {
        final Scanner in = new Scanner(System.in);
        final int n = in.nextInt(); // the number of temperatures to analyse
        
        int mini = 1000000;
        boolean min_plus = false;
        final Vector<Integer> number = new Vector<Integer>(n); 


        if (n != 0){
        for (int i = 0; i < n; i++) {
            final int t = in.nextInt();
            number.add(t);
            mini = Math.min(mini,Math.abs(t));
        }

        for (int i = 0; i < n; i++) {
            final int t = number.get(i);

            if (t == mini){
                min_plus = !min_plus;
                break;
            }
        }

       
        if (min_plus) {System.out.println(mini);}
        else {System.out.println(-mini);}
        }
        
        else { System.out.println("0"); } 
    }
}
