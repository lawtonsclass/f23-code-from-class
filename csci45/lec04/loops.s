.global _start   // _start is a global label
_start:
  mov r0, #10

loopstart:
  cmp r0, #1
  blt done // this is the opposite of the loop condition--exit when this is true
  // loop body
  sub r0, r0, #1
  bal loopstart
done:


  ///////////////////////// 4x4 box of stars

  /*
    int i = 1;
    while (i <= 4) {
      int j = 1;
      while (j <= 4) {
        cout << '*';
        j++;
      }
      cout << '\n';
      i++;
    }
  */

  // let's put i in r4 and j in r5
  mov r4, #1
outerloop:
  cmp r4, #4
  bgt outerloopdone

  mov r5, #1
innerloop:
  cmp r5, #4
  bgt innerloopdone
  // print a single star
    mov r7, #4 // write syscall is #4
    mov r0, #1 // file #1 is stdout
    ldr r1, =star // addr of string goes in r1
    mov r2, #1 // # of chars to print from the string at the starting addr given in r1
    swi 0 // run the syscall I just set up
  // done printing star
  add r5, r5, #1
  bal innerloop
innerloopdone:
 // print newline
    mov r7, #4 // write syscall is #4
    mov r0, #1 // file #1 is stdout
    ldr r1, =newline // addr of string goes in r1
    mov r2, #1 // # of chars to print from the string at the starting addr given in r1
    swi 0 // run the syscall I just set up
  // done printing newline
  add r4, r4, #1
  bal outerloop
outerloopdone:

  // exit (0)
  mov r0, #0
  mov r7, #1   // move 1 into the register r7
  // 1 is the code for the "exit" system call
  swi 0  // hey Linux kernel, please execute the system call that I just set up!

.data
star: .ascii "*"
newline: .ascii "\n"
