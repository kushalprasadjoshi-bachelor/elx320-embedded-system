----------------------------------------------------------------------------------
-- Module Name:    HalfAdder - Behavioral 
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity HalfAdder is
    Port ( A : in  STD_LOGIC;
           B : in  STD_LOGIC;
           Sum : out  STD_LOGIC;
           Carry : out  STD_LOGIC);
end HalfAdder;

architecture Behavioral of HalfAdder is
begin
    Sum   <= A xor B;
    Carry <= A and B;
end Behavioral;


