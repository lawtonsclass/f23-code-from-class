public class Counter {
  // there is no such thing as function/method declarations
  // you also can't say public: or private:
  //   (so you have to put public/private next to everything)

  // we'll need one field called count
  // count is private
  private int count;

  // constructor
  public Counter() {
    // set count to 0
    count = 0;
  }

  // we can't mark a method as const very easily in Java
  public int getCount() {
    return count;
  }

  public void inc() {
    count++;
  }

  // Java doesn't have default parameters, so you have to make two
  // separate reset methods
  public void reset() {
    count = 0;
  }

  public void reset(int newCount) {
    count = newCount;
  }

  // c.add(c2)
  public Counter add(Counter other) {
    int sumCount = count + other.count;
    Counter res = new Counter();
    res.reset(sumCount);
    return res;
  }

  public static void main(String[] args) {
    Counter c = new Counter(); 
    System.out.println(c.getCount()); // 0
    c.inc();
    c.inc();
    c.inc();
    System.out.println(c.getCount()); // 3
    c.reset();
    c.inc();
    c.inc();
    System.out.println(c.getCount()); // 2
    c.reset(42);
    c.inc();
    c.inc();
    c.inc();
    System.out.println(c.getCount()); // 45

    Counter c2 = new Counter();
    c2.inc();
    c2.inc();
    c2.inc();

    Counter c3 = c.add(c2);
    System.out.println(c3.getCount()); // 48
  }
}
