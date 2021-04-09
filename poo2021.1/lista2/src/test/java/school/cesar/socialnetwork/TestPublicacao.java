package school.cesar.socialnetwork;

import static org.hamcrest.MatcherAssert.assertThat; 
import static org.hamcrest.Matchers.*;
import org.junit.Test;

public class TestPublicacao {
    @Test
    public void TestPublicacaoRetornaTags() {
        Publicacao p1 = new Publicacao();
        Usuario u1 = new Usuario();

        p1.setAutor(u1);
        // dentro do setTexto é chamado addTags que já inicializa a lista de tags
        p1.setTexto("Meu primeiro caso de teste #junit #hamcrest #poo #java");

        assertThat(p1.getTags(), contains("junit", "hamcrest", "poo", "java"));
    }
}
