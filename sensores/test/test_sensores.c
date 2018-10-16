/*============================================================================
 * Autor:       Roberto Company
 * Fecha:       16/10/2018
 * Descripcion: TEST de libreria .h 'sensores'
 *===========================================================================*/


/* === Inclusiones de cabeceras ============================================ */
#include "unity.h"
#include "sensores.h"
#include "mock_ds1820.h"

/* === Definicion y Macros ================================================= */

/* === Declaraciones de tipos de datos internos ============================ */

/* === Declaraciones de funciones internas ================================= */

/* === Definiciones de variables externas ================================== */

/* === Definiciones de funciones internas =================================- */

/* === Definiciones de funciones externas ================================== */


void setUp(void){
	
}

void tearDown(void){
	
}

void test_inicializa_hardware_normal_ds1(void){
	//TEST_FAIL_MESSAGE("Empezamos");

	unassignedProbe_ExpectAndReturn(27, 1);
	unassignedProbe_ExpectAndReturn(27, 0);

	uint8_t inicializar_hardware = sensor_inicializar_hardware( );
	TEST_ASSERT_EQUAL( 0, inicializar_hardware );
}


