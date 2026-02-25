import java.util.Scanner;

public class selecao_vetor {
    public static void main(String[] args) {
        double[] a = new double[100];
        int  i;
        try (Scanner isso = new Scanner(System.in)) {
            for(i=0; i<100; i++)
                a[i] = isso.nextDouble();
        }

        for (i=0; i<100; i++)
        {
            if (a[i]<=10)
                System.out.printf("A[%d] = %.1f\n", i, a[i]);
        }
        
    }
}
