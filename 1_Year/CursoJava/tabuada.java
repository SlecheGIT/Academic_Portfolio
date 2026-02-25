import java.util.Scanner;

public class tabuada {
    public static void main(String[] args) {
        int n, i=1;
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        scanner.close();

        for (i=1; i<=10; i++){
            System.out.printf("%d x %d = %d\n", i, n, (i*n));
        }
    }
}
