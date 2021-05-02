package biblioteca.livro;

import biblioteca.autor.Autor;

import java.util.ArrayList;
import java.util.Set;
import java.util.HashSet;

public class Livro() {
    private String titulo;
    private ArrayList<Autor> autores = new ArrayList<>();
    private Set<String> tags = new HashSet<String>();
    private double isbn;

    public String getTitulo() {
        return this.titulo;
    }

    public void setTitulo(String novoTitulo) {
        this.titulo = novoTitulo;
    }
    
    
    public double getIsbn() {
        return this.isbn;
    }

    public void setIsbn(double novoIsbn) {
        this.isbn = novoIsbn;
    }

    public void setAutor(String nome) {
        autores.add(nome);
    }

    public String getAutores(int id) {
        return autores.get(id);
    }

    public void setTag(String nome) {
        this.tags.add(nome);
    }

    public String getTag() {
        Iterator<String> tagIterator = tags.iterator();
        while (tags.hasNext()) {
            String it = tagIterator.next();
            System.out.println(it + " ");
        }
        
    }

}