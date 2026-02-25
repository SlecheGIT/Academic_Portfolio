import java.util.Scanner;

public class medias_ponderadas {
    public static void main(String[] args) {
        int i;
        float n1, n2, n3;
        Scanner scanner = new Scanner(System.in);
        i = scanner.nextInt();
        
        for (int r=0; r<i; r++){
            n1 = scanner.nextFloat();
            n2 = scanner.nextFloat();
            n3 = scanner.nextFloat();
            System.out.printf("%.1f\n", (n1*0.2)+(n2*0.3)+(n3*0.5));
        }
        scanner.close();
    }
}
