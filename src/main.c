/* Copyright 2017, Pablo Ridolfi, Juan Esteban Alarcón, Juan Manuel Cruz
 * All rights reserved.
 *
 * This file is part of Workspace.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from this
 *    software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 */
 
/** @brief This is a simple statechart example using Yakindu Statechart Tool
 * Plug-in (update site: http://updates.yakindu.org/sct/mars/releases/).
 */

/** \addtogroup statechart Simple UML Statechart example.
 ** @{ */

/*==================[inclusions]=============================================*/

#include "main.h"
#include "sapi.h"       // <= sAPI header

/* Include statechart header file. Be sure you run the statechart C code
 * generation tool!
 */
#include "Main_state_diagram.h"
#include "TimerTicks.h"


/*==================[macros and definitions]=================================*/
/* Compilation choices */
#define TEST_1 (1)

/* Select a compilation choise	*/
#define TEST (TEST_1)

#define TICKRATE_1MS	(1)				/* 1000 ticks per second */
#define TICKRATE_50MS	(50)			/* 20 ticks per second */
#define TICKRATE_MS		(TICKRATE_1MS)	/* 1000 ticks per second */

/*==================[internal data declaration]==============================*/

volatile bool SysTick_Time_Flag = false;

/*! This is a state machine */
static Main_state_diagram statechart;

/* Select a TimeEvents choise	*/
//#define __USE_TIME_EVENTS (false)	/* "false" without TimeEvents */
#define __USE_TIME_EVENTS (true)	/* or "true" with TimerEvents */

/*! This is a timed state machine that requires timer services */
#if (__USE_TIME_EVENTS == true)
	#define NOF_TIMERS (sizeof(Main_state_diagramTimeEvents)/sizeof(sc_boolean))
#else
	#define NOF_TIMERS 0
#endif

TimerTicks ticks[NOF_TIMERS];


/*==================[internal functions declaration]=========================*/

/*==================[internal data definition]===============================*/

/*==================[external data definition]===============================*/

/*==================[internal functions definition]==========================*/

/*==================[external functions definition]==========================*/

/*! \file This header defines prototypes for all functions that are required by the state machine implementation.

This is a state machine uses time events which require access to a timing service. Thus the function prototypes:
	- main_state_diagram_setTimer and
	- main_state_diagram_unsetTimer
are defined.

This state machine makes use of operations declared in the state machines interface or internal scopes. Thus the function prototypes:
	- main_state_diagramIface_opLED
are defined.

These functions will be called during a 'run to completion step' (runCycle) of the statechart.
There are some constraints that have to be considered for the implementation of these functions:
	- never call the statechart API functions from within these functions.
	- make sure that the execution time is as short as possible.

*/
/** state machine user-defined external function (action)
 *
 * @param handle state machine instance
 * @param LEDNumber number of LED
 * @param onoff state machine operation parameter
 */
void main_state_diagramIface_opLED(Main_state_diagram* handle, sc_integer LEDNumber, sc_boolean State)
{
	gpioWrite( (LEDR + LEDNumber), State);
}


/*!
 * This is a timed state machine that requires timer services
 */

#if (__USE_TIME_EVENTS == true)
/*! This function has to set up timers for the time events that are required by the state machine. */
/*!
	This function will be called for each time event that is relevant for a state when a state will be entered.
	\param evid An unique identifier of the event.
	\time_ms The time in milli seconds
	\periodic Indicates the the time event must be raised periodically until the timer is unset
*/
void main_state_diagram_setTimer(Main_state_diagram* handle, const sc_eventid evid, const sc_integer time_ms, const sc_boolean periodic)
{
	SetNewTimerTick(ticks, NOF_TIMERS, evid, time_ms, periodic);
}

/*! This function has to unset timers for the time events that are required by the state machine. */
/*!
	This function will be called for each time event taht is relevant for a state when a state will be left.
	\param evid An unique identifier of the event.
*/
void main_state_diagram_unsetTimer(Main_state_diagram* handle, const sc_eventid evid)
{
	UnsetTimerTick(ticks, NOF_TIMERS, evid);
}
#endif


/**
 * @brief	Hook on Handle interrupt from SysTick timer
 * @return	Nothing
 */
void myTickHook( void *ptr ){
	SysTick_Time_Flag = true;
}


#if (TEST == 0)	/* Test Statechart EDU-CIAA-NXP - Blink LED3
						#define __USE_TIME_EVENTS (false)
						rm main_state_diagram.sct
 	 	 	 	 	 	cp Blink.-sct main_state_diagram.sct 							 */
					/* Test Statechart EDU-CIAA-NXP - Blink TimeEvent LED3
						#define __USE_TIME_EVENTS (true)
 	 	 	 	 	 	rm main_state_diagram.sct
 	 	 	 	 	 	cp BlinkTimeEvent.-sct main_state_diagram.sct 					 */
/**
 * @brief	main routine for statechart example
 * @return	Function should not exit.
 */
int main(void)
{
	#if (__USE_TIME_EVENTS == true)
	uint32_t i;
	#endif

	/* Generic Initialization */
	boardConfig();

	/* Init Ticks counter => TICKRATE_MS */
	tickConfig( TICKRATE_MS );

	/* Add Tick Hook */
	tickCallbackSet( myTickHook, (void*)NULL );

	/* Statechart Initialization */
	#if (__USE_TIME_EVENTS == true)
	InitTimerTicks(ticks, NOF_TIMERS);
	#endif

	main_state_diagram_init(&statechart);
	main_state_diagram_enter(&statechart);

	/* LEDs toggle in main */
	while (1) {
		__WFI();

		if (SysTick_Time_Flag == true) {
			SysTick_Time_Flag = false;

			#if (__USE_TIME_EVENTS == true)
			UpdateTimers(ticks, NOF_TIMERS);
			for (i = 0; i < NOF_TIMERS; i++) {
				if (IsPendEvent(ticks, NOF_TIMERS, ticks[i].evid) == true) {

					main_state_diagram_raiseTimeEvent(&statechart, ticks[i].evid);	// Event -> Ticks.evid => OK
					MarkAsAttEvent(ticks, NOF_TIMERS, ticks[i].evid);
				}
			}
			#else
			main_state_diagramIface_raise_evTick(&statechart);					// Event -> evTick => OK
			#endif

			main_state_diagram_runCycle(&statechart);							// Run Cycle of Statechart
		}
	}
}
#endif


#if (TEST == 0)	/* Test Statechart EDU-CIAA-NXP - Idle Blink LED3
						#define __USE_TIME_EVENTS (true)
 	 	 	 	 	 	rm main_state_diagram.sct
 	 	 	 	 	 	cp IdleBlink.-sct main_state_diagram.sct 					 	 */
					/* Test Statechart EDU-CIAA-NXP - Button
						#define __USE_TIME_EVENTS (true)
 	 	 	 	 	 	rm main_state_diagram.sct
 	 	 	 	 	 	cp Button.-sct main_state_diagram.sct 							 */


uint32_t Buttons_GetStatus_(void) {
	uint8_t ret = false;

	if (gpioRead( TEC3 ) == 0)
		ret = true;

	return ret;
}

 /**
 * @brief	main routine for statechart example
 * @return	Function should not exit.
 */
int main(void)
{
#if (__USE_TIME_EVENTS == true)
	uint32_t i;
#endif

	uint32_t BUTTON_Status;

	/* Generic Initialization */
	boardConfig();

	/* Init Ticks counter => TICKRATE_MS */
	tickConfig( TICKRATE_MS );

	/* Add Tick Hook */
	tickCallbackSet( myTickHook, (void*)NULL );

	/* Statechart Initialization */
	#if (__USE_TIME_EVENTS == true)
	InitTimerTicks(ticks, NOF_TIMERS);
	#endif

	main_state_diagram_init(&statechart);
	main_state_diagram_enter(&statechart);

	/* LEDs toggle in main */
	while (1) {
		__WFI();

		if (SysTick_Time_Flag == true) {
			SysTick_Time_Flag = false;

			#if (__USE_TIME_EVENTS == true)
			UpdateTimers(ticks, NOF_TIMERS);
			for (i = 0; i < NOF_TIMERS; i++) {
				if (IsPendEvent(ticks, NOF_TIMERS, ticks[i].evid) == true) {

					main_state_diagram_raiseTimeEvent(&statechart, ticks[i].evid);	// Event -> Ticks.evid => OK
					MarkAsAttEvent(ticks, NOF_TIMERS, ticks[i].evid);
				}
			}
			#else
			main_state_diagramIface_raise_evTick(&statechart);					// Event -> evTick => OK
			#endif

		    BUTTON_Status = Buttons_GetStatus_();
			if (BUTTON_Status != 0)
				main_state_diagramIface_raise_evTECXOprimido(&statechart);		// Event -> evTECXOprimodo => OK
			else
				main_state_diagramIface_raise_evTECXNoOprimido(&statechart);	// Event -> evTECXNoOprimido => OK

			main_state_diagram_runCycle(&statechart);							// Run Cycle of Statechart
		}
	}
}
#endif


#if (TEST == TEST_1)	/* Test Statechart EDU-CIAA-NXP - IDE LPCXpresso - Application
						#define __USE_TIME_EVENTS (true)
 	 	 	 	 	 	rm main_state_diagram.sct
 	 	 	 	 	 	cp Application.-sct main_state_diagram.sct 								*/
					/* Test Statechart EDU-CIAA-NXP - IDE LPCXpresso - Portón
						#define __USE_TIME_EVENTS (true)
 	 	 	 	 	 	rm main_state_diagram.sct
 	 	 	 	 	 	cp Porton.-sct main_state_diagram.sct 							 		*/

uint32_t Buttons_GetStatus_(void) {
	uint8_t ret = false;
	uint32_t idx;

	for (idx = 0; idx < 4; ++idx) {
		if (gpioRead( TEC1 + idx ) == 0)
			ret |= 1 << idx;
	}
	return ret;
}

/**
 * @brief	main routine for statechart example
 * @return	Function should not exit.
 */
int main(void)
{
	#if (__USE_TIME_EVENTS == true)
	uint32_t i;
	#endif

	uint32_t BUTTON_Status;

	/* Generic Initialization */
	boardConfig();

	/* Init Ticks counter => TICKRATE_MS */
	tickConfig( TICKRATE_MS );

	/* Add Tick Hook */
	tickCallbackSet( myTickHook, (void*)NULL );

	/* Statechart Initialization */
	#if (__USE_TIME_EVENTS == true)
	InitTimerTicks(ticks, NOF_TIMERS);
	#endif

	main_state_diagram_init(&statechart);
	main_state_diagram_enter(&statechart);

	/* LEDs toggle in main */
	while (1) {
		__WFI();

		if (SysTick_Time_Flag == true) {
			SysTick_Time_Flag = false;

			#if (__USE_TIME_EVENTS == true)
			UpdateTimers(ticks, NOF_TIMERS);
			for (i = 0; i < NOF_TIMERS; i++) {
				if (IsPendEvent(ticks, NOF_TIMERS, ticks[i].evid) == true) {

					main_state_diagram_raiseTimeEvent(&statechart, ticks[i].evid);	// Event -> Ticks.evid => OK
					MarkAsAttEvent(ticks, NOF_TIMERS, ticks[i].evid);
				}
			}
			#else
			main_state_diagramIface_raise_evTick(&statechart);					// Event -> evTick => OK
			#endif

			BUTTON_Status = Buttons_GetStatus_();
			if (BUTTON_Status != 0)									// Event -> evTECXOprimodo => OK
				main_state_diagramIface_raise_evTECXOprimido(&statechart, BUTTON_Status);	// Value -> Tecla
			else													// Event -> evTECXNoOprimido => OK
				main_state_diagramIface_raise_evTECXNoOprimido(&statechart);

			main_state_diagram_runCycle(&statechart);							// Run Cycle of Statechart
		}
	}
}
#endif

/*==================[end of file]============================================*/
