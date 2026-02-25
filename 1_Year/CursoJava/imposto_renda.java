import java.util.Scanner;

public class imposto_renda {
    public static void main(String[] args) 
    {
        float oito, dezoito, vinte;

        Scanner scanf = new Scanner(System.in);
        float sa = scanf.nextFloat();
        
        if (sa<=2000){
            System.out.printf("Isento\n");
        } 
        if (sa>=2000.01 && sa<=3000)
        {
            sa= sa-2000;
            oito= (sa/100) * 8;
            System.out.printf("R$ %.2f\n", oito);  
        }
        if (sa>=3000.01 && sa<=4500)
        {
            sa= sa-2000;
            dezoito= sa-1000;
            oito= sa-dezoito;
            oito= (oito/100) * 8;
            dezoito= (dezoito/100) * 18;
            System.out.printf("R$ %.2f\n", dezoito+oito);
        }
        if (sa>=4500.01)
        {
    
           oito= (1000/100) * 8;
           dezoito= (1500/100) * 18;
           sa= (sa-4500);
           vinte= (sa/100) * 28;
           System.out.printf("R$ %.2f\n", vinte+dezoito+oito);
        }
        scanf.close();
    }
}
