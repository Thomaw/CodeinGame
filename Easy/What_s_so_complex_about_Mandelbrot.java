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
        String c = in.nextLine();   // Nombre de départ
        int m = in.nextInt();       // Nombre d'itération 

        //System.out.println(c);
        //System.out.println(m);
        String z = c;
        
        int isExists_c = z.indexOf("+");
        
        if (isExists_c==-1){
            isExists_c = z.indexOf("-",1);
            }
            
        String real_c = c.substring(0, isExists_c);
        String imag_c = c.substring(isExists_c, c.length()-1);

        Double real2_c = Double.parseDouble(real_c);  
        Double imag2_c = Double.parseDouble(imag_c); 
        
        int i;

        for (i=1; i<m;i++) {
        
            int isExists = z.indexOf("+");
            

            if (isExists==-1){
                isExists = z.indexOf("-",1);
            }
            //System.out.println(isExists);

            String real = z.substring(0, isExists);
            String imag = z.substring(isExists, z.length()-1);
            /*
            System.out.print("real:");
            System.out.println(real);
            System.out.print("imag:");
            System.out.println(imag);
            */

            Double real2=Double.parseDouble(real);  
            Double imag2=Double.parseDouble(imag); 
            //System.out.println(real2);
            //System.out.println(imag2);

            Double modu = Math.sqrt(Math.pow(real2, 2) + Math.pow(imag2, 2));
            //System.out.print("module = "); System.out.println(modu);

            if (modu>2){
                break;
            }
            else{
                // Elever au carré le nombre et ajouter c
                // (a + ib)^2 = a^2 – b^2 + 2 i*a*b
                Double a2_b2 = Math.pow(real2, 2)-Math.pow(imag2, 2);
                Double ab = 2*real2*imag2;

                Double z1 = a2_b2 + real2_c;
                Double z2 = ab+imag2_c;

                String q = Double.toString(a2_b2)+Double.toString(ab)+"i";
                //System.out.println(q);
                String p ="";

                if (z2<0) {
                   p = Double.toString(z1)+Double.toString(z2)+"i";
                }
                else {
                   p = Double.toString(z1)+"+"+Double.toString(z2)+"i";
                }
                //System.out.print("p = "); System.out.println(p);

                z = p;
                //System.out.println("");

            }
        }


        if (i+1 == m){
            System.out.println(m);
        }
        else {
            System.out.println(i);
        }


    }
}
