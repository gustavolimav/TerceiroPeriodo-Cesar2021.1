package netflix.entrypoint;
import netflix.genero.Genero;
import netflix.titulo.Titulo;
import netflix.*;

public class Main {
    public static void main(String[] args) {
        Genero acao = new Genero();
        Genero comedia = new Genero();

        acao.name = "Acao";
        acao.maioridade = false;
        comedia.name = "Comedia";
        comedia.maioridade = true;

        Titulo filme1 = new Titulo();
        filme1.generoPrincipal = acao;
        filme1.titulo = "A volta dos que não foram";
        filme1.sinopse = "Os que não foram e voltaram";
        filme1.generos.add(acao);
        System.out.println(filme1.generos);
        
    }
}
