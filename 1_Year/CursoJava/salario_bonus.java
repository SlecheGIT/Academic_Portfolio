import java.util.Scanner;

public class salario_bonus {
    public static void main(String[] args) 
    {
    Scanner scanner = new Scanner(System.in);
    
    double money = scanner.nextDouble();
    double sell =scanner.nextDouble();
    scanner.close();
    // ingles pq é menorzinho
    money = money + sell*0.15;
    System.out.printf("TOTAL = R$ %.2f\n", money);
    }
}
