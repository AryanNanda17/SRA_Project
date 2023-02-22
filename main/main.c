#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "sra_board.h"
static TaskHandle_t xtask1;
static TaskHandle_t xtask2;
static TaskHandle_t xtask3;
void task_handler(){
    enable_switches();
    while(1){
        if(read_switch(SWITCH_1)){
            vTaskSuspend(xtask2);
            vTaskResume(xtask1);
        }
        else if(read_switch(SWITCH_2)){
            vTaskSuspend(xtask1);
            vTaskResume(xtask2);
        }
    }
}
void blink_fibonacci(){
        uint8_t var = 0x01;
        //0x01 = 0000 0001(only 8th led is on)
        // After left-shifting 0x01 8-times, we end up with 0x00. To recover the var variable, we initialise it with 0x01.
        int a=0;
        int b=1;
        int c=a+b;
        while(1)
        {   
            if(c>13){
                var=0x01;
                a=0;
                b=1;
                c=a+b;
            }
             ESP_ERROR_CHECK(set_bar_graph(var));
             vTaskDelay(1000 / portTICK_RATE_MS);
             ESP_ERROR_CHECK(set_bar_graph(0));
             vTaskDelay(1000 / portTICK_RATE_MS);
             for(int i=0;i<c-b;i++){
                var=var<<1;
                var=var+1;
             }
             a=b;
             b=c;
             c=a+b;
        }
    
}

void blink_sequential(){
   

        uint8_t var = 0x01;
        //0x01 = 0000 0001(only 8th led is on)
        // After left-shifting 0x01 8-times, we end up with 0x00. To recover the var variable, we initialise it with 0x01.

        while(1)
        {   
            // After left-shifting 0x01 8-times, we end up with 0x00. To recover the var variable, we initialise it with 0x01.
            if (var == 0x00)
            //if variable var is  0x00(i.e, all leds are off)
            //it checks whether the value of var has changed from 0x01 to 0x00.
            {
                var = 0x01;
           //setting var to  0x01(8th led is on)
            }            
            ESP_ERROR_CHECK(set_bar_graph(var));
            // var contains the data for the LEDs and it's been passed as an argument to set_bar_graph() function.
            var = var << 1;
            // It left shifts the values of var eg. from 0x01(means only the 8th led is on) it changes to 
            // 0x02 (means only the 7th LED is on). Similarly, the LED's are turned on one by one from the 8th to the 1st.
            vTaskDelay(1000 / portTICK_PERIOD_MS);
            //delay of 1s
        }
    
}

void app_main()
{
    ESP_ERROR_CHECK(enable_bar_graph());
    // enable_bar_graph() turns on the gpio pins, if it succeeds it returns ESP_OK else it returns ESP_FAIL
    // If the argument of ESP_ERROR_CHECK() is not equal ESP_OK, then an error message is printed on the console, and abort() is called. 
    // xTaskCreate -> Create a new task and add it to the list of tasks that are ready to run
	xTaskCreate(&blink_sequential, "blink_sequential", 4096, NULL, 1, &xtask1);
    xTaskCreate(&blink_fibonacci, "blink_fibonacci", 4096, NULL, 1, &xtask2);
    xTaskCreate(&task_handler, "task handler", 4096,NULL,0,&xtask3 );
    vTaskSuspend(xtask1);
    vTaskSuspend(xtask2);

}