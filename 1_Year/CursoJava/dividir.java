import java.util.Scanner;

public class dividir {
    public static void main(String[] args) {
        float x=0, y=0;
        Scanner scanner = new Scanner(System.in);
        int i = scanner.nextInt();
        
        for(int r=0; r<i; r++)
        {
            x = scanner.nextInt();
            y = scanner.nextInt();

            if (y==0)
                System.out.printf("divisao impossivel\n");
            else
                System.out.printf("%.1f\n", (x/y));
        }
        scanner.close();
    }
}
