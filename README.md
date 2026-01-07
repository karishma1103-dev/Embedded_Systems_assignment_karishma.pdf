# Embedded JSON Serialization Library for Smart Meter Data
## 1. Goal of the Assignment
The goal of this assignment is to design and implement an embedded-friendly software library that serializes structured smart meter data into a predefined JSON format.
This task represents a realistic part of a smart-meter / w-M-Bus data pipeline where measurement data is converted from internal data structures into JSON for gateway or backend integration.
The focus of this implementation is on:
- Clean software architecture
- Embedded-oriented API design
- Controlled memory usage
- Robust error handling
- Clear and complete documentation
w-M-Bus radio communication, OMS protocol handling, encryption, and real meter interaction are explicitly out of scope.

---

## 2. Platform & Development Environment
**Chosen Platform:** Arduino / Generic Embedded C Environment  
**Development Tools:** Arduino IDE / GCC Toolchain
### Justification
The Arduino and generic embedded C environment were chosen due to their simplicity, portability, and wide usage in embedded firmware development. This environment allows easy testing while maintaining low-level control over memory and execution.
The core serialization library is platform-agnostic and can be ported to STM32 (STM32CubeIDE) or ESP32 (ESP-IDF) with minimal changes. No hardware-specific dependencies are included in the core logic.

---

## 3. Programming Language
**Chosen Language:** C
### Statement
- Freely selectable programming language  
- Must be suitable for embedded systems  
- No unnecessary dependencies  
**General expectations:**
- Controlled memory usage  
- Robust error handling  
- Readable and maintainable code  
### Justification
The C programming language was selected because it is highly suitable for embedded and firmware development. It provides fine-grained control over memory and system resources, which is essential for resource-constrained embedded systems.
C ensures deterministic behavior, minimal runtime overhead, and high portability across platforms such as STM32, ESP32, and Arduino, making it an industry-relevant choice for this assignment.

---

## 4. Data Model
### Statement
Implement appropriate internal data structures to represent gateway-level metadata and measurement data.
### Gateway-Level Metadata
The following fields are used:
- `gatewayId` (string)
- `date` (YYYY-MM-DD format)
- `deviceType` (string)
- `interval_minutes` (integer)
- `total_readings` (integer)
### Measurement Data
Measurement data consists of multiple device readings:
- `device_count` (integer)
- List of device readings
Each **device reading** contains:
- `media` (string)
- `meter` (string)
- `deviceId` (string)
- `unit` (string)
Each device includes one or more **data points**, where each data point contains:
- `timestamp` (string)
- `meter_datetime` (string)
- `total_m3` (floating-point value)
- `status` (string)
The internal data structures are designed to be simple, deterministic, and memory-efficient, ensuring suitability for embedded systems.

---

## 5. Mandatory JSON Output Format
The library generates a strictly defined JSON structure with the following guarantees:
- Field names are unchanged
- Structure is unchanged
- Numbers are not serialized as strings
- No additional fields are added
- The outer JSON element is always an array
An example JSON output is provided in the example application.

---

## 6. Library API Requirements
### Statement
The library must serialize data into a caller-provided buffer, be transport-agnostic, and provide clear error handling.
### API Design
```c
int serialize_to_json(const input_data_t *input,
                      char *output_buffer,
                      size_t buffer_size);
