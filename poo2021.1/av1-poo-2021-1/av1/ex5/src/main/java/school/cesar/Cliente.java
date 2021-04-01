public class Cliente {
    private String cpf;
    private double renda;
    private String nome;

    public void setNome(String nome) throws Exception {
        if (nome == null || "".equals(nome))
            throw new Exception("nome invalido");
        this.nome = nome;
    }

    public void setRenda(double renda) throws Exception {
        if (renda < 0)
            throw new Exception("Renda não pode ser negativa");
        this.renda = renda;
    }

    public void setCpf(String cpf) throws Exception {
        if (cpf.lenght() < 11)
            throw new Exception("Renda não pode ser negativa");
        this.cpf = cpf;
    }

    public String getNome() {
        return this.nome;
    }

    public String getCpf() {
        return this.cpf;
    }

    public double getRenda() {
        return this.renda;
    }
}