package structure;

import java.util.NoSuchElementException;



public class MyStack<T> {
	private int size = 0;
	private Node<T> top;
	private static class Node<T> {
		public T data;
		public Node<T> next;
		public Node(T d, Node<T> n) {
			data = d;
			next = n;
		}
	}
	
	public void push(T e) {
		if (top == null)
			top = new Node<T>(e, null);
		top = new Node<T>(e, top);
		size++;
	}
	
	public T pop() {
		if (isEmpty()){
			throw new NoSuchElementException();
		}
		T data = top.data;
		Node<T> temp = top;
		top = top.next;
		temp.next = null;
		size--;
		return data;
	}
	
	public boolean isEmpty() {
		return size == 0;
	}
}
class ArrayStack<T> {
	private static final int DEFAULT_CAPACITY = 10;
	private int top = 0;
	private T[] data;
	public ArrayStack() {
		data=(T[])new Object[DEFAULT_CAPACITY];
	}
	public ArrayStack(int size) {
		data=(T[])new Object[size];
	}
	
	public void push(T e) {
		if (top < data.length)
			data[top++] = e;
		else
			throw new IllegalStateException("Stack full, can't push");
	}
	public T pop() {
		if (top > 0)
			return data[--top];
		else
			throw new IllegalStateException("Stack empty");
	}
	
	public boolean isEmpty() {
		return top == 0;
	}
}
