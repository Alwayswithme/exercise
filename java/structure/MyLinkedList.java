package structure;

import java.util.ListIterator;

public class MyLinkedList<T> implements Iterable<T> {
	private int theSize;
	private int modCount = 0;
	private Node<T> beginMarker;
	private Node<T> endMarker;
	private static class Node<T> {
		public T data;
		public Node<T> prev;
		public Node<T> next;
		public Node(T d, Node<T> p, Node<T> n) {
			data = d;
			prev = p;
			next = n;
		}
	}

	public MyLinkedList() {
		doClear();
	}
	public void clear() {
		doClear();
	}
	private void doClear() {
		beginMarker = new Node<T>( null, null, null );
		endMarker = new Node<T>( null, beginMarker, null );
		beginMarker.next = endMarker;
		theSize = 0;
		modCount++;
	}
	public int size() {
		return theSize;
	}
	public boolean isEmpty() {
		return size() == 0;
	}
	public boolean add(T x) {
		add(size(), x);
		return true;
	}
	public void add(int idx, T x) {
		addBefore(getNode(idx, 0, size()), x);
	}
	public T get(int idx) {
		return getNode(idx).data;
	}
	public T set(int idx, T newVal) {
		Node<T> p = getNode(idx);
		T oldVal = p.data;
		p.data = newVal;
		return oldVal;
	}
	public T remove(int idx) {
		return remove(getNode(idx));
	}
	private class LinkedListIterator implements ListIterator<T> {
		private Node<T> lastReturned = null;
		private Node<T> current;
		private int expectedModCount = modCount;
		private int index;
		private boolean okToRemove = false;
		public boolean hasNext() {
			return current != endMarker;
		}
		LinkedListIterator(int idx) {
			index = idx;
			current = getNode(idx);
		}
		public T next() {
			checkModification();
			if ( !hasNext() )
				throw new java.util.NoSuchElementException();
			lastReturned = current;
			current = current.next;
			okToRemove = true;
			index++;
			return lastReturned.data;
		}

		public void remove() {
			checkModification();
			if ( !okToRemove )
				throw new IllegalStateException();
			MyLinkedList.this.remove( current.prev);
			expectedModCount++;
			okToRemove = false;
		}
		@Override
		public boolean hasPrevious() {
			return current != beginMarker;
		}
		@Override
		public T previous() {
			checkModification();
			if ( !hasPrevious() )
				throw new java.util.NoSuchElementException();
			lastReturned = current = (current == beginMarker.next)? endMarker.prev:current.prev;
			okToRemove = true;
			index--;
			return lastReturned.data;
		}
		@Override
		public int nextIndex() {
			return index;
		}
		@Override
		public int previousIndex() {
			return index-1;
		}
		@Override
		public void set(T e) {
            if (lastReturned == null)
                throw new IllegalStateException();
            checkModification();
            lastReturned.data = e;
		}
		@Override
		public void add(T e) {
			checkModification();
            lastReturned = null;
            if(current == null)
            	add(e);
            else
            	addBefore(getNode(index), e);
            index++;
            expectedModCount++;
			
		}
		final void checkModification() {
			if (modCount != expectedModCount)
				throw new java.util.ConcurrentModificationException();
		}
	}
	public ListIterator<T> iterator() {
		return new LinkedListIterator(0);
	}
	/**
	 * Adds an item to this collection, at specified position p.
	 * Items at or after that position are sild on position higher.
	 * @param p Node to add before
	 * @param x any Object.
	 * @throws IndexOutOfBoundsException if idx is not between 0 and size(),.
	 */
	private void addBefore( Node<T> p, T x) {
		p.prev = p.prev.next = new Node<T>(x, p.prev, p);
		theSize++;
		modCount++;
	}
	/**
	 * Removes the object contained in Node p.
	 * @param p the Node containing the object.
	 * @return the item was removed from the collection.
	 */
	private T remove( Node<T> p) {
		p.next.prev = p.prev;
		p.prev.next = p.next;
		theSize--;
		modCount++;
		return p.data;
	}
	/**
	 * Gets the Node at position idx, which must range from 0 to size() - 1.
	 * @param idx index to search at.
	 * @return internal node corresponding to idx.
	 * @throws IndexOutOfBoundsException if idx is not
	 *         between 0 and size() - 1, inclusive.
	 */
	private Node<T> getNode( int idx ) {
		return getNode( idx, 0, size() -1);
	}
	/**
	 * Gets the Node at position idx, which must range form lower to upper.
	 * @param idx index to search at.
	 * @param lower lowest valid index.
	 * @param upper highest valid index.
	 * @return internal node corresponding to idx.
	 * @throws IndexOutOfBoundsException if idx is not
	 *		   between lower and upper, inclusive.
	 */
	private Node<T> getNode(int idx, int lower, int upper ){
		Node<T> p;
		if (idx < lower || idx > upper)
			throw new IndexOutOfBoundsException();
		if (idx < size() / 2) {
			p = beginMarker.next;
			for ( int i = 0; i < idx; i++)
				p = p.next;
		} else {
			p = endMarker;
			for ( int i = size(); i > idx; i--)
				p = p.prev;
		}
		return p;
	}

}