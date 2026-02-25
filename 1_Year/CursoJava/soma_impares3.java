import java.util.Scanner;

public class soma_impares3 {
    public static void main(String[] args) {
        int r, i=0, s, f, media=0, aux=0;
        Scanner scanf = new Scanner(System.in);
        r = scanf.nextInt();
        while (i<r)
        {
            s = scanf.nextInt();
            f = scanf.nextInt();
            if (s>f) 
            {
                aux=s;
                s=f;
                f=aux;
            }
            s++;
            while (s<f)
            {
                if (s%2!=0)
                    media+=s;
                s++;
            }
            System.out.printf("%d\n", media);
            media=0;
            i++;
        }
        scanf.close();
    }
}
