package fundamentos.src;

public class AreaCircuferencia {
    public static void main(String[] args) {
        int raio = 3;
        final double PI = 3.4;

        double area = PI * raio * raio;
        System.out.println(area);

        raio = 10;
        area = PI * raio * raio;
        System.out.println(area);
    }
}
