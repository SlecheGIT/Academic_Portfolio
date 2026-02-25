import java.util.Scanner;

public class Iccanobif {
    public static void main(String[] args) 
    {
        int ant = 0, atu = 1, dep, i, r;
        int [] resul = new int[40];
        Scanner scanf = new Scanner(System.in);
        r = scanf.nextInt();
        scanf.close();
        for (i = 0; i < r; i++)
        {
            resul[i] = atu;
            dep = ant + atu;
            ant = atu;
            atu = dep;
        }
        r--;
        for (i = 0; i < r; r--)
        {
            System.out.printf("%d ", resul[r]);
        }
        System.out.printf("%d\n", resul[0]);
    }
}
