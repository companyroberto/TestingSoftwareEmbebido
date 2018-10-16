#include "unity.h"
#include "sensores.h"


void setUp(void){
	
}

void tearDown(void){
	
}

void test_sensor_inicializar_hardware(void){
	//TEST_FAIL_MESSAGE("Empezamos");

	uint8_t inicializar_hardware = sensor_inicializar_hardware( );
	TEST_ASSERT_EQUAL( 0, inicializar_hardware );
}

void test_sensor_leer_dato(void){
	//TEST_FAIL_MESSAGE("Sensor");

	uint8_t dato_leido = sensor_leer_dato ( 1 );
	TEST_ASSERT_EQUAL( 5, dato_leido );
}

