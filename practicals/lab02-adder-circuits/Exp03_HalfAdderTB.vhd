--------------------------------------------------------------------------------
-- VHDL Test Bench Created by ISE for module: Exp01_HalfAdder
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
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
