--------------------------------------------------------------------------------
-- VHDL Test Bench Created by ISE for module: Exp02_OR
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
ENTITY Exp05_ORTestBench IS
END Exp05_ORTestBench;
 
ARCHITECTURE behavior OF Exp05_ORTestBench IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT Exp02_OR
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
   uut: Exp02_OR PORT MAP (
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
