import java.util.Scanner;

public class intervalo {
    public static void main(String[] args) 
    {
        Scanner scanf = new Scanner(System.in);
        double n = scanf.nextDouble();
        
        if (n>=0 && n<=25) 
            System.out.printf("Intervalo [0,25]\n");
        else if (n>=25 && n<=50) 
            System.out.printf("Intervalo (25,50]\n");
        else if (n>=50 && n<=75)
            System.out.printf("Intervalo (50,75]\n");
        else if (n>=75 && n<=100)
            System.out.printf("Intervalo (75,100]\n");
        else 
            System.out.printf("Fora de intervalo\n");
        scanf.close();
    }
}
