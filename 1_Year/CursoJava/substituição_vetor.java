import java.util.Scanner;

public class substituição_vetor {
    public static void main(String[] args) 
    {
        int[] x = new int[10];
        int i=0;
        Scanner vet = new Scanner(System.in);

        while (i<10)
        {
            x[i] = vet.nextInt();
            if (x[i]<=0)
            {
                x[i]=1;
            }
    
            System.out.printf("X[%d] = %d\n", i, x[i]);
            i++;
        }
        vet.close();
    }
}
