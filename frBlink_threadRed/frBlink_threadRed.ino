/*
 * Example to demonstrate thread definition, semaphores, and thread sleep.
 */
#include <FreeRTOS_ARM.h>
#include "PowerDueLED.h"

// Declare a semaphore handle.
SemaphoreHandle_t sem;
//------------------------------------------------------------------------------
/*
 * ThreadRed, turn the Red LED on for 500 ms.
 */
// Declare the thread function for thread 1.
static void ThreadRed(void* arg) {
  SerialUSB.println("Turning the RED LED on");
  pd_rgb_led(PD_RED);

  //Sleep for 500ms
  vTaskDelay((500L * configTICK_RATE_HZ) / 1000L);

  //turn off red led
  SerialUSB.println("Turning off red led");
  pd_rgb_led(PD_OFF);

  //sleep for 500 ms again
  vTaskDelay((500L * configTICK_RATE_HZ) / 1000L);

  //done
  SerialUSB.println("Done");
  while(1);
}
//------------------------------------------------------------------------------
void setup() {
  portBASE_TYPE s1, s2;

  Serial.begin(9600);

  // initialize semaphore
  sem = xSemaphoreCreateCounting(1, 0);

  // create task at priority two
  s1 = xTaskCreate(ThreadRed, NULL, configMINIMAL_STACK_SIZE, NULL, 2, NULL);

  // create task at priority one
  //s2 = xTaskCreate(Thread2, NULL, configMINIMAL_STACK_SIZE, NULL, 1, NULL);

  // check for creation errors
  if (sem== NULL || s1 != pdPASS || s2 != pdPASS ) {
    Serial.println(F("Creation problem"));
    while(1);
  }
  // start scheduler
  vTaskStartScheduler();
  Serial.println("Insufficient RAM");
  while(1);
}
//------------------------------------------------------------------------------
// WARNING idle loop has a very small stack (configMINIMAL_STACK_SIZE)
// loop must never block
void loop() {
  // Not used.
}
