import java.util.Scanner;

public class seix_pares {
    public static void main(String[] args) {
        int i=0, pos=0;
        double n;
        Scanner scanner = new Scanner(System.in);

        while (i<6)
        {
            n=scanner.nextDouble();
            if (n>0)
                pos++;
            i++;
        }
        scanner.close();
        System.out.printf("%d valores positivos\n", pos);
    }
}
