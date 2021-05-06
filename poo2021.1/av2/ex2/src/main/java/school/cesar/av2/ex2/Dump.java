package school.cesar.av2.ex2;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.util.ArrayList;

public class Dump {
    public static void main(String[] args) throws IOException {
        Leitura l1 = new Leitura(1, 0);
        Leitura l2 = new Leitura(2, 0);
        Leitura l3 = new Leitura(3, 0);
        ArrayList<Leitura> leituras = new ArrayList<>();
        leituras.add(l1);
        leituras.add(l2);
        leituras.add(l3);
        ObjectOutputStream oos = new ObjectOutputStream(new FileOutputStream("dump.bin"));
        oos.writeObject(leituras);
        oos.flush();
        oos.close();
    }
}