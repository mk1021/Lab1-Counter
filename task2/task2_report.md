
---

## Task 2: Linking Verilator simulation with Vbuddy

### **Step 1:** Setting up Vbuddy interface 

- Windows Device Manager needs to be opened and under 'COMS' Port there should be a number (e.g. COM1 or COM6) which changes. When the Vbuddy is first connected, this number should be checked and noted in the file *'vbuddy.cfg'*. 

(insert screenshot)

- There's a switch just above the TFT display that needs to be switched to *NORM* from *SELF-TEST* before even plugging the Vbuddy in.

- Files *Vbuddy.cpp*, *Vbuddy.cfg*, *counter.sv* and *counter_tb.cpp* are copied into task 2 folder.

### **Step 2-3:** Modify testbench for Vbuddy and explore the flag feature

- The testbench is modified to allow interaction with the Vbuddy.

(modified code screenshot)

> `vbdHex(int digit, int v)` is used to display a 4-bit binary value in v on a 7 segment display on the TFT colour display.

> `vbdHeader(const char* header)` will display a chosen header at the top of the TFT display

> `vbdOpen()` opens port path specified in *vbuddy.cfg*

> `vbdClose()` closes Vbuddy device, this is for housekeeping

> `vbdFlag()` returns the current flag value which toggles between '1' and '0'


- Vbuddy's rotary encode is also a push-button switch. Line 50 `top->en = vbdFlag();` codes so that every time the rotary encode button is pressed the flag toggle state changes, therefore enabling or disabling the counter.

Recompiled and tested the code, and the TFT display showed a little postbox with a flag and a header at the top just as it should.

(pic of screen)

Instead of a 7-segment display, you can also plot a graph. 

> `vbdPlot(int y, int min, int max)` plots value of y scaled between the minimum and maximum x co-ordinate on TFT screen.

Line 45 `vbdPlot(int(top->count), 0, 255);` shows this in action. This graph plotting can be started/stopped with the flag and rotary encode.

(pic of graph on TFT screen)

### **Challenge 1:** 

> **Modify the counter and testbench so that the *en* signal controls the direction of the counting, so '1' = up and '0' = down.**

For this, the file *counter.sv* needed to be edited.

(edited always_ff code)

(explanation on how it works)

 

---