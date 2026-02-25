import java.util.Scanner;

public class sequencia_soma {
    public static void main(String[] args) {
        int s=1, f=1, media=0, aux;
        while (s>0 || f>0)
        {
            Scanner scanf = new Scanner(System.in);
            s = scanf.nextInt();
            f = scanf.nextInt();
            scanf.close();
            if (s>0 && f>0)
            {
                if (s>f) 
                {
                    aux=s;
                    s=f;
                    f=aux;
                }
                while (s<=f)
                {
                    System.out.printf("%d ", s);
                    media+=s;
                    s++;
                }
                System.out.printf("Sum=%d\n", media);
                media=0;
            }
            else 
                return;
        }
    }
}
