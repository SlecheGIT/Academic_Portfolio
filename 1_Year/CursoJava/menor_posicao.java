import java.util.Scanner;

public class menor_posicao {
    public static void main(String[] args) 
    {
        int menor_posicao = 1000, n=0, p=0, r;
        
        try (Scanner isso = new Scanner(System.in)) {
            r = isso.nextInt();
            for (int i = 0; i<r; i++) 
            {
                n = isso.nextInt();
                if (n<menor_posicao) {
                    menor_posicao=n;
                    p=i;
                }
            }
        }
        System.out.println("Menor valor: "+menor_posicao);
        System.out.println("Posicao: "+p);
    }
}
