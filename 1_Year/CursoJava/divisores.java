import java.util.Scanner;

public class divisores {
    public static void main(String[] args) 
    {
        Scanner scanf = new Scanner(System.in);
        int div = scanf.nextInt();

        for (int i=1; i<=div; i++){
            if (div%i==0)
                System.out.println(i);
        }
        scanf.close();
    }
}
