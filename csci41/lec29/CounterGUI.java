// java's version of #include
import java.awt.event.*;
import javax.swing.*;

public class CounterGUI {
  // the actual Counter that we'll use to hold our state
  public static Counter c;

  public static void main(String[] args) {
    c = new Counter();

    // a JFrame is a window
    JFrame frame = new JFrame("Counter GUI"); // that's the title of the window
    // for some strange reason, clicking the X on the window doesn't
    // actually close that window unless you add the following line
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

    // a JPanel holds components
    JPanel panel = new JPanel();

    // a JTextField allows you to display text
    JTextField tf = new JTextField(3); // 3 characters wide
    tf.setEditable(false); // the user can't type in here--we'll fill it in programmatically
    tf.setText(Integer.toString(c.getCount())); // initially, tf holds "0"
    setFontSize(tf, 32); // make the font size 32 instead of the small default font

    JButton inc = new JButton("Increment");
    // IncClickHandler is a custom class that will run a function each
    // time inc is clicked
    IncClickHandler incClickHandler = new IncClickHandler(c, tf);
    inc.addActionListener(incClickHandler); // "install" the handler
    setFontSize(inc, 32);

    JButton reset = new JButton("Reset");
    // a muuuuuch easier way to handle clicks is to make an "anonymous
    // class" inline
    reset.addActionListener(new ActionListener() {
      public void actionPerformed(ActionEvent evt) {
        c.reset();
        tf.setText(Integer.toString(c.getCount()));
      }
    });
    setFontSize(reset, 32);

    // add all our stuff to the panel
    panel.add(tf);
    panel.add(inc);
    panel.add(reset);

    // add the panel to the window
    frame.getContentPane().add(panel);
    frame.pack(); // adjust the width/height of the window to the contents
    frame.setVisible(true);
  }

  // helper function to set a component's font size
  public static void setFontSize(JComponent jc, double newSize) {
    jc.setFont(jc.getFont().deriveFont((float) newSize));
  }
}

// Java has both "extends" and "implements"
// "implements" is for interfaces, which are kind of like abstract
// classes.
// To implement the ActionListener interface, you have to provide an
// actionPerformed method.
class IncClickHandler implements ActionListener {
  private Counter c;
  private JTextField tf;

  public IncClickHandler(Counter c, JTextField tf) {
    this.c = c;
    this.tf = tf;
  }

  // when the button gets clicked, this is the function that gets run
  public void actionPerformed(ActionEvent evt) {
    c.inc(); // increment the counter
    tf.setText(Integer.toString(c.getCount())); // reset the text to the new count
  }
}
