package school.cesar.av2.ex2;

import java.io.Serializable;

public class Leitura implements Serializable {
    private int sensor;
    private int valor;
    public int getSensor() {
        return sensor;
    }
    public void setSensor(int sensor) {
        this.sensor = sensor;
    }
    public int getValor() {
        return valor;
    }
    public void setValor(int valor) {
        this.valor = valor;
    }
    public Leitura() {
    }
    public Leitura(int sensor, int valor) {
        this.sensor = sensor;
        this.valor = valor;
    }

}
