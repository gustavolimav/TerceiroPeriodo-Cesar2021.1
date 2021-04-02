package biblioteca.autor;

import java.util.ArrayList;

public class Autor {
    private String nome;
    private String cpf;
    private ArrayList<String> obras = new ArrayList<string>();

    public String getNome() {
        return this.nome;
    }

    Public void setNome(String novoNome) {
        this.nome = novoNome;
    }

    public String getCpf() {
        return this.cpf;
    }

    public void setCpf(String novoCpf) {
        this.cpf = novoCpf;
    }

    public ArrayList<String> getObras() {
        return obras;
    }

    public String getObra(int id) {
        return obras.get(id);
    }

    public void setObra(String novaObra) {
        this.obras.add(novaObra);
    }
}