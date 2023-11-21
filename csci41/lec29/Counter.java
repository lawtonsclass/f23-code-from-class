// there are no method/function declarations in Java--you just start
// implementing!
public class Counter extends Object { // every class in java by
                                      // default extends Object
  // stores the actual count
  private int x;

  // Java has no default parameters, so you can't do something like:
  //   public Counter(int startingValue = 0) { ... }
  // You have to make two separate constructors

  public Counter() {
    x = 0;
  }

  public Counter(int startingValue) {
    x = startingValue;
  }

  public int getCount() {
    return x;
  }

  public void inc() {
    x++;
  }

  public void reset() {
    x = 0;
  }

  public void reset(int newValue) {
    x = newValue;
  }

  // Java has no operator overloading--you have to use words.
  // There are also no const parameters--you have to do some weird
  // tricks if you want to guarantee other doesn't get modified.
  public Counter add(Counter other) {
    Counter ret = new Counter(x + other.x);
    return ret;
  }

  public static void main(String[] args) {
    Counter c = new Counter();
    c.inc();
    c.inc();
    c.inc();
    System.out.println(c.getCount());

    Counter c2 = new Counter(42);
    c2.inc();
    System.out.println(c2.getCount());

    Counter c3 = c.add(c2);
    System.out.println(c3.getCount());
  }
}
