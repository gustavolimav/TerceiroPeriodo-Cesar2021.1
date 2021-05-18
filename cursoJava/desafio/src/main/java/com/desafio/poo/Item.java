package com.desafio.poo;

public class Item {
    int quantidade;
    Produto produto;

    public void definirQuantidade(Produto produto, int quantidade) {
        this.produto = produto;
        this.quantidade = quantidade;
    }
}
