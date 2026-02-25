import java.util.Scanner;

public class tipos_triangulos {
    public static void main(String[] args) {
        double a, b, c, a2, b2, c2;
        Scanner scanner = new Scanner(System.in);
        a = scanner.nextDouble();
        b = scanner.nextDouble();
        c = scanner.nextDouble();
        scanner.close();
        if (c>b) {
            a2 = b;
            b = c;
            c = a2;
        } if (b>a)
        {
            a2 = a;
            a = b;
            b = a2;
        } if (c>b) {
            a2 = b;
            b = c;
            c = a2;
        }
        a2=a*a;
        b2=b*b;
        c2=c*c;
    
        if (a>=(b+c)) {
            System.out.printf("NAO FORMA TRIANGULO\n");
            return;
        }
        if (a2==(b2+c2))
            System.out.printf("TRIANGULO RETANGULO\n");
        if (a2>(b2+c2))
            System.out.printf("TRIANGULO OBTUSANGULO\n");
        if (a2<(b2+c2))
            System.out.printf("TRIANGULO ACUTANGULO\n");
        if (a==b && b==c)
            System.out.printf("TRIANGULO EQUILATERO\n");
        else if (a==b || b==c || a==c)
            System.out.printf("TRIANGULO ISOSCELES\n");
    }
}
