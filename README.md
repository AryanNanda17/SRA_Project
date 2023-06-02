# Multi_Code_ESP 

>Bind any two tasks to any two switches of SRA-Board.

## Table of Contents

- [Multi_Code_ESP ](#Multi_Code_ESP)
  - [Table of Contents](#table-of-contents)
  - [Demonstration](#demonstration)
  - [About the Project](#about-the-project)
    - [Tech Stack](#tech-stack)
    - [File Structure](#file-structure)
      - [Data Handling](#data-handling)
    - [How to use](#how-to-use)
      - [Prerequisites](#prerequisites)
      - [Installation](#installation)
      - [Binding](#binding)
  - [Contributors](#contributors)
  - [Acknowledgements and Resources](#acknowledgements-and-resources)

## Demonstration

## About the Project

### Tech Stack

> This project uses the [ESP-IDF](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/) development framework.

> It uses [FreeRTOS](https://www.freertos.org/openrtos.html).

### File Structure

```
.
├── CMakeLists.txt
├── README.md
├── include
│   └── multicode_esp.h
└── main
    ├── CMakeLists.txt
    ├── component.mk
    └── main.c

```

### Data Handling
>Struct is used to store User's Input

```c++
typedef struct{
    int switchno1;
    int switchno2;
    fptr funtask1;
    fptr funtask2;

}bind;
```

Task is made from the data given by the user and the task is then, bound to the switches of SRA Board.
### How to use

#### Prerequisites

Install ESP-IDF : https://github.com/espressif/esp-idf
 
SRA-Board Component: https://github.com/SRA-VJTI/sra-board-component.git

#### Installation

Clone the project


>Make a Components folder in your project and clone multi_code_esp and SRA Board component in it.
```
  - git clone https://github.com/AryanNanda17/multi_code_esp.git --recursive

  - git clone  https://github.com/SRA-VJTI/sra-board-component.git
```
  
#### Binding

-Call bindTask function and bind your tasks to switches   sra-board.


#### **bindTask Function details**

>It takes four Parameters.

**First Parameter**-  Switch number you want your first task to be bound with.

**Second Parameter**- Switch number you want your second task to be bound with.

**Third Parameter**-  Task 1 function.

**Fourth Parameter**- Task 2 function.
```c++
void bindTask(int n1,int n2, void (*inputfun1)(), void (*inputfun2)())

```

-Create a Task of manageTask

Once the tasks have been bound, the user needs to start the main management of the tasks using the buttons by simply creating a task of the function manageTasks()

```
  xTaskCreate(manageTasks, "multi_code_esp", 4096, NULL, 1, NULL);
```
---
---
Building the project

```sh
get_idf
```

```sh
idf.py build
```

Flash

```sh
idf.py -p (PORT) flash monitor
```
---

## Contributors

- [Aryan](https://github.com/AryanNanda17)


## Acknowledgements
- [SRA VJTI](https://github.com/SRA-VJTI)
- [SRA Wall-E Workshop](https://github.com/SRA-VJTI/Wall-E_v2.2)
- Special thanks to [Zain Siddavatam](https://github.com/SuperChamp234)

