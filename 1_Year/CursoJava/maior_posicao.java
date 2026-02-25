import java.util.Scanner;

public class maior_posicao {
    public static void main(String[] args)
    {
        int maior = 0, n=0, p=0;
        try (Scanner isso = new Scanner(System.in)) {
            for (int i = 0; i<100; i++) 
            {
                n = isso.nextInt();
                if (n>maior) {
                    maior=n;
                    p=i;
                }
            }
        }
        System.out.println(maior);
        System.out.println(p+1);
    }
}
