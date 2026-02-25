import java.util.Scanner;

public class quadrante {
    public static void main(String[] args) 
    {
        int y = 1;
        int x = 1;
        Scanner scanf = new Scanner(System.in);

        while (x!=0 && y!=0) {

        x = scanf.nextInt();
        y = scanf.nextInt();

        if (x>0 && y>0)
            System.out.println("primeiro");

        if (x>0 && y<0) 
            System.out.println("quarto");

        if (x<0 && y<0)
            System.out.println("terceiro");

        if (x<0 && y>0)
            System.out.println("segundo");
        
        }
        scanf.close();
    }
}
