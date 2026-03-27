---------------------------------------------------------------------------------- 
-- Module Name:    Exp01_SodaVendingMachine - Behavioral 
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Exp01_SodaVendingMachine is
   Port ( 
        clk       : in  STD_LOGIC; 
        reset     : in  STD_LOGIC; 
        coin      : in  STD_LOGIC;   -- 1 when 25c coin inserted 
        soda_out  : out STD_LOGIC    -- 1 when soda is dispensed 
    ); 
end Exp01_SodaVendingMachine;

architecture Behavioral of Exp01_SodaVendingMachine is

  type state_type is (S0, S1, S2, S3); 
  signal current_state, next_state : state_type; 
 
begin 
 
    -- State Register 
    process(clk, reset) 
    begin 
        if reset = '1' then 
            current_state <= S0; 
        elsif rising_edge(clk) then 
            current_state <= next_state; 
        end if; 
    end process; 
 
    -- Next State Logic 
    process(current_state, coin) 
    begin 
        case current_state is 
 
            when S0 => 
                if coin = '1' then 
                    next_state <= S1; 
                else 
                    next_state <= S0; 
                end if; 
 
            when S1 => 
                if coin = '1' then 
                    next_state <= S2; 
                else 
                    next_state <= S1; 
                end if;
            when S2 => 
                if coin = '1' then 
                    next_state <= S3; 
                else 
                    next_state <= S2; 
                end if; 
 
            when S3 => 
                next_state <= S0;   -- reset after vending 
 
        end case; 
    end process; 
 
    -- Output Logic (Moore) 
    soda_out <= '1' when current_state = S3 else '0';
	 
end Behavioral;

