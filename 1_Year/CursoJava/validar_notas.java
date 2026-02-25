import java.util.Scanner;

public class validar_notas {
    public static void main(String[] args) {
        double nota1, nota2;
        Scanner scanf = new Scanner(System.in);
        do {
            nota1 = scanf.nextDouble();
            if (nota1 < 0 || nota1 > 10)
                System.out.printf("nota invalida\n");
        } while (nota1 < 0 || nota1 > 10);
    
        do {
            nota2 = scanf.nextDouble();
            if (nota2 < 0 || nota2 > 10)
                System.out.printf("nota invalida\n");
        } while (nota2 < 0 || nota2 > 10);
            System.out.printf("media = %.2f\n", (nota1 + nota2) / 2.0);
        scanf.close();
    }
}
