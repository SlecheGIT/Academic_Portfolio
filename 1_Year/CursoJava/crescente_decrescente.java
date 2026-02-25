import java.util.Scanner;

public class crescente_decrescente {
    public static void main(String[] args) {
        int x=0, y=1;
        Scanner scanf = new Scanner(System.in);
        while (x!=y)
        {
        x = scanf.nextInt();
        y = scanf.nextInt();

        if (x==y) 
            x=y;
        else if (x>y)
            System.out.printf("Decrescente\n");
        else
            System.out.printf("Crescente\n");
        }
        scanf.close();
    }
}
