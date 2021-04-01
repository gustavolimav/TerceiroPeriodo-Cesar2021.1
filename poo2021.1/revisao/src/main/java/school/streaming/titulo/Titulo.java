package school.streaming.titulo;

import java.util.ArrayList;
import school.streaming.genero.Genero;


public class Titulo {
    private String titulo;
    private String sinopse;
    private Genero generoPrincipal;
    private ArrayList<Genero> generos = new ArrayList<Genero>();

    public String getTitulo() {
        return this.titulo;
    }

    public void setTitulo(String titulo) {
        this.titulo = titulo;
    }

    public void setGeneroPrincipal(Genero genero) {
        if (genero == null)
            throw new RuntimeException("genero nao pode ser nulo");
        this.generoPrincipal = genero;
    }

    public Genero getGeneroPrincipal() {
        return this.generoPrincipal;
    }

    public ArrayList<Genero> getGeneros() {
        return this.generos;
    }

    public void setGeneros(ArrayList<Genero> generos) {
        this.generos = generos;
    }

    public void addGenero(Genero genero) {
        if (this.generos.contains(genero) || genero.equals(generoPrincipal))
            return;
        this.generos.add(genero);
    }

    public void removeGenero(Genero genero) {
        this.generos.remove(genero);
    }

    public boolean containsGenero(Genero genero) {
        return this.generos.contains(genero) || genero.equals(this.generoPrincipal);
    }
}
