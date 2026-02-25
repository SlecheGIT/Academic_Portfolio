public class sequencia_ij3 {
    public static void main(String[] args) 
    {
        int i, jm=7, jc, j=7;

        for (i=1; i<=9; i=i+2)
        {
            jc=1; 
            while (jc<=3)
            {
                System.out.printf("I=%d J=%d\n", i, j);
                j=j-1;
                jc++;
            }
            jm=jm+2;
            j=jm;
        }
    }
}
