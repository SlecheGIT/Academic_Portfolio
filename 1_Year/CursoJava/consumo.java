import java.util.Scanner;

public class consumo {
    public static void main(String[] args) {
        Scanner scanf = new Scanner(System.in);
        float distancia = scanf.nextFloat();
        float consumo = scanf.nextFloat();
        scanf.close();
        System.out.printf("%.3f km/l\n", distancia/consumo);
    }
}
