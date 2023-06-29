/* AUTOGENERATED FILE. DO NOT EDIT. */

/*=======Automagically Detected Files To Include=====*/
#include "unity.h"
#include "cmock.h"
#include "mock_AHT10_port.h"

int GlobalExpectCount;
int GlobalVerifyOrder;
char* GlobalOrderError;

/*=======External Functions This Runner Calls=====*/
extern void setUp(void);
extern void tearDown(void);
extern void test_init_buffer_transmission_AHT10(void);
extern void test_init_size_transmission_AHT10(void);
extern void test_command_to_read_temp_AHT10(void);
extern void test_size_of_buffer_transmition_read_temperature_function_AHT10(void);
extern void test_convertion_data_read_in_temperature_celcius();
extern void test_size_of_buffer_transmition_read_humidity_function_AHT10(void);
extern void test_size_of_buffer_transmition_read_hum_function_AHT10(void);
extern void test_convertion_data_read_in_humidity_percent(void);


/*=======Mock Management=====*/
static void CMock_Init(void)
{
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
  GlobalOrderError = NULL;
  mock_AHT10_port_Init();
}
static void CMock_Verify(void)
{
  mock_AHT10_port_Verify();
}
static void CMock_Destroy(void)
{
  mock_AHT10_port_Destroy();
}

/*=======Setup (stub)=====*/
void setUp(void) {}

/*=======Teardown (stub)=====*/
void tearDown(void) {}

/*=======Test Reset Options=====*/
void resetTest(void);
void resetTest(void)
{
  tearDown();
  CMock_Verify();
  CMock_Destroy();
  CMock_Init();
  setUp();
}
void verifyTest(void);
void verifyTest(void)
{
  CMock_Verify();
}

/*=======Test Runner Used To Run Each Test=====*/
static void run_test(UnityTestFunction func, const char* name, UNITY_LINE_TYPE line_num)
{
    Unity.CurrentTestName = name;
    Unity.CurrentTestLineNumber = line_num;
#ifdef UNITY_USE_COMMAND_LINE_ARGS
    if (!UnityTestMatches())
        return;
#endif
    Unity.NumberOfTests++;
    UNITY_CLR_DETAILS();
    UNITY_EXEC_TIME_START();
    CMock_Init();
    if (TEST_PROTECT())
    {
        setUp();
        func();
    }
    if (TEST_PROTECT())
    {
        tearDown();
        CMock_Verify();
    }
    CMock_Destroy();
    UNITY_EXEC_TIME_STOP();
    UnityConcludeTest();
}

/*=======MAIN=====*/
int main(void)
{
  UnityBegin("test_AHT10.c");
  run_test(test_init_buffer_transmission_AHT10, "test_init_buffer_transmission_AHT10", 39);
  run_test(test_init_size_transmission_AHT10, "test_init_size_transmission_AHT10", 52);
  run_test(test_command_to_read_temp_AHT10, "test_command_to_read_temp_AHT10", 71);
  run_test(test_size_of_buffer_transmition_read_temperature_function_AHT10, "test_size_of_buffer_transmition_read_temperature_function_AHT10", 88);
  run_test(test_convertion_data_read_in_temperature_celcius, "test_convertion_data_read_in_temperature_celcius", 102);
  run_test(test_size_of_buffer_transmition_read_humidity_function_AHT10, "test_size_of_buffer_transmition_read_humidity_function_AHT10", 122);
  run_test(test_size_of_buffer_transmition_read_hum_function_AHT10, "test_size_of_buffer_transmition_read_hum_function_AHT10", 139);
  run_test(test_convertion_data_read_in_humidity_percent, "test_convertion_data_read_in_humidity_percent", 157);

  CMock_Guts_MemFreeFinal();
  return UnityEnd();
}
