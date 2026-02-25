import java.util.Scanner;

public class cobaias {
    public static void main(String[] args) {
            float cob, ratos = 0, coelhos = 0, sapos = 0; 
            int r;
            char c;
            Scanner scanner = new Scanner(System.in);
            r = scanner.nextInt();

            for (int i = 0; i < r; i++)
            {
                cob = scanner.nextFloat();
                c = scanner.next().charAt(0);

                if (c == 'C')
                    coelhos += cob;
                else if (c == 'R')
                    ratos += cob;
                else if (c == 'S')
                    sapos += cob;
            }
            scanner.close();
            cob = sapos + ratos + coelhos;
            System.out.printf("Total: %.0f cobaias\n", cob);
            System.out.printf("Total de coelhos: %.0f\n", coelhos);
            System.out.printf("Total de ratos: %.0f\n", ratos);
            System.out.printf("Total de sapos: %.0f\n", sapos);
            System.out.printf("Percentual de coelhos: %.2f %%\n", (coelhos/cob)*100);
            System.out.printf("Percentual de ratos: %.2f %%\n", (ratos/cob)*100);
            System.out.printf("Percentual de sapos: %.2f %%\n", (sapos/cob)*100);
        
    }
}
