import java.util.Scanner;

public class impar_par_pos {
    public static void main(String[] args) {
        int i=0, r, n;
        Scanner scanner = new Scanner(System.in);
        r = scanner.nextInt();
    
        while (i<r)
        {
            n = scanner.nextInt();
    
            if (n==0)
                System.out.printf("NULL\n");
            else if (n%2==0 && n>0)
                System.out.printf("EVEN POSITIVE\n");
            else if (n%2==0 && n<0)
                System.out.printf("EVEN NEGATIVE\n");
            else if (n%2!=0 && n>0)
                System.out.printf("ODD POSITIVE\n");
            else if (n%2!=0 && n<0)
                System.out.printf("ODD NEGATIVE\n");
            i++;
        }
        scanner.close();
    }
}
