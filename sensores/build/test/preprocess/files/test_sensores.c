#include "build/temp/_test_sensores.c"
#include "sensores.h"
#include "unity.h"




void setUp(void){



}



void tearDown(void){



}



void test_sensor_inicializar_hardware(void){





 uint8_t inicializar_hardware = sensor_inicializar_hardware( );

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((inicializar_hardware)), (

((void *)0)

), (UNITY_UINT)(17), UNITY_DISPLAY_STYLE_INT);

}



void test_sensor_leer_dato(void){





 uint8_t dato_leido = sensor_leer_dato ( 1 );

 UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((dato_leido)), (

((void *)0)

), (UNITY_UINT)(24), UNITY_DISPLAY_STYLE_INT);

}
