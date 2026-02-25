import java.util.Scanner;

public class lanche {
    public static void main(String[] args) {
    double quant, n;
    Scanner scanner = new Scanner(System.in);
    n = scanner.nextFloat();
    quant = scanner.nextDouble();
    scanner.close();

    if (n==1)
        n=4*quant;
    else if (n==2)
        n=4.5*quant;
    else if (n==3)
        n=5*quant;
    else if (n==4)
        n=2*quant;
    else if (n==5)
        n=1.5*quant;

    System.out.printf("Total: R$ %.2f\n", n);

    }
}
