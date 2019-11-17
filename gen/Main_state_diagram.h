/** Generated by YAKINDU Statechart Tools code generator. */

#ifndef MAIN_STATE_DIAGRAM_H_
#define MAIN_STATE_DIAGRAM_H_

#include "sc_types.h"

#ifdef __cplusplus
extern "C" { 
#endif 

/*! \file Header of the state machine 'main_state_diagram'.
*/

/*! Define number of states in the state enum */

#define MAIN_STATE_DIAGRAM_STATE_COUNT 14

/*! Define dimension of the state configuration vector for orthogonal states. */
#define MAIN_STATE_DIAGRAM_MAX_ORTHOGONAL_STATES 4

/*! Define maximum number of time events that can be active at once */
#define MAIN_STATE_DIAGRAM_MAX_PARALLEL_TIME_EVENTS 1

/*! Define indices of states in the StateConfVector */
#define SCVI_MAIN_STATE_DIAGRAM_TECX_NO_OPRIMIDO 0
#define SCVI_MAIN_STATE_DIAGRAM_TECX_DEBOUNCE 0
#define SCVI_MAIN_STATE_DIAGRAM_TECX_VALIDATION 0
#define SCVI_MAIN_STATE_DIAGRAM_TECX_OPRIMIDO 0
#define SCVI_MAIN_STATE_DIAGRAM_IDLE_ESPERA 1
#define SCVI_MAIN_STATE_DIAGRAM_PUERTA_ABIERTA 2
#define SCVI_MAIN_STATE_DIAGRAM_PUERTA_CERRADA 2
#define SCVI_MAIN_STATE_DIAGRAM_ESTARTSTOP_START 3
#define SCVI_MAIN_STATE_DIAGRAM_ESTARTSTOP_STOP 3
#define SCVI_MAIN_STATE_DIAGRAM_ESTARTSTOP_STOP_MODO_HORNO 3
#define SCVI_MAIN_STATE_DIAGRAM_ESTARTSTOP_STOP_MODO_GRILL 3
#define SCVI_MAIN_STATE_DIAGRAM_ESTARTSTOP_STOP_MODO_HORNO_Y_GRILL 3
#define SCVI_MAIN_STATE_DIAGRAM_ESTARTSTOP_STOP_MODO_INICIO_LED 3
#define SCVI_MAIN_STATE_DIAGRAM_ESTARTSTOP_INICIALIZACION 3

/*! Enumeration of all states */ 
typedef enum
{
	Main_state_diagram_last_state,
	Main_state_diagram_TECX_NO_OPRIMIDO,
	Main_state_diagram_TECX_DEBOUNCE,
	Main_state_diagram_TECX_VALIDATION,
	Main_state_diagram_TECX_OPRIMIDO,
	Main_state_diagram_IDLE_ESPERA,
	Main_state_diagram_PUERTA_Abierta,
	Main_state_diagram_PUERTA_Cerrada,
	Main_state_diagram_eStartStop_START,
	Main_state_diagram_eStartStop_STOP,
	Main_state_diagram_eStartStop_STOP_MODO_Horno,
	Main_state_diagram_eStartStop_STOP_MODO_Grill,
	Main_state_diagram_eStartStop_STOP_MODO_Horno_y_Grill,
	Main_state_diagram_eStartStop_STOP_MODO_INICIO_LED,
	Main_state_diagram_eStartStop_INICIALIZACION
} Main_state_diagramStates;

/*! Type definition of the data structure for the Main_state_diagramIface interface scope. */
typedef struct
{
	sc_boolean evTECXOprimido_raised;
	sc_integer evTECXOprimido_value;
	sc_boolean evTECXNoOprimido_raised;
	sc_integer tension;
	sc_integer frecuencia;
} Main_state_diagramIface;


/* Declaration of constants for scope Main_state_diagramIface. */
extern const sc_integer MAIN_STATE_DIAGRAM_MAIN_STATE_DIAGRAMIFACE_LEDR;
extern const sc_integer MAIN_STATE_DIAGRAM_MAIN_STATE_DIAGRAMIFACE_LEDG;
extern const sc_integer MAIN_STATE_DIAGRAM_MAIN_STATE_DIAGRAMIFACE_LEDB;
extern const sc_integer MAIN_STATE_DIAGRAM_MAIN_STATE_DIAGRAMIFACE_LED1;
extern const sc_integer MAIN_STATE_DIAGRAM_MAIN_STATE_DIAGRAMIFACE_LED2;
extern const sc_integer MAIN_STATE_DIAGRAM_MAIN_STATE_DIAGRAMIFACE_LED3;
extern const sc_boolean MAIN_STATE_DIAGRAM_MAIN_STATE_DIAGRAMIFACE_LED_ON;
extern const sc_boolean MAIN_STATE_DIAGRAM_MAIN_STATE_DIAGRAMIFACE_LED_OFF;
extern const sc_integer MAIN_STATE_DIAGRAM_MAIN_STATE_DIAGRAMIFACE_TEC1;
extern const sc_integer MAIN_STATE_DIAGRAM_MAIN_STATE_DIAGRAMIFACE_TEC2;
extern const sc_integer MAIN_STATE_DIAGRAM_MAIN_STATE_DIAGRAMIFACE_TEC3;
extern const sc_integer MAIN_STATE_DIAGRAM_MAIN_STATE_DIAGRAMIFACE_TEC4;
extern const sc_integer MAIN_STATE_DIAGRAM_MAIN_STATE_DIAGRAMIFACE_MODOHORNO;
extern const sc_integer MAIN_STATE_DIAGRAM_MAIN_STATE_DIAGRAMIFACE_MODOGRILL;
extern const sc_integer MAIN_STATE_DIAGRAM_MAIN_STATE_DIAGRAMIFACE_MODOHORNOYGRILL;


/*! Type definition of the data structure for the Main_state_diagramInternal interface scope. */
typedef struct
{
	sc_boolean siTECXOK_raised;
	sc_boolean siStart_raised;
	sc_boolean siStop_raised;
	sc_boolean siModo_raised;
	sc_boolean siPuerta_raised;
	sc_integer viTecla;
	sc_boolean viCerrada;
	sc_integer viModo;
} Main_state_diagramInternal;



/*! Type definition of the data structure for the Main_state_diagramTimeEvents interface scope. */
typedef struct
{
	sc_boolean main_state_diagram_TECX_DEBOUNCE_tev0_raised;
} Main_state_diagramTimeEvents;




/*! 
 * Type definition of the data structure for the Main_state_diagram state machine.
 * This data structure has to be allocated by the client code. 
 */
typedef struct
{
	Main_state_diagramStates stateConfVector[MAIN_STATE_DIAGRAM_MAX_ORTHOGONAL_STATES];
	sc_ushort stateConfVectorPosition; 
	
	Main_state_diagramIface iface;
	Main_state_diagramInternal internal;
	Main_state_diagramTimeEvents timeEvents;
} Main_state_diagram;



/*! Initializes the Main_state_diagram state machine data structures. Must be called before first usage.*/
extern void main_state_diagram_init(Main_state_diagram* handle);

/*! Activates the state machine */
extern void main_state_diagram_enter(Main_state_diagram* handle);

/*! Deactivates the state machine */
extern void main_state_diagram_exit(Main_state_diagram* handle);

/*! Performs a 'run to completion' step. */
extern void main_state_diagram_runCycle(Main_state_diagram* handle);

/*! Raises a time event. */
extern void main_state_diagram_raiseTimeEvent(Main_state_diagram* handle, sc_eventid evid);

/*! Raises the in event 'evTECXOprimido' that is defined in the default interface scope. */ 
extern void main_state_diagramIface_raise_evTECXOprimido(Main_state_diagram* handle, sc_integer value);

/*! Raises the in event 'evTECXNoOprimido' that is defined in the default interface scope. */ 
extern void main_state_diagramIface_raise_evTECXNoOprimido(Main_state_diagram* handle);

/*! Gets the value of the variable 'LEDR' that is defined in the default interface scope. */ 
extern sc_integer main_state_diagramIface_get_lEDR(const Main_state_diagram* handle);
/*! Gets the value of the variable 'LEDG' that is defined in the default interface scope. */ 
extern sc_integer main_state_diagramIface_get_lEDG(const Main_state_diagram* handle);
/*! Gets the value of the variable 'LEDB' that is defined in the default interface scope. */ 
extern sc_integer main_state_diagramIface_get_lEDB(const Main_state_diagram* handle);
/*! Gets the value of the variable 'LED1' that is defined in the default interface scope. */ 
extern sc_integer main_state_diagramIface_get_lED1(const Main_state_diagram* handle);
/*! Gets the value of the variable 'LED2' that is defined in the default interface scope. */ 
extern sc_integer main_state_diagramIface_get_lED2(const Main_state_diagram* handle);
/*! Gets the value of the variable 'LED3' that is defined in the default interface scope. */ 
extern sc_integer main_state_diagramIface_get_lED3(const Main_state_diagram* handle);
/*! Gets the value of the variable 'LED_ON' that is defined in the default interface scope. */ 
extern sc_boolean main_state_diagramIface_get_lED_ON(const Main_state_diagram* handle);
/*! Gets the value of the variable 'LED_OFF' that is defined in the default interface scope. */ 
extern sc_boolean main_state_diagramIface_get_lED_OFF(const Main_state_diagram* handle);
/*! Gets the value of the variable 'TEC1' that is defined in the default interface scope. */ 
extern sc_integer main_state_diagramIface_get_tEC1(const Main_state_diagram* handle);
/*! Gets the value of the variable 'TEC2' that is defined in the default interface scope. */ 
extern sc_integer main_state_diagramIface_get_tEC2(const Main_state_diagram* handle);
/*! Gets the value of the variable 'TEC3' that is defined in the default interface scope. */ 
extern sc_integer main_state_diagramIface_get_tEC3(const Main_state_diagram* handle);
/*! Gets the value of the variable 'TEC4' that is defined in the default interface scope. */ 
extern sc_integer main_state_diagramIface_get_tEC4(const Main_state_diagram* handle);
/*! Gets the value of the variable 'modoHorno' that is defined in the default interface scope. */ 
extern sc_integer main_state_diagramIface_get_modoHorno(const Main_state_diagram* handle);
/*! Gets the value of the variable 'modoGrill' that is defined in the default interface scope. */ 
extern sc_integer main_state_diagramIface_get_modoGrill(const Main_state_diagram* handle);
/*! Gets the value of the variable 'modoHornoYGrill' that is defined in the default interface scope. */ 
extern sc_integer main_state_diagramIface_get_modoHornoYGrill(const Main_state_diagram* handle);
/*! Gets the value of the variable 'tension' that is defined in the default interface scope. */ 
extern sc_integer main_state_diagramIface_get_tension(const Main_state_diagram* handle);
/*! Sets the value of the variable 'tension' that is defined in the default interface scope. */ 
extern void main_state_diagramIface_set_tension(Main_state_diagram* handle, sc_integer value);
/*! Gets the value of the variable 'frecuencia' that is defined in the default interface scope. */ 
extern sc_integer main_state_diagramIface_get_frecuencia(const Main_state_diagram* handle);
/*! Sets the value of the variable 'frecuencia' that is defined in the default interface scope. */ 
extern void main_state_diagramIface_set_frecuencia(Main_state_diagram* handle, sc_integer value);

/*!
 * Checks whether the state machine is active (until 2.4.1 this method was used for states).
 * A state machine is active if it was entered. It is inactive if it has not been entered at all or if it has been exited.
 */
extern sc_boolean main_state_diagram_isActive(const Main_state_diagram* handle);

/*!
 * Checks if all active states are final. 
 * If there are no active states then the state machine is considered being inactive. In this case this method returns false.
 */
extern sc_boolean main_state_diagram_isFinal(const Main_state_diagram* handle);

/*! Checks if the specified state is active (until 2.4.1 the used method for states was called isActive()). */
extern sc_boolean main_state_diagram_isStateActive(const Main_state_diagram* handle, Main_state_diagramStates state);


#ifdef __cplusplus
}
#endif 

#endif /* MAIN_STATE_DIAGRAM_H_ */
