import java.util.Scanner;

public class teste {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
		
		while(scanner.hasNext()) {
			int total = scanner.nextInt();
			int conta=0;
			while(total!=1) {
				if (total%2==0) {
					total/=2;
					conta++;
				}
				else
					return;
			}
			System.out.println(conta);
		}
		scanner.close();
    }
}
