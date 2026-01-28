--------------------------------------------------------------------------------
-- VHDL Test Bench Created by ISE for module: Exp01_AND
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
ENTITY Exp04_ANDTestBench IS
END Exp04_ANDTestBench;
 
ARCHITECTURE behavior OF Exp04_ANDTestBench IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
    
    COMPONENT Exp01_AND
    PORT(
         A : IN  std_logic;
         B : IN  std_logic;
         Y : OUT  std_logic
        );
    END COMPONENT;
    
   --Inputs
   signal A : std_logic := '0';
   signal B : std_logic := '0';

 	--Outputs
   signal Y : std_logic;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: Exp01_AND PORT MAP (
          A => A,
          B => B,
          Y => Y
        );
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	
      -- insert stimulus here 
		A <= '0';
		B <= '0';
		
		wait for 100 ns;	
		A <= '0';
		B <= '1';
		
		wait for 100 ns;	
		A <= '1';
		B <= '0';
		
		wait for 100 ns;	
		A <= '1';
		B <= '1';

      wait;
   end process;

END;
