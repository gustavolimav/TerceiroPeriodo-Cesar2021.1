public class TestaArray{

    public static void main(String[] args) throws Exception{
        int[] idades = new int[]{1,2,3,4,5,6,7,8,9};

        // Cliente[] clientes = new Cliente[]
        //     {new cliente(), null, new Cliente()}

        idades[4] = 10;

        for(int i =0; i < idades.length; i++) {
            System.out.println(idades[i]);
        }

        for(int idade : idades){
            System.out.println(idade);
        }

    }
}