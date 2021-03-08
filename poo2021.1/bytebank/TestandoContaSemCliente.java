
public class TestandoContaSemCliente {
    
    public static void main(String[] args) {
        Conta contaDaMarcela = new Conta();
        System.out.println(contaDaMarcela.balance);

        contaDaMarcela.holder = new Cliente();
        System.out.println(contaDaMarcela.holder);

        contaDaMarcela.holder.nome = "Marcela";
        System.out.println(contaDaMarcela.holder.nome);
    }

}
