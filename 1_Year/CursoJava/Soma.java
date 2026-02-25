import java.util.Scanner;

public class Soma {
    
    public static void main(String[] args) 
    {
        Scanner entrada = new Scanner(System.in);
        int x= entrada.nextInt();
        int y= entrada.nextInt();

        System.out.println("X = "+(x+y));
        entrada.close();
    }
}
