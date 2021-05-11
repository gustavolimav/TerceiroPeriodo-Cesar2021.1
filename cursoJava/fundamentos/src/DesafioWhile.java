import java.util.Scanner;

public class DesafioWhile {
    public static void main(String[] args) {
        // nota de 0 a 10 armazenar na variavel total e outra pra
        // contar a quantidade de notas
        // pra sair -1

        Scanner entrada = new Scanner(System.in);

        int total = 0;
        double nota = 0;
        int quantidadeDeNotas = 0;

        while(nota != -1){
            System.out.print("(-1 pra sair)Digite a nota: ");
            nota = entrada.nextDouble();

            if (nota == -1) {
                System.out.println("Saindo!");
                break;
            }

            if (nota > 10 || nota < 0) {
                System.out.println("Nota inválida!");
                continue;
            }

            total += nota;
            quantidadeDeNotas++;
        }

        System.out.println("Quantidade de notas: " + quantidadeDeNotas + " \nmedia: " + total/quantidadeDeNotas);

        entrada.close();
    }
}
