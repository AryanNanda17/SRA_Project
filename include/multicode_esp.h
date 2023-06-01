#include <stdio.h>
#include "sra_board.h"
typedef void (*fptr)();
typedef struct{
    int switchno1;
    int switchno2;
    fptr funtask1;
    fptr funtask2;

}bind;
void bindTask();
void manageTasks();