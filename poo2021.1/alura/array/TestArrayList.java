import java.util.ArrayList;

public class TestArrayList {
    
    public static void main(String[] args) {
        ArrayList<String> nomes = new ArrayList<>();

        nomes.add("Java");
        nomes.add("python");
        nomes.add("Java");

        System.out.println(nomes.contains("Java"));

        boolean removido = nomes.remove("Java");
        // removeu a primeira ocorrencia

        System.out.println(removido);
        System.out.println(nomes.contains("Java"));

        System.out.println(nomes.size());

        // Object[] objetos = nomes.toArray();

        // String[] nomesArray = nomes.toArray(new String[nomes.size()]);
        // String[] nomesArray2 = nomes.toArray(new String[0]); 
        
        ArrayList<String> paises = new ArrayList<>();
        paises.add("Brasil");
        paises.add("EUA");

        ArrayList<String> tudo = new ArrayList<>();

        tudo.addAll(nomes);
        tudo.addAll(paises);

        System.out.println(tudo.size());
        System.out.println(nomes.get(0));
        nomes.add(0, "php");
        System.out.println(nomes.get(0));
        System.out.println(nomes.get(1));

        nomes.remove(0);
        System.out.println(nomes.get(0));

        // troca um elemento por outro
        nomes.set(0, "set");
        System.out.println(nomes.get(0));

        System.out.println(nomes.indexOf("Java"));
        System.out.println(nomes.lastIndexOf("Java"));
    }
}
