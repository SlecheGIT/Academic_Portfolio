import java.util.Scanner;

public class posit_media {
    public static void main(String[] args) 
    {
    int i=0;
    float n, media=0, cont=0;
    Scanner scanf = new Scanner(System.in);
    while (i<6)
    {
        n = scanf.nextFloat();
        if (n>0)
        {
            cont++;
            media+=n;
        }
        i++;
    }
    System.out.printf("%.0f valores positivos\n", cont);
    System.out.printf("%.1f\n", media/cont);
    scanf.close();
    }
}
