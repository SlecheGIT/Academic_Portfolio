import java.util.Scanner;

public class escolha_dificil {
    public static void main(String[] args) {
        int[] r = new int[4], p = new int[4];
        int f = 0, i;

        Scanner scanf = new Scanner(System.in);
        r[1] = scanf.nextInt();
        r[2] = scanf.nextInt();
        r[3] = scanf.nextInt();

        p[1] = scanf.nextInt();
        p[2] = scanf.nextInt();
        p[3] = scanf.nextInt(); 
        scanf.close();

        for (i = 1; i <= 3; i++) {

            if (r[i] < p[i])
                f = (p[i] - r[i]) + f;
        }

        System.out.printf("%d\n", f);
    }
}
