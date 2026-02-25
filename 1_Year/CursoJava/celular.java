import java.util.Scanner;

public class celular {
    public static void main(String[] args) 
    {
        int[] notas = new int[7];
        Scanner scanf = new Scanner(System.in);
        int n = scanf.nextInt();
        int copia = n;
        scanf.close();
        
        notas[0] = n / 100;
        n = n % 100;
        notas[1] = n / 50;
        n = n % 50;
        notas[2] = n / 20;
        n = n % 20;
        notas[3] = n / 10;
        n = n % 10;
        notas[4] = n / 5;
        n = n % 5;
        notas[5] = n / 2;
        n = n % 2;
        notas[6] = n / 1;
        n = n % 1;

        System.out.println(copia);
        System.out.printf("%d nota(s) de R$ 100,00\n", notas[0]);
        System.out.printf("%d nota(s) de R$ 50,00\n", notas[1]);
        System.out.printf("%d nota(s) de R$ 20,00\n", notas[2]);
        System.out.printf("%d nota(s) de R$ 10,00\n", notas[3]);
        System.out.printf("%d nota(s) de R$ 5,00\n", notas[4]);
        System.out.printf("%d nota(s) de R$ 2,00\n", notas[5]);
        System.out.printf("%d nota(s) de R$ 1,00\n", notas[6]);

    }
}
