package school.cesar.socialnetwork;

import static org.hamcrest.MatcherAssert.assertThat; 
import static org.hamcrest.Matchers.*;
import org.junit.Test;

public class TestServicoPublicacao {
    @Test
    public void testPublicacaoEhArmazenadaCorretamente() {
        ServicoPublicacao servico = new ServicoPublicacao();
        Publicacao p1 = new Publicacao();
        Usuario u1 = new Usuario();
        p1.setAutor(u1);
        servico.publicar(p1);
        assertThat(servico.listarPublicacoes(u1), contains(p1));
    }
}
