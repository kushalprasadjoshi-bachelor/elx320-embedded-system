----------------------------------------------------------------------------------
-- Module Name:    Exp03_Mux8To1 - Structural 
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Exp03_Mux8To1 is
    Port (
        I0 : in  STD_LOGIC;
        I1 : in  STD_LOGIC;
        I2 : in  STD_LOGIC;
        I3 : in  STD_LOGIC;
        I4 : in  STD_LOGIC;
        I5 : in  STD_LOGIC;
        I6 : in  STD_LOGIC;
        I7 : in  STD_LOGIC;
        S0 : in  STD_LOGIC;
        S1 : in  STD_LOGIC;
        S2 : in  STD_LOGIC;
        Y  : out STD_LOGIC
    );
end Exp03_Mux8To1;

architecture Structural of Exp03_Mux8To1 is

    -- Component declaration for 4:1 MUX
    component Exp01_Mux4To1 is
        Port (
            I0 : in  STD_LOGIC;
            I1 : in  STD_LOGIC;
            I2 : in  STD_LOGIC;
            I3 : in  STD_LOGIC;
            S0 : in  STD_LOGIC;
            S1 : in  STD_LOGIC;
            Y  : out STD_LOGIC
        );
    end component;

    -- Component declaration for 2:1 MUX
    component Mux2To1 is
        Port (
            A : in  STD_LOGIC;
            B : in  STD_LOGIC;
            S : in  STD_LOGIC;
            MUX_OUT : out STD_LOGIC
        );
    end component;

    -- Internal signals
    signal Y0, Y1 : STD_LOGIC;

begin

    -- First 4:1 MUX (I0 to I3)
    MUX4_0 : Exp01_Mux4To1
        port map (
            I0 => I0,
            I1 => I1,
            I2 => I2,
            I3 => I3,
            S0 => S0,
            S1 => S1,
            Y  => Y0
        );

    -- Second 4:1 MUX (I4 to I7)
    MUX4_1 : Exp01_Mux4To1
        port map (
            I0 => I4,
            I1 => I5,
            I2 => I6,
            I3 => I7,
            S0 => S0,
            S1 => S1,
            Y  => Y1
        );

    -- Final 2:1 MUX
    MUX2 : Mux2To1
        port map (
            A       => Y0,
            B       => Y1,
            S       => S2,
            MUX_OUT => Y
        );

end Structural;

