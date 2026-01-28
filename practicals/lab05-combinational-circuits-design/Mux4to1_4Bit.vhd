----------------------------------------------------------------------------------
-- Module Name:    Mux4to1_4Bit - Behavioral 
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Mux4to1_4Bit is
    Port (
        D0, D1, D2, D3 : in  STD_LOGIC_VECTOR (3 downto 0);
        Sel            : in  STD_LOGIC_VECTOR (1 downto 0);
        Y              : out STD_LOGIC_VECTOR (3 downto 0)
    );
end Mux4to1_4Bit;

architecture Behavioral of Mux4to1_4Bit is

begin
    process (D0, D1, D2, D3, Sel)
    begin
        case Sel is
            when "00" => Y <= D0; -- NOP
            when "01" => Y <= D1; -- ADD
            when "10" => Y <= D2; -- MUL
            when "11" => Y <= D3; -- XOR
            when others => Y <= "0000";
        end case;
    end process;

end Behavioral;

