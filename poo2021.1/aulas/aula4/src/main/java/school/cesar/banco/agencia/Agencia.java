package school.cesar.banco.agencia;

import java.util.Map;
import java.util.HashMap;
import school.cesar.banco.contacorrente.*;


public class Agencia {
    private int numero;
    private map<String, ContaCorrente> contaCorrentePorNumero = new HashMap();

    public void cadastrarCliente(ContaCorrente contaCorrente) {
        this.contaCorrentePorNumero.put(contaCorrente.getNumero(), contaCorrente);

    }

    public ContaCorrente recuperarContaCorrente(int numero) {
        return this.contaCorrentePorNumero.get(numero);        
    }

    
}