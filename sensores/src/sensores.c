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

#define MAX_SENSORES    5							// Establezco un máximo de 5 sensores por ds.
#define ds1_DATA_PIN    27


/* === Declaraciones de tipos de datos internos ============================ */

static int8_t ds1_num_devices = 0;
static Sensor_t sensor_conectado[MAX_SENSORES];
static uint8_t segTrasmitirDatos;


/* === Declaraciones de funciones internas ================================= */

void	sensor_inicializar( Sensor_t * Sensor, uint8_t pin  );


/* === Definiciones de variables externas ================================== */

static uint8_t nivelDebug = 1;

/* === Definiciones de funciones externas ================================== */


uint8_t
sensor_inicializar_hardware( uint8_t _segTrasmitirDatos )
{
    int8_t resultado = 14;                                                	// Error al inicializar hardware

    segTrasmitirDatos = _segTrasmitirDatos;
    
    // Initialize the ds1 array to DS1820 objects
    while( unassignedProbe( ds1_DATA_PIN ) ) {
	sensor_inicializar( &sensor_conectado[ds1_num_devices], ds1_DATA_PIN );
        ds1_num_devices++;

        if (nivelDebug)
            printf("ds1: Found %d device(s)\r\n", ds1_num_devices);

        if (ds1_num_devices == MAX_SENSORES)
            break;
    }

    if ( ds1_num_devices )
        resultado = 0;                                                    	// Algún sensor se configuro				

    return resultado;
}


uint8_t
sensor_chequear
( uint8_t segActuales )
{
    int8_t resultado = 0;                           				// No hay datos

    for (int i = 0; i < ds1_num_devices; i++){

        int8_t diferencia = (sensor_conectado[i].segTrasmitido > segActuales) ? sensor_conectado[i].segTrasmitido - segActuales : segActuales - sensor_conectado[i].segTrasmitido;

        if ( diferencia >= segTrasmitirDatos ){

            convertTemperature( sensor_conectado[i].IDSensor );
            sensor_conectado[i].valor = temperature( sensor_conectado[i].IDSensor );
            sensor_conectado[i].estado = Sensado;
            sensor_conectado[i].segTrasmitido = segActuales;
            resultado = 1;                          				// Hay datos
        }
    }

    return resultado;
}


int8_t
sensor_leer_dato
( Sensor_t * sensor )
{
    int8_t resultado = 0;                           // No hay datos

    int8_t i=0;
    while( i < ds1_num_devices ){
        if ( sensor_conectado[i].estado == Sensado ){
            sensor->IDSensor        = sensor_conectado[i].IDSensor;
            sensor->pin             = sensor_conectado[i].pin;
            sensor->estado          = sensor_conectado[i].estado;
            sensor->valor           = sensor_conectado[i].valor;
            sensor->segTrasmitido   = sensor_conectado[i].segTrasmitido;
            resultado = 1;                          // Hay datos

            sensor_conectado[i].estado = sinSensar;
            break;
        }
        i++;
    }
    //printf ("i = %d - resultado = %d \n\n", i, resultado);
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


/* === Definiciones de funciones de reinicio test =========================- */

void
reset_variables_static
( )
{
    ds1_num_devices   = 0;
    segTrasmitirDatos = 0;
}


