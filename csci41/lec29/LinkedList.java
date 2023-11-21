public class LinkedList {
  public class Node {
    public int data;
    public Node next;
  }

  // first pointer (now a reference!)
  private Node first;

  public LinkedList() {
    first = null;
  }

  public Node getFirst() {
    return first;
  }

  public void push_back(int val) {
    if (first == null) {
      first = new Node();
      first.data = val;
      first.next = null;
    } else {
      // find the last node, and add to the end of it
      Node n = first;
      while (n.next != null) {
        n = n.next;
      }
      // n is the last node now
      Node newNode = new Node();
      newNode.data = val;
      newNode.next = null;
      n.next = newNode;
    }
  }

  public static void main(String[] args) {
    LinkedList l = new LinkedList(); // start out empty
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

    LinkedList.Node n = l.getFirst();
    while (n != null) {
      System.out.println(n.data);
      n = n.next;
    }
  }
}
