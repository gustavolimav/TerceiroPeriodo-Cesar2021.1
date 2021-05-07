import java.util.Scanner;

public class Ternario {
    public static void main(String[] args) {
        double media = 0;
        String resultado = media >= 7.0 ? "Aprovado" : "Reprovado";

        System.out.println("Aluno esta " + resultado);

        Scanner entrada = new Scanner(System.in);
        String s2 = entrada.next(); // ja tira espaco em branco, nextline nao
        System.out.println("2".equals(s2.trim())); // trim tira espaco em branco

        entrada.close();
    }
}
