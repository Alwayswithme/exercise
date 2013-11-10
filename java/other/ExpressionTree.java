package other;

import java.util.HashMap;


public class ExpressionTree {
  public static final Integer BUF_SIZE = 100;
  /* 低优先级运算符 */
  public static final Integer LOW_PRI_OP = 1;
  /* 高优先级运算符 */
  public static final Integer HIGH_PRI_OP = 2;
  /* 圆括号 */
  public static final Integer PAREN = 3;

  /* 运算符对照表 */
  public static HashMap<String, Integer> opTable = new HashMap<>();
  static {
    opTable.put("+", LOW_PRI_OP);
    opTable.put("-", LOW_PRI_OP);
    opTable.put("*", HIGH_PRI_OP);
    opTable.put("/", HIGH_PRI_OP);
    opTable.put("(", PAREN);
    opTable.put(")", PAREN);
  }
  /* 泛型栈的简单实现 */
  private static class Stack<T> {
    int top = 0;
    T[] buf;
    Stack() {
      buf = (T[])new Object[BUF_SIZE];
    }
    public void push(T item) {
      if (item == null)
        return;
      buf[top++] = item;
    }
    public T pop() {
      return (T)((top > 0) ? buf[--top] : null);
    }
  }
  /**
   * 将中缀表达式转换为后缀表达式
   * @param infix 以空格分割的中缀表达式
   * @return 逆波兰表达式
   */
  static String convert(String infix) {
    String[] input = infix.split(" ");
    StringBuilder output = new StringBuilder();
    String temp;
    Stack<String> opStack = new Stack<>(); // 运算符栈
    for (String str: input)
      if ( opTable.containsKey(str) ) { // 如果是运算符,进行处理
        Integer priority = opTable.get(str); // 获取当前运算符优先优先级
        if (priority == PAREN && ")".equals(str)) {
          // 输出运算符栈中与对应圆括号之间所有运算符
          while (!"(".equals(temp = opStack.pop()))
            output.append(temp).append(" ");
        } else {
          // 输出优先级比当前高或相等的运算符,并把当前运算符压入栈中
          for (temp = opStack.pop(); temp != null &&
              opTable.get(temp) != PAREN &&
              opTable.get(temp) >= priority; temp = opStack.pop())
            output.append(temp).append(" ");
          opStack.push(temp);
          opStack.push(str);
        }
      } else    // 不是运算符直接输出
        output.append(str).append(" ");

    // 取出运算符栈中所有运算符
    while (( temp = opStack.pop()) != null)
      output.append(temp).append(" ");
    return output.toString();
  }
  /**
   * 树的节点
   */
  private static class Node<T> {
		T element;
		Node<T> left;	// left child
		Node<T> right;	// right child
		Node(T theElement) {
			this(theElement, null, null);
		}
		Node(T theElement, Node<T> lt, Node<T> rt) {
			element = theElement;
			left = lt;
			right = rt;
		}
  }
  /**
   * 将后缀表达式转换为表达式树
   * @param postfix 要转换的后缀表达式
   */
static Node<String> expTree(String postfix) {
	String[] token = postfix.split(" ");
    Stack<Node<String>> nodeStack = new Stack<>(); // 节点栈
    for (String str: token) {
    	if (opTable.containsKey(str)) { // 遇到运算符,弹出两个元素生成子树
    		Node<String> rightNode = nodeStack.pop();
    		Node<String> leftNode = nodeStack.pop();
    		Node<String> temp = new Node<>(str, leftNode, rightNode);
    		nodeStack.push(temp);
    	} else
    		nodeStack.push(new Node<String>(str));
    }
    return nodeStack.pop();
}
  private static <T> void print(Node<T> t, int indent) {
	  if (t != null) {
			print(t.right, indent + 1);
			for (int i = 0; i < indent; i++)
				System.out.print("   ");
			System.out.println(t.element);
			print(t.left, indent+1);
	  }
  }

  public static void main(String[] args) {
	  System.out.println("=== inorder: ===");
	  String infix = "( a + ( b * c ) ) + ( ( ( d * e ) - f ) * g )";
	  System.out.println(infix+"\n=== postoreder: ===");
	  String postfix = convert(infix);
	  System.out.println(postfix+"\n=== 表达式树: ===");
	  Node<String> expTree = expTree(postfix);
	  print(expTree, 0);
  }
}
