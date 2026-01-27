----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    10:20:33 01/27/2026 
-- Design Name: 
-- Module Name:    Exp01_Mux4To1 - Behavioral 
-- Project Name: 
-- Target Devices: 
-- Tool versions: 
-- Description: 
--
-- Dependencies: 
--
-- Revision: 
-- Revision 0.01 - File Created
-- Additional Comments: 
--
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity Exp01_Mux4To1 is
    Port ( I0 : in  STD_LOGIC;
           I1 : in  STD_LOGIC;
           I2 : in  STD_LOGIC;
           I3 : in  STD_LOGIC;
           S0 : in  STD_LOGIC;
           S1 : in  STD_LOGIC;
           Y : out  STD_LOGIC);
end Exp01_Mux4To1;


architecture Structural of Exp01_Mux4To1 is

    -- Component Declaration for 2:1 MUX
    component Mux2To1 is
        Port ( A : in  STD_LOGIC;
               B : in  STD_LOGIC;
               S : in  STD_LOGIC;
               MUX_OUT : out STD_LOGIC);
    end component;
    
    -- Signals for intermediate MUX outputs
    signal MUX1_out, MUX2_out : STD_LOGIC;
    
begin

    -- First level of 2:1 MUXes
    MUX1: Mux2To1 port map (I0, I1, S0, MUX1_out);  -- MUX1 selects between I0 and I1 based on S0
    MUX2: Mux2To1 port map (I2, I3, S0, MUX2_out);  -- MUX2 selects between I2 and I3 based on S0
    
    -- Second level of 2:1 MUX (final output Y)
    MUX3: Mux2To1 port map (MUX1_out, MUX2_out, S1, Y);  -- MUX3 selects between MUX1_out and MUX2_out based on S1

end Structural;

