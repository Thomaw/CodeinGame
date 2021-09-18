import java.util.*;
import java.io.*;
import java.math.*;


class Player {

    public static void main(String args[]) {
        Scanner in = new Scanner(System.in);

        

        while (true) {
            int maxi = 0;
            int p = 0;
            
            for (int i = 0; i < 8; i++) {
                int mountainH = in.nextInt(); // represents the height of one mountain.
                maxi=Math.max(maxi,mountainH);
                
                if (maxi==mountainH) {
                    p=i;
                }
                
            }
            //System.out.println(tab);
            // Write an action using System.out.println()
            // To debug: System.err.println("Debug messages...");

            System.out.println(p); // The index of the mountain to fire on.
        }
    }
}
