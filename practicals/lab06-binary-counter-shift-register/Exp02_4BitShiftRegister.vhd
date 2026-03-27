----------------------------------------------------------------------------------
-- Module Name:    Exp02_4BitShiftRegister - Behavioral 
----------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

entity Exp02_4BitShiftRegister is
	port( 
		clk : in STD_LOGIC; 
		clr : in STD_LOGIC; 
		data_in : in STD_LOGIC; 
		q : out STD_LOGIC_VECTOR (3 downto 0) 
	); 
end Exp02_4BitShiftRegister;

architecture Behavioral of Exp02_4BitShiftRegister is

	signal qs : STD_LOGIC_VECTOR(3 downto 0); 
begin 
	process (clk, clr) 
	begin 
		if clr = '1' then 
			qs <= "0000"; 
		elsif clk'event and clk = '1' then 
			qs(3) <= data_in; 
			qs (2 downto 0)  <= qs(3 downto 1); 
		end if; 
	end process; 
	
	q <= qs; 

end Behavioral;

