package structure;

public class BinarySearchTree<T extends Comparable<? super T>> {
    private static class BinaryNode<T> {
        T element;
        BinaryNode<T> left; // left child
        BinaryNode<T> right; // right child

        BinaryNode(T theElement) {
            this(theElement, null, null);
        }

        BinaryNode(T theElement, BinaryNode<T> lt, BinaryNode<T> rt) {
            element = theElement;
            left = lt;
            right = rt;
        }
    }

    private BinaryNode<T> root;

    public BinarySearchTree() {
        root = null;
    }

    public void makeEmpty() {
        root = null;
    }

    public boolean isEmpty() {
        return root == null;
    }

    // overload
    public boolean contains(T x) {
        return contains(x, root);
    }

    public T findMin() {
        if (isEmpty())
            throw new UnderflowException("Tree is empty");
        return findMin(root).element;
    }

    public T findMax() {
        if (isEmpty())
            throw new UnderflowException("Tree is empty");
        return findMax(root).element;
    }

    public void insert(T x) {
        root = insert(x, root);
    }

    public void remove(T x) {
        root = remove(x, root);
    }

    /**
     * Internal method to find an item in a subtree
     * 
     * @param x
     *            is item to search for.
     * @param t
     *            the node that roots the subtree.
     * @return true if the item is found, false otherwise.
     */
    private boolean contains(T x, BinaryNode<T> t) {
        if (t == null)
            return false;
        int compareResult = x.compareTo(t.element);

        if (compareResult < 0)
            return contains(x, t.left);
        else if (compareResult > 0)
            return contains(x, t.right);
        else
            return true;
    }

    /**
     * Internal method to find the smallest item in a subtree.
     * 
     * @param t
     *            the node that roots the subtree.
     * @return node containing the smallest item.
     */
    private BinaryNode<T> findMin(BinaryNode<T> t) {
        // recursively
        if (t == null)
            return null;
        else if (t.left == null)
            return t;
        return findMin(t.left);
    }

    /**
     * Internal method to find the largest item in a subtree.
     * 
     * @param t
     *            the node that roots the subtree.
     * @return node containing the largest item.
     */
    private BinaryNode<T> findMax(BinaryNode<T> t) {
        // nonrecursively
        if (t != null)
            while (t.right != null)
                t = t.right;
        return t;
    }

    /**
     * Internal method to insert into a subtree.
     * 
     * @param x
     *            the item to insert.
     * @param t
     *            the node that roots the subtree.
     * @return the new root of the subtree.
     */
    private BinaryNode<T> insert(T x, BinaryNode<T> t) {
        if (t == null)
            return new BinaryNode<T>(x);
        int compareResult = x.compareTo(t.element);
        if (compareResult < 0)
            t.left = insert(x, t.left);
        else if (compareResult > 0)
            t.right = insert(x, t.right);
        else
            ; // Duplicate; do nothing
        return t;
    }

    /**
     * Internal method to remove from a subtree.
     * 
     * @param x
     *            the item to remove
     * @param t
     *            the node that roots the subtree.
     * @return the new root of the subtree.
     */
    private BinaryNode<T> remove(T x, BinaryNode<T> t) {
        if (t == null)
            return null;

        int compareResult = x.compareTo(t.element);

        if (compareResult < 0)
            t.left = remove(x, t.left);
        else if (compareResult > 0)
            t.right = remove(x, t.right);
        else if (t.left != null && t.right != null) {
            // Found the delete node and it got two children
            t.element = findMin(t.right).element;
            t.right = remove(t.element, t.right);
        } else
            // Found the delete node and it got one or zero children
            t = (t.left != null) ? t.left : t.right;
        return t;
    }

    /**
     * Print the tree contents in sorted order.
     */
    public void printTree() {
        if (isEmpty())
            System.out.println("Empty tree");
        else
            printTree(root);
    }

    /**
     * Internal method to print a subtree in sorted order.
     * 
     * @param t
     *            the node that roots the subtree.
     */
    private void printTree(BinaryNode<T> t) {
        if (t != null) {
            printTree(t.left);
            System.out.println(t.element);
            printTree(t.right);
        }
    }
}
