/**
 * @file test_AHT10.c
 * @autor Amilcar Rincon 
 * @brief
 * @version 0.1
 * @date 28 de junio 2023
 *
 * @copyright Copyright (c) 2023
 *
 */
#include "unity.h"
#include "mock_AHT10_port.h"
#include "AHT10.h"

/**
 * @brief Declaración de variables externas, del driver AHT10.c para poder asignar valores en los diversos test.
 *
 */
static uint8_t buffer_read[6];
static uint8_t buffer_transmission[3];
extern uint16_t size;

/**
 * @brief Declaración de variables buffers para los assert de los arrays de comandos.
 *
 */
uint8_t buffer_transmission_compare[] = {0xE1, 0x08, 0x00};

uint8_t buffer_read_temperatura_compare[] = {0xAC, 0x33, 0x00};

uint8_t buffer_read_humidity_compare_command[] = {0xAC, 0x33, 0x00};

/*
 * @brief Test de inicialización del bufffer de comandos para la transmision de datos hacia
 * el sensor de temperatura y humedad AHT10.
 *
 */
void test_init_buffer_transmission_AHT10(void)
{
    buffer_transmission[0] = 0xE1;
    buffer_transmission[1] = 0x08;
    buffer_transmission[2] = 0x00;
    AHT10_I2C_Init_Handler_Expect();
    AHT10_I2C_Send_Expect(0x38,buffer_transmission,3,100);
    AHT10_I2C_Delay_Ignore();
    AHT10_Init();
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer_transmission_compare, buffer_transmission, 3);
}

/**
 * @brief test_init_size_transmission_AHT10: función test para verificar el correcto cálculo del size del
 * buffer de comandos que se envían al sensor.
 *
 */
void test_init_size_transmission_AHT10(void)
{
    size = 0u;
    AHT10_I2C_Init_Handler_Expect();
    AHT10_I2C_Send_Expect(0x38,buffer_transmission,3,100);
    AHT10_I2C_Delay_Ignore();
    AHT10_Init();
    TEST_ASSERT_EQUAL_HEX16(0x0003, size);
}
/**
 * @brief test_command_to_Read_Temp_AHT10 : función de test para verificar el buffer de comandos para efectuar
 * la lectura del valor de la temperatura.
 */
void test_command_to_read_temp_AHT10(void)
{
    buffer_transmission[0] = 0xAC;
    buffer_transmission[1] = 0x33;
    buffer_transmission[2] = 0x00;
    AHT10_I2C_Send_Expect(0x38,buffer_transmission,3,100);
    AHT10_I2C_Delay_Ignore();
    AHT10_I2C_Receive_Expect(0x38,buffer_read_temperatura_compare,3,100);
    //AHT10_I2C_Receive_ReturnMemThruPtr_pData(buffer_read_temperatura_compare,3);
    AHT10_Read_Temp();
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer_read_temperatura_compare, buffer_transmission, 3);
}
/**
 * @brief test_size_of_buffer_transmition_read_function_AHT10: función de test para verificar el cálculo del valor
 * del tamaño del buffer de comandos a enviar al sensor.
 *
 */
void test_size_of_buffer_transmition_read_temperature_function_AHT10(void)
{
    size = 0u;
    buffer_transmission[0] = 0xAC;
    buffer_transmission[1] = 0x33;
    buffer_transmission[2] = 0xFF;
    AHT10_I2C_Send_Expect(0x38,buffer_transmission,3,100);
    AHT10_I2C_Delay_Ignore();
    AHT10_I2C_Receive_Expect(0x38,buffer_read_temperatura_compare,3,100);
    AHT10_Read_Temp();
    TEST_ASSERT_EQUAL_HEX16(0x0003, size);
}
/**
 * @brief test_convertion_data_read_in_temperature_celcius: test para verificar la correcta conversión
 * de los datos leidos del registro del sensor y convertidos a grados celcius.
 * Se carga en el buffer de lectura el valor equivalente a 25 °C, en donde el TEST_ASSERT_EQUAL_FLOAT(25, temperature);
 * compara el valor obtenido del registro con 25.
 */
void test_convertion_data_read_in_temperature_celcius()
{
    float temperature = 0u;
    buffer_read[3] = 0b00000110;
    buffer_read[4] = 0b00000000;
    buffer_read[5] = 0b00000000;
    AHT10_I2C_Send_Ignore();
    AHT10_I2C_Delay_Ignore();
    AHT10_I2C_Receive_Expect(0x38,buffer_read_temperatura_compare,3,100);
    temperature = AHT10_Read_Temp();
    TEST_ASSERT_EQUAL_FLOAT(25, temperature);
}
<<<<<<< HEAD
=======

/**
 * @brief test_size_of_buffer_transmition_read_humidity_function_AHT10: función de test para verificar el buffer de comandos para efectuar
 * la lectura del valor de la humedad.
 */
void test_size_of_buffer_transmition_read_humidity_function_AHT10(void)
{
    buffer_transmission[0] = 0xFF;
    buffer_transmission[1] = 0xFF;
    buffer_transmission[2] = 0xFF;
    AHT10_I2C_Send_Ignore();
    AHT10_I2C_Delay_Ignore();
    AHT10_I2C_Receive_Ignore();
    AHT10_Read_Hum();
    TEST_ASSERT_EQUAL_UINT8_ARRAY(buffer_read_humidity_compare_command, buffer_transmission, 3);
}

/**
 * @brief test_size_of_buffer_transmition_read_hum_function_AHT10: función de test para verificar el cálculo del valor
 * del tamaño del buffer de recepción de los datos del sensor.
 */
void test_size_of_buffer_transmition_read_hum_function_AHT10(void)
{
    size = 0u;
    buffer_transmission[0] = 0xFF;
    buffer_transmission[1] = 0xFF;
    buffer_transmission[2] = 0xFF;
    AHT10_I2C_Send_Ignore();
    AHT10_I2C_Delay_Ignore();
    AHT10_I2C_Receive_Ignore();
    AHT10_Read_Hum();
    TEST_ASSERT_EQUAL_HEX16(0x0006, size);
}

/**
 * @brief test_convertion_data_read_in_humidity_percent: función de test para verificar el return de la función
 * AHT10_Read_Hum(). Se asigna al buffer read, el valor del registro equivalente al 50% de humedad.
 *
 */
void test_convertion_data_read_in_humidity_percent(void)
{
    int humidity = 0u;
    buffer_read[1] = 0b10000000;
    buffer_read[2] = 0b00000000;
    buffer_read[3] = 0b00001111;
    AHT10_I2C_Send_Ignore();
    AHT10_I2C_Delay_Ignore();
    AHT10_I2C_Receive_Ignore();
    humidity = AHT10_Read_Hum();
    TEST_ASSERT_EQUAL_INT(50, humidity);
}
>>>>>>> f5b59f3efa43e82f3139760e6096f60ceb12cedd
