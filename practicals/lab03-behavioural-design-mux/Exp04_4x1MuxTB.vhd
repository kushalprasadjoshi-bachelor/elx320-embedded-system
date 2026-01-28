--------------------------------------------------------------------------------
-- VHDL Test Bench Created by ISE for module: Exp04_4x1Mux
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
ENTITY Exp04_4x1MuxTB IS
END Exp04_4x1MuxTB;
 
ARCHITECTURE behavior OF Exp04_4x1MuxTB IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT Exp04_4x1Mux
    PORT(
         A : IN  std_logic;
         B : IN  std_logic;
         C : IN  std_logic;
         D : IN  std_logic;
         S0 : IN  std_logic;
         S1 : IN  std_logic;
         MUX_OUT : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal A : std_logic := '0';
   signal B : std_logic := '0';
   signal C : std_logic := '0';
   signal D : std_logic := '0';
   signal S0 : std_logic := '0';
   signal S1 : std_logic := '0';

 	--Outputs
   signal MUX_OUT : std_logic;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: Exp04_4x1Mux PORT MAP (
          A => A,
          B => B,
          C => C,
          D => D,
          S0 => S0,
          S1 => S1,
          MUX_OUT => MUX_OUT
        );
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	

      -- insert stimulus here 
		-- Test case 1: A = '0', B = '0', C = '0', D = '0', S1 = '0', S0 = '0' (select A)
		A <= '0'; B <= '0'; C <= '0'; D <= '0'; S1 <= '0'; S0 <= '0';
		wait for 100 ns;

		-- Test case 2: A = '1', B = '0', C = '0', D = '0', S1 = '0', S0 = '0' (select A)
		A <= '1'; B <= '0'; C <= '0'; D <= '0'; S1 <= '0'; S0 <= '0';
		wait for 100 ns;

		-- Test case 3: A = '0', B = '1', C = '0', D = '0', S1 = '0', S0 = '1' (select B)
		A <= '0'; B <= '1'; C <= '0'; D <= '0'; S1 <= '0'; S0 <= '1';
		wait for 100 ns;

		-- Test case 4: A = '0', B = '0', C = '1', D = '0', S1 = '1', S0 = '0' (select C)
		A <= '0'; B <= '0'; C <= '1'; D <= '0'; S1 <= '1'; S0 <= '0';
		wait for 100 ns;

		-- Test case 5: A = '0', B = '0', C = '0', D = '1', S1 = '1', S0 = '1' (select D)
		A <= '0'; B <= '0'; C <= '0'; D <= '1'; S1 <= '1'; S0 <= '1';
		wait for 100 ns;

		-- Test case 6: A = '1', B = '1', C = '0', D = '0', S1 = '0', S0 = '0' (select A)
		A <= '1'; B <= '1'; C <= '0'; D <= '0'; S1 <= '0'; S0 <= '0';
		wait for 100 ns;

		-- Test case 7: A = '1', B = '1', C = '1', D = '0', S1 = '0', S0 = '1' (select B)
		A <= '1'; B <= '1'; C <= '1'; D <= '0'; S1 <= '0'; S0 <= '1';
		wait for 100 ns;

		-- Test case 8: A = '1', B = '1', C = '1', D = '1', S1 = '1', S0 = '0' (select C)
		A <= '1'; B <= '1'; C <= '1'; D <= '1'; S1 <= '1'; S0 <= '0';
		wait for 100 ns;

		-- Test case 9: A = '1', B = '1', C = '1', D = '1', S1 = '1', S0 = '1' (select D)
		A <= '1'; B <= '1'; C <= '1'; D <= '1'; S1 <= '1'; S0 <= '1';

      wait;
   end process;

END;
