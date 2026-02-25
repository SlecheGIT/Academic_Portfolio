import java.util.Scanner;

public class area_circulo {
    public static void main(String[] args) 
    {
        Scanner s = new Scanner(System.in);
        double raio = s.nextDouble();
        double n = 3.14159 * (raio * raio);
        s.close();

        System.out.printf("A=%.4f\n", n);
    }
}
