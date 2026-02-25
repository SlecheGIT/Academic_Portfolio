import java.util.Scanner;

public class diagonal_secundaria {
    public static void main(String[] args) 
    {
        Scanner leitor = new Scanner(System.in);
        double[][] M = new double[12][12];
        char O = leitor.next().toUpperCase().charAt(0);
        double soma = 0;

        for (int i = 0; i < M.length; i++) {
        	for (int j = 0; j < M[i].length; j++) {
        		M[i][j] = leitor.nextDouble();
        	}
        }
        
        for (int i = 0; i < M.length; i++) {
        	for (int j = 0; j < M[i].length; j++) {
        		if (j > M.length-i-1) soma += M[i][j];
        	}
        }

        if (O == 'M') 
            soma /= ((M.length * M.length) - 12) / 2;

    	System.out.printf("%.1f\n", soma);
        leitor.close();
    }
}
