import java.text.DecimalFormat;
import java.util.Scanner;

public class media3 {
    public static void main(String[] args) {
		Scanner leitor = new Scanner(System.in);
		DecimalFormat df = new DecimalFormat("0.0");
		double Nota1 = leitor.nextDouble()* 2;
		double Nota2 = leitor.nextDouble()* 3;
		double Nota3 = leitor.nextDouble()* 4;
		double Nota4 = leitor.nextDouble();
        double MEDIA = (Nota1 + Nota2 + Nota3 + Nota4) / 10;
		System.out.println("Media: " + df.format(MEDIA));
		

        if (MEDIA >= 7) {
        	System.out.println("Aluno aprovado.");

        } else if (MEDIA >= 5 && MEDIA < 7) {
        	System.out.println("Aluno em exame.");
        	double NExame = leitor.nextDouble();
			System.out.println("Nota do exame: " + df.format(NExame));
        	MEDIA = (MEDIA + NExame) / 2;

        	if (MEDIA >= 5) {
            	System.out.println("Aluno aprovado.");
        	} else {
            	System.out.println("Aluno reprovado.");
        	}
			System.out.println("Media final: " + df.format(MEDIA));
        } else {
        	System.out.println("Aluno reprovado.");
        }
        leitor.close();
    }
}
