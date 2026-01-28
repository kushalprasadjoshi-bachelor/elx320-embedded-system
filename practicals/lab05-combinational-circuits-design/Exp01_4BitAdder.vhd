----------------------------------------------------------------------------------
-- Module Name:    Exp01_4BitAdder - Structural 
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Exp01_4BitAdder is
    Port ( A : in  STD_LOGIC_VECTOR (3 downto 0);
           B : in  STD_LOGIC_VECTOR (3 downto 0);
           S : out  STD_LOGIC_VECTOR (4 downto 0));
end Exp01_4BitAdder;

architecture Structural of Exp01_4BitAdder is

    -- Component declarations
    component HalfAdder
        Port (
            A     : in  STD_LOGIC;
            B     : in  STD_LOGIC;
            Sum   : out STD_LOGIC;
            Carry : out STD_LOGIC
        );
    end component;

    component FullAdder
        Port (
            A    : in  STD_LOGIC;
            B    : in  STD_LOGIC;
            Cin  : in  STD_LOGIC;
            Sum  : out STD_LOGIC;
            Cout : out STD_LOGIC
        );
    end component;

    -- Internal carry signals
    signal C1, C2, C3 : STD_LOGIC;

begin

    -- Bit 0: Half Adder
    HA0: HalfAdder
        port map (
            A     => A(0),
            B     => B(0),
            Sum   => S(0),
            Carry => C1
        );

    -- Bit 1: Full Adder
    FA1: FullAdder
        port map (
            A    => A(1),
            B    => B(1),
            Cin  => C1,
            Sum  => S(1),
            Cout => C2
        );

    -- Bit 2: Full Adder
    FA2: FullAdder
        port map (
            A    => A(2),
            B    => B(2),
            Cin  => C2,
            Sum  => S(2),
            Cout => C3
        );

    -- Bit 3: Full Adder
    FA3: FullAdder
        port map (
            A    => A(3),
            B    => B(3),
            Cin  => C3,
            Sum  => S(3),
            Cout => S(4)
        );

end Structural;


