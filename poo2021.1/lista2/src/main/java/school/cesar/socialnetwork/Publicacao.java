package school.cesar.socialnetwork;

import java.sql.Date;
import java.util.ArrayList;
import java.util.List;

public class Publicacao {
    private Usuario autor;
    private String texto;
    private List<String> tags = new ArrayList<String>();
    private Date data;

    public Usuario getAutor() {
        return autor;
    }

    public void setAutor(Usuario autor) {
        this.autor = autor;
    }

    public void setTexto(String texto) {
        this.texto = texto;
    }

    public String getTexto() {
        return this.texto;
    }
    
    public void setTags(List<String> tags) {
        this.tags = tags;
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
