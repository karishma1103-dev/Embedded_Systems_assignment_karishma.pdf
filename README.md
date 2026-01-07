# Embedded_Systems_assignment_karishma.pdf
#Embedded JSON serialization libarary for smart meter data
Project Overview:
The goal of this assignment is to design and implement an embedded-friendly software library that serializes structured smart meter data into a predefined JSON format.
This project represents a realistic part of a smart-meter / w-M-Bus data pipeline where measurement data is converted from internal data structures into JSON for gateway or backend integration.
The focus of this implementation is on:
- Clean software architecture
- Embedded-oriented API design
- Controlled memory usage
- Robust error handling
- Clear and complete documentation
w-M-Bus radio communication, OMS protocol handling, encryption, and real meter interaction are intentionally kept out of scope.

#Platform & Development Environment
Chosen Platform:Arduino / Generic Embedded C environment  
Development Tools:Arduino IDE / GCC toolchain
Justification:
The Arduino platform and generic Embedded C environment were chosen because they are widely used for rapid prototyping and embedded firmware development. They provide a simple setup while still allowing low-level control over memory and execution flow.
The implementation is written in a platform-agnostic manner, making it portable across STM32 (STM32CubeIDE), ESP32 (ESP-IDF), and other microcontroller platforms with minimal changes.
The core serialization library does not depend on any hardware peripherals or communication interfaces, ensuring transport independence and reusability.

