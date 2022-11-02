
---
## Task 1: Simulating a basic 8-bit binary counter

### **Step 1-3:** Setting Up

- Learnt how to use GitHub, then forked and cloned 'Lab1-Counter' repository from GitHub. 
    - While doing this, on my command prompt it comes up with *'root@DESKTOP'* instead of *'user@host'*. This just meant that the cloned files would be stored in the *'root'* folder of Ubuntu and not *'home'*.


- Opened VS Code to create and run a SV file (counter.sv):
    - File name MUST be the same as the module name
    - 'WIDTH' = number of bits
    - `always_ff @ (posedge clk)` is the notation for a clocked circuit
    - '`<=`' are non-blocking assignments and are always used in a clocked circuit
        - *'Non-blocking'* means that this line of code occurs simultaneously with others
    - { , } is a concatenation operator
        - In line 13 we use it to concatenate the first 7 bits from count and the 8th bit (LSB) from enable.
        - In line 12 we use it to concatenate 8 bits of '0' to start counting
    
    

![Counter.sv Code!] (https://github.com/mk1021/Lab1-Counter/blob/master/lab1_task1_counter.jpg "Counter.sv" )

### **Step 4:** Creating the testbench file in C++ (Counter_tb.cpp)

Just copied the code given.

(insert image)

### **Step 5:** Compile the System Verilog model with the testbench

We got given commands to type into our terminal window. 

> `verilator -Wall --cc --trace counter.sv --exe counter_tb.cpp` - runs Verilator to translate counter.sv into C++ and merges with testbench to produce a folder of files obj_dir in which you will find a .mk file, this is a simulation model of Vcounter

> `make -j -C obj_dir/ -f Vcounter.mk Vcounter` - builds an executable model of our counter

> `obj_dir/Vcounter` - runs the executable simulation file that was made earlier and generates a file 'Vcounter.vcd'

#### **Shortcut:**

Created a shell script called *doit.sh* containing all 3 commands to run them all at the same time by typing ***source**  ./doit.sh*.

By typing *'chmod +x doit.sh'* the permissions of the file change therefore means you only need to type *./doit.sh*

(insert a picture of the doit.sh script)

### **Step 6:** Plot the counter waveforms with GTKwave:

- Opening *Vcounter.vcd* on GTKwave gave us this waveform: 

(insert wave)

- Execution of line 32 of the code in testbench is below. Reset turns on before the 2nd clock cycle and at the 15th clock cycle.

(insert screenshot x2)

- Execution of line 33 below is proved as the enable is low for the first 4 clock cycles.

(insert screenshot)

**Why is the time axis in ps?** - The time period of each clock cycle is in picoseconds, but usually the scale used doesn't matter.

### **Challenge 1:** 

> **Modify the testbench so that the counter stops counting for 3 cycles when it reaches 0x9 and then resumes counting.**

(insert code)

- There is a one cycle delay for changes, therefore when *top->count = 8* the instruction has to be given. (more to write after question has been answered)   

QUESTION TO ASK: why doesn the loop only run for s+1 and s+2?

### **Challenge 2:** 

> **Change the current synchronous reset to aysnchronous.**

BEFORE:

(before pic + waveform)

AFTER:

(after pic + waveform)

- The `posedge rst` changes the reset so that it is implemented immediately without the one cycle delay.

---