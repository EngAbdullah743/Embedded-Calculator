# 🧮 STM32 Embedded Calculator Project

A fully functional calculator system built using the **STM32F103C6** microcontroller, featuring a **20x4 LCD display** and a **4x4 matrix keypad**. Designed for real-time arithmetic operations, the system supports multiple operations, error handling, and an intuitive user interface.

> 🔧 Developed by **Abdullah Ahmad** | 📅 **June 2025**  
> 🎓 Project for **COME328 – Microcontrollers** course  
> 🧪 Simulated using **Proteus 8 Demonstration**

---

## 📂 Project Structure

<img width="205" height="417" alt="image" src="https://github.com/user-attachments/assets/40a99b11-c312-4662-b4f9-99dd140c6292" />


---

## 🧠 Features

- ✅ Basic Operations: Addition, Subtraction, Multiplication, Division
- ➗ Advanced: Modulo (`%`), Square Root (`√`)
- 🛑 Error Handling: Division by zero, input validation
- 🖥️ 20x4 LCD Display: Cursor positioning, real-time updates
- ⌨️ Matrix Keypad: Clean UI with dedicated function keys
- 🧱 Modular Code: Separate drivers for LCD, Keypad, Arithmetic

---

## 🔌 Hardware Overview

| Component         | Details |
|------------------|---------|
| **MCU**          | STM32F103C6 (ARM Cortex-M3, 72 MHz) |
| **Display**      | 20x4 HD44780-compatible LCD |
| **Input**        | 4x4 Matrix Keypad |
| **Voltage**      | 5V input, regulated to 3.3V for STM32 |
| **Power Draw**   | ~50mA typical |

---

## 🧰 Software Architecture

- **`main.c`** – Initializes the system, handles UI and program logic
- **`LCD.c / LCD.h`** – Controls 8-bit LCD communication
- **`keypad.c / keypad.h`** – Scans and debounces keypad input
- **`Arithmatic.c / Arithmatic.h`** – Contains all math operations with safety checks

---

## 🔁 System Flowchart

```mermaid
graph TD;
    A[Start] --> B[Initialize LCD & Keypad]
    B --> C[Display Welcome Message]
    C --> D{Key Pressed?}
    D -- No --> C
    D -- Yes --> E[Process Key Type]
    E --> F[Update Display / Buffer]
    F --> G{Equals Pressed?}
    G -- No --> D
    G -- Yes --> H[Calculate Result]
    H --> I[Show Result on LCD]
    I --> C

