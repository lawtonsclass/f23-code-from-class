.global _start   // _start is a global label
_start:
  mov x0, #10

loopstart:
  cmp x0, #1
  b.lt done // this is the opposite of the loop condition--exit when this is true
  // loop body
  sub x0, x0, #1
  b.al loopstart
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

  // let's put i in x4 and j in x5
  mov x4, #1
outerloop:
  cmp x4, #4
  b.gt outerloopdone

  mov x5, #1
innerloop:
  cmp x5, #4
  b.gt innerloopdone
  // print a single star
    mov x8, #64 // write syscall is #64
    mov x0, #1 // file #1 is stdout
    ldr x1, =star // addr of string goes in x1
    mov x2, #1 // # of chars to print from the string at the starting addr given in x1
    svc #0 // run the syscall I just set up
  // done printing star
  add x5, x5, #1
  b.al innerloop
innerloopdone:
 // print newline
    mov x8, #64 // write syscall is #64
    mov x0, #1 // file #1 is stdout
    ldr x1, =newline // addr of string goes in x1
    mov x2, #1 // # of chars to print from the string at the starting addr given in x1
    svc #0 // run the syscall I just set up
  // done printing newline
  add x4, x4, #1
  b.al outerloop
outerloopdone:

  // exit (0)
  mov x0, #0
  mov x8, #93   // move 93 into the register x8
  // 93 is the code for the "exit" system call
  svc #0  // hey Linux kernel, please execute the system call that I just set up!

.data
star: .ascii "*"
newline: .ascii "\n"
