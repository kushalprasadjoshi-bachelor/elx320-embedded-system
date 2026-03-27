----------------------------------------------------------------------------------
-- Module Name:    Exp01_4BitBinaryCounter - Behavioral 
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.STD_LOGIC_ARITH.ALL;
use IEEE.STD_LOGIC_UNSIGNED.ALL;

entity Exp01_4BitBinaryCounter is
	Port(
		clk: in STD_LOGIC; -- Clock input
		rst: in STD_LOGIC; -- Reset input
		q: out STD_LOGIC_VECTOR (3 downto 0)
	);
end Exp01_4BitBinaryCounter;

architecture Behavioral of Exp01_4BitBinaryCounter is
	signal count: STD_LOGIC_VECTOR (3 downto 0) := "0000";
begin
	process(clk, rst)
	begin
		if rst = '1' then
			count <= "0000";
		elsif rising_edge(clk) then
			count <= count + 1;
		end if;
	end process;
	
	q <= count;

end Behavioral;

