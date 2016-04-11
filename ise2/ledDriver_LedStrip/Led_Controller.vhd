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
use ieee.math_real.all;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity Led_Controller is
	 generic ( system_clk: positive := 100000000 );
    Port ( Pixel: in STD_LOGIC_VECTOR (23 downto 0);
			  tx   : in STD_LOGIC;
			  clk : in  STD_LOGIC;
           reset : in  STD_LOGIC;
           DataOut : out  STD_LOGIC := '1');
end Led_Controller;

architecture Behavioral of Led_Controller is

--For the clock divider count up to sysclk/8MHz We want our clock to be 8 MHz
	constant count_to : integer := system_clk/8000000;
	signal clock_divider : unsigned (7 downto 0) := x"00";

	signal divided_clk : std_logic := '0';
	
	--reset stuff
	constant reset_count_to : integer := system_clk*50/1000000;
	signal reset_counter : unsigned (15 downto 0) := (others => '0');
	
	--System states
	type states_type is (
		reseting,
		waiting, 
		transmitting
		);
	signal system_state : states_type :=reseting;

	signal index : STD_LOGIC_VECTOR(5 downto 0) := (others => '0');
	signal counter : STD_LOGIC_VECTOR(3 downto 0) := (others => '0');
	begin

	clk_proc: process (divided_clk,reset,tx)
	begin
		-- only operate on rising edge of clk
		if rising_edge(tx) then 
			if system_state /= reseting then
				system_state<=transmitting;
			end if;
		elsif rising_edge(reset) then 
				counter <= (others => '0');
				index <= (others => '0');
				reset_counter <= (others => '0');
				system_state <= reseting;
		elsif rising_edge(divided_clk) then
			-- on reset, set DataOut low and reset counter and index
			case system_state is
			when reseting =>
				DataOut <= '0';
				if reset_counter = reset_count_to then
					reset_counter <= (others =>'0');
					system_state <= waiting;
				else
					reset_counter <= reset_counter + 1;
				end if;
			when transmitting =>
					-- index = 24
					-- we've transmitted all of this pixel, stop transmitting.
					if index = "011000" then
						index <= "000000";
						system_state <= waiting;
						DataOut <= '1';
					end if;
					
					
					case counter is 
						when "0000" =>
							counter <= counter + '1';
							DataOut <= '1';
						-- counter = 12
						-- reset counter, increment index
						when "1100" =>
							DataOut<='1';
							counter <= "0000";
							index <= index + '1';
						-- counter = 4
						-- bit at Pixel[index] is low
						when "0100" =>
							if Pixel(to_integer(unsigned(index)))='0' then
								DataOut <= '0';
							end if;
							counter <= counter + '1';
						-- counter = 7
						-- whether bit at Pixel[index] is low or high
						when "0111" =>
							DataOut <= '0';
							counter <= counter + '1';
						-- increment counter
						when others =>
							counter <= counter + '1';
					end case;
				-- not transmitting data
				when waiting =>
					counter <= "0000";
					index <= "000000";
					
				when others =>
					system_state <= waiting;
				end case;
		end if;

	end process;

	clk_gen: process (clk)
	begin
		if rising_edge(clk) then
				if clock_divider = count_to then
					clock_divider <= (others => '0');
					divided_clk <= '1';
				else
					clock_divider <= clock_divider + 1;
					divided_clk <= '0';
				end if;
		end if;

	end process;


end Behavioral;

