public class Alura {
    public static void main(String[] args) {
        Conta primeiraConta = new Conta();

        primeiraConta.balance = 200;
        primeiraConta.agency = 1;
        primeiraConta.number = 202;
        primeiraConta.holder = "Gustavo Lima";

        // System.out.println(primeiraConta.balance);
        // System.out.println(primeiraConta.agency);
        // System.out.println(primeiraConta.number);
        // System.out.println(primeiraConta.holder);
        
        primeiraConta.balance += 100;
        
        Conta segundaConta = new Conta();

        segundaConta.balance = 700;

        System.out.println("Primeira conta tem: " + primeiraConta.balance);
        System.out.println("Segunda conta tem " + segundaConta.balance);
        System.out.println(segundaConta.number); // 0
    
    }
}
