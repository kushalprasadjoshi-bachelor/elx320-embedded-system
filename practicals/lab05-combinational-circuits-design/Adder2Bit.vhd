----------------------------------------------------------------------------------
-- Module Name:    Adder2Bit - Structural 
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Adder2Bit is
    Port (
        A : in  STD_LOGIC_VECTOR (1 downto 0);
        B : in  STD_LOGIC_VECTOR (1 downto 0);
        S : out STD_LOGIC_VECTOR (3 downto 0)
    );
end Adder2Bit;

architecture Structural of Adder2Bit is

    component HalfAdder
        Port ( A, B : in STD_LOGIC;
               Sum, Carry : out STD_LOGIC );
    end component;

    component FullAdder
        Port ( A, B, Cin : in STD_LOGIC;
               Sum, Cout : out STD_LOGIC );
    end component;

    signal C1 : STD_LOGIC;

begin
    -- Bit 0
    HA0: HalfAdder
        port map (A(0), B(0), S(0), C1);

    -- Bit 1
    FA1: FullAdder
        port map (A(1), B(1), C1, S(1), S(2));

    -- MSB unused
    S(3) <= '0';

end Structural;


