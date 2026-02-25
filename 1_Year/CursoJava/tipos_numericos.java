import java.util.Scanner;

public class tipos_numericos {
    public static void main(String[] args) 
    {
    int pos=0, neg=0, par=0, impar=0, i=0;
    Scanner scanf = new Scanner(System.in);

    while (i<5)
    {
    int n = scanf.nextInt();

    if (n>0)
        pos++;
    else if (n<0)
        neg++;

    if (n%2==0)
        par++;
    else if (n%2!=0)
        impar++;
    i++;
    }
    System.out.printf("%d valor(es) par(es)\n", par);
    System.out.printf("%d valor(es) impar(es)\n", impar);
    System.out.printf("%d valor(es) positivo(s)\n", pos);
    System.out.printf("%d valor(es) negativo(s)\n", neg);
    scanf.close();
    }
}
