# Embedded_Systems_assignment_karishma.pdf
Embedded Firmware Assignment
#Platform & Development Environment
Chosen Platform:Arduino / Generic Embedded C environment  
Development Tools:Arduino IDE / GCC toolchain
Justification:
The Arduino platform and generic Embedded C environment were chosen because they are widely used for rapid prototyping and embedded firmware development. They provide a simple setup while still allowing low-level control over memory and execution flow.
The implementation is written in a platform-agnostic manner, making it portable across STM32 (STM32CubeIDE), ESP32 (ESP-IDF), and other microcontroller platforms with minimal changes.
The core serialization library does not depend on any hardware peripherals or communication interfaces, ensuring transport independence and reusability.
