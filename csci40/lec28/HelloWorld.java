// In Java, everything is a class. If you just want a function, you
// need to put it inside a class. HelloWorld is public, so it's
// visible to the outside world--that means other people could import
// it and use it.
public class HelloWorld {
  // The main "function" lives inside the public class associated with
  // the file. You must use the definition below--args are the command
  // line arguments--even if you're not using the command line args.
  // In Java, args is array of Strings.
  // main is a public method inside the HelloWorld class
  // It's also "static", which means that it belongs to the class
  // itself, rather than to any object of the class.
  // You don't have to declare any functions/methods in Java--it just
  // finds them no matter what order you put them in.
  public static void main(String[] args) {
    System.out.println("Hello, world!"); 
  }
}
