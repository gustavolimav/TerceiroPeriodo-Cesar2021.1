import java.util.Scanner;

public class DoWilhe {
    public static void main(String[] args) {
        Scanner entrada = new Scanner(System.in);

        String texto = "";

        do {
            System.out.println("Qual a palavra magica?");
            texto = entrada.nextLine();
        } while(!texto.equalsIgnoreCase("por favor"));
        
        entrada.close();
    }
}
