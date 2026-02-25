import java.util.Scanner;

public class media2 {
    public static void main(String[] args) 
    {
        Scanner s = new Scanner(System.in);
        double a = s.nextDouble()* 2;
        double b = s.nextDouble()* 3;
        double c = s.nextDouble() * 5;
        double media = (a+b+c) / 10;
        s.close();
        
        System.out.printf("MEDIA = %.1f\n", media);
    }
}
