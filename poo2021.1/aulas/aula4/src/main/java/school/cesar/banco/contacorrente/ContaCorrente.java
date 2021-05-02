package main.java.school.cesar.banco.contacorrente;

public class ContaCorrente {
    int saldo;
    int proprietario;

    public ContaCorrente() {
        super();
    }
    public ContaCorrente(double saldoInicial) {
        this.saldo = saldoInicial;
    }
    public void creditar(double value) {
        this.saldo += value;
    }

    public boolean debitar(double value) {
        if (this.saldo > value) {
            this.saldo -= value;
            return true;
        }
        return false;
    }
    public boolean transferir(ContaCorrente destino, double value) {
        if (this.saldo > value) {
            destino.saldo += value;
            this.saldo -= value;
            return true;
        }
    }
}