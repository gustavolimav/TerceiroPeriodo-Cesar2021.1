package com.desafio.poo;

import java.util.ArrayList;

public class Cliente {
    String nome;
    ArrayList<Compra> compras = new ArrayList<>();

    double obterValorTotal() {
        double valorTotal = 0;
        for(Compra compra : this.compras) {
            for(Item item : compra.itens) {
                valorTotal += item.produto.preco * item.quantidade;
            }
        }
        return valorTotal;
    }

    void adicionarCompra(Compra compra) {
        this.compras.add(compra);
    }
}
