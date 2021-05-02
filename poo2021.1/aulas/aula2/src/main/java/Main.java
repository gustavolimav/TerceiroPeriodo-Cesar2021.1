package aula2.src.main.java;

public class Main {
    public static void main(String[] args) {
        Todo meuPrimeiroTodo = new Todo();

        meuPrimeiroTodo.titulo = "Instalar JDK";
        meuPrimeiroTodo.texto="Instalar JDK na versão compatível";

        System.out.println("O título do Todo é: " + meuPrimeiroTodo.titulo);
        System.out.println("A situacao do Todo é: " + meuPrimeiroTodo.concluido);
        System.out.println("O tamanho do texto é: " + meuPrimeiroTodo.texto.length());

        Todo meuSegundoTodo = new Todo();

        meuSegundoTodo.titulo = "Instalar o Maven";
        System.out.println(meuSegundoTodo.titulo);
        System.out.println(meuPrimeiroTodo);
        System.out.println(meuSegundoTodo);
    }
}
