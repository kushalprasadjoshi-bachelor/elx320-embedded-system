----------------------------------------------------------------------------------
-- Module Name:    XOR2Bit - Behavioral 
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity XOR2Bit is
    Port (
        A : in  STD_LOGIC_VECTOR (1 downto 0);
        B : in  STD_LOGIC_VECTOR (1 downto 0);
        Y : out STD_LOGIC_VECTOR (3 downto 0)
    );
end XOR2Bit;

architecture Behavioral of XOR2Bit is
begin
    Y(0) <= A(0) xor B(0);
    Y(1) <= A(1) xor B(1);
    Y(3 downto 2) <= "00";
end Behavioral;


