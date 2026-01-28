----------------------------------------------------------------------------------
-- Module Name:    Exp03_Alt_4x1Mux - Behavioral 
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Exp03_Alt_4x1Mux is
    Port ( A : in  STD_LOGIC;
           B : in  STD_LOGIC;
           C : in  STD_LOGIC;
           D : in  STD_LOGIC;
           S0 : in  STD_LOGIC;
           S1 : in  STD_LOGIC;
           MUX_OUT : out  STD_LOGIC);
end Exp03_Alt_4x1Mux;

architecture Behavioral of Exp03_Alt_4x1Mux is

begin
    -- MUX logic: select one of A, B, C, D based on S1 and S0
    process (S1, S0, A, B, C, D)  -- Sensitivity list optimized for used signals
    variable select_line : STD_LOGIC_VECTOR(1 downto 0);  -- Create a 2-bit vector for the select lines
    begin
        -- Concatenate S1 and S0 into the select_line variable
        select_line := S1 & S0;

        -- Now, perform the case statement on the concatenated select_line
        case select_line is
            when "00" => MUX_OUT <= A;   -- Select A when S1S0 = "00"
            when "01" => MUX_OUT <= B;   -- Select B when S1S0 = "01"
            when "10" => MUX_OUT <= C;   -- Select C when S1S0 = "10"
            when "11" => MUX_OUT <= D;   -- Select D when S1S0 = "11"
            when others => MUX_OUT <= 'X'; -- Undefined state (safety catch)
        end case;
    end process;
end Behavioral;
