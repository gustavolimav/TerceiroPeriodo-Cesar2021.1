package br.com.alura.leilao.dao;

import org.junit.Test;

import br.com.alura.leilao.model.Usuario;

import javax.persistence.EntityManager;

import org.junit.Assert;

public class UsuarioDaoTest {

    private UsuarioDao dao;

    private EntityManager em;

    @Test
    public void testeBuscaDeUsuarioPeloUserName() {
        this.dao = new UsuarioDao(em);
        Usuario usuario = this.dao.buscarPorUsername("fulano");
        Assert.assertNotNull(usuario);
    }
}
