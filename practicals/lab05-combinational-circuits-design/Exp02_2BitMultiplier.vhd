----------------------------------------------------------------------------------
-- Module Name:    Exp02_2BitMultiplier - Structural 
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Exp02_2BitMultiplier is
    Port ( A : in  STD_LOGIC_VECTOR (1 downto 0);
           B : in  STD_LOGIC_VECTOR (1 downto 0);
           P : out  STD_LOGIC_VECTOR (3 downto 0));
end Exp02_2BitMultiplier;

architecture Structural of Exp02_2BitMultiplier is

    -- Half Adder component
    component HalfAdder
        Port (
            A     : in  STD_LOGIC;
            B     : in  STD_LOGIC;
            Sum   : out STD_LOGIC;
            Carry : out STD_LOGIC
        );
    end component;

    -- Internal signals (partial products & carries)
    signal PP0, PP1, PP2, PP3 : STD_LOGIC;
    signal C1 : STD_LOGIC;

begin

    -- Partial products (AND gates)
    PP0 <= A(0) and B(0);
    PP1 <= A(1) and B(0);
    PP2 <= A(0) and B(1);
    PP3 <= A(1) and B(1);

    -- Least significant bit
    P(0) <= PP0;

    -- First Half Adder (PP1 + PP2)
    HA1: HalfAdder
        port map (
            A     => PP1,
            B     => PP2,
            Sum   => P(1),
            Carry => C1
        );

    -- Second Half Adder (PP3 + Carry)
    HA2: HalfAdder
        port map (
            A     => PP3,
            B     => C1,
            Sum   => P(2),
            Carry => P(3)
        );

end Structural;


