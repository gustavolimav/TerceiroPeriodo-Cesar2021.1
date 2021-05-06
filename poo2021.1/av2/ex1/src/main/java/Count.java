import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

public class Count {

    public static void ler(String path) throws IOException {
        BufferedReader arquivo = new BufferedReader(new FileReader(path));

        String linha = arquivo.readLine(); // lê a primeira linha
        while (linha != null) {
            System.out.printf("%s\n", linha);
            linha = arquivo.readLine(); // lê da segunda até a última linha
        }
        arquivo.close();
    }
    public static void main(String[] args) throws IOException {
        String path = "ids.txt";
        ler(path);
    }
}
