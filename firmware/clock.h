/*
 * clock.h - part of USBasp
 *
 * Autor..........: Thomas Fischl <tfischl@gmx.de>
 * Description....: Provides functions for timing/waiting
 * Licence........: GNU GPL v2 (see Readme.txt)
 * Creation Date..: 2005-02-23
 * Last change....: 2006-11-16
 */

#ifndef __clock_h_included__
#define __clock_h_included__
#include <avr/io.h>
//#define F_CPU           12000000L   /* 12MHz */ Moved to Makefile
#define TIMERVALUE TCNT0
//#define CLOCK_T_320us	60
#define CLOCK_T_320us ((5 * F_CPU) / 1000000)

#ifdef __AVR_ATmega8__
#define TCCR0B TCCR0
#endif

/* set prescaler to 64 */
#define clockInit() TCCR0B = (1 << CS01) | (1 << CS00);

/* wait time * 320 us */
void clockWait(uint8_t time);

#endif /* __clock_h_included__ */
