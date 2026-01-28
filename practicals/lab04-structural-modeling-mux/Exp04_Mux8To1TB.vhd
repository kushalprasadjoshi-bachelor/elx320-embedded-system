--------------------------------------------------------------------------------
-- VHDL Test Bench Created by ISE for module: Exp03_Mux8To1
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
ENTITY Exp04_Mux8To1TB IS
END Exp04_Mux8To1TB;
 
ARCHITECTURE behavior OF Exp04_Mux8To1TB IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT Exp03_Mux8To1
    PORT(
         I0 : IN  std_logic;
         I1 : IN  std_logic;
         I2 : IN  std_logic;
         I3 : IN  std_logic;
         I4 : IN  std_logic;
         I5 : IN  std_logic;
         I6 : IN  std_logic;
         I7 : IN  std_logic;
         S0 : IN  std_logic;
         S1 : IN  std_logic;
         S2 : IN  std_logic;
         Y : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal I0 : std_logic := '0';
   signal I1 : std_logic := '0';
   signal I2 : std_logic := '0';
   signal I3 : std_logic := '0';
   signal I4 : std_logic := '0';
   signal I5 : std_logic := '0';
   signal I6 : std_logic := '0';
   signal I7 : std_logic := '0';
   signal S0 : std_logic := '0';
   signal S1 : std_logic := '0';
   signal S2 : std_logic := '0';

 	--Outputs
   signal Y : std_logic;

 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: Exp03_Mux8To1 PORT MAP (
          I0 => I0,
          I1 => I1,
          I2 => I2,
          I3 => I3,
          I4 => I4,
          I5 => I5,
          I6 => I6,
          I7 => I7,
          S0 => S0,
          S1 => S1,
          S2 => S2,
          Y => Y
        );
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	

      -- insert stimulus here 
        
        -- Test case 1: I0 to I7 with S0, S1, S2
        I0 <= '1'; wait for 100 ns; -- Expected Y = I0
        S0 <= '0'; S1 <= '0'; S2 <= '0';
        
        I1 <= '1'; wait for 100 ns; -- Expected Y = I1
        S0 <= '1'; S1 <= '0'; S2 <= '0';
        
        I2 <= '1'; wait for 100 ns; -- Expected Y = I2
        S0 <= '0'; S1 <= '1'; S2 <= '0';
        
        I3 <= '1'; wait for 100 ns; -- Expected Y = I3
        S0 <= '1'; S1 <= '1'; S2 <= '0';
        
        I4 <= '1'; wait for 100 ns; -- Expected Y = I4
        S0 <= '0'; S1 <= '0'; S2 <= '1';
        
        I5 <= '1'; wait for 100 ns; -- Expected Y = I5
        S0 <= '1'; S1 <= '0'; S2 <= '1';
        
        I6 <= '1'; wait for 100 ns; -- Expected Y = I6
        S0 <= '0'; S1 <= '1'; S2 <= '1';
        
        I7 <= '1'; wait for 100 ns; -- Expected Y = I7
        S0 <= '1'; S1 <= '1'; S2 <= '1';

        -- End of simulation
      wait;
   end process;

END;
