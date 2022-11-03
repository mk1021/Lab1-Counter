
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
    
![lab1_task1_counter](https://user-images.githubusercontent.com/93614234/199852355-eb93f9b0-f52a-4d05-9b6d-848252911ad2.png)

Here's the mapping between SV and counter circuit "synthesized" via Verilator:

![image](https://user-images.githubusercontent.com/93614234/199852708-b3ea379d-ece5-4e15-99d7-20295f58b049.png)


### **Step 4:** Creating the testbench file in C++ (Counter_tb.cpp)

Just copied the code given.

![image](https://user-images.githubusercontent.com/93614234/199852783-d8c3ceca-8893-4989-9505-fca9d7bb9b7b.png)


### **Step 5:** Compile the System Verilog model with the testbench

We got given commands to type into our terminal window. 

> `verilator -Wall --cc --trace counter.sv --exe counter_tb.cpp` - runs Verilator to translate counter.sv into C++ and merges with testbench to produce a folder of files obj_dir in which you will find a .mk file, this is a simulation model of Vcounter

> `make -j -C obj_dir/ -f Vcounter.mk Vcounter` - builds an executable model of our counter

> `obj_dir/Vcounter` - runs the executable simulation file that was made earlier and generates a file 'Vcounter.vcd'

#### **Shortcut:**

Created a shell script called *doit.sh* containing all 3 commands to run them all at the same time by typing ***source**  ./doit.sh*.

By typing *'chmod +x doit.sh'* the permissions of the file change therefore means you only need to type *./doit.sh*

![image](https://user-images.githubusercontent.com/93614234/199853103-03c12aba-90fb-4143-a1ef-cad5cd3cae2b.png)

### **Step 6:** Plot the counter waveforms with GTKwave:

- Opening *Vcounter.vcd* on GTKwave gave us this waveform: 

![lab1_task1_FirstGTKWave](https://user-images.githubusercontent.com/93614234/199853158-eee664e1-2840-412b-b7b3-648237daf10d.png)

- Execution of line 32 of the code in testbench is below. Reset turns on before the 2nd clock cycle and at the 15th clock cycle.

![lab1_task1_rst_before2](https://user-images.githubusercontent.com/93614234/199853238-2da0aef0-7980-4eb4-89b2-adf0550b7cf1.png)

![lab1_task1_rst_on](https://user-images.githubusercontent.com/93614234/199853213-8c91a378-636e-4f28-806b-daab717a25c4.png)

- Execution of line 33 below is proved as the enable is low for the first 4 clock cycles.

![lab1_task1_enon](https://user-images.githubusercontent.com/93614234/199853264-f187d4d3-f109-44ee-a5ef-2c8f6f305d47.png)

**Why is the time axis in ps?** - The time period of each clock cycle is in picoseconds, but usually the scale used doesn't matter.

### **Challenge 1:** 

> **Modify the testbench so that the counter stops counting for 3 cycles when it reaches 0x9 and then resumes counting.**

![image](https://user-images.githubusercontent.com/93614234/199853514-8f9b0e3d-afdb-4b82-a176-0c9282020a42.png)

- There is a one cycle delay for changes, therefore when *top->count = 8* the instruction has to be given. The current cycle stays as it is, and then enable needs to turn off for the next 2 cycles more and then resume counting, therefore the next *if* statement addresses this, it stops *top->count* from increasing until the 3 cycles are completed.  

### **Challenge 2:** 

> **Change the current synchronous reset to aysnchronous.**

BEFORE:

(before pic + waveform)

AFTER:

(after pic + waveform)

- The `posedge rst` changes the reset so that it is implemented immediately without the one cycle delay.

---
