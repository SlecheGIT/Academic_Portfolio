import java.util.Scanner;

public class aproveite_oferta {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int i = sc.nextInt();
        int soma;

        while (i>0){
            int n = sc.nextInt();
            int k = sc.nextInt();
            soma = (n/k) + (n%k);
            System.out.println(soma);
            i--;
        }
        sc.close();
    }
}
