	.arch msp430g2553
	.p2align 1,0
	.text

	.global led_init
	.global led_update
	.extern P1OUT
	.extern P1DIR
	.extern LEDS


led_init:
	
