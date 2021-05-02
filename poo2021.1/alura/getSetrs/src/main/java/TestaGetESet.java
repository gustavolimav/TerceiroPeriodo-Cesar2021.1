public class TestaGetESet {
    
    public static void main(String[] args) {
        Conta conta = new Conta();
        //conta.number = 1337;
        conta.setNumber(1337);
        System.out.println(conta.getNumber());

        Cliente paulo = new Cliente();

        paulo.setNome("Paulo Silveira");
        conta.setHolder(paulo);

        System.out.println(conta.getHolder().getNome());

        conta.getHolder().setProfissao("programador");
        // agora em duas linhas
        Cliente titularDaConta = conta.getHolder();
        titularDaConta.setProfissao("programador");


        System.out.println(titularDaConta);
        System.out.println(paulo);
        System.out.println(conta.getHolder());
    }
}
