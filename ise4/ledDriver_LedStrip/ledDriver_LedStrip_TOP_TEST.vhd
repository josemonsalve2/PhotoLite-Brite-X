----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    01:25:04 05/22/2016 
-- Design Name: 
-- Module Name:    ledDriver_LedStrip_TOP_TEST - Behavioral 
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
use IEEE.NUMERIC_STD.ALL;
use IEEE.STD_LOGIC_UNSIGNED.all;
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity ledDriver_LedStrip_TOP_TEST is
    Port ( clk : in  STD_LOGIC;
           LEDS_OUT : out  STD_LOGIC;
           C_out : out  STD_LOGIC);
end ledDriver_LedStrip_TOP_TEST;

architecture Behavioral of ledDriver_LedStrip_TOP_TEST is
	 COMPONENT ledDriver_LedStrip_top
    PORT(
         clk : IN  std_logic;
         pixel_add : IN  std_logic_vector(7 downto 0);
         pixel_new_value : IN  std_logic_vector(23 downto 0);
         print_leds : IN  std_logic;
         busy_writing : OUT  std_logic;
         LEDS_out : OUT  std_logic;
         C_out : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal pixel_add : std_logic_vector(7 downto 0) := (others => '0');
   signal pixel_new_value : std_logic_vector(23 downto 0) := (others => '0');
   signal print_leds : std_logic := '0';

 	--Outputs
   signal busy_writing : std_logic;


	type COLORS_TYPE is (
		RED,
		GREEN,
		BLUE
	);
	
	signal CURRENT_COLOR : COLORS_TYPE := RED;

	-- clock counter
	signal clk_counter : unsigned (31 downto 0) := (others => '0');
	
	-- address counter
	signal currentAdd : STD_LOGIC_VECTOR (7 downto 0):=(others => '0');

	
	
begin
	uut: ledDriver_LedStrip_top PORT MAP (
          clk => clk,
          pixel_add => pixel_add,
          pixel_new_value => pixel_new_value,
          print_leds => print_leds,
          busy_writing => busy_writing,
          LEDS_out => LEDS_out,
          C_out => C_out
        );
	
	Pixel_add <= currentAdd;
	
   -- Stimulus process
   stim_proc: process (clk)
   begin	
		if (rising_edge(clk)) then
			print_leds <= '0';
			clk_counter <= clk_counter + 1;
			if (clk_counter = x"00000001" ) then
					if CURRENT_COLOR = RED then
						pixel_new_value <= x"00FF00";
						CURRENT_COLOR <= GREEN;
					elsif CURRENT_COLOR = GREEN then
						pixel_new_value <= x"FF0000";
						CURRENT_COLOR <= BLUE;
					elsif CURRENT_COLOR = BLUE then
						pixel_new_value <= x"0000FF";
						CURRENT_COLOR <= RED;
					end if;
			elsif (clk_counter = x"00000003" ) then
				clk_counter <= (others => '0');
				if (currentAdd <= x"90") then 
					currentAdd <= currentAdd + 1;
				elsif (currentAdd /= x"FE") then
					currentAdd <= x"FF";
				end if;
			end if;
			if (currentAdd = x"FF") then
				if (busy_writing = '0') then
					print_leds <= '1';
					currentAdd <= x"FE";
				end if;
			end if;
		end if;
   end process;
	
end Behavioral;

