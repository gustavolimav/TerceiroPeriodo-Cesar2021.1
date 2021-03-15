public class TestandoMetodo {
    public static void main(String[] args) {
        Conta contaDoPaulo = new Conta();
        contaDoPaulo.balance = 100;
        contaDoPaulo.deposit(50);
        System.out.println(contaDoPaulo.balance);
        
        boolean conseguiuRetirar = contaDoPaulo.saca(20);
        System.out.println(contaDoPaulo.balance);
        System.out.println(conseguiuRetirar);

        Conta contaDaMarcela = new Conta();
        contaDaMarcela.deposit(1000);

        boolean sucessoTransferencia = contaDaMarcela.transfer(300, contaDoPaulo);

        if(sucessoTransferencia) {
            System.out.println("Transferência realizada com sucesso");
        } else {
            System.out.println("Falha na Transferência");
        }

        System.out.println(contaDaMarcela.balance);
        System.out.println(contaDoPaulo.balance);

        contaDoPaulo.holder = "paulo silveira";
        System.out.println(contaDoPaulo.holder);
    }
}
