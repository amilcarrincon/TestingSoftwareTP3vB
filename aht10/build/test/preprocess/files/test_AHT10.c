#include "src/AHT10.h"
#include "build/test/mocks/mock_AHT10_port.h"
#include "/var/lib/gems/2.5.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"










static uint8_t buffer_read[6];

static uint8_t buffer_transmission[3];

extern uint16_t size;











uint8_t buffer_transmission_compare[] = {0xE1, 0x08, 0x00};



uint8_t buffer_read_temperatura_compare[] = {0xAC, 0x33, 0x00};



uint8_t buffer_read_humidity_compare_command[] = {0xAC, 0x33, 0x00};













void test_init_buffer_transmission_AHT10(void)

{

    buffer_transmission[0] = 0xE1;

    buffer_transmission[1] = 0x08;

    buffer_transmission[2] = 0x00;

    AHT10_I2C_Init_Handler_CMockExpect(43);

    AHT10_I2C_Send_CMockExpect(44, 0x38, buffer_transmission, 3, 100);

    AHT10_I2C_Delay_CMockIgnore();

    AHT10_Init();

    UnityAssertEqualIntArray(( const void*)((buffer_transmission_compare)), ( const void*)((buffer_transmission)), (UNITY_UINT32)((3)), (

   ((void *)0)

   ), (UNITY_UINT)(47), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}













void test_init_size_transmission_AHT10(void)

{

    size = 0u;

    AHT10_I2C_Init_Handler_CMockExpect(58);

    AHT10_I2C_Send_CMockExpect(59, 0x38, buffer_transmission, 3, 100);

    AHT10_I2C_Delay_CMockIgnore();

    AHT10_Init();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0003)), (UNITY_INT)(UNITY_INT16)((size)), (

   ((void *)0)

   ), (UNITY_UINT)(62), UNITY_DISPLAY_STYLE_HEX16);

}









void test_command_to_read_temp_AHT10(void)

{

    buffer_transmission[0] = 0xAC;

    buffer_transmission[1] = 0x33;

    buffer_transmission[2] = 0x00;

    AHT10_I2C_Send_CMockExpect(73, 0x38, buffer_transmission, 3, 100);

    AHT10_I2C_Delay_CMockIgnore();

    AHT10_I2C_Receive_CMockExpect(75, 0x38, buffer_read_temperatura_compare, 3, 100);



    AHT10_Read_Temp();

    UnityAssertEqualIntArray(( const void*)((buffer_read_temperatura_compare)), ( const void*)((buffer_transmission)), (UNITY_UINT32)((3)), (

   ((void *)0)

   ), (UNITY_UINT)(78), UNITY_DISPLAY_STYLE_UINT8, UNITY_ARRAY_TO_ARRAY);

}











void test_size_of_buffer_transmition_read_temperature_function_AHT10(void)

{

    size = 0u;

    buffer_transmission[0] = 0xAC;

    buffer_transmission[1] = 0x33;

    buffer_transmission[2] = 0xFF;

    AHT10_I2C_Send_CMockExpect(91, 0x38, buffer_transmission, 3, 100);

    AHT10_I2C_Delay_CMockIgnore();

    AHT10_I2C_Receive_CMockExpect(93, 0x38, buffer_read_temperatura_compare, 3, 100);

    AHT10_Read_Temp();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0003)), (UNITY_INT)(UNITY_INT16)((size)), (

   ((void *)0)

   ), (UNITY_UINT)(95), UNITY_DISPLAY_STYLE_HEX16);

}
