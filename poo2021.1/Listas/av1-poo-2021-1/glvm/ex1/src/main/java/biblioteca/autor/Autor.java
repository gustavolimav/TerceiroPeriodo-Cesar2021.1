package biblioteca.autor;

import java.util.Iterator;
import java.util.Set;

import java.util.ArrayList;
import java.util.HashSet;

public class Autor {
    private String nome;
    private String cpf;
    private Set<String> obras = new HashSet<String>();

    public Set<String> getObras() {
        return obras;
    }

    public void setObras(Set<String> obras) {
        this.obras = obras;
    }

    public String getNome() {
        return this.nome;
    }

    public void setNome(String novoNome) {
        this.nome = novoNome;
    }

    public String getCpf() {
        return this.cpf;
    }

    public void setCpf(String novoCpf) {
        this.cpf = novoCpf;
    }

    public void setObra(String novaObra) {
        this.obras.add(novaObra);
    }
}