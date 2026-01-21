--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   11:15:50 01/21/2026
-- Design Name:   
-- Module Name:   D:/lab01-introduction-to-vhdl/Exp06_FuinctionTestBench.vhd
-- Project Name:  lab01-introduction-to-vhdl
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: Exp03_Fuction
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY Exp06_FuinctionTestBench IS
END Exp06_FuinctionTestBench;
 
ARCHITECTURE behavior OF Exp06_FuinctionTestBench IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT Exp03_Fuction
    PORT(
         A : IN  std_logic;
         B : IN  std_logic;
         C : IN  std_logic;
         F : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal A : std_logic := '0';
   signal B : std_logic := '0';
   signal C : std_logic := '0';

 	--Outputs
   signal F : std_logic;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: Exp03_Fuction PORT MAP (
          A => A,
          B => B,
          C => C,
          F => F
        );

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	
      -- insert stimulus here 
		A <= '0';
		B <= '0';
		C <= '0';
		
		wait for 100 ns;	
		A <= '0';
		B <= '0';
		C <= '1';
		
		wait for 100 ns;	
		A <= '0';
		B <= '1';
		C <= '0';
		
		wait for 100 ns;
		A <= '0';
		B <= '1';
		C <= '1';
		
		wait for 100 ns;
		A <= '1';
		B <= '0';
		C <= '0';
		
		wait for 100 ns;	
		A <= '1';
		B <= '0';
		C <= '1';
		
		wait for 100 ns;	
		A <= '1';
		B <= '1';
		C <= '0';
		
		wait for 100 ns;
		A <= '1';
		B <= '1';
		C <= '1';
      wait;
   end process;

END;
