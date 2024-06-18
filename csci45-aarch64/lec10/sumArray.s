.global sumArray
.type sumArray, %function
.func sumArray
sumArray:
  // int sumArray(int arr[], int size); 
  // arr is in r0
  // size is in r1

  mov r2, #0 // holds the sum

  // loop while size > 0
loop:
  cmp r1, #0
  ble done

  // body of the loop
  // add the current elem into sum
  ldr r3, [r0]
  add r2, r2, r3

  // advance pointer, decrement size
  add r0, r0, #4
  sub r1, r1, #1
  bal loop

done:

  // return the sum 
  mov r0, r2

  // return to lr
  mov pc, lr
