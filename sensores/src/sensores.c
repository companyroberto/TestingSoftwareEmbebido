#include "sensores.h"
#include "ds1820.h"
#include "ds1820.c"	// no me funciona mock_ds1820.h

#define MAX_SENSORES    5
#define ds1_DATA_PIN    27

int8_t ds1_num_devices = 0;


int8_t
sensor_inicializar_hardware( )
{
    int8_t resultado = 14;                                                // Error al inicializar hardware

    
    // Initialize the ds1 array to DS1820 objects
    while( unassignedProbe( ds1_DATA_PIN ) ) {
        ds1_num_devices++;
        if (ds1_num_devices == MAX_SENSORES)
            break;
    }

    // num_devices == 0, la siguiente instruccion es bloqueante
    if (ds1_num_devices > 0 )        
        convertTemperature( ds1_num_devices );

    if (ds1_num_devices )
        resultado = 0;                                                    // Algún sensor se configuro				

    return resultado;
}

int8_t
sensor_leer_dato( int8_t _idSensor )
{
    convertTemperature ( _idSensor );
    return temperature ( _idSensor );
}
