import java.util.Scanner;

public class produto_simples {
    public static void main(String[] args) 
    {
        Scanner yes = new Scanner(System.in);
        int x = yes.nextInt();
        int y = yes.nextInt();
        System.out.println("PROD = "+(x*y));
        yes.close();
    }
}
