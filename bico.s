
.global read_sonar
.global read_sonars
.global register_proximity_callback
.global set_motor_speed
.global set_motors_speed
.global get_time
.global set_time
.global set_alarm

.text
.align 4

read_sonar:
  push {r7, lr}
  mov r7, #16
  svc 0x0
  pop {r7, lr}
  mov pc, lr

  @ Reads all sonars at once.
  @ Parameters:
  @ r0 - start: reading goes from this integer and
  @ r1 - end: reading goes until this integer (a range of sonars to be read)
  @ r2 - distances: pointer to array that must receive the distances.
  @ Returns:
  @   void
read_sonars:
  push {r4-r9, lr}
  mov r5, #0
  mov r6, r0      @r6 é o primeiro sonar a ser lido
  mov r8, r1
  mov r9, r2
laco:
  cmp r6, r8
  bgt fim
  mov r0, r6
  mov r7, #16
  svc 0x0
  mov r4, r5, lsl #2
  str r0, [r9, r4]
  add r5, r5, #1
  add r6, r6, #1
  b laco
fim:
  pop {r4-r9, lr}
  mov pc, lr


register_proximity_callback:
  push {r7, lr}
  mov r7, #17
  svc 0x0
  pop {r7, lr}
  mov pc, lr

set_motor_speed:
  push {r5-r7, lr}
  ldrb r5, [r0]
  ldrb r6, [r0, #1]
  mov r0, r5
  mov r1, r6
  mov r7, #18
  svc 0x0
  pop {r5-r7, lr}
  mov pc, lr

set_motors_speed:
  push {r4, r7, lr}
  ldrb r4, [r0]
  cmp r4, #0
  b na_ordem
inverte:
  ldrb r0, [r1, #1]
  ldrb r1, [r0, #1]
  mov r7, #19
  svc 0x0
  b final
na_ordem:
  ldrb r0, [r0, #1]
  ldrb r1, [r1, #1]
  mov r7, #19
  svc 0x0
final:
  pop {r4, r7, lr}
  mov pc, lr

get_time:
  push {r7-r8, lr}
  mov r8, r0
  mov r7, #20
  svc 0x0
  str r0, [r8]
  pop {r7-r8, lr}
  mov pc, lr

set_time:
  push {r7, lr}
  mov r7, #21
  svc 0x0
  pop {r7, lr}
  mov pc, lr

set_alarm:
  push {r7, lr}
  mov r7, #22
  svc 0x0
  pop {r7, lr}
  mov pc, lr
