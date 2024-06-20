.global sumArray
.type sumArray, %function
sumArray:
  // int sumArray(int arr[], int size); 
  // arr is in x0
  // size is in w1

  mov w2, #0 // holds the sum

  // loop while size > 0
loop:
  cmp w1, #0
  b.le done

  // body of the loop
  // add the current elem into sum
  ldr w3, [x0]
  add w2, w2, w3

  // advance pointer, decrement size
  add x0, x0, #4
  sub w1, w1, #1
  b.al loop

done:

  // return the sum 
  mov w0, w2

  // return to lr
  ret
