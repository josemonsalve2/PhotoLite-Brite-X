----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    02:41:10 05/20/2016 
-- Design Name: 
-- Module Name:    ledDriver_LedStrip - Behavioral 
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

entity ledDriver_LedStrip is
	 generic (system_clk : in integer := 100000000);
    Port ( clk 			: in  STD_LOGIC;
			  New_Pixel 	: in  STD_LOGIC;
           busy_signal 	: out  STD_LOGIC:='0';
           Reset_Leds 	: in  STD_LOGIC;
			  Pixel_value 	: in  STD_LOGIC_VECTOR (23 downto 0);
           LEDS_out 		: out  STD_LOGIC := '0');
end ledDriver_LedStrip;

architecture Behavioral of ledDriver_LedStrip is

---LEDS DEFINITIONS FOR TIMING
	-- values for 0 and 1
	constant TH0 : integer := (400*system_clk/1000000000 - 1); -- for 400 ns
	constant TH1 : integer := (800*system_clk/1000000000 - 1); -- for 800 ns
   constant T_Bit : integer := (1250*system_clk/1000000000 - 1); -- for 1250 ns
	--reset stuff
	constant reset_count_to : integer := 60*system_clk/1000000 - 1; -- for 60 us reset
	--Counter signal
	signal internal_counter : unsigned (31 downto 0) := (others => '0');
	signal PIXEL_counter : unsigned (31 downto 0) := (others => '0');
	

---LEDS DEFINITIONS FOR SIGNAL BUFFERS
	signal Input_Pixel_Buffer : STD_LOGIC_VECTOR (23 downto 0) := (others => '0');
	signal output_pixel_Buffer: STD_LOGIC := '0';
	
---STATE MACHINE DEFINITIONS
	type state_machine_type is
	(
		resetting,  				-- Set the leds to 0 for 50 us to allow print another line
		waiting_for_value,		-- Waiting to get a new request
		new_pixel_value,   		-- When there is a change in the new_pixel signal, it takes the Pixel_value
		transmitting_pixel 		-- After getting a new value we need to start transmitting it.
	);
	signal state_machine_state :state_machine_type := waiting_for_value;
	signal state_machine_next :state_machine_type := waiting_for_value;
begin

	--Static connections
	LEDS_Out <= output_pixel_buffer;

main_process: process (clk,state_machine_next)
	begin
		state_machine_state <= state_machine_next;
		if (rising_edge(clk)) then
			-- By default they are 1, depending on the sate they change
			busy_signal <= '1';
			output_pixel_buffer <= '1';
			-- Checking the state machine
			case state_machine_state is 
				when resetting => -- On reset of pixels
					output_pixel_buffer<= '0';
				when waiting_for_value => -- Doing nothing waiting
					busy_signal <= '0';
					output_pixel_buffer <= '0';
				when new_pixel_value =>-- There is a new value
					null;
				when transmitting_pixel =>-- setting it up to either 1 or 0;
					case Input_Pixel_Buffer(23) is
						when '0' =>
							if (internal_counter > to_unsigned(TH0,32)) then 
								output_pixel_buffer <= '0';
							end if;
						when '1' =>
							if (internal_counter >  to_unsigned(TH1,32)) then
								output_pixel_buffer <= '0';
							end if;
						when others =>
								output_pixel_buffer <= '0';
					end case;
				when others =>
					null;
				end case;
		end if;
			
end process; -- End of main_process;

asnyc_input_proc: process (clk, Reset_Leds, New_Pixel)
	begin 
	
	if (rising_edge(clk)) then
		if (Reset_Leds='1') then
			state_machine_next <= resetting;
		end if;
		if (New_Pixel='1') then 
			if (state_machine_state = waiting_for_value) then 
				state_machine_next <= new_pixel_value;
			end if;
		end if;
	
		case state_machine_state is 
			when resetting =>
				internal_counter <= internal_counter + 1; -- increment the counter 
				if (internal_counter = to_unsigned (reset_count_to,32)) then -- see if 60 us has lapsed
					internal_counter <= (others => '0');
					state_machine_next <= waiting_for_value; -- go to waiting for value
				end if;
			when waiting_for_value =>
				internal_counter<=(others => '0'); -- Reset the counter
				PIXEL_counter <= (others => '0'); -- Reset the pixe counter
			when new_pixel_value =>  
				Input_Pixel_Buffer <= Pixel_value; -- Obtain a copy of the new value
				state_machine_next <= transmitting_pixel; 
				internal_counter<=(others => '0');
				PIXEL_counter <= (others => '0');
			when transmitting_pixel => 
				internal_counter <= internal_counter + 1;
				if (internal_counter = to_unsigned (T_bit,32)) then -- Time to send a single bit
					Input_Pixel_Buffer <= Input_Pixel_Buffer(22 downto 0) & '0'; -- shift the value 1
					internal_counter<=(others => '0'); -- Reset the counter for the next bit
					PIXEL_counter <= PIXEL_counter + 1; -- Inrease the pixel counter
					if (PIXEL_counter = x"00000017") then -- If it reaches 24 bits already
						state_machine_next <= waiting_for_value;
					end if;
				end if;
			when others => 
				state_machine_next <= waiting_for_value;
		end case;
	end if;
end process;



end Behavioral;

