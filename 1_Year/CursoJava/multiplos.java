import java.util.Scanner;

public class multiplos {
    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in);
        int a, b;
        a = scanner.nextInt();
        b = scanner.nextInt();
        scanner.close();
        if (b % a == 0 || a % b == 0)
            System.out.printf("Sao Multiplos\n");
        else
            System.out.printf("Nao sao Multiplos\n");
    }
}
