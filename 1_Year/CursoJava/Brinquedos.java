import java.util.Scanner;

public class Brinquedos {
    public static void main(String[] args) 
    {
        Scanner scanf = new Scanner(System.in);
        int i = scanf.nextInt(), m = 0, f = 0;
        char s;

        while (i!=0){
            scanf.next();
            s = scanf.next().charAt(0);

            if (s=='F') 
                f++;

            if (s=='M')
                m++;

            i--;
        }    
        System.out.println(m+" carrinhos");
        System.out.println(f+" bonecas");
        scanf.close();
    }
}
