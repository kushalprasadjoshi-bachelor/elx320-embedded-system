----------------------------------------------------------------------------------
-- Module Name:    Exp03_SimpleProcessor - Structural 
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Exp03_SimpleProcessor is
    Port ( A : in  STD_LOGIC_VECTOR (1 downto 0);
           B : in  STD_LOGIC_VECTOR (1 downto 0);
           OP : in  STD_LOGIC_VECTOR (1 downto 0);
           Y : out  STD_LOGIC_VECTOR (3 downto 0));
end Exp03_SimpleProcessor;

architecture Structural of Exp03_SimpleProcessor is

    component Adder2Bit
        Port ( A, B : in STD_LOGIC_VECTOR (1 downto 0);
               S    : out STD_LOGIC_VECTOR (3 downto 0) );
    end component;

    component Multiplier2Bit
        Port ( A, B : in STD_LOGIC_VECTOR (1 downto 0);
               P    : out STD_LOGIC_VECTOR (3 downto 0) );
    end component;

    component XOR2Bit
        Port ( A, B : in STD_LOGIC_VECTOR (1 downto 0);
               Y    : out STD_LOGIC_VECTOR (3 downto 0) );
    end component;

    component Mux4to1_4Bit
        Port ( D0, D1, D2, D3 : in STD_LOGIC_VECTOR (3 downto 0);
               Sel            : in STD_LOGIC_VECTOR (1 downto 0);
               Y              : out STD_LOGIC_VECTOR (3 downto 0) );
    end component;

    signal NOP_OUT, ADD_OUT, MUL_OUT, XOR_OUT : STD_LOGIC_VECTOR (3 downto 0);

begin

    -- No Operation
    NOP_OUT <= "0000";

    -- Addition
    ADDER: Adder2Bit
        port map (A, B, ADD_OUT);

    -- Multiplication
    MULT: Multiplier2Bit
        port map (A, B, MUL_OUT);

    -- XOR
    XORU: XOR2Bit
        port map (A, B, XOR_OUT);

    -- Opcode selection
    MUX: Mux4to1_4Bit
        port map (
            D0  => NOP_OUT,
            D1  => ADD_OUT,
            D2  => MUL_OUT,
            D3  => XOR_OUT,
            Sel => OP,
            Y   => Y
        );

end Structural;


