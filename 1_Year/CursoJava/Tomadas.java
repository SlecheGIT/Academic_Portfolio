import java.util.Scanner;

public class Tomadas {
    
    public static void main(String[] args) {
        Scanner tomadas = new Scanner(System.in);
        int a = tomadas.nextInt()-1;
        int b = tomadas.nextInt()-1;
        int c = tomadas.nextInt()-1;
        int d = tomadas.nextInt();

        int soma = a+b+c+d;

        System.out.println(soma);
        tomadas.close();
    }
}
