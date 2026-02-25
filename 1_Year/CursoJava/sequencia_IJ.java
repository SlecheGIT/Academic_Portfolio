public class sequencia_IJ {

    public static void main(String[] args) 
    {
        int i = 1;
        int j = 60;

        System.out.println("I="+i +" J="+j);
        do {
            i=i+3;
            j=j-5;
            System.out.println("I="+i +" J="+j);
        } while (j != 0);
    }
}
