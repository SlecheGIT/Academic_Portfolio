import java.util.Scanner;

public class numero_perfeito {
    public static void main(String[] args) {
        int n, ir, i=1, soma=0, r;
        Scanner scanf = new Scanner(System.in);
        r = scanf.nextInt();

        for (ir=1; ir<=r; ir++)
        {
            n = scanf.nextInt();
            while (i<n)
            {
                if (n%i==0)
                {
                    soma= soma+i;
                }
                i++;
            }
                if (soma==n)
                    {
                    System.out.printf("%d eh perfeito\n", n);
                    } else {
                    System.out.printf("%d nao eh perfeito\n", n);
                }
            i=1;
            soma=0;
            scanf.close();
        }
        
    }
}
