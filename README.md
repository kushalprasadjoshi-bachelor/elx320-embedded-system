# ELX320 Embedded Systems Repository

This repository contains course materials for ELX320, including AVR C programs, VHDL lab work, assignment code, lab output documents, and simulation images.

## Quick Navigation

### Main Sections
- [Theory Overview](./theory/README.md)
- [Practicals Overview](./practicals/README.md)
- [Assignments Folder](./assignments)
- [Lab Documents (`docs/`)](./docs)
- [Lab Images (`images/`)](./images)

### Theory Readmes
- [Programming for Embedded Systems](./theory/02-programming-for-embedded-systems/README.md)
- [Communication Protocols](./theory/05-communication-protocols/README.md)

### Practical Readmes
- [Xilinx ISE Setup Guide](./practicals/setup-xilinx.md)
- [Lab 01 - Introduction to VHDL](./practicals/lab01-introduction-to-vhdl/README.md)
- [Lab 02 - Adder Circuits](./practicals/lab02-adder-circuits/README.md)
- [Lab 03 - Behavioural Modeling MUX](./practicals/lab03-behavioural-design-mux/README.md)
- [Lab 04 - Structural Modeling MUX](./practicals/lab04-structural-modeling-mux/README.md)
- [Lab 05 - Combinational Circuits Design](./practicals/lab05-combinational-circuits-design/README.md)
- [Lab 06 - Binary Counter and Shift Register](./practicals/lab06-binary-counter-shift-register/README.md)
- [Lab 07 - Soda Vending Machine](./practicals/lab07-soda-vending-machine/README.md)

### Assignment Readmes and Files
- [Assignment 04 - FreeRTOS README](./assignments/04-free-rtos/README.md)
- [Assignment 04 - `main.c`](./assignments/04-free-rtos/main.c)
- [Assignment 04 - `FreeRTOSConfig.h`](./assignments/04-free-rtos/FreeRTOSConfig.h)
- [Assignment 02 - `01-count-pulse.c`](./assignments/02-timer1-programming/01-count-pulse.c)
- [Assignment 02 - `02-overflow-interrupt.c`](./assignments/02-timer1-programming/02-overflow-interrupt.c)

### Lab Output Documents
- [Lab 01 Output PDF](./docs/lab01/outputs.pdf) | [DOCX](./docs/lab01/outputs.docx)
- [Lab 02 Output PDF](./docs/lab02/outputs.pdf) | [DOCX](./docs/lab02/outputs.docx)
- [Lab 03 Output PDF](./docs/lab03/outputs.pdf) | [DOCX](./docs/lab03/outputs.docx)
- [Lab 04 Output PDF](./docs/lab04/outputs.pdf) | [DOCX](./docs/lab04/outputs.docx)
- [Lab 05 Output PDF](./docs/lab05/outputs.pdf) | [DOCX](./docs/lab05/outputs.docx)
- [Lab 06 Output PDF](./docs/lab06/outputs.pdf) | [DOCX](./docs/lab06/outputs.docx)
- [Lab 07 Output PDF](./docs/lab07/outputs.pdf) | [DOCX](./docs/lab07/outputs.docx)

### Key Root Files
- [Makefile](./Makefile)
- [License](./LICENSE)
- [Git Ignore](./.gitignore)

## Repository Layout

```text
.
|-- assignments/
|   |-- 02-timer1-programming/
|   |-- 04-free-rtos/
|-- docs/
|   |-- lab01/ ... lab07/
|-- images/
|   |-- lab01/ ... lab07/
|-- practicals/
|   |-- lab01-introduction-to-vhdl/ ... lab07-soda-vending-machine/
|   |-- README.md
|   `-- setup-xilinx.md
|-- theory/
|   |-- 02-programming-for-embedded-systems/
|   |-- 05-communication-protocols/
|   `-- README.md
|-- Makefile
|-- LICENSE
```

## Build AVR C Programs

Use the root `Makefile` to compile AVR C files:

```bash
make SRC=theory/02-programming-for-embedded-systems/01-input-output.c
```

Clean generated output:

```bash
make clean
```

---

___Happy Coding!___
