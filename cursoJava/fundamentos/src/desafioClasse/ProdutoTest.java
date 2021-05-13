
public class ProdutoTest {
    public static void main(String[] args) {
        Produto p1 = new Produto("Notebook", 3000);

        var p2 = new Produto();
        p2.nome = "Notebook";
        p2.preco = 4000;

        Produto.desconto = 0.50;

        System.out.println(p1.nome + " " + p1.precoComDesconto());
        System.out.println(p1.nome + " " + p2.precoComDesconto());

        double precoFinal1 = p1.precoComDesconto();
        double precoFinal2 = p2.precoComDesconto(0.1);
        double mediaCarrinho = (precoFinal1 + precoFinal2) / 2;

        System.out.printf("Media do carrinho = R$%.2f.", mediaCarrinho);
    }
}
