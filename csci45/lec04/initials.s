.global _start   // _start is a global label
_start:
  mov r7, #4 // write syscall is #4
  mov r0, #1 // file #1 is stdout
  ldr r1, =prompt // addr of string goes in r1
  mov r2, #21 // # of chars to print from the string at the starting addr given in r1
  swi 0 // run the syscall I just set up

  // let's read from stdin
  mov r7, #3 // read syscall is #3
  mov r0, #0 // file #0 is stdin
  ldr r1, =initials // addr of string to write to goes in r1
  mov r2, #4 // we're getting 4 chars (3 initials and a newline)
  swi 0 // run the syscall I just set up

  // let's print what is stored in initials
  mov r7, #4 // write syscall is #4
  mov r0, #1 // file #1 is stdout
  ldr r1, =initials // addr of string goes in r1
  mov r2, #4 // # of chars to print from the string at the starting addr given in r1
  swi 0 // run the syscall I just set up

  // let's add dots to the correct spots in the initials_with_dots string
  
  // first addr to write to is &initials_with_dots
  ldr r0, =initials_with_dots
  // first addr to read from is &initials
  ldr r1, =initials
  ldrb r2, [r1] // r2 = *r1 (first char now in r2)
  strb r2, [r0] // *r0 = r2 (first char has been put in initials_with_dots)

  // next char to write to is r0 + 2
  add r0, r0, #2
  // next char to read from is r1 + 1
  add r1, r1, #1
  ldrb r2, [r1]
  strb r2, [r0]

  // next char to write to is r0 + 2
  add r0, r0, #2
  // next char to read from is r1 + 1
  add r1, r1, #1
  ldrb r2, [r1]
  strb r2, [r0]

  // let's print what is stored in initials_with_dots
  mov r7, #4 // write syscall is #4
  mov r0, #1 // file #1 is stdout
  ldr r1, =initials_with_dots // addr of string goes in r1
  mov r2, #7 // # of chars to print from the string at the starting addr given in r1
  swi 0 // run the syscall I just set up

  mov r0, #0
  mov r7, #1   // move 1 into the register r7
  // 1 is the code for the "exit" system call
  swi 0  // hey Linux kernel, please execute the system call that I just set up!

.data
prompt: .ascii "Enter your initials: "
initials: .ascii "XXXX" // room for 3 initials and a newline
initials_with_dots: .ascii "X.X.X.\n"
