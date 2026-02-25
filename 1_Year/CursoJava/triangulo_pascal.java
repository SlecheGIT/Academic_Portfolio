import java.util.Scanner;

public class triangulo_pascal {
    public static void main(String[] args) {
        double  n, s;
        Scanner scanf = new Scanner(System.in);
        int t = scanf.nextInt();
        
        while (t!=0) {
            n = scanf.nextInt();
            s= Math.pow(2, n) -1;
            System.out.printf("%.0f\n", s);   
            s=2;
            t--;
        }
        scanf.close();
    }
}
