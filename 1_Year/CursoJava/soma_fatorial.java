import java.util.Scanner;

public class soma_fatorial {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long f1, f2, conta= 1; 
        int i=1;
        
        while (sc.hasNext()) {
            
            f1 = sc.nextInt();
            f2 = sc.nextInt(); 
            while (i<=f1){
                conta*=i;
                i++;
            }
            f1=conta;
            conta=1;
            i=1;
    
            while (i<=f2){
                conta*=i;
                i++;
            }
            f2=conta;
            conta=1;
            i=1;
            System.out.println(f1+f2);
        }
        sc.close();
    }
}
