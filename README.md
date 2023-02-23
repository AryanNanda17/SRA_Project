# Multi_Code_ESP 

Switching between two tasks using switches of SRA board.

## Table of Contents

- [Multi_Code_ESP ](#Multi_Code_ESP)
  - [Table of Contents](#table-of-contents)
  - [Demonstration](#demonstration)
  - [About the Project](#about-the-project)
    - [Tech Stack](#tech-stack)
    - [File Structure](#file-structure)
      - [Switches](#switches)
    - [How to use](#how-to-use)
      - [Prerequisites](#prerequisites)
      - [Installation](#installation)
  - [Contributors](#contributors)
  - [Acknowledgements and Resources](#acknowledgements-and-resources)

## Demonstration

## About the Project

### Tech Stack

This project uses the [ESP-IDF](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/) development framework.

It uses [FreeRTOS](https://www.freertos.org/openrtos.html).

### File Structure

```
.
├── CMakeLists.txt
├── README.md
├── components
│   └── sra-board-component
├── main
│   ├── CMakeLists.txt
│   ├── component.mk
│   └── main.c
└── sdkconfig
```


#### Switches
 
* `Switch_1` for running **blink_sequential** task
* `Switch_2` for running **blink_fibonacci**  task



### How to use

#### Prerequisites

Install ESP-IDF : https://github.com/espressif/esp-idf

#### Installation

Clone the project

```sh
git clone https://github.com/AryanNanda17/SRA_Project --recursive
cd multi_code_esp
```

Building the project

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


## Acknowledgements and Resources
- [SRA VJTI](https://github.com/SRA-VJTI)
- [SRA Wall-E Workshop](https://github.com/SRA-VJTI/Wall-E_v2.2)
- Special thanks to [Zain Siddavatam](https://github.com/SuperChamp234)
- https://github.com/espressif/esp-idf/tree/release/v4.2/examples/protocols/http_server
- https://github.com/Molorius/esp32-websocket/
