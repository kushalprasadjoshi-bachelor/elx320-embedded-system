----------------------------------------------------------------------------------
-- Module Name:    Exp03_4x1Mux - Behavioral 
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Exp03_4x1Mux is
    Port ( A : in  STD_LOGIC;
           B : in  STD_LOGIC;
           C : in  STD_LOGIC;
           D : in  STD_LOGIC;
           S0 : in  STD_LOGIC;
           S1 : in  STD_LOGIC;
           MUX_OUT : out  STD_LOGIC);
end Exp03_4x1Mux;

architecture Behavioral of Exp03_4x1Mux is

begin
    -- MUX logic: select one of A, B, C, D based on S1 and S0
    process (A, B, C, D, S0, S1)
    begin
        case (S1 & S0) is
            when "00" => MUX_OUT <= A;   -- Select A when S1S0 = "00"
            when "01" => MUX_OUT <= B;   -- Select B when S1S0 = "01"
            when "10" => MUX_OUT <= C;   -- Select C when S1S0 = "10"
            when "11" => MUX_OUT <= D;   -- Select D when S1S0 = "11"
        end case;
    end process;
end Behavioral;


