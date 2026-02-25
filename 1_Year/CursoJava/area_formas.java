import java.util.Scanner;

public class area_formas {
    public static void main(String[] args) {
        Scanner scanf = new Scanner(System.in);
        double a = scanf.nextDouble();
        double b = scanf.nextDouble();
        double c = scanf.nextDouble();
        double calc;
        scanf.close();

        calc = (a / 2) * c;
        System.out.printf("TRIANGULO: %.3f\n", calc);
    
        calc = (c * c) * 3.14159;
        System.out.printf("CIRCULO: %.3f\n", calc);
    
        calc = ((a+b) * c) / 2;
        System.out.printf("TRAPEZIO: %.3f\n", calc);
    
        calc = b*b;
        System.out.printf("QUADRADO: %.3f\n", calc);
    
        calc = a*b;
        System.out.printf("RETANGULO: %.3f\n", calc);
    }
}
