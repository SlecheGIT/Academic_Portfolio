import java.util.Scanner;

public class quadrado_pares {
    public static void main(String[] args) {
        int i=1, r;
        Scanner scanner = new Scanner(System.in);
        r = scanner.nextInt();
        scanner.close();

        while (i<=r)
        {
            if (i%2==0)
                System.out.printf("%d^2 = %d\n", i, (i*i));
            i++;
        }
        
    }
}
