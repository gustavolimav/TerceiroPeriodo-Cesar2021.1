package fundamentos.src;

import javax.swing.JOptionPane;

public class ConversaoStringInt {
    public static void main(String[] args) {
        String valor1 = JOptionPane.showInputDialog("Digite o primeiro Numero");
        String valor2 = JOptionPane.showInputDialog("Digite o segundo Numero");

        System.out.println(valor1 + valor2);

        double numero1 = Double.parseDouble(valor1);
        double numero2 = Double.parseDouble(valor2);

        double soma = numero1 + numero2;

        System.out.println("Soma e " + soma);
        System.out.println("Media e " + soma / 2);
    }
}