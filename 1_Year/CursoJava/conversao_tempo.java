import java.util.Scanner;

public class conversao_tempo {
    public static void main(String[] args) {
        int s, m, h;

        Scanner scanf = new Scanner(System.in);
        s = scanf.nextInt();
    
        m = s / 60;
        s = s % 60;
        h = m / 60;
        m = m % 60;
    
        System.out.printf("%d:%d:%d\n", h, m, s);
        scanf.close();
    }
}
