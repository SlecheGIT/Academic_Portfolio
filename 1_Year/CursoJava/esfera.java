import java.util.Scanner;

public class esfera {
    public static void main(String[] args) 
    {
        Scanner scanf = new Scanner(System.in);
        int r = scanf.nextInt();
        scanf.close();
        System.out.printf("VOLUME = %.3f\n", (4.0/3) * 3.14159 * Math.pow(r, 3));
 
    }
}
