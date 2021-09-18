import java.util.*;
import java.io.*;
import java.math.*;
import java.util.Vector;

class Solution {

    public static void main(String args[]) {

        Vector v = new Vector();
        boolean result = true;

        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        if (in.hasNextLine()) {
            in.nextLine();
        }

        for (int i = 0; i < n; i++) {
            String row = in.nextLine();
            int p0 = v.indexOf(row.charAt(0));
            int p1 = v.indexOf(row.charAt(4));

            if (p0 == -1){v.add(row.charAt(0));}
            if (p1 == -1){v.add(row.charAt(4));}

            if (p0 != -1 & p1 != -1){
                if (p0>p1){
                    result = false;
                    break;
                }
            }
        }

        if (!result) {System.out.println("contradiction");}
        else{System.out.println("consistent");}
    }
}
