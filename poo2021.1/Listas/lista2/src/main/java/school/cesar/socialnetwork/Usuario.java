package school.cesar.socialnetwork;

public class Usuario {
    private String login;
    private String nome;

    public void setLogin(String user) {
        this.login = user;
    }

    public void setNome(String nome) {
        this.nome = nome;
    }

    public String getLogin() {
        return this.login;
    }

    public String getNome() {
        return this.nome;
    }
    
}