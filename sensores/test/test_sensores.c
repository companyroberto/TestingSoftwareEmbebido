#include "unity.h"
#include "sensores.h"


void setUp(void){
	
}

void tearDown(void){
	
}

void test_sensor_inicializar_hardware(void){
	//TEST_FAIL_MESSAGE("Empezamos");
	uint8_t _segTrasmitirDatos   = 0;
	uint8_t inicializar_hardware = sensor_inicializar_hardware( _segTrasmitirDatos );
	TEST_ASSERT_EQUAL( 0, inicializar_hardware );
}
