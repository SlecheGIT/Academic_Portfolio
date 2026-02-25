import java.util.Scanner;

public class bhaskara {
    public static void main(String[] args) {
        Scanner scanf = new Scanner(System.in);
        double a = scanf.nextDouble();
        double b = scanf.nextDouble();
        double c = scanf.nextDouble();
        scanf.close();
        double delta = (b * b) - 4 * a * c;

        if (delta > 0 && a != 0) {
            delta = (-b + Math.sqrt(delta)) / (2 * a);
            System.out.printf("R1 = %.5f\n", delta);

            delta = (b * b) - 4 * a * c;
            delta = (-b - Math.sqrt(delta)) / (2 * a);
            System.out.printf("R2 = %.5f\n", delta);
        } else
            System.out.printf("Impossivel calcular\n");
    }
}
