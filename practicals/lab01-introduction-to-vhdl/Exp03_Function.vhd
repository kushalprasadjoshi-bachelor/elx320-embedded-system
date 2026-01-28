----------------------------------------------------------------------------------
-- Module Name:    Exp03_Function - Behavioral 
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Exp03_Function is
    Port ( A : in  STD_LOGIC;
           B : in  STD_LOGIC;
           C : in  STD_LOGIC;
           F : out  STD_LOGIC);
end Exp03_Function;

architecture Behavioral of Exp03_Function is

begin
	F <= (A and B) or C;

end Behavioral;

