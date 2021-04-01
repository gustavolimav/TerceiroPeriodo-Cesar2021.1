package school.streaming.genero;

public class Genero {
    private String nome;
    private boolean maioridade;

    public Genero(String nome, boolean maioridade) throws Exception {
        setNome(nome);
        setMaioridade(maioridade);
    }

    public void setNome(String nome) throws Exception {
        if (nome == null || "".equals(nome))
            throw new Exception("nome invalido");
        this.nome = nome;
    }
    
    public String getNome() {
        return this.nome;
    }

    public void setMaioridade(boolean maioridade) {
        this.maioridade = maioridade;
    }

    public boolean isMaioridade() {
        return this.maioridade;
    }

}
