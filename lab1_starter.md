# Lab1 - Counter
---
## A few things I need to understand before I start the labs...

### **System Verilog**
is a hardware description and verification language (HDL) most commonly used for designing digital integrated circuits and hardware such as microprocessors such as RISC-V. 

### **Verilator** 
is a software package to simulate SV designs as a cycle-accurate simulator where circuit states are evaulated once in a clock cycle. As it doesn't evaluate time within clock cycles, it's only suitable for functional verification without timing information.
- ***So why use Verilator?*** - There are multiple reasons 
    - Most modern digital circuits are synchronous, which Verilator executes much faster than event-driven simulators. 
        - This is because SV code is translated into C++ (or system C) code which is compiled to produce an executable model known as a Device-Under-Test (DUT) and this program is run to simulate.
    - Only synthesizable SV code is accepted, therefore verilator verified design is guaranteed to be synthesizable.
    - It's free and open-source which is great for educational users.

### **Verilator Testbench** 
is the name of the *'wrapper'* program needed to instantiate the DUT, provide input signals at correct times, display and compare output signals. This restricts interaction with your simulator. 

### **Vbuddy** 
is the bridge between the verilator simulator and actual physical electronics (e.g. a microphone signal and 7-segment display). There's a lack of connection between the software simulation and physical hardware and no easy way of interacting with the DUT therefore Vbdudy was created.
- 'Vbuddy' was named because it is a companion to verilator, verilog and RISC-V. It consists of:
    - an ESP-C3 RISC-V microcontroller,
    - a 240x240 TFT colour display,
    - a rotary encoder (EC11)
    - a microphone with an autogain amplifier (MAX9814),
    - an Inertia Measure Unit (MPU6050),
    - a 12-bit DAC Converter (MCP4725),
    - and 2 channel lowpass filter

---