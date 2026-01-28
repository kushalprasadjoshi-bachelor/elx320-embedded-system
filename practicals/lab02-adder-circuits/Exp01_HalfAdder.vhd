----------------------------------------------------------------------------------
-- Module Name:    Exp01_HalfAdder - Behavioral 
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Exp01_HalfAdder is
    Port ( A : in  STD_LOGIC;
           B : in  STD_LOGIC;
           Sum : out  STD_LOGIC;
           Carry : out  STD_LOGIC);
end Exp01_HalfAdder;

architecture Behavioral of Exp01_HalfAdder is

begin
    -- Sum is the XOR of A and B
    SUM <= A XOR B;
    
    -- Carry is the AND of A and B
    CARRY <= A AND B;

end Behavioral;

