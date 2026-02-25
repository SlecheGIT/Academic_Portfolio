import java.util.Scanner;

public class fibonacci_vetor {
    public static void main(String[] args) 
    {
		Scanner s = new Scanner(System.in);

		long[] fib = new long[61];
		int t, f;

		fib[0] = 0;
		fib[1] = 1;
		for (int i = 2; i <= 60; i++)
			fib[i] = fib[i-1] + fib[i-2];

		t = s.nextInt();
		while (t>0){
			f = s.nextInt();
			System.out.printf("Fib(%d) = %d\n",f,fib[f]);
			t--;
		}
		s.close();
    }
}
