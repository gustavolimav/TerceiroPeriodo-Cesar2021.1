package school.cesar.socialnetwork;

import java.sql.Date;
import java.util.ArrayList;
import java.util.List;

public class Publicacao {
    private Usuario autor;
    private String texto;
    private List<String> tags = new ArrayList<String>();
    private Date data;


    public void addTags(String texto) {
        String[] listaseparada = texto.split(" "); 

        for(int i = 0; i < listaseparada.length; i++) {
            if (listaseparada[i].startsWith("#") == true) {
                tags.add(listaseparada[i].substring(1));
            }
        }
    }

    public Usuario getAutor() {
        return this.autor;
    }

    public void setAutor(Usuario autor) {
        this.autor = autor;
    }

    public void setTexto(String texto) {
        this.addTags(texto);
        this.texto = texto;
    }

    public String getTexto() {
        return this.texto;
    }

    public List<String> getTags() {
        return this.tags;
    }
    
    public Date getData() {
        return this.data;
    }

    public void setData(Date data) {
        this.data = data;
    }
}
