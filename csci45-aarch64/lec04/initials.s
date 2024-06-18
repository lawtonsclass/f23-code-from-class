.global _start   // _start is a global label
_start:
  mov x8, #64 // write syscall is #64
  mov x0, #1 // file #1 is stdout
  ldr x1, =prompt // addr of string goes in x1
  mov x2, #21 // # of chars to print from the string at the starting addr given in x1
  svc #0 // run the syscall I just set up

  // let's read from stdin
  mov x8, #63 // read syscall is #63
  mov x0, #0 // file #0 is stdin
  ldr x1, =initials // addr of string to write to goes in x1
  mov x2, #4 // we're getting 4 chars (3 initials and a newline)
  svc #0 // run the syscall I just set up

  // let's print what is stored in initials
  mov x8, #64 // write syscall is #64
  mov x0, #1 // file #1 is stdout
  ldr x1, =initials // addr of string goes in x1
  mov x2, #4 // # of chars to print from the string at the starting addr given in x1
  svc #0 // run the syscall I just set up

  // let's add dots to the correct spots in the initials_with_dots string
  
  // first addr to write to is &initials_with_dots
  ldr x0, =initials_with_dots
  // first addr to read from is &initials
  ldr x1, =initials
  ldrb w2, [x1] // w2 = *x1 (first char now in x2)
  strb w2, [x0] // *x0 = w2 (first char has been put in initials_with_dots)

  // next char to write to is x0 + 2
  add x0, x0, #2
  // next char to read from is x1 + 1
  add x1, x1, #1
  ldrb w2, [x1]
  strb w2, [x0]

  // next char to write to is x0 + 2
  add x0, x0, #2
  // next char to read from is x1 + 1
  add x1, x1, #1
  ldrb w2, [x1]
  strb w2, [x0]

  // let's print what is stored in initials_with_dots
  mov x8, #64 // write syscall is #64
  mov x0, #1 // file #1 is stdout
  ldr x1, =initials_with_dots // addr of string goes in x1
  mov x2, #7 // # of chars to print from the string at the starting addr given in x1
  svc #0 // run the syscall I just set up

  mov x0, #0
  mov x8, #93   // move 93 into the register x8
  // 93 is the code for the "exit" system call
  svc #0  // hey Linux kernel, please execute the system call that I just set up!

.data
prompt: .ascii "Enter your initials: "
initials: .ascii "XXXX" // room for 3 initials and a newline
initials_with_dots: .ascii "X.X.X.\n"
