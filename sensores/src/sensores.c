/*============================================================================
 * Autor:       Roberto Company
 * Fecha:       16/10/2018
 * Descripcion: Libreria .h 'sensores'
 *===========================================================================*/


/* === Inclusiones de cabeceras ============================================ */
#include "sensores.h"
#include "ds1820.h"
#include "stdio.h"

/* === Definicion y Macros ================================================= */

#define MAX_SENSORES    5
#define ds1_DATA_PIN    27


/* === Declaraciones de tipos de datos internos ============================ */

static int8_t ds1_num_devices = 0;
static Sensor_t sensor_conectado[MAX_SENSORES];


/* === Declaraciones de funciones internas ================================= */

void	sensor_inicializar( Sensor_t * Sensor, uint8_t pin  );


/* === Definiciones de variables externas ================================== */

static uint8_t nivelDebug = 1;

/* === Definiciones de funciones externas ================================== */


int8_t
sensor_inicializar_hardware(  )
{
    int8_t resultado = 14;                                                	// Error al inicializar hardware

    
    // Initialize the ds1 array to DS1820 objects
    while( unassignedProbe( ds1_DATA_PIN ) ) {
	sensor_inicializar( &sensor_conectado[ds1_num_devices], ds1_DATA_PIN );
        ds1_num_devices++;

        if (nivelDebug)
            printf("ds1: Found %d device(s)\r\n", ds1_num_devices);

        if (ds1_num_devices == MAX_SENSORES)
            break;
    }


    if (ds1_num_devices )
        resultado = 0;                                                    	// Algún sensor se configuro				

    return resultado;
}



/* === Definiciones de funciones internas =================================- */

void
sensor_inicializar
( Sensor_t * Sensor, uint8_t pin  )
{
    Sensor->IDSensor = ds1_num_devices;
    Sensor->pin = pin;
    Sensor->estado =  sinSensar;
    Sensor->valor = 0;
    Sensor->segTrasmitido = 0;
}

