package fundamentos.src;

public class SwitchSemBreak {
    public static void main(String[] args) {
        String faixa = "marrom";

        switch (faixa.toLowerCase()) {
            case "preta":
                System.out.println("Sei o Bassai-Dai");
            case "marrom":
                System.out.println("Sei o Tekki Shodan");

                // default:
                // System.out.println("sei nada");
        }
    }
}
