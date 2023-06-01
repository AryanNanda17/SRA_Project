#include "multicode_esp.h"
static TaskHandle_t xtask1;
static TaskHandle_t xtask2;
static bind a;
void bindTask(int n1,int n2, void (*inputfun1)(), void (*inputfun2)()){
    switch(n1){
        case 1:
                a.switchno1=SWITCH_1;
                break;
        case 2:
                a.switchno1=SWITCH_2;
                break;
        case 3:
                a.switchno1=SWITCH_3;
                break;
        case 4:
                a.switchno1=SWITCH_4;
                break;
    }
    switch(n2){
        case 1:
                a.switchno2=SWITCH_1;
                break;
        case 2:
                a.switchno2=SWITCH_2;
                break;
        case 3:
                a.switchno2=SWITCH_3;
                break;
        case 4:
                a.switchno2=SWITCH_4;
                break;
    }
    a.funtask1=inputfun1;
    a.funtask2=inputfun2;
    ESP_ERROR_CHECK(enable_bar_graph());
    xTaskCreate( a.funtask1, "User's Task1" , 4096 , NULL , 2, &xtask1 );
    vTaskSuspend(xtask1);
    xTaskCreate( a.funtask2, "User's Task2" , 4096 , NULL , 2, &xtask2 );
    vTaskSuspend(xtask2);
}

void manageTasks(){
    enable_switches();
    vTaskSuspend(xtask1);
    vTaskSuspend(xtask2);
    while(1){
        if(read_switch(a.switchno1)){
            vTaskSuspend(xtask2);
            vTaskResume(xtask1);
            ESP_LOGI("multi-code-esp","Task1 resumed");
        }
        else if(read_switch(a.switchno2)){
            vTaskSuspend(xtask1);
            vTaskResume(xtask2);
            ESP_LOGI("multi-code-esp","Task2 resumed");
        }
        else
        vTaskDelay(100);
    }
}
