import java.util.Scanner;

public class eh_maior {
    public static void main(String[] args) 
    {
        Scanner n = new Scanner(System.in);
        int x = n.nextInt();
        int y = n.nextInt();
        int z = n.nextInt();
        int maior=x;
        n.close();
        
        if (y>maior)
            maior=y;
        if (z>maior)
            maior=z;

        System.out.println(maior+" eh o maior");
    }
}
