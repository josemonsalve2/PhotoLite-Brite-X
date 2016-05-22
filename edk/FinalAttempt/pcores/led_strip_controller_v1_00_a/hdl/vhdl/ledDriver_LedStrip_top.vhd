----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    04:13:18 05/21/2016 
-- Design Name: 
-- Module Name:    ledDriver_LedStrip_top - Behavioral 
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
USE ieee.std_logic_1164.ALL;
USE ieee.std_logic_unsigned.all;
USE ieee.numeric_std.ALL;
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity ledDriver_LedStrip_top is
	 GENERIC ( NUM_LEDS : integer := 143);
    Port ( clk : in  STD_LOGIC;										-- System clock
			  pixel_add : in STD_LOGIC_VECTOR(7 downto 0);		-- Address to the pixel buffer
			  pixel_new_value : in STD_LOGIC_VECTOR(23 downto 0);-- Value to set the pixel buffer 
			  print_leds : in STD_LOGIC;								-- Tell the system to change the leds
			  busy_writing : out STD_LOGIC;							-- Tell the outside that we are setting the leds
           LEDS_out : out  STD_LOGIC;								-- Values going to the LEDS
			  C_out : out STD_LOGIC:='0');							-- DEBUGGING Clock out for sync
end ledDriver_LedStrip_top;

architecture Behavioral of ledDriver_LedStrip_top is

	COMPONENT ledDriver_LedStrip
	PORT(
		clk : IN std_logic;
		New_Pixel : IN std_logic;
		Reset_Leds : IN std_logic;
		Pixel_value : IN std_logic_vector(23 downto 0);          
		busy_signal : OUT std_logic;
		LEDS_out : OUT std_logic
		);
	END COMPONENT;

	--Inputs
   signal New_Pixel : std_logic := '0';
   signal Reset_Leds : std_logic := '0';
   signal Pixel_value : std_logic_vector(23 downto 0) := (others => '0');

 	--Outputs
   signal busy_signal : std_logic;

	-- Clock counter
	signal clk_counter : unsigned(32 downto 0) := (others => '0');
	signal c_out_sig : STD_LOGIC:='0';
	
	--Colors DELETE ME
	signal COLOR :std_logic_vector(23 downto 0) := (others =>'0');
	
	--LEDS BUFFER TO BE SENT
	type leds_buffer_type is array (NUM_LEDS downto 0) of std_logic_vector (23 downto 0);
	signal leds_buffer : leds_buffer_type;
	
	-- State machine sender
	type state_machine_type is (
		init,
		waiting_trans_signal,
		waiting_because_busy,
		set_value,
		send_new_pixel_pulse,
		waiting_for_busy
	);
	signal state_machine_state : state_machine_type := init;
	
	-- signal to reset before waiting for the transmission
	signal RESETED : STD_LOGIC:='0';
	
	-- leds counter
	signal LEDS_Counter : unsigned(31 downto 0) := to_unsigned(NUM_LEDS,32);

begin
	--clk out
	c_out <= c_out_sig;
	
	-- SETTING THE COLORS OUT
	 Pixel_value <= COLOR;
	
	-- LED Driver instance
	Inst_ledDriver_LedStrip: ledDriver_LedStrip PORT MAP(
		clk => clk,
		New_Pixel => New_Pixel,
		busy_signal => busy_signal,
		Reset_Leds => Reset_Leds,
		Pixel_value => Pixel_value,
		LEDS_out => LEDS_out
	);
	
	-- Stimulus process
   stim_proc: process (clk)
   begin
		if (rising_edge(clk)) then
			busy_writing <= '1'; -- Assume busy unless waiting for transm
			c_out_sig <= not c_out_sig; -- FOR DEBUGGING SYNC
			New_Pixel <= '0';
			case state_machine_state is 
				when init => -- reset the leds
					COLOR <= (others => '0');
					clk_counter <= clk_counter + 1;
					if (clk_counter = x"00000000") then
						Reset_Leds<='1';
					elsif (clk_counter = x"00000002") then
						Reset_Leds<='0';
						RESETED<='1'; -- Tell the waiting for busy to go to waiting trans signal
						state_machine_state <= waiting_for_busy;
					end if;
				when waiting_for_busy => -- wait to the ack
					clk_counter <= clk_counter + 1; -- WATCH DOG
					if (clk_counter > x"000927C0") then -- WATCH DOG
						state_machine_state <= waiting_because_busy;
					end if;
					if (busy_signal = '1') then
						state_machine_state <= waiting_because_busy;
					end if;
				when waiting_because_busy => -- wait until transmission is finished
					clk_counter <= (others => '0');
					if (busy_signal = '0') then
						if (LEDS_counter = to_unsigned(NUM_LEDS,32)) then -- RESET AFTER SENDING ALL
							if (RESETED = '1') then
								LEDS_Counter <= (others => '0');
								state_machine_state <= waiting_trans_signal;
							else
								state_machine_state <= init;
							end if;
						else
							state_machine_state <= set_value;
						end if;
					end if;
				when waiting_trans_signal => -- waiting
					RESETED<='0';  -- Set this value to 0 for the next transmission;
					busy_writing <= '0'; -- tell the outside a new transmission can happen
					if (print_leds = '1') then
						state_machine_state <= set_value; -- Start the tranmission
					end if;
				when set_value =>
					COLOR <= leds_buffer (to_integer(LEDS_Counter)); -- Set the current pixel
					state_machine_state <= send_new_pixel_pulse;
				when send_new_pixel_pulse =>
					New_Pixel <= '1';
					state_machine_state <= waiting_for_busy;
					LEDS_Counter <= LEDS_Counter + 1;
				
				when others =>  -- SHOULD NOT HAPPEN
					state_machine_state <= waiting_trans_signal;
			end case;
		end if;
   end process;

	leds_buffer_proc: process (clk,pixel_add,pixel_new_value)
	begin
		if ( pixel_add < std_logic_vector(to_unsigned(NUM_LEDS,8)) ) then
			leds_buffer (to_integer(unsigned(pixel_add))) <= pixel_new_value;
		end if;
	end process;
	

end Behavioral;

