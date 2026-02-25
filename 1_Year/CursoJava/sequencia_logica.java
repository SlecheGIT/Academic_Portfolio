import java.util.Scanner;

public class sequencia_logica {
    
    public static void main(String[] args)
    {
        var x = 1;
        Scanner scanner = new Scanner(System.in);
        int i = scanner.nextInt();
        
        while (x<=i){
            System.out.println(x+" "+(x*x)+" "+(x*x*x));
            System.out.println(x+" "+((x*x)+1)+" "+((x*x*x)+1));
            x++;
        }
        scanner.close();
    }
}
