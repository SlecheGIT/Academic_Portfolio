import java.util.Scanner;

public class num_impar {
    public static void main(String[] args) 
    {
    Scanner scanner = new Scanner(System.in);
    int i=1, n = scanner.nextInt();
    scanner.close();
    while (i<=n)
    {
        if (i%2!=0)
            System.out.printf("%d\n", i);
        i++;
    }
    }
}
