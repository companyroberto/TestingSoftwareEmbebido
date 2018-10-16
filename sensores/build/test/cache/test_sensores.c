#include "build/temp/_test_sensores.c"
#include "mock_ds1820.h"
#include "sensores.h"
#include "unity.h"










Sensor_t sensor;



typedef struct sensores_s {

 int8_t _convertTemperature_Expect;

 int8_t _temperature_Expect;

 int8_t _temperature_Return;

 int8_t _leer_dato;

 uint16_t _valor;

} Sensores_t;



Sensores_t sensores[2];

void setUp(void){

 sensores[0]._convertTemperature_Expect = 0;

 sensores[0]._temperature_Expect = 0;

 sensores[0]._temperature_Return = 5;

 sensores[0]._leer_dato = 1;

 sensores[0]._valor = 5;



 sensores[1]._convertTemperature_Expect = 1;

 sensores[1]._temperature_Expect = 1;

 sensores[1]._temperature_Return = 6;

 sensores[1]._leer_dato = 1;

 sensores[1]._valor = 6;

}





void tearDown(void){

 reset_variables_static();

}





void test_inicializa_hardware_normal_ds1(void){





 unassignedProbe_CMockExpectAndReturn(61, 27, 1);

 unassignedProbe_CMockExpectAndReturn(62, 27, 0);



 uint8_t _segTrasmitirDatos = 20;

 uint8_t inicializar_hardware = sensor_inicializar_hardware( _segTrasmitirDatos );

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((inicializar_hardware)), (

((void *)0)

), (UNITY_UINT)(66), UNITY_DISPLAY_STYLE_INT);

}





void test_inicializa_hardware_falla_ds1(void){





 unassignedProbe_CMockExpectAndReturn(73, 27, 0);



 uint8_t _segTrasmitirDatos = 20;

 uint8_t inicializar_hardware = sensor_inicializar_hardware( _segTrasmitirDatos );

 UnityAssertEqualNumber((UNITY_INT)((14)), (UNITY_INT)((inicializar_hardware)), (

((void *)0)

), (UNITY_UINT)(77), UNITY_DISPLAY_STYLE_INT);

}





void test_inicializa_hardware_normal_ds1_sensor_chequear_fuera_de_tiempo(void){





 unassignedProbe_CMockExpectAndReturn(84, 27, 1);

 unassignedProbe_CMockExpectAndReturn(85, 27, 0);



 uint8_t _segTrasmitirDatos = 20;

 uint8_t inicializar_hardware = sensor_inicializar_hardware( _segTrasmitirDatos );

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((inicializar_hardware)), (

((void *)0)

), (UNITY_UINT)(89), UNITY_DISPLAY_STYLE_INT);



 uint8_t segActuales = 19;

 uint8_t chequear = sensor_chequear( segActuales );

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((chequear)), (

((void *)0)

), (UNITY_UINT)(93), UNITY_DISPLAY_STYLE_INT);

}





void test_inicializa_hardware_normal_ds1_sensor_chequear_en_tiempo(void){





 unassignedProbe_CMockExpectAndReturn(100, 27, 1);

 unassignedProbe_CMockExpectAndReturn(101, 27, 0);



 uint8_t _segTrasmitirDatos = 20;

 uint8_t inicializar_hardware = sensor_inicializar_hardware( _segTrasmitirDatos );

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((inicializar_hardware)), (

((void *)0)

), (UNITY_UINT)(105), UNITY_DISPLAY_STYLE_INT);



 convertTemperature_CMockExpect(107, 0);

 temperature_CMockExpectAndReturn(108, 0, 5);



 uint8_t segActuales = 20;

 uint8_t chequear = sensor_chequear( segActuales );

 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((chequear)), (

((void *)0)

), (UNITY_UINT)(112), UNITY_DISPLAY_STYLE_INT);



 int8_t leer_dato = sensor_leer_dato( &sensor );

 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((leer_dato)), (

((void *)0)

), (UNITY_UINT)(115), UNITY_DISPLAY_STYLE_INT);

 UnityAssertEqualNumber((UNITY_INT)((5)), (UNITY_INT)((sensor.valor)), (

((void *)0)

), (UNITY_UINT)(116), UNITY_DISPLAY_STYLE_INT);

}





void test_inicializa_hardware_normal_ds1_sensor_chequear_varios_en_tiempo(void){





 unassignedProbe_CMockExpectAndReturn(123, 27, 2);

 unassignedProbe_CMockExpectAndReturn(124, 27, 1);

 unassignedProbe_CMockExpectAndReturn(125, 27, 0);



 uint8_t _segTrasmitirDatos = 20;

 uint8_t inicializar_hardware = sensor_inicializar_hardware( _segTrasmitirDatos );

 UnityAssertEqualNumber((UNITY_INT)((0)), (UNITY_INT)((inicializar_hardware)), (

((void *)0)

), (UNITY_UINT)(129), UNITY_DISPLAY_STYLE_INT);



 for(uint8_t indice = 0; indice < sizeof(sensores) / sizeof( Sensores_t ); indice++) {

  convertTemperature_CMockExpect(132, sensores[indice]._convertTemperature_Expect);

  temperature_CMockExpectAndReturn(133, sensores[indice]._temperature_Expect, sensores[indice]._temperature_Return);

 }



 uint8_t segActuales = 20;

 uint8_t chequear = sensor_chequear( segActuales );

 UnityAssertEqualNumber((UNITY_INT)((1)), (UNITY_INT)((chequear)), (

((void *)0)

), (UNITY_UINT)(138), UNITY_DISPLAY_STYLE_INT);



 char mensaje[20];

 for(uint8_t indice = 0; indice < sizeof(sensores) / sizeof( Sensores_t ); indice++) {

  sprintf(mensaje, "sensores[%d]", indice);

  int8_t leer_dato = sensor_leer_dato( &sensor );

  UnityAssertEqualNumber((UNITY_INT)((sensores[indice]._leer_dato)), (UNITY_INT)((leer_dato)), ((mensaje)), (UNITY_UINT)(144), UNITY_DISPLAY_STYLE_INT);

  UnityAssertEqualNumber((UNITY_INT)((sensores[indice]._valor)), (UNITY_INT)((sensor.valor)), ((mensaje)), (UNITY_UINT)(145), UNITY_DISPLAY_STYLE_INT);

 }

}
