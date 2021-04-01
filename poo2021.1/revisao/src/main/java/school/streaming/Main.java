package school.streaming;

import school.streaming.genero.Genero;
import school.streaming.titulo.Titulo;

public class Main {
    public static void main(String[] args) throws Exception {
        Genero g1 = new Genero("Violência", true);    
        Genero g2 = new Genero("Ficção", false);    
        Titulo t1 = new Titulo();
        t1.setGeneroPrincipal(g1);
        t1.addGenero(g1);
        t1.addGenero(g2);
        System.out.println(t1.getGeneros());
        System.out.println(t1.getGeneros());
    }
}
