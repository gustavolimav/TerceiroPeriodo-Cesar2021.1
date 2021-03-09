
public class TesteSacaNegativo {
    public static void main(String[] args) {
        Conta conta = new Conta();
        conta.deposit(100);
        conta.saca(200);
        System.out.println(conta.saca(101));

        conta.saca(101);

        System.out.println(conta.getSaldo()); // invoca metodo com o principio de encapsular

        
        // proibidooooo:
        // conta.balance = conta.balance - 101;
        // System.out.println(conta.balance);
    }
}
