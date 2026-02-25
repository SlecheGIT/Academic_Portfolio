import java.util.Scanner;

public class fliper {
    public static void main(String[] args) 
    {
        Scanner scanf = new Scanner(System.in);
        int x = scanf.nextInt();
        int y = scanf.nextInt();

        if (x==0)
            System.out.println("C");

        if (x==1 && y==0) 
            System.out.println("B");

        if (x==1 && y==1)
            System.out.println("A");
        scanf.close();
    }    
}
