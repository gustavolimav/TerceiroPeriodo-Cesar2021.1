import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
public class CountFormaBruta {

    public static int contar(String path) throws IOException {
        BufferedReader arquivo = new BufferedReader(new FileReader(path));

        int count = 0;

        String linha = arquivo.readLine(); // lê a primeira linha
        while (linha != null) {
            count++;
            
            linha = arquivo.readLine(); // lê da segunda até a última linha
        }
        arquivo.close();

        return count;
    }
    public static int contarNumerosDistintos(String path, int linhas) throws IOException {
        BufferedReader arquivo = new BufferedReader(new FileReader(path));

        String array[][] = new String[linhas][1];
        int count = 0;
        int numerosRepetidos = 0;
        int numerosDistintos = 0;

        String linha = arquivo.readLine(); // lê a primeira linha
        while (linha != null) {
            array[count][0] = linha;
            
            if(count != 0) {
                for(int i = 0; i < linhas; i++) {
                    if(array[count][0].equals(array[i][0]) && array[i][0] != null && i != count) {
                        numerosRepetidos++;
                        break;
                    }
                }
            }

            count++;
            linha = arquivo.readLine(); // lê da segunda até a última linha
        }
        arquivo.close();

        numerosDistintos = linhas - numerosRepetidos;
        return numerosDistintos;
    }
    public static void main(String[] args) throws IOException {
        
        String currentDirectory = System.getProperty("user.dir"); // pega o diretorio atual
        String pathIds = currentDirectory + "/ex1/ids.txt"; // add o diretorio de ids.txt

        int numeroLinhas = contar(pathIds);

        int quantidadeNumerosDistintos = contarNumerosDistintos(pathIds, numeroLinhas);

        System.out.println(quantidadeNumerosDistintos);


    }
}
