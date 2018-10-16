#include "build/temp/_test_sensores.c"
#include "mock_ds1820.h"
#include "sensores.h"
#include "unity.h"










Sensor_t sensor;

void setUp(void){



}





void tearDown(void){

 reset_variables_static();

}





void test_inicializa_hardware_normal_ds1(void){





 unassignedProbe_CMockExpectAndReturn(41, 27, 1);

 unassignedProbe_CMockExpectAndReturn(42, 27, 0);



 uint8_t _segTrasmitirDatos = 20;

 uint8_t inicializar_hardware = sensor_inicializar_hardware( _segTrasmitirDatos );

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((inicializar_hardware)), (

((void *)0)

), (UNITY_UINT)(46), UNITY_DISPLAY_STYLE_INT);

}





void test_inicializa_hardware_falla_ds1(void){





 unassignedProbe_CMockExpectAndReturn(53, 27, 0);



 uint8_t _segTrasmitirDatos = 20;

 uint8_t inicializar_hardware = sensor_inicializar_hardware( _segTrasmitirDatos );

 UnityAssertEqualNumber((UNITY_INT)((14)), (UNITY_INT)((inicializar_hardware)), (

((void *)0)

), (UNITY_UINT)(57), UNITY_DISPLAY_STYLE_INT);

}





void test_inicializa_hardware_normal_ds1_sensor_chequear_fuera_de_tiempo(void){





 unassignedProbe_CMockExpectAndReturn(64, 27, 1);

 unassignedProbe_CMockExpectAndReturn(65, 27, 0);



 uint8_t _segTrasmitirDatos = 20;

 uint8_t inicializar_hardware = sensor_inicializar_hardware( _segTrasmitirDatos );

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((inicializar_hardware)), (

((void *)0)

), (UNITY_UINT)(69), UNITY_DISPLAY_STYLE_INT);



 uint8_t segActuales = 19;

 uint8_t chequear = sensor_chequear( segActuales );

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((chequear)), (

((void *)0)

), (UNITY_UINT)(73), UNITY_DISPLAY_STYLE_INT);

}





void test_inicializa_hardware_normal_ds1_sensor_chequear_en_tiempo(void){





 unassignedProbe_CMockExpectAndReturn(80, 27, 1);

 unassignedProbe_CMockExpectAndReturn(81, 27, 0);



 uint8_t _segTrasmitirDatos = 20;

 uint8_t inicializar_hardware = sensor_inicializar_hardware( _segTrasmitirDatos );

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((inicializar_hardware)), (

((void *)0)

), (UNITY_UINT)(85), UNITY_DISPLAY_STYLE_INT);



 convertTemperature_CMockExpect(87, 0);

 temperature_CMockExpectAndReturn(88, 0, 5);



 uint8_t segActuales = 20;

 uint8_t chequear = sensor_chequear( segActuales );

 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((chequear)), (

((void *)0)

), (UNITY_UINT)(92), UNITY_DISPLAY_STYLE_INT);



 int8_t leer_dato = sensor_leer_dato( &sensor );

 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((leer_dato)), (

((void *)0)

), (UNITY_UINT)(95), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((sensor.valor)), (

((void *)0)

), (UNITY_UINT)(96), UNITY_DISPLAY_STYLE_INT);

}
