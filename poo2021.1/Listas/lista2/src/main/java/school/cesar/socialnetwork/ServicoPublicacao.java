package school.cesar.socialnetwork;

import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class ServicoPublicacao {
    private Map<Usuario, List<Publicacao>> publicacaos = new HashMap<>();

    public void publicar(Publicacao publicacao) {
        Usuario autor = publicacao.getAutor();
        // List<Publicacao> publicacaosUsuario = publicacao.getOrDefault(autor, new ArrayList<>());
        List<Publicacao> publicacaosUsuario = publicacaos.get(autor);
        if (publicacaosUsuario != null) {
            publicacaosUsuario.add(publicacao);
        } else {
            publicacaosUsuario = new ArrayList<>();
            publicacaosUsuario.add(publicacao);
            publicacaos.put(autor, publicacaosUsuario); 
        }

    }

    public List<Publicacao> listarPublicacoes(Usuario usuario) {
        //return publicacoes.getOrDefault(usuario, new ArrayList()); cria uma nova lista sempre
        List<Publicacao> publicacaosAutor = publicacaos.getOrDefault(usuario, Collections.EMPTY_LIST);
        List<Publicacao> copiaPublicacao =  new ArrayList<>(publicacaosAutor);
        return copiaPublicacao;
    }
}
