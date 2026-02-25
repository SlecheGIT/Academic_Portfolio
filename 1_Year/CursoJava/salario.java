import java.util.Scanner;

public class salario {
    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        double s = scanner.nextInt();
        double h = scanner.nextDouble();
    
        System.out.printf("NUMBER = %d\n", n);
        System.out.printf("SALARY = U$ %.2f\n", (h*s));
        scanner.close();
    }
}
