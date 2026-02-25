import java.util.Scanner;

public class resto2 {
    public static void main(String[] args) {
        int n, i=1;
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        scanner.close();

        while (i<10000)
        {   
            if (i%n==2)
                System.out.printf("%d\n", i);
        
            i++;
        }
    }
}
