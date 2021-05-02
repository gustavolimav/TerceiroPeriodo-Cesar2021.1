package biblioteca.autor;

import java.util.Set;
import java.util.HashSet;

public class Autor {
    private String nome;
    private String cpf;
    private Set<String> obras = new HashSet<string>();

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

    public String getObra() {
        Iterator<String> obraIterator = obras.iterator();
        while (obras.hasNext()) {
            String it = obraIterator.next();
            System.out.println(it + " ");
        }
    }

    public void setObra(String novaObra) {
        this.obras.add(novaObra);
    }
}