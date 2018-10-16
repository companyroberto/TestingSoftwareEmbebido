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

typedef struct sensores_s {
	int8_t   _convertTemperature_Expect;					// idSensor
	int8_t   _temperature_Expect;						// idSensor
	int8_t   _temperature_Return;						// Valor leido por sensor
	int8_t   _leer_dato;							// 1 = Hay Datos | 0 = No hay datos
	uint16_t _valor;							// Valor leido por sensor
} Sensores_t;

Sensores_t sensores[2];

/* === Declaraciones de funciones internas ================================= */

/* === Definiciones de variables externas ================================== */

/* === Definiciones de funciones internas =================================- */

/* === Definiciones de funciones externas ================================== */


void setUp(void){
	sensores[0]._convertTemperature_Expect	= 0;
	sensores[0]._temperature_Expect		= 0;
	sensores[0]._temperature_Return		= 5;
	sensores[0]._leer_dato			= 1;
	sensores[0]._valor			= 5;

	sensores[1]._convertTemperature_Expect	= 1;
	sensores[1]._temperature_Expect		= 1;
	sensores[1]._temperature_Return		= 6;
	sensores[1]._leer_dato			= 1;
	sensores[1]._valor			= 6;
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


void test_inicializa_hardware_normal_ds1_sensor_chequear_varios_en_tiempo(void){
	//TEST_FAIL_MESSAGE("Empezamos");

	unassignedProbe_ExpectAndReturn(27, 2);
	unassignedProbe_ExpectAndReturn(27, 1);
	unassignedProbe_ExpectAndReturn(27, 0);

	uint8_t _segTrasmitirDatos = 20;
	uint8_t inicializar_hardware = sensor_inicializar_hardware( _segTrasmitirDatos );
	TEST_ASSERT_EQUAL( 0, inicializar_hardware );

	for(uint8_t indice = 0; indice < sizeof(sensores) / sizeof( Sensores_t ); indice++) {
		convertTemperature_Expect( sensores[indice]._convertTemperature_Expect );
		temperature_ExpectAndReturn( sensores[indice]._temperature_Expect, sensores[indice]._temperature_Return);
	}

	uint8_t segActuales = 20;
	uint8_t chequear = sensor_chequear( segActuales );
	TEST_ASSERT_EQUAL( 1, chequear );

	for(uint8_t indice = 0; indice < sizeof(sensores) / sizeof( Sensores_t ); indice++) {
		int8_t leer_dato = sensor_leer_dato( &sensor );
		TEST_ASSERT_EQUAL( sensores[indice]._leer_dato, leer_dato );
		TEST_ASSERT_EQUAL( sensores[indice]._valor, sensor.valor );
	}
}

