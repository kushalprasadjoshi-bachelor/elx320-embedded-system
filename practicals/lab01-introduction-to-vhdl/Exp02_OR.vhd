----------------------------------------------------------------------------------
-- Module Name:    Exp02_OR - Behavioral 
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Exp02_OR is
    Port ( A : in  STD_LOGIC;
           B : in  STD_LOGIC;
           Y : out  STD_LOGIC);
end Exp02_OR;

architecture Behavioral of Exp02_OR is

begin
	Y <= A or B;

end Behavioral;

