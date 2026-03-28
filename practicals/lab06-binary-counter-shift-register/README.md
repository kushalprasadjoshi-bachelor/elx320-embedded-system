# Lab 6 - Binary Counter and Shift Register

## Objective

1. To write VHDL code for 4 bit binary counter.
2. To write VHDL code for 4 bit shift register.

---

## Theory

### Binary Counter

A binary counter is a sequential circuit that counts in binary sequence. A 4-bit binary counter can count from 0 to 15 (0000 to 1111 in binary). It increments by one with each clock pulse, cycling back to zero after reaching its maximum value. Binary counters are fundamental building blocks in digital systems for timing, frequency division, and event counting applications.

### Shift Register

A shift register is a sequential circuit that stores and shifts binary data. A 4-bit shift register can hold 4 bits of data and move them left or right with each clock pulse. Data enters from one end (serial input) and exits from the other end (serial output), while all intermediate values shift one position. Shift registers are widely used in data conversion (serial-to-parallel and parallel-to-serial), signal processing, and data transmission systems.

---

## Source Code

### VHDL Code for Four Bit Binary Counter

```vhdl
----------------------------------------------------------------------------------
-- Module Name:    Exp01_4BitBinaryCounter - Behavioral 
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity Exp01_4BitBinaryCounter is
	Port(
		clk: in STD_LOGIC; -- Clock input
		rst: in STD_LOGIC; -- Reset input
		q: out STD_LOGIC_VECTOR (3 downto 0)
	);
end Exp01_4BitBinaryCounter;

architecture Behavioral of Exp01_4BitBinaryCounter is
	signal count: STD_LOGIC_VECTOR (3 downto 0) := "0000";
begin
	process(clk, rst)
	begin
		if rst = '1' then
			count <= "0000";
		elsif rising_edge(clk) then
			count <= count + 1;
		end if;
	end process;
	
	q <= count;

end Behavioral;
```

**Output:**

![RTL Schematic Block](../../images/lab06/Op01_RTLSchematicBlock.PNG)

*Figure 1: RTL Schematic Block of Four Bit Binary Counter*

![RTL Schematic Diagram](../../images/lab06/Op01_RTLSchematicDiagram.PNG)

*Figure 2: RTL Schematic Diagram of Four Bit Binary Counter*

### VHDL Code for Four Bit Shift Register

```vhdl
----------------------------------------------------------------------------------
-- Module Name:    Exp02_4BitShiftRegister - Behavioral 
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Exp02_4BitShiftRegister is
	port( 
		clk : in STD_LOGIC; 
		clr : in STD_LOGIC; 
		data_in : in STD_LOGIC; 
		q : out STD_LOGIC_VECTOR (3 downto 0) 
	); 
end Exp02_4BitShiftRegister;

architecture Behavioral of Exp02_4BitShiftRegister is

	signal qs : STD_LOGIC_VECTOR(3 downto 0); 
begin 
	process (clk, clr) 
	begin 
		if clr = '1' then 
			qs <= "0000"; 
		elsif clk'event and clk = '1' then 
			qs(3) <= data_in; 
			qs (2 downto 0)  <= qs(3 downto 1); 
		end if; 
	end process; 
	
	q <= qs; 

end Behavioral;
```

**Output:**

![RTL Schematic Block](../../images/lab06/Op02_RTLSchematicBlock.PNG)

*Figure 3: RTL Schematic Block of Four Bit Binary Register*

![RTL Schematic Diagram](../../images/lab06/Op02_RTLSchematicDiagram.PNG)

*Figure 4: RTL Schematic Diagram of Four Bit Binary Register*

---

## Discussion and Conclusion

In this lab experiment, we designed a 4 bit binary counter and a 4 bit shift register using VHDL.

---

[Download Outputs PDF](../../docs/lab06/outputs.pdf)