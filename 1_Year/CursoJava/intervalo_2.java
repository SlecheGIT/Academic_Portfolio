import java.util.Scanner;

public class intervalo_2 {
    public static void main(String[] args) {
        int n, r, i=0, in=0, out=0;
        Scanner scanner = new Scanner(System.in);
        r = scanner.nextInt();

        while (i<r)
        {
            n = scanner.nextInt();
            if (n>=10 && n<=20)
                in++;
            else
                out++;
            i++;
        }
        scanner.close();
        System.out.printf("%d in\n", in);
        System.out.printf("%d out\n", out);
    }
}
