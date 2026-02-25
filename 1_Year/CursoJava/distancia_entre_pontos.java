import java.util.Scanner;

public class distancia_entre_pontos {
    public static void main(String[] args) {
        float x1, x2, y1, y2, x, y, resul;
        Scanner scanner = new Scanner(System.in);
        x1 = scanner.nextFloat();
        y1 = scanner.nextFloat();
        x2 = scanner.nextFloat();
        y2 = scanner.nextFloat();
        scanner.close();

        x = (x2 - x1) * (x2 - x1);
        y = (y2 - y1) * (y2 - y1);
        resul = x + y;

        System.out.printf("%.4f\n", Math.sqrt(resul));
    }
}
