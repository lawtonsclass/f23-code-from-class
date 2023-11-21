// Java's version of #include
import javax.swing.*;
import java.awt.event.*;

public class CounterGUI {
  // we'll use a Counter under the hood to keep track of our GUI's
  // data
  // we don't have to import Counter--it's in the same folder and Java
  // sees it!
  // static fields are essentially global variables
  private static Counter c;

  public static void main(String[] args) {
    c = new Counter(); // this is our "database"

    // a JFrame is a window
    JFrame frame = new JFrame("Counter GUI"); // the argument is the title of the window
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    // because we want multiple things in our window, we need a
    // wrapper to hold all that stuff in order
    JPanel panel = new JPanel();

    // a JTextField lets you display text!
    JTextField tf = new JTextField(3); // 3 characters wide
    tf.setEditable(false); // don't let the user type in here--we'll programmatically fill this
    tf.setText(Integer.toString(c.getCount())); // give the text field the value of our Counter
    setFontSize(tf, 32); // make the font huge

    JButton inc = new JButton("Increment");
    setFontSize(inc, 32);
    // let's set up the "action" that gets performed whenever the
    // JButton is clicked
    inc.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent evt) {
        c.inc(); // increment the Counter
        tf.setText(Integer.toString(c.getCount()));
      }
    });

    JButton reset = new JButton("Reset");
    setFontSize(reset, 32);
    reset.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent evt) {
        c.reset(); // reset the Counter
        tf.setText(Integer.toString(c.getCount()));
      }
    });

    // add all our stuff to our panel
    panel.add(tf);
    panel.add(inc);
    panel.add(reset);

    // add the panel to the window
    frame.getContentPane().add(panel);
    frame.pack(); // resizes the window to fit the contents
    frame.setVisible(true);
  }

  public static void setFontSize(JComponent jc, double newSize) {
    jc.setFont(jc.getFont().deriveFont((float) newSize));
  }
}
