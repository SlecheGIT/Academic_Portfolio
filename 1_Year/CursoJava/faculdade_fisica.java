import java.util.Scanner;

public class faculdade_fisica {
    public static void main(String[] args) {
        Scanner scanf = new Scanner(System.in);
        int v=0, t=0;

        while (scanf.hasNext()){
        v = scanf.nextInt();
        t = scanf.nextInt();
        System.out.println(v * (2 * t));
        }
        scanf.close();
 
    }
}
