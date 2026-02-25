import java.util.Scanner;

public class batalha_pokemons {
    public static void main(String[] args) {
        int tst, Dab, Gab, a1, a2, d1, d2, l1, l2, bns;
        Scanner scanf = new Scanner(System.in);
        tst = scanf.nextInt();

        while(tst>0)
        {
            bns = scanf.nextInt();

            a1 = scanf.nextInt(); d1 = scanf.nextInt(); l1 = scanf.nextInt();
            a2 = scanf.nextInt(); d2 = scanf.nextInt(); l2 = scanf.nextInt();
            Dab = (a1+d1)/2;

            if(l1%2==0) Dab += bns;

            Gab = (a2+d2)/2;

            if(l2%2==0) Gab += bns;
            if(Dab == Gab) 
                System.out.printf("Empate\n");
            else 
                System.out.printf((Dab > Gab)? "Dabriel\n" : "Guarte\n");
            tst--;
        }
        scanf.close();
    }
}
