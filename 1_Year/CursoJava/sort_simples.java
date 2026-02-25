import java.util.Scanner;

public class sort_simples {
    public static void main(String[] args) {
        int a, b, c, aux;
        int x, y, z;
        Scanner l = new Scanner(System.in);
        a = l.nextInt();
        b = l.nextInt();
        c = l.nextInt();
        l.close();
        x=a;
        y=b;
        z=c;
        
        if (c < b) {
            aux = b;
            b = c;
            c = aux;
        }
    
        if (b < a) {
            aux = a;
            a = b;
            b = aux;
        }
        
         if (c < b) {
            aux = b;
            b = c;
            c = aux;
        }
    
        System.out.printf("%d\n%d\n%d\n\n%d\n%d\n%d\n",a,b,c,x,y,z);
    
    }
}
