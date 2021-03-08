package main.java.school.cesar.banco.entrypoint;

import school.cesar.banco.contacorrente.ContaCorrente;

public class Main {
    public static void main(String[] args) {
        ContaCorrente c1 = new ContaCorrente();
        c1.creditar(100);

        ContaCorrente c2 = new ContaCorrente();
        c2.creditar(100);
        System.out.println(c2.saldo);

        System.out.println(c2.debitar(1000));
        System.out.println(c2.debitar(10));
        System.out.println(c2.saldo);

        c2.creditar(1000);
    }
}
