package school.cesar.socialnetwork;

import java.util.Date;

public class Story extends Publicacao {
    private Date expiracao;

    public void setExpiracao(Date expiracao) {
        this.expiracao = expiracao;
    }

    public Date getExpiracao() {
        return expiracao;
    }

}
