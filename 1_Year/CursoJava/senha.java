import java.util.Scanner;

public class senha {
    public static void main(String[] args) {
        int senha;
        Scanner scanf = new Scanner(System.in);
        do {
            senha = scanf.nextInt();
            if(senha==2002)
                System.out.printf("Acesso Permitido\n");
            else
                System.out.printf("Senha Invalida\n");
        } while (senha!=2002);
        scanf.close();
    }
}
