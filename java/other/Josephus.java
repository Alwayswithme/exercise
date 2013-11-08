package other;

import java.util.LinkedList;
import java.util.ListIterator;

public class Josephus {

	private static final int N = 67;
	private static final int FIRST = 1;
	private static final int STEP = 6;
	public static void main(String[] args) {
		int peopleNumber = N;
		int start = FIRST, count = STEP;
		CycleLinkedList c = new CycleLinkedList(peopleNumber);
		c.setCount(count);
		c.setStart(start);
		c.play();
		josephus();
	}
	// another solve
	public static void josephus() {
		LinkedList<Integer> total = new LinkedList<Integer>();
		int last=0;
		
		for (int i = 0; i < N; i++) {
			total.add(i+1);
		}
		ListIterator<Integer> it = total.listIterator();
		while(it.next() !=FIRST) 
			;
		it.previous();
		while (it.hasNext() || it.hasPrevious()) {
			for (int i = 0; i< STEP; i++) {
				if (it.hasNext()) {
					last = it.next();
				}else {
					while(it.hasPrevious())
						it.previous();
					last = it.next();
				}
			}

			//System.out.printf("%d is out \n", last);
			it.remove();
		}
		System.out.println("last one is " + last);
	}
	
}
class CycleLinkedList {
	// the one  start to count
	int start;
	
	int count;
	
	int length;
	
	People cursor;
	
	People first;
	
	public CycleLinkedList(int len) {
		length = len;
		for (int i = 1; i <= len; i++) {
			People p = new People();
			if (i == 1) {
				first = p;
				cursor = first;
				continue;
			} else if (i == len) {
				p.next = first;
				first.prev = p;
			} 
			p.prev = cursor;
			cursor.next = p;
			cursor = p;
		}
	}
	public void play() {
		//find start people
		cursor = first;
		while(cursor.id != start) {
			cursor = cursor.next;
		}
		while(length > 1) {
			for(int i = 0; i < count-1; i++){ 
				cursor = cursor.next;
			}
			//System.out.printf("%d is out \n", cursor.id);
			length--;
			cursor.prev.next = cursor.next;
			cursor.next.prev = cursor.prev;
			cursor = cursor.next;
		}
		System.out.printf("last one is %d\n", cursor.id);
	}
	public void setStart(int start) {
		this.start = start;
	}
	public void setCount(int count) {
		this.count = count;
	}

}
class People {
	People next;
	People prev;
	int id;
	public static int count = 0;
	public People() {
		id = ++count;
	}
}