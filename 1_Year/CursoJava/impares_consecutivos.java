import java.util.Scanner;

public class impares_consecutivos {
    public static void main(String[] args) {
        int soma=0;

        Scanner scanf = new Scanner(System.in);
        int x = scanf.nextInt();
        int y = scanf.nextInt();
    
        if (y>x)
        {
            soma=x;
            x=y;
            y=soma;
            soma=0;
        }
        y++;
            while (y!=x)
            {
                if (y%2 != 0)
                {
                    soma= soma+y;
                }
                y++;
            }
          System.out.println(soma);
        scanf.close();
    }
}
