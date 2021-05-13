import java.util.Random;

public class MyThread extends Thread {
    public void run() {
        Random gerador = new Random();
        System.out.println("lebre: " + Thread.currentThread().getId() + " pulou " + gerador.nextInt()%10);
        
    }

    public static void main(String[] args) throws InterruptedException {

        Thread fstThread = new MyThread();
        Thread scdThread = new MyThread();
        fstThread.setPriority(Thread.MIN_PRIORITY);
        scdThread.setPriority(Thread.NORM_PRIORITY);
        fstThread.start();
        scdThread.start();
    }
}
