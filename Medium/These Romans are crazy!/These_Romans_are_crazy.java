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
        String rom1 = in.next();
        String rom2 = in.next();
        int nb1=nombreArabe(rom1);
        int nb2=nombreArabe(rom2);
        System.err.println(nb1);
        System.err.println(nb2);
        int reslutatArabe = nb1+nb2;
        System.err.println(reslutatArabe);
        System.out.println(conversionArabeRomain(reslutatArabe));
    }
    
    public static int nombreArabe(String romain){
        int longueur = romain.length();
        int tabChiffre[] = new int[longueur];
        int reslutat =0;
        for(int i=0;i<longueur;i++){
            tabChiffre[i] = conversionRomainArabe(romain.charAt(i));            
        }
        reslutat += tabChiffre[0];
        for(int i=1;i<longueur;i++){
            //System.err.println(tabChiffre[i]);
            if(tabChiffre[i] <= tabChiffre[i-1]){
                reslutat += tabChiffre[i];
                //System.err.println("plus");
            }else {
                reslutat += tabChiffre[i] - 2*tabChiffre[i-1];
                 //System.err.println("moins");
            }
        }
        return reslutat;
    }
    
    public static int conversionRomainArabe(char romain){
        switch(romain){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;
    }
    public static String conversionArabeRomain(int arabe){
        String resultat ="";
        int reste=arabe;
        int multiple = reste/1000;
        if( multiple != 0){
            reste -= multiple*1000;
            for(int i =0;i<multiple;i++){
                resultat+="M";
            }
        }
        multiple = reste/100;
        while( multiple != 0){
           if(multiple == 9){
                reste -= 900;
                resultat+="CM";
                 multiple = reste/100;
                 continue;
            }
            if(multiple >= 5){
                reste -= 500;
                resultat+="D";
                 multiple = reste/100;
                 continue;
            }
            if(multiple == 4){
                reste -= 400;
                resultat+="CD";
                 multiple = reste/100;
                 continue;
            }
            if(multiple < 4){
                reste -= 100;
                resultat+="C";
                 multiple = reste/100;
                 continue;
            }
           
        }
        System.err.println("multiple 10");
        multiple = reste/10;
        while( multiple != 0){
           if(multiple == 9){
                reste -= 90;
                resultat+="XC";
                multiple = reste/10;
            continue;
            }
            if(multiple >= 5){
                reste -= 50;
                resultat+="L";
                multiple = reste/10;
            continue;
            }
            if(multiple == 4){
                reste -= 40;
                resultat+="XL";
                multiple = reste/10;
            continue;
            }
            if(multiple < 4){
                reste -= 10;
                resultat+="X";
                multiple = reste/10;
            continue;
            }
            
        }
        System.err.println(reste);
        while( reste != 0){
           if(reste == 9){
                reste -= 9;
                resultat+="IX";
                continue;
            }
            if(reste >= 5){
                reste -= 5;
                resultat+="V";
                continue;
            }
            if(reste == 4){
                reste -= 4;
                resultat+="IV";
                continue;
            }
            if(reste < 4){
                reste -= 1;
                resultat+="I";
                continue;
            }
        }
        
        System.err.println(resultat);
        
        return resultat;
    }
}
