package school.cesar.av2.ex2;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.util.ArrayList;

public class Reload {
    public static void main(String[] args) throws IOException, ClassNotFoundException {
        String currentDirectory = System.getProperty("user.dir"); // pega o diretorio atual
        String pathDump = currentDirectory + "/ex2/dump.bin"; // add o diretorio de dump.bin

        ObjectInputStream arquivo = new ObjectInputStream(new FileInputStream(pathDump));       

        ArrayList<Leitura> leituras = (ArrayList<Leitura>) arquivo.readObject();

        System.out.println("1- sensor: " + leituras.get(0).getSensor() + " valor: " + leituras.get(0).getValor());
        System.out.println("2- sensor: " + leituras.get(1).getSensor() + " valor: " + leituras.get(1).getValor());
        System.out.println("3- sensor: " + leituras.get(2).getSensor() + " valor: " + leituras.get(2).getValor());

    }
}