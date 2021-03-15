public class TesteReferencia {
    public static void main(String[] args) {
        Conta primeiraConta = new Conta();
        primeiraConta.balance = 300;

        System.out.println("saldo: " + primeiraConta.balance);

        Conta segundaConta = primeiraConta;

        segundaConta.balance += 200;

        System.out.println("segunda conta: " + segundaConta.balance);
        System.out.println("primeira conta: " + primeiraConta.balance);

    }
}
