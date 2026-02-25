import java.util.Scanner;

public class media1 {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        double a = s.nextDouble()* 3.5;
        double b = s.nextDouble()*7.5;
        double media = (a+b) / 11;
        s.close();
        
        System.out.printf("MEDIA = %.5f\n", media);
    }
}
