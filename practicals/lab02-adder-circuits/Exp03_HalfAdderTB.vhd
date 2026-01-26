--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   11:35:08 01/21/2026
-- Design Name:   
-- Module Name:   D:/lab02-adder-circuits/Exp03_HalfAdderTB.vhd
-- Project Name:  lab02-adder-circuits
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: Exp01_HalfAdder
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
 
ENTITY Exp03_HalfAdderTB IS
END Exp03_HalfAdderTB;
 
ARCHITECTURE behavior OF Exp03_HalfAdderTB IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT Exp01_HalfAdder
    PORT(
         A : IN  std_logic;
         B : IN  std_logic;
         Sum : OUT  std_logic;
         Carry : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal A : std_logic := '0';
   signal B : std_logic := '0';

 	--Outputs
   signal Sum : std_logic;
   signal Carry : std_logic;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: Exp01_HalfAdder PORT MAP (
          A => A,
          B => B,
          Sum => Sum,
          Carry => Carry
        );
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	
      -- insert stimulus here 
		-- Test case 1: A = '0', B = '0'
		A <= '0'; B <= '0';
		wait for 100 ns;

		-- Test case 2: A = '0', B = '1'
		A <= '0'; B <= '1';
		wait for 100 ns;

		-- Test case 3: A = '1', B = '0'
		A <= '1'; B <= '0';
		wait for 100 ns;

		-- Test case 4: A = '1', B = '1'
		A <= '1'; B <= '1';
		wait for 100 ns;

      wait;
   end process;

END;
