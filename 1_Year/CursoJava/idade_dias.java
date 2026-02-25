import java.util.Scanner;

public class idade_dias {
    public static void main(String[] args) 
    {
        int anos, messes, dias, n;
        Scanner porre = new Scanner(System.in);
        n = porre.nextInt();
        porre.close();
        
        anos=n/365;
        messes=(n%365)/30;
        dias=(n%365)%30;
    
        System.out.printf("%d ano(s)\n", anos);
        System.out.printf("%d mes(es)\n", messes);
        System.out.printf("%d dia(s)\n", dias);
    }
}
