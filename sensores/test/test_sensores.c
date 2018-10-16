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

Sensor_t sensor;

/* === Declaraciones de funciones internas ================================= */

/* === Definiciones de variables externas ================================== */

/* === Definiciones de funciones internas =================================- */

/* === Definiciones de funciones externas ================================== */


void setUp(void){

}


void tearDown(void){
	reset_variables_static();
}


void test_inicializa_hardware_normal_ds1(void){
	//TEST_FAIL_MESSAGE("Empezamos");

	unassignedProbe_ExpectAndReturn(27, 1);
	unassignedProbe_ExpectAndReturn(27, 0);

	uint8_t _segTrasmitirDatos = 20;
	uint8_t inicializar_hardware = sensor_inicializar_hardware( _segTrasmitirDatos );
	TEST_ASSERT_EQUAL( 0, inicializar_hardware );
}


void test_inicializa_hardware_falla_ds1(void){
	//TEST_FAIL_MESSAGE("Empezamos");

	unassignedProbe_ExpectAndReturn(27, 0);

	uint8_t _segTrasmitirDatos = 20;
	uint8_t inicializar_hardware = sensor_inicializar_hardware( _segTrasmitirDatos );
	TEST_ASSERT_EQUAL( 14, inicializar_hardware );
}


void test_inicializa_hardware_normal_ds1_sensor_chequear_fuera_de_tiempo(void){
	//TEST_FAIL_MESSAGE("Empezamos");

	unassignedProbe_ExpectAndReturn(27, 1);
	unassignedProbe_ExpectAndReturn(27, 0);

	uint8_t _segTrasmitirDatos = 20;
	uint8_t inicializar_hardware = sensor_inicializar_hardware( _segTrasmitirDatos );
	TEST_ASSERT_EQUAL( 0, inicializar_hardware );

	uint8_t segActuales = 19;
	uint8_t chequear = sensor_chequear( segActuales );
	TEST_ASSERT_EQUAL( 0, chequear );
}


void test_inicializa_hardware_normal_ds1_sensor_chequear_en_tiempo(void){
	//TEST_FAIL_MESSAGE("Empezamos");

	unassignedProbe_ExpectAndReturn(27, 1);
	unassignedProbe_ExpectAndReturn(27, 0);

	uint8_t _segTrasmitirDatos = 20;
	uint8_t inicializar_hardware = sensor_inicializar_hardware( _segTrasmitirDatos );
	TEST_ASSERT_EQUAL( 0, inicializar_hardware );

	convertTemperature_Expect( 0 );
	temperature_ExpectAndReturn(0, 5);

	uint8_t segActuales = 20;
	uint8_t chequear = sensor_chequear( segActuales );
	TEST_ASSERT_EQUAL( 1, chequear );

	int8_t leer_dato = sensor_leer_dato( &sensor );
	TEST_ASSERT_EQUAL( 1, leer_dato );
	TEST_ASSERT_EQUAL( 5, sensor.valor );
}


