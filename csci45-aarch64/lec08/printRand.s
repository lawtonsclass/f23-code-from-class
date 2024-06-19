.global main
.type main, %function
main:
  sub sp, sp, #16
  str lr, [sp]
  str x19, [sp, #8]

  // srand(time(0))
  mov x0, #0
  bl time
  bl srand

  // print 50 random #s
  mov x19, #0 
  // needs to go in a saved register because the functions that we
  // call can clobber x0-x18. We have to save and restore the original
  // x19!!!
loop:
  cmp x19, #50
  b.ge done

  // call rand() and print the #
  bl rand
  // rand returns an int (so w0)

  // printf("%d\n", rand_result)
  mov w1, w0
  ldr x0, =fmt
  bl printf

  add x19, x19, #1
  b.al loop

done:
  mov w0, #0
  ldr lr, [sp]
  ldr x19, [sp, #8]
  add sp, sp, #16
  ret

.data
fmt: .asciz "%d\n"
