package biblioteca.livro;

import biblioteca.autor.Autor;

import java.util.List;

public class Livro() {
    private String titulo;
    private ArrayList<Autor> autores = new ArrayList<>();
    private ArrayList<String> tags = new ArrayList<>();
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

    public void setAutor(String nome, String cpf, String obra) {
        Autor novo = new Autor();

        novo.setNome(nome);
        novo.setCpf(cpf);
        novo.setObra(obra);
        
        this.autores.add(novo);
    }

    public String getAutores(int id) {
        return autores.get(id);
    }

    public void setTag(String nome) {
        for (String tag : tags) {
            if (nome == tag) {
                break
            }
        }
        this.tags.add(nome);
    }

    public String getTag(int id) {
        return tags.get(id);
    }

}