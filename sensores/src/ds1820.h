/*============================================================================
 * Autor:       Roberto Company
 * Fecha:       16/10/2018
 * Descripcion: Libreria .h 'ds1820'
 *===========================================================================*/


/* === Inclusiones de cabeceras ============================================ */
#include "stdint.h"


/* === Declaraciones de funciones externas ================================= */

int8_t	unassignedProbe    ( int8_t ds1_DATA_PIN );
void    convertTemperature ( int8_t idSensor     );
int8_t  temperature        ( int8_t idSensor     );
