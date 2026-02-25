import java.util.Scanner;

public class reajuste_salario {
    public static void main(String[] args) 
    {
    Scanner scanner = new Scanner(System.in);
    double sal = scanner.nextDouble();
    scanner.close();

    if ((sal >= 0) && (sal <= 400)) {
        System.out.printf("Novo salario: %.2f\n", (sal + (sal * 0.15)));
        System.out.printf("Reajuste ganho: %.2f\n", (sal * 0.15));
        System.out.printf("Em percentual: 15 %%\n");
    }
    else if ((sal > 400) && (sal <= 800)) {
        System.out.printf("Novo salario: %.2f\n", (sal + (sal * 0.12)));
        System.out.printf("Reajuste ganho: %.2f\n", (sal * 0.12));
        System.out.printf("Em percentual: 12 %%\n");
        }
    else if ((sal > 800) && (sal <= 1200)) {
        System.out.printf("Novo salario: %.2f\n", (sal + (sal * 0.10)));
        System.out.printf("Reajuste ganho: %.2f\n", (sal * 0.10));
        System.out.printf("Em percentual: 10 %%\n");
        }
    else if ((sal > 1200) && (sal <= 2000)) {
        System.out.printf("Novo salario: %.2f\n", (sal + (sal * 0.07)));
        System.out.printf("Reajuste ganho: %.2f\n", (sal * 0.07));
        System.out.printf("Em percentual: 7 %%\n");
        }
    else if (sal > 2000) {
        System.out.printf("Novo salario: %.2f\n", (sal + (sal * 0.04)));
        System.out.printf("Reajuste ganho: %.2f\n", (sal * 0.04));
        System.out.printf("Em percentual: 4 %%\n");
        }
    }
}
