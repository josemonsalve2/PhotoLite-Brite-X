----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    17:44:38 03/19/2016 
-- Design Name: 
-- Module Name:    Led_Controller - Behavioral 
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
use IEEE.STD_LOGIC_UNSIGNED.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity Led_Controller is
    Port ( Pixel: in STD_LOGIC_VECTOR (23 downto 0);
			  tx   : in STD_LOGIC;
				clk : in  STD_LOGIC;
           reset : in  STD_LOGIC;
           DataOut : out  STD_LOGIC := '1');
end Led_Controller;

architecture Behavioral of Led_Controller is
signal index : STD_LOGIC_VECTOR(5 downto 0) := (others => '0');
signal Counter : STD_LOGIC_VECTOR(3 downto 0) := (others => '0');
signal transmitting_clk : STD_LOGIC := '0';
signal transmitting_tx : STD_LOGIC := '0';
signal transmitting : STD_LOGIC := '0';
begin

clk_proc: process (clk)
begin
   if (transmitting = '1' and rising_edge(clk)) then
		transmitting_clk <='1';
		if index = "011000" then
			index <= "000000";
			transmitting_clk <='0';
		end if;
		if (counter = "1001") then
			DataOut<='1';
			counter <= "0000";
			index <= index + '1';
		elsif (counter="0011" and Pixel(to_integer(unsigned(index)))='0') then
			DataOut <= '0';
			counter <= counter + '1';
		elsif (counter="0111") then 
			DataOut <= '0';
			counter <= counter + '1';
		else
			counter <= counter + '1';
		end if;
	elsif (transmitting = '0' and rising_edge(clk)) then
		counter <= "0000";
		index <= "000000";
	end if;

end process;

tx_proc: process (tx)
begin
if (rising_edge(tx)) then

		transmitting_tx <='1';
		transmitting_tx <='0' after 20ns;

	 end if;
end process;

transmitting<=transmitting_tx or transmitting_clk;

end Behavioral;

