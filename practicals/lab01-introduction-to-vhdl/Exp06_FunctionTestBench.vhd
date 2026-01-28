--------------------------------------------------------------------------------
-- VHDL Test Bench Created by ISE for module: Exp03_Function
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
ENTITY Exp06_FunctionTestBench IS
END Exp06_FunctionTestBench;
 
ARCHITECTURE behavior OF Exp06_FunctionTestBench IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT Exp03_Function
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
   uut: Exp03_Function PORT MAP (
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
