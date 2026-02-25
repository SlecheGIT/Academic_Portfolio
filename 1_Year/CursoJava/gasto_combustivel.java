import java.util.Scanner;

public class gasto_combustivel {
    public static void main(String[] args) 
    {
        Scanner scanf = new Scanner(System.in);
        int tempo = scanf.nextInt();
        int vm = scanf.nextInt();
        double media = 12;

        media = (tempo*vm)/media;

        System.out.printf("%.3f\n", media);
        scanf.close();
    }
}
