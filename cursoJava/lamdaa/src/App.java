public class App {
    public static void main(String[] args) throws Exception {
        Calculo calc = (x, y) -> {
            return x + y;
        };

        System.out.println(calc.executar(1, 2));
    }
}
