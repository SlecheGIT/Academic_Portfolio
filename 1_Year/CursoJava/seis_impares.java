import java.util.Scanner;

public class seis_impares {
    public static void main(String[] args) {

    int n, i=0;
    Scanner scanner = new Scanner(System.in);
    n = scanner.nextInt();
        scanner.close();
    while (i<6)
    {
        if (n%2!=0)
        {
            System.out.printf("%d\n", n);
            i++;
        }
        n++;
    }
    }
}

