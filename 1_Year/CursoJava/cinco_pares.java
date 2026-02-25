import java.util.Scanner;

public class cinco_pares {
    public static void main(String[] args) {
        int n[] = new int[5], i=0, p=0;
        Scanner scanf = new Scanner(System.in);
        while (i<5)
        {
            n[i] = scanf.nextInt();
            if (n[i]%2==0)
                p++;
            
            i++;
        }
        scanf.close();
        System.out.printf("%d valores pares\n", p);
    
    }
}
