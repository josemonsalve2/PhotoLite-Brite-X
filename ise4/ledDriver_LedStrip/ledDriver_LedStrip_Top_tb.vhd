--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   00:32:42 05/22/2016
-- Design Name:   
-- Module Name:   /home/bee/FinalProject/github/PhotoLite-Brite-X/ise4/ledDriver_LedStrip/ledDriver_LedStrip_Top_tb.vhd
-- Project Name:  ledDriver_LedStrip
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: ledDriver_LedStrip_top
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
USE ieee.std_logic_unsigned.ALL;
use ieee.numeric_std.all;
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY ledDriver_LedStrip_Top_tb IS
END ledDriver_LedStrip_Top_tb;
 
ARCHITECTURE behavior OF ledDriver_LedStrip_Top_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
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
   signal clk : std_logic := '0';
   signal pixel_add : std_logic_vector(7 downto 0) := (others => '0');
   signal pixel_new_value : std_logic_vector(23 downto 0) := (others => '0');
   signal print_leds : std_logic := '0';

 	--Outputs
   signal busy_writing : std_logic;
   signal LEDS_out : std_logic;
   signal C_out : std_logic;

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

   -- Clock period definitions
   constant clk_period : time := 10 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: ledDriver_LedStrip_top PORT MAP (
          clk => clk,
          pixel_add => pixel_add,
          pixel_new_value => pixel_new_value,
          print_leds => print_leds,
          busy_writing => busy_writing,
          LEDS_out => LEDS_out,
          C_out => C_out
        );

   -- Clock process definitions
   clk_process :process
   begin
		clk <= '0';
		wait for clk_period/2;
		clk <= '1';
		wait for clk_period/2;
   end process;
 
	
	Pixel_add <= currentAdd;
   -- Stimulus process
   stim_proc: process (clk)
   begin	
		if (rising_edge(clk)) then
			print_leds <= '0';
			clk_counter <= clk_counter + 1;
			if (clk_counter = x"00000003" ) then
				clk_counter <= (others => '0');
				if (currentAdd <= x"90") then 
					currentAdd <= currentAdd + 1;
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

END;
