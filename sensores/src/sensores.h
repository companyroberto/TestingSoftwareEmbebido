/*============================================================================
 * Autor:       Roberto Company
 * Fecha:       16/10/2018
 * Descripcion: Libreria .h 'sensores'
 *===========================================================================*/


/* === Inclusiones de cabeceras ============================================ */
#include "stdint.h"


/* === Definicion y Macros ================================================= */

enum sensor_modo {
    Sensado = 1,
    sinSensar = 2
};

typedef struct {
    uint8_t IDSensor;                    // 0, 1, 2...
    uint8_t pin;                         // gpioMap_t pin;
    uint8_t estado;                      // Sensado = Hay Datos / Sin Sensar = No hay datos.
    uint16_t valor;                      // 30 = 30 grados Centigrados.
    uint8_t segTrasmitido;               // Segundos de reloj al momento de trasmitir.
} Sensor_t;


/* === Declaraciones de funciones externas ================================= */

int8_t	sensor_inicializar_hardware( );
int8_t  sensor_leer_dato           ( int8_t _idSensor           );
void	reset_variables_static     ( );
