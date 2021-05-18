package com.desafio.poo;

/**
 * Hello world!
 *
 */
public class ClienteTest 
{
    public static void main( String[] args )
    {
        Produto produto1 = new Produto();
        Produto produto2 = new Produto();
        Produto produto3 = new Produto();

        produto1.criarProduto(20, "nutella pequena");
        produto2.criarProduto(30, "nutella media");
        produto3.criarProduto(40, "nutella grande");

        Item item1 = new Item();
        Item item2 = new Item();

        item2.definirQuantidade(produto2, 2);
        item1.definirQuantidade(produto1, 3);

        Compra compras = new Compra();

        compras.adicionarItem(item1);
        compras.adicionarItem(item2);
        
        for(Item item : compras.itens) {
            System.out.println("nome do item: " + item.produto.nome);
            System.out.println("quantidade: " + item.quantidade);
            System.out.println("preco: " + item.produto.preco);
        }

        Cliente douglasCliente = new Cliente();
        douglasCliente.nome = "douglas";
        
        douglasCliente.adicionarCompra(compras);

        System.out.println(douglasCliente.obterValorTotal());
        
    }
}
