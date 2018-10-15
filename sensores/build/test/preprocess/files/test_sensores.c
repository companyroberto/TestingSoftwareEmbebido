#include "build/temp/_test_sensores.c"
#include "sensores.h"
#include "unity.h"




void setUp(void){



}



void tearDown(void){



}



void test_sensor_inicializar_hardware(void){



 uint8_t _segTrasmitirDatos = 0;

 uint8_t inicializar_hardware = sensor_inicializar_hardware( _segTrasmitirDatos );

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((inicializar_hardware)), (

((void *)0)

), (UNITY_UINT)(17), UNITY_DISPLAY_STYLE_INT);

}
