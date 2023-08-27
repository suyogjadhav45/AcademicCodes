import java.util.LinkedList;
import java.util.concurrent.Semaphore;

public class P_C {
    static LinkedList<Integer> Buffer;
    int size;
    Semaphore empty;
    Semaphore full;
    Semaphore mutex;
    int cunsumed_count = 0;

    public P_C(int size) {
        this.size = size;
        empty = new Semaphore(size);
        full = new Semaphore(0);
        mutex = new Semaphore(1);
        Buffer = new LinkedList<>();
    }

    public class P implements Runnable {

        public P() {
            System.out.println("Producer Invoked\n");

        }

        public void run() {
            int j = 0;
            do {

                try {
                    System.out.println("Producer wants to produce : " + j);
                    empty.acquire();
                } catch (Exception e) {
                    // TODO: handle exception
                    e.printStackTrace();
                }
                try {
                    mutex.acquire();
                    System.out.println("Producer got permission to produce : " + j);
                } catch (Exception e) {
                    // TODO: handle exception
                    e.printStackTrace();
                }

                Buffer.add(j);
                System.out.println("Producer produced item : " + j + "\n");

                mutex.release();
                full.release();

                if (j % 2 == 0) {
                    try {
                        Thread.sleep(3000);
                    } catch (Exception e) {
                        // TODO: handle exception
                        e.printStackTrace();
                    }
                }

                j++;
            } while (j < 10);
        }

    }

    public class C implements Runnable {
        int j = 0;

        public C() {
            System.out.println("Consumer Invoked\n");
        }

        public void run() {
            do {
                try {
                    System.err.println("Consumer want to consume : " + j);
                    full.acquire();
                } catch (Exception e) {
                    // TODO: handle exception
                    e.printStackTrace();
                }
                try {
                    mutex.acquire();
                    System.out.println("Consumer got permission to consume : " + j);
                } catch (Exception e) {
                    // TODO: handle exception
                    e.printStackTrace();
                }

                Buffer.removeFirst();
                System.out.println("Consumer Consumed item : " + j + "\n");
                empty.release();
                mutex.release();
                if (j % 2 != 0) {
                    try {
                        Thread.sleep(5000);
                    } catch (Exception e) {
                        // TODO: handle exception
                        e.printStackTrace();
                    }
                }
                j++;
            } while (j < 10);
        }
    }

    public static void main(String[] args) {
        P_C obj = new P_C(10);

        Thread t1 = new Thread(obj.new P());
        Thread t2 = new Thread(obj.new C());

        t2.start();
        t1.start();

    }

}
