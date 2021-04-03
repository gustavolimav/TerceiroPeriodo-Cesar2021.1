package biblioteca.catalogo;

import java.util.List;
import biblioteca.livro.Livro;
import biblioteca.autor.Autor;

public class Catalogo() {
    private  ArrayList<Livro> Livros = new ArrayList<>();

    public void setLivro(String titulo) {
        Livros.add(titulo);
    }

}