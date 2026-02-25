import java.util.Scanner;

public class linha_matriz {
    public static void main(String[] args) 
    {
        Scanner leitor = new Scanner(System.in);
        int linha_matriz = leitor.nextInt();
        double soma = 0;
        char T = leitor.next().toUpperCase().charAt(0);
        double[][] matriz = new double[12][12];
        for (int i = 0; i < matriz.length; i++) {
        	for (int j = 0; j < matriz[i].length; j++) {
        		matriz[i][j] = leitor.nextDouble();
        	}
        }
        
    	for(int j = 0; j < matriz.length; j++) {
    		soma += matriz[linha_matriz][j];
    	}

        if (T == 'M') soma /= matriz.length;   
    	System.out.println(String.format("%.1f", soma));

        leitor.close();
    }
}
