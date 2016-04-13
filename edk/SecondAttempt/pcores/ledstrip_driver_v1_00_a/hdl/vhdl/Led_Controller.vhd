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
	 generic ( system_clk: positive := 100000000;
				  numLeds: positive := 144);
    Port ( Pixel: in STD_LOGIC_VECTOR (23 downto 0);
			  tx   : in STD_LOGIC;
			  clk : in  STD_LOGIC;
           reset : in  STD_LOGIC;
           DataOut_port : out  STD_LOGIC := '1';
			  secondClk: out STD_LOGIC);
end Led_Controller;

architecture Behavioral of Led_Controller is
	--reset stuff
	constant reset_count_to : integer := 6000; -- TODO FIX ERROR HERE BS FU we might want to do -1 here as well
	signal reset_counter : unsigned (15 downto 0) := (others => '0');
	
	--Multiple LEDS
	signal led_counter : unsigned (15 downto 0) := (others => '0');
	
	signal s : std_logic:='0';
	
	--System states
	type states_type is (
		reseting,
		waiting, 
		transmitting
		);
	signal system_state : states_type := reseting;
	signal dataOut : STD_LOGIC :='1';

	signal index : STD_LOGIC_VECTOR(5 downto 0) := (others => '0');
	signal counter : STD_LOGIC_VECTOR(7 downto 0) := (others => '0');
	begin

	clk_proc: process (clk,reset,tx)
	begin
	
	if rising_edge(clk) then
		case system_state is
			when transmitting =>
				counter <= counter + '1';
				case counter is 
					when x"00" =>
						DataOut <= '1';
					-- counter = 
					-- bit at Pixel[index] is low
					when x"22" =>
						if Pixel(to_integer(unsigned(index)))='0' then
							DataOut <= '0';
						end if;
					-- counter = 
					-- whether bit at Pixel[index] is low or high
					when x"46" =>
						DataOut <= '0';
					-- increment counter
					-- counter = 
					-- reset counter, increment index
					when x"7D" =>
						s <= not s;
						DataOut<='1';
						counter <= x"00";
						if index = "010111" then
							index <= "000000";
							led_counter <= led_counter + 1;
							if led_counter = numLeds - 1 then
								system_state <= reseting;
							end if;
						else 
							index <= index + '1';
						end if;
					when others => 
						null;
				end case;
			when reseting =>
				DataOut <= '0';
				if reset_counter = reset_count_to then
					reset_counter <= (others =>'0');
					led_counter <= (others => '0');
					system_state <= transmitting;
				else
					reset_counter <= reset_counter + 1;
				end if;
			when others =>
				null;
		end case;
	end if;

--		-- only operate on rising edge of clk
--		if rising_edge(tx) then 
--			if system_state /= reseting then
--				system_state <= transmitting;
--			end if;
--		end if;
--		if rising_edge(reset) then 
--				counter <= (others => '0');
--				index <= (others => '0');
--				reset_counter <= (others => '0');
--				system_state <= reseting;
--		end if;
--		if rising_edge(divided_clk) then
--			-- on reset, set DataOut low and reset counter and index
--			case system_state is
--			when reseting =>
--				DataOut <= '0';
--				if reset_counter = reset_count_to then
--					reset_counter <= (others =>'0');
--					system_state <= waiting;
--				else
--					reset_counter <= reset_counter + 1;
--				end if;
--			when transmitting =>
--					-- index = 24
--					-- we've transmitted all of this pixel, stop transmitting.
--					if index = "011000" then
--						led_counter <= led_counter + 1;
--						counter <= "0000";
--						index <= "000000";
--						--system_state <= waiting;
--						if led_counter = numLeds then
--							led_counter <= (others=> '0');
--							--system_state <= reseting;
--							system_state <= waiting;
--						end if;
--						DataOut <= '1';
--					end if;
--					
--					
--					case counter is 
--						when "0000" =>
--							counter <= counter + '1';
--							DataOut <= '1';
--						-- counter = 4
--						-- bit at Pixel[index] is low
--						when "0100" =>
--							if Pixel(to_integer(unsigned(index)))='0' then
--								DataOut <= '0';
--							end if;
--							counter <= counter + '1';
--						-- counter = 7
--						-- whether bit at Pixel[index] is low or high
--						when "0111" =>
--							DataOut <= '0';
--							counter <= counter + '1';
--						-- increment counter
--						-- counter = 12
--						-- reset counter, increment index
--						when "1100" =>
--							DataOut<='1';
--							counter <= "0000";
--							index <= index + '1';
--						when others =>
--							counter <= counter + '1';
--					end case;
--				-- not transmitting data
--				when waiting =>
--					counter <= "0000";
--					index <= "000000";
--					led_counter <= (others=> '0');
--					system_state <= transmitting;
--
--					
--				when others =>
--					--system_state <= waiting;
--					system_state <= transmitting;
--				end case;
--		end if;

	end process;
	dataOut_port <= dataOut;
	secondClk <= s;
end Behavioral;

