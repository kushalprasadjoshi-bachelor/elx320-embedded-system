--------------------------------------------------------------------------------
-- VHDL Test Bench Created by ISE for module: Exp01_2x1Mux
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
ENTITY Exp02_2x1MuxTB IS
END Exp02_2x1MuxTB;
 
ARCHITECTURE behavior OF Exp02_2x1MuxTB IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT Exp01_2x1Mux
    PORT(
         A : IN  std_logic;
         B : IN  std_logic;
         S : IN  std_logic;
         MUX_OUT : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal A : std_logic := '0';
   signal B : std_logic := '0';
   signal S : std_logic := '0';

 	--Outputs
   signal MUX_OUT : std_logic;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: Exp01_2x1Mux PORT MAP (
          A => A,
          B => B,
          S => S,
          MUX_OUT => MUX_OUT
        );
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	

      -- insert stimulus here 
		-- Test case 1: A = '0', B = '0', S = '0' (select A)
		A <= '0'; B <= '0'; S <= '0';
		wait for 100 ns;

		-- Test case 2: A = '0', B = '0', S = '1' (select B)
		A <= '0'; B <= '0'; S <= '1';
		wait for 100 ns;

		-- Test case 3: A = '0', B = '1', S = '0' (select A)
		A <= '0'; B <= '1'; S <= '0';
		wait for 100 ns;

		-- Test case 4: A = '0', B = '1', S = '1' (select B)
		A <= '0'; B <= '1'; S <= '1';
		wait for 100 ns;

		-- Test case 5: A = '1', B = '0', S = '0' (select A)
		A <= '1'; B <= '0'; S <= '0';
		wait for 100 ns;

		-- Test case 6: A = '1', B = '0', S = '1' (select B)
		A <= '1'; B <= '0'; S <= '1';
		wait for 100 ns;

		-- Test case 7: A = '1', B = '1', S = '0' (select A)
		A <= '1'; B <= '1'; S <= '0';
		wait for 100 ns;

		-- Test case 8: A = '1', B = '1', S = '1' (select B)
		A <= '1'; B <= '1'; S <= '1';

      wait;
   end process;

END;
