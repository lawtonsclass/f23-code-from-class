// In each java file, there is a public class. That class must be the
// same name as the file

public class HelloWorld {
  // java programs also have main functions, and they always take the
  // command line arguments
  // Array types use the []s next to the name of the type
  // So "String[]" means "String array"

  // main is a static method, which means it belongs to the class and
  // acts like a function
  // this "function" is part of the class itself, and not part of any of its objects

  // you have to say public/private/etc. each time you define something
  public static void main(String[] args) {
    // System.out lives inside of java.lang
    // java.lang.System.out
    System.out.println("Hello, world!");

    int i = 0;
    i++;
    System.out.println(i);

    int[] arr = new int[] {1, 2, 3};
    // arrays in Java know their length!!!
    for (int j = 0; j < arr.length; j++) {
      System.out.println(arr[j]);
    }
  }
}
