package util;

import java.util.LinkedList;


public class Test {
	
	public static void main(String[] args) throws InterruptedException {
		Queue resources = new Queue();
		Test test = new Test();
		Thread producer  = new Thread(test.new Producer(resources));
		Thread cosumer = new Thread(test.new Consumer(resources));
		producer.start();
		cosumer.start();
		cosumer.join();
		System.out.println("main exist");
	}
	class Consumer implements Runnable {
		private Queue resources;
		public Consumer(Queue r) {
			this.resources = r;
		}
		@Override
		public void run() {
			for(;;) {
				sleepOneSec();
				String result = null;
				try {
					result = resources.comsume();
				} catch (InterruptedException e) {
					e.printStackTrace();
				}
				if ("bye".equals(result))
					break;
				else
					System.out.println("cosumer get integer from producer: "+result);
			}
		}
		
	}
	void sleepOneSec() {
		try {
			Thread.sleep(1000);
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
	}
	class Producer implements Runnable {
		private Queue resources;
		public Producer(Queue r) {
			this.resources = r;
		}
		@Override
		public void run() {
			for (int i = 0; i < 30; i++) {
				sleepOneSec();
				String temp = String.valueOf((int)(Math.random()*100));
				resources.produce(temp);
				System.out.println("producer add integer: " + temp);
			}
			resources.produce("bye");
		}
	}
}
class Queue {
	LinkedList<String> resources =new LinkedList<String>();
	public synchronized void produce(String item) {
		resources.add(item);
		super.notify();
	}
	public synchronized String comsume() throws InterruptedException {
		if (resources.size()==0)
			super.wait();
		return resources.removeFirst();
	}
}


