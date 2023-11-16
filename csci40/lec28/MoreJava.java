public class MoreJava {
  public static void main(String[] args) {
    int x = 42;
    double y = 3.14;
    boolean b = true;
    String s = "hi mom";

    // arrays must be made on the heap
    // the [] goes after the type
    // all arrays in Java know their size! (arr.length)
    int[] arr = new int[]{1, 2, 3};

    for (int i = 0; i < arr.length; i++) {
      System.out.println(arr[i]);
    }

    // no delete is necessary!!! Java takes of deletion for you.
    // It notices when we're finished with heap memory and "garbage
    // collects" it.
  }
}
