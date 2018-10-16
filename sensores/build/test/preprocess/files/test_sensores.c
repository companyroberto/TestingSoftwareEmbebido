#include "build/temp/_test_sensores.c"
#include "mock_ds1820.h"
#include "sensores.h"
#include "unity.h"
void setUp(void){



}



void tearDown(void){



}



void test_inicializa_hardware_normal_ds1(void){





 unassignedProbe_CMockExpectAndReturn(37, 27, 1);

 unassignedProbe_CMockExpectAndReturn(38, 27, 0);



 uint8_t inicializar_hardware = sensor_inicializar_hardware( );

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((inicializar_hardware)), (

((void *)0)

), (UNITY_UINT)(41), UNITY_DISPLAY_STYLE_INT);

}
