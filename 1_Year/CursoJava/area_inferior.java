import java.util.Scanner;

public class area_inferior {
    public static void main(String[] args) 
    {
        Scanner scanf = new Scanner(System.in);
        double s = 0;
        char O = scanf.next().toUpperCase().charAt(0);
        double[][] M = new double[12][12];

        for (int i = 0; i < M.length; i++) {
        	for (int j = 0; j < M[i].length; j++) {
        		M[i][j] = scanf.nextDouble();
        	}
        }
        
        for (int i = 0; i < M.length; i++) {
        	for (int j = 0; j < M[i].length; j++) {
        		if (j < i && j > M.length-i-1) s += M[i][j];
        	}
        }

        if (O == 'M') s /= 30;
    	System.out.println(String.format("%.1f", s));
        scanf.close();
    }
}
