.global _start
.global delay

_start:
	// 把外设的基地址告诉CPU
	ldr r0, =0x70000000
	orr r0, r0, #0x13
	mcr p15, 0, r0, c15, c2, 4

	// 关看门狗
	ldr r0, =0x7e004000
	mov r1, #0
	str r1, [r0]

	ldr sp, =0x0c002000

#ifdef ICACHE_OFF
	bic r0, r0, #0x00001000
#else
	orr r0, r0, #0x00001000
#endif

	mcr p15, 0, r0,c1,c0,0

	bl clock_init

	bl main


delay:
delay_loop:
	cmp r0, #02
	sub r0, r0, #1
	bne delay_loop
	mov pc, lr
halt:
	b halt
