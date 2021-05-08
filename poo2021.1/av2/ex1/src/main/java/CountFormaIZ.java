import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.LinkedHashSet;
import java.util.Set;
public class CountFormaIZ {

    public static int contarNumerosDistintos(String path) throws IOException {
        BufferedReader arquivo = new BufferedReader(new FileReader(path));

        Set<String> semRepeticao = new LinkedHashSet<String>();

        String linha = arquivo.readLine(); // lê a primeira linha
        while (linha != null) {

            semRepeticao.add(linha);
            
            linha = arquivo.readLine(); // lê da segunda até a última linha
        }
        arquivo.close();

        int numerosDistintos = semRepeticao.size();
        return numerosDistintos;
    }
    public static void main(String[] args) throws IOException {
        
        String currentDirectory = System.getProperty("user.dir"); // pega o diretorio atual
        String pathIds = currentDirectory + "/ex1/ids.txt"; // add o diretorio de ids.txt

        int quantidadeNumerosDistintos = contarNumerosDistintos(pathIds);

        System.out.println(quantidadeNumerosDistintos);


    }
}
