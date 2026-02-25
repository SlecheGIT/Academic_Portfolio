import java.util.Scanner;

public class cara_coroa {
    public static void main(String[] args) {
    int i=1, t=0, cc=0, maria=0, jao=0;
    Scanner scanf = new Scanner(System.in);

    while (i!=0)
    {
        i = scanf.nextInt();
        t=i;
        while (t>0)
        {
            cc = scanf.nextInt();
            if (cc==0)
                maria++;
            else  
                jao++;
            t--;
        }
        if (i!=0){
            System.out.println("Mary won "+maria+" times and John won "+jao+" times");
            maria=0;
            jao=0;
        }
    }
    scanf.close();
    }
}
