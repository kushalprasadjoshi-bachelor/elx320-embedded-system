# AVR ATmega32 Programs

Welcome! 👋  
This folder contains all **ATmega32 programs** corresponding to the theory **Chapter 2: Programming for Embedded Systems** of this **Embedded Systems (ELX 320)** course by **Pokhara University**.  

Each program is **self-contained**, numbered, and easy to compile and simulate.

Even if you have never used AVR before, you can follow this guide from **setting up software to simulating in Proteus**.

---

## 📁 Folder Structure

```

theory/
├── 02-programming-for-embedded-systems
│   ├── 01-input-output.c
│   ├── 02-looping-output.c
│   └── ............
````

**Notes:**

- Each `.c` file represents **one practical or concept**.  
- Files are numbered (`01-`, `02-`, `03-`) to maintain order.  
- Programs can be compiled **individually** using the Makefile in the root folder.  

---

## 1️⃣ Setting Up Your Environment

To compile and simulate programs, you need the following software:

### 1.1 Required Software

| Software | Purpose | Download Link |
|----------|---------|---------------|
| **VS Code** | Code editor | [https://code.visualstudio.com/](https://code.visualstudio.com/) |
| **AVR GCC Toolchain** | Compile AVR programs | Windows: [Microchip AVR Toolchain](https://www.microchip.com/mplab/avr-support/avr-and-arm-toolchains-c-compilers) <br> Linux: `sudo apt install gcc-avr avr-libc` |
| **AVRDUDE** | Upload programs to hardware (optional) | Comes with AVR toolchain |
| **Proteus** | Simulate ATmega32 programs visually | [https://www.labcenter.com/](https://www.labcenter.com/) |

---

### 1.2 Setting Environment Variables

Make sure `avr-gcc` and `avr-objcopy` are recognized by your system.

- **Windows**:
  1. Go to System Properties → Environment Variables → PATH
  2. Add the folder where `avr-gcc.exe` is located, e.g., `C:\avr8-gnu-toolchain\bin`
  3. Test in terminal:
     ```bash
     avr-gcc --version
     ```
- **Linux**:
  ```bash
  avr-gcc --version
   ````

> ✅ If you see the version number, you’re ready.

---

## 2️⃣ How to Compile a Program

1. Open **VS Code terminal** at the **root folder** of your repo.
2. Use the **Makefile** in the root to compile any program.

```bash
make SRC=theory/02-programming-for-embedded-systems/01-input-output.c
```

3. After compilation, you will get:

```
build.elf  → Executable file
build.hex  → Hex file for Proteus or flashing to hardware
```

4. To **remove generated files**:

```bash
make clean
```

> ⚠️ Each time you compile a new program the  `build.elf` and `build.hex` files will be overwritten.

---

## 3️⃣ Simulating in Proteus

Once you have `build.hex`:

1. Open **Proteus** and create a new project.
2. Add **ATmega32** microcontroller.
3. Add required peripherals (LEDs, switches, etc.) according to the program.
4. Load the `.hex` file into the microcontroller:

   * Double-click the microcontroller → Program File → Select `build.hex`
5. Click **Run** to simulate.
6. Observe the program behavior:

   * LED blinking
   * Port mirroring
   * USART communication
   * Interrupt behavior, etc.

---

## 4️⃣ References & Learning Resources

1. [AVR Libc User Guide](http://www.nongnu.org/avr-libc/user-manual/)
2. [ATmega32 Datasheet](http://ww1.microchip.com/downloads/en/DeviceDoc/Atmel-8271-8-bit-AVR-Microcontroller-ATmega32_Datasheet.pdf)
3. [VS Code Documentation](https://code.visualstudio.com/docs)
4. [Proteus Tutorials](https://www.labcenter.com/tutorials/)

---

Thank you!
