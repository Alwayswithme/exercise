package structure;

import java.util.NoSuchElementException;

public class MyQueue {
	public static void main(String[] args) {
		ArrayQueue<Character> q = new ArrayQueue<Character>();
		int i = 0;
		while(!q.isFull()){
			q.enQueue((char) ('a'+ ++i));
		}
		while(!q.isEmpty()) {
			System.out.println(q.deQueue());
		}
	}
}
class ArrayQueue<T> {
	private static final int DEFAULT_CAPACITY = 10;
	private T[] data;
	int front;
	int rear;
	public ArrayQueue() {
		front = rear = 0;
		data = (T[])new Object[DEFAULT_CAPACITY];
	}
	public int length() {
		return (rear - front + data.length) % data.length;
	}
	public boolean isFull() {
		return (rear + 1) % data.length == front;
	}
	public boolean isEmpty() {
		return rear == front;
	}
	
	public boolean enQueue(T e) {
		if (!isFull()) {
			data[rear] = e;
			rear = (rear + 1)%data.length;
			return true;
		}else
			return false;
	}
	
	public T deQueue() {
		if (!isEmpty()) {
			T temp = data[front];
			front = (front + 1) % data.length;
			return temp;
		}else 
			throw new NoSuchElementException();
	}
}