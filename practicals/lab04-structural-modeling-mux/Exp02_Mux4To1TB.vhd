--------------------------------------------------------------------------------
-- VHDL Test Bench Created by ISE for module: Exp01_Mux4To1
----------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
ENTITY Exp02_Mux4To1TB IS
END Exp02_Mux4To1TB;
 
ARCHITECTURE behavior OF Exp02_Mux4To1TB IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT Exp01_Mux4To1
    PORT(
         I0 : IN  std_logic;
         I1 : IN  std_logic;
         I2 : IN  std_logic;
         I3 : IN  std_logic;
         S0 : IN  std_logic;
         S1 : IN  std_logic;
         Y : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal I0 : std_logic := '0';
   signal I1 : std_logic := '0';
   signal I2 : std_logic := '0';
   signal I3 : std_logic := '0';
   signal S0 : std_logic := '0';
   signal S1 : std_logic := '0';

 	--Outputs
   signal Y : std_logic;
	
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: Exp01_Mux4To1 PORT MAP (
          I0 => I0,
          I1 => I1,
          I2 => I2,
          I3 => I3,
          S0 => S0,
          S1 => S1,
          Y => Y
        );

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	

      -- insert stimulus here 
		-- Test case 1: Select I0
      I0 <= '1'; I1 <= '0'; I2 <= '0'; I3 <= '0';
      S1 <= '0'; S0 <= '0'; -- S1S0 = 00
      wait for 100 ns;
      assert (Y = I0) report "Test Case 1 Failed" severity error;

       -- Test case 2: Select I1
       I0 <= '0'; I1 <= '1'; I2 <= '0'; I3 <= '0';
       S1 <= '0'; S0 <= '1'; -- S1S0 = 01
       wait for 100 ns;
       assert (Y = I1) report "Test Case 2 Failed" severity error;

       -- Test case 3: Select I2
       I0 <= '0'; I1 <= '0'; I2 <= '1'; I3 <= '0';
       S1 <= '1'; S0 <= '0'; -- S1S0 = 10
       wait for 100 ns;
       assert (Y = I2) report "Test Case 3 Failed" severity error;

       -- Test case 4: Select I3
       I0 <= '0'; I1 <= '0'; I2 <= '0'; I3 <= '1';
       S1 <= '1'; S0 <= '1'; -- S1S0 = 11
       wait for 100 ns;
       assert (Y = I3) report "Test Case 4 Failed" severity error;

      --wait;
   end process;

END;
