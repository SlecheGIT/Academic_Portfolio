import java.util.Scanner;

public class teste_selecao {
    public static void main(String[] args) {

        Scanner scanf = new Scanner(System.in);
        int a = scanf.nextInt();
        int b = scanf.nextInt();
        int c = scanf.nextInt();
        int d = scanf.nextInt();

        if (b>c)
        {
            if (d>a)
            {
                if ((c+d)>(a+b))
                {
                    if (c>0 && d>0)
                    {
                        if (a%2==0)
                        {
                            System.out.println("Valores aceitos");
                        } else {
                            System.out.println("Valores nao aceitos");
                        }  
                    }else {
                        System.out.println("Valores nao aceitos");
                    }
                    
                }else {
                    System.out.println("Valores nao aceitos");
                }
                
            }else {
                System.out.println("Valores nao aceitos");
            }
            
        }else {
            System.out.println("Valores nao aceitos");
        }
        scanf.close();
    }
}
