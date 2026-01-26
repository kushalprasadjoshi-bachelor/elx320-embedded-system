--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   11:41:39 01/21/2026
-- Design Name:   
-- Module Name:   D:/lab02-adder-circuits/Exp04_FullAdderTB.vhd
-- Project Name:  lab02-adder-circuits
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: Exp02_FullAdder
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
 
ENTITY Exp04_FullAdderTB IS
END Exp04_FullAdderTB;
 
ARCHITECTURE behavior OF Exp04_FullAdderTB IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT Exp02_FullAdder
    PORT(
         A : IN  std_logic;
         B : IN  std_logic;
         Cin : IN  std_logic;
         Sum : OUT  std_logic;
         Cout : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal A : std_logic := '0';
   signal B : std_logic := '0';
   signal Cin : std_logic := '0';

 	--Outputs
   signal Sum : std_logic;
   signal Cout : std_logic;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: Exp02_FullAdder PORT MAP (
          A => A,
          B => B,
          Cin => Cin,
          Sum => Sum,
          Cout => Cout
        );

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	
      -- insert stimulus here 
		-- Test case 1: A = '0', B = '0', Cin = '0'
		A <= '0'; B <= '0'; Cin <= '0';
		wait for 100 ns;

		-- Test case 2: A = '0', B = '0', Cin = '1'
		A <= '0'; B <= '0'; Cin <= '1';
		wait for 100 ns;

		-- Test case 3: A = '0', B = '1', Cin = '0'
		A <= '0'; B <= '1'; Cin <= '0';
		wait for 100 ns;

		-- Test case 4: A = '0', B = '1', Cin = '1'
		A <= '0'; B <= '1'; Cin <= '1';
		wait for 100 ns;

		-- Test case 5: A = '1', B = '0', Cin = '0'
		A <= '1'; B <= '0'; Cin <= '0';
		wait for 100 ns;

		-- Test case 6: A = '1', B = '0', Cin = '1'
		A <= '1'; B <= '0'; Cin <= '1';
		wait for 100 ns;

		-- Test case 7: A = '1', B = '1', Cin = '0'
		A <= '1'; B <= '1'; Cin <= '0';
		wait for 100 ns;

		-- Test case 8: A = '1', B = '1', Cin = '1'
		A <= '1'; B <= '1'; Cin <= '1';

      wait;
   end process;

END;
