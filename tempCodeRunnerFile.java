import java.io.RandomAccessFile;
import java.security.PublicKey;
import java.util.Random;
import java.util.RandomAccess;
import java.time.LocalTime;

public class Inter_process {
    public static volatile int x = 0;
    public static class Responce implements Runnable{

        @Override
        public void run() {
            System.out.println("Tell the time ");
            while (x == 0) {
                Thread.onSpinWait();
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    throw new RuntimeException(e);
                }
                
                System.out.println(LocalTime.now());
            }
            System.out.println(System.currentTimeMillis());
        }
    }
    public static class  Request implements Runnable{
        @Override
        public void run(){
            System.out.println("In Request Thread");
            try {
                Thread.sleep(10000);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
            x = 1;
        }
    }
    public static void Main() {
        Request request = new Request();
        Responce responce = new Responce();
        Thread request_thread = new Thread(request);
        Thread responce_thread = new Thread(responce);
        responce_thread.start();
        request_thread.start();

    }

    public static void main(String[] args) {
        Main();
    }
}
