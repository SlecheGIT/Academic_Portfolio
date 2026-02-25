import java.util.Scanner;

public class bob_conduinte {
    public static void main(String[] args) {
        int n, n2, i, r;

        Scanner verificar = new Scanner(System.in);
        r = verificar.nextInt();
        for (i=0; i<r; i++)
        {
            n = verificar.nextInt();
            n2 = verificar.nextInt();
            System.out.printf("%d\n", n+n2);
        verificar.close();

        }
    }
}
