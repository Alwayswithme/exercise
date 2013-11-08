package multiThread;

import java.util.LinkedList;
import java.util.concurrent.locks.Condition;
import java.util.concurrent.locks.ReentrantLock;

public class ConsumerAndProducer {
  private LinkedList<String> queue = new LinkedList<String>();
  private final ReentrantLock lock = new ReentrantLock();
  private final Condition empty = lock.newCondition();

  public static void main(String[] args) throws InterruptedException {
    ConsumerAndProducer cap = new ConsumerAndProducer();
    cap.start();
    System.out.println("main exist");
  }

  public static void sleepOneSec() {
    try {
      Thread.sleep(1000);
    }catch (InterruptedException e) {
      e.printStackTrace();
    }
  }
  public void start() throws InterruptedException {
    /* 使用匿名内部类创建两个线程 */
    Thread producer = new Thread(new Runnable(){
        @Override
        public void run() {
          for(int i = 0; i < 30; i++) {
        	  sleepOneSec();
        	  lock.lock();
        	  try{
        		  String temp = String.valueOf((int)(Math.random()*100));
        		  queue.addLast(temp);
        		  empty.signal();
        		  System.out.println("producer add integer: " + temp);
        	  } finally {
        		  lock.unlock();
        	  }
          }
          queue.addLast("bye");
        }
    });
    Thread consumer = new Thread(new Runnable(){
        @Override
        public void run() {
          for(;;) {
            sleepOneSec();
            lock.lock();
            try {
              while(queue.size() == 0)
                empty.await();
              String item = queue.removeFirst();
              System.out.println("consumer get integer form producer: " + item);
              if ("bye".equals(item))
                break;
            } catch(InterruptedException e) {
              e.printStackTrace();
            }finally {
              lock.unlock();
            }
          }
        }
    });
    consumer.start();
    producer.start();
    //启动两个线程,并让主线程等待消费者进程退出
    consumer.join();
  }
}

