#include "build/temp/_test_sensores.c"
#include "mock_ds1820.h"
#include "sensores.h"
#include "unity.h"
void setUp(void){



}





void tearDown(void){

 reset_variables_static();

}





void test_inicializa_hardware_normal_ds1(void){





 unassignedProbe_CMockExpectAndReturn(39, 27, 1);

 unassignedProbe_CMockExpectAndReturn(40, 27, 0);



 uint8_t inicializar_hardware = sensor_inicializar_hardware( );

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((inicializar_hardware)), (

((void *)0)

), (UNITY_UINT)(43), UNITY_DISPLAY_STYLE_INT);

}





void test_inicializa_hardware_falla_ds1(void){





 unassignedProbe_CMockExpectAndReturn(50, 27, 0);



 uint8_t inicializar_hardware = sensor_inicializar_hardware( );

 UnityAssertEqualNumber((UNITY_INT)((14)), (UNITY_INT)((inicializar_hardware)), (

((void *)0)

), (UNITY_UINT)(53), UNITY_DISPLAY_STYLE_INT);

}
