#include "ds1820.h"


static uint8_t sensorConectado = 1;


int8_t	unassignedProbe    ( int8_t ds1_DATA_PIN )
{
    return sensorConectado--;
}

void    convertTemperature ( int8_t idSensor     )
{
    // Se inicializa sensor
}
