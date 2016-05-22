--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   03:39:45 05/21/2016
-- Design Name:   
-- Module Name:   /home/bee/FinalProject/github/PhotoLite-Brite-X/ise4/ledDriver_LedStrip/ledDriver_LedStri_tb.vhd
-- Project Name:  ledDriver_LedStrip
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: ledDriver_LedStrip
-- 
-- Dependencies:
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
--
-- Notes: 
-- This testbench has been automatically generated using types std_logic and
-- std_logic_vector for the ports of the unit under test.  Xilinx recommends
-- that these types always be used for the top-level I/O of a design in order
-- to guarantee that the testbench will bind correctly to the post-implementation 
-- simulation model.
--------------------------------------------------------------------------------
LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
USE ieee.std_logic_unsigned.all;
USE ieee.numeric_std.ALL;
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY ledDriver_LedStri_tb IS
END ledDriver_LedStri_tb;
 
ARCHITECTURE behavior OF ledDriver_LedStri_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT ledDriver_LedStrip
    PORT(
         clk : IN  std_logic;
         New_Pixel : IN  std_logic;
         busy_signal : OUT  std_logic;
         Reset_Leds : IN  std_logic;
         Pixel_value : IN  std_logic_vector(23 downto 0);
         LEDS_out : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal clk : std_logic := '0';
   signal New_Pixel : std_logic := '0';
   signal Reset_Leds : std_logic := '0';
   signal Pixel_value : std_logic_vector(23 downto 0) := (others => '0');

 	--Outputs
   signal busy_signal : std_logic;
   signal LEDS_out : std_logic;

   -- Clock period definitions
   constant clk_period : time := 10 ns;
	
	-- Clock counter
	signal clk_counter : unsigned(32 downto 0) := (others => '0');
	
	-- State machine sender
	type state_machine_type is (
		init,
		waiting_because_busy,
		set_value,
		send_new_pixel_pulse,
		waiting_for_busy
	);
	signal state_machine_state : state_machine_type := init;
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: ledDriver_LedStrip PORT MAP (
          clk => clk,
          New_Pixel => New_Pixel,
          busy_signal => busy_signal,
          Reset_Leds => Reset_Leds,
          Pixel_value => Pixel_value,
          LEDS_out => LEDS_out
        );

   -- Clock process definitions
   clk_process :process
   begin
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process (clk)
   begin
		if (rising_edge(clk)) then
			New_Pixel <= '0';
			case state_machine_state is 
				when init =>
					clk_counter <= clk_counter + 1;
					if (clk_counter = x"00000000") then
						Reset_Leds<='1';
					elsif (clk_counter = x"00000002") then
						Reset_Leds<='0';
						state_machine_state <= waiting_because_busy;
					end if;
				when waiting_because_busy => 
					clk_counter <= (others => '0');
					if (busy_signal = '0') then
						state_machine_state <= set_value;
					end if;
				when set_value =>
					Pixel_value <= x"FFFFFF";
					state_machine_state <= send_new_pixel_pulse;
				when send_new_pixel_pulse =>
					New_Pixel <= '1';
					state_machine_state <= waiting_for_busy;
				when waiting_for_busy =>
					clk_counter <= clk_counter + 1;
					if (clk_counter > x"000927C0") then
						state_machine_state <= waiting_because_busy;
					end if;
					if (busy_signal = '1') then
						state_machine_state <= waiting_because_busy;
					end if;
				when others =>
					state_machine_state <= waiting_because_busy;
			end case;
		end if;
   end process;

END;
