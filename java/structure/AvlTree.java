package structure;

public class AvlTree<T extends Comparable<? super T>> {
    private static class AvlNode<T> {
        T element;               // The data in the node

        AvlNode<T> left;        // Left child

        AvlNode<T> right;       // Right child

        int height;              // Height

        AvlNode(T element) {
            this(element, null, null);
        }

        AvlNode(T element, AvlNode<T> le, AvlNode<T> re) {
            this.element = element;
            left = le;
            right = re;
            height = 0;
        }
    }

    private static final int ALLOWED_IMBLANCE = 1;

    private AvlNode<T> root;

    public AvlTree() {
        root = null;
    }

    /**
     * Insert into the tree; duplicates are ignored.
     * 
     * @param x the item to insert
     */
    public void insert(T x) {
        root = insert(x, root);
    }

    // Assume t is either balanced or within one of being balanced
    private AvlNode<T> balance(AvlNode<T> t) {
        if (t == null) {
            return t;
        }

        if (height(t.left) - height(t.right) > ALLOWED_IMBLANCE) {
            if (height(t.left.left) >= height(t.left.right)) {
                t = rotateWithLeftChild(t);
            } else {
                t = doubleWithLeftChild(t);
            }
        } else if (height(t.right) - height(t.left) > ALLOWED_IMBLANCE) {
            if (height(t.right.right) >= height(t.right.left)) {
                t = rotateWithRightChild(t);
            } else {
                t = doubleWithRightChild(t);
            }
        }
        t.height = updateHeight(t);
        return t;

    }

    /**
     * Return the height of node t, or -1, if null.
     */
    private int height(AvlNode<T> t) {
        return t == null ? -1 : t.height;
    }

    /**
     * Internal method to insert into a subtree.
     * 
     * @param x the item to insert
     * @param t the node that roots the subtree.
     * @return the new root of the subtree.
     *         AvlNode<T>
     */
    private AvlNode<T> insert(T x, AvlNode<T> t) {
        if (t == null) {
            return new AvlNode<>(x, null, null);
        }
        int compareResult = x.compareTo(t.element);
        if (compareResult < 0) {
            t.left = insert(x, t.left);
        } else if (compareResult > 0) {
            t.right = insert(x, t.right);
        } else {
            ; // Duplicate; do nothing
        }
        return balance(t);
    }

    /**
     * Rotate binary tree node with left child.
     * For AVL trees, this is a single rotation for left-left case.
     * Update heights, then return new root.
     */
    private AvlNode<T> rotateWithLeftChild(AvlNode<T> ori) {
        AvlNode<T> pivot = ori.left;
        ori.left = pivot.right;
        pivot.right = ori;
        ori.height = updateHeight(ori);
        pivot.height = updateHeight(pivot);
        return pivot;
    }

    /**
     * Rotate binary tree node with right child.
     * For AVL trees, this is a single rotation for right-right case.
     * Update heights, then return new root.
     */
    private AvlNode<T> rotateWithRightChild(AvlNode<T> ori) {
        AvlNode<T> pivot = ori.right;
        ori.right = pivot.left;
        pivot.left = ori;
        ori.height = updateHeight(ori);
        pivot.height = updateHeight(pivot);
        return pivot;
    }

    /**
     * Double rotate binary tree node: first right child
     * with its left child; then node ori with new right child.
     * For AVL trees, this is a double rotation for right-left case.
     * Update heights, then return new root.
     * @param ori
     * @return new root of subtree
     */
    private AvlNode<T> doubleWithRightChild(AvlNode<T> ori) {
        ori.right = rotateWithLeftChild(ori.right);
        return rotateWithRightChild(ori);
    }

    /**
     * Double rotate binary tree node: first left child
     * with its right child; then node ori with new left child.
     * For AVL trees, this is a double rotation for left-right case.
     * Update heights, then return new root.
     * @param ori
     * @return new root of subtree
     */
    private AvlNode<T> doubleWithLeftChild(AvlNode<T> ori) {
        ori.left = rotateWithRightChild(ori.left);
        return rotateWithLeftChild(ori);
    }

    /**
     * Internal methods to calculate a AvlNode's height after update.
     * updateHeight
     * 
     * @param node the AvlNode have been rotated.
     * @return
     *         int heights of the node.
     */
    private int updateHeight(AvlNode<T> node) {
        return Math.max(height(node.left), height(node.right)) + 1;
    }
}
