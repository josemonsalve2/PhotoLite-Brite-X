--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   18:28:13 03/19/2016
-- Design Name:   
-- Module Name:   /home/bee/ledDriver_LedStrip/Led_controller_tb.vhd
-- Project Name:  ledDriver_LedStrip
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: Led_Controller
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
 
-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--USE ieee.numeric_std.ALL;
 
ENTITY Led_controller_tb IS
END Led_controller_tb;
 
ARCHITECTURE behavior OF Led_controller_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT Led_Controller
	 generic ( system_clk: positive := 100000000 );
    PORT(
         Pixel : IN  std_logic_vector(23 downto 0);
         tx : IN  std_logic;
         clk : IN  std_logic;
         reset : IN  std_logic;
         DataOut : OUT  std_logic
        );
    END COMPONENT;
    

   --Inputs
   signal Pixel : std_logic_vector(23 downto 0) := (others => '0');
   signal tx : std_logic := '0';
   signal clk : std_logic := '0';
   signal reset : std_logic := '0';

 	--Outputs
   signal DataOut : std_logic;

   -- Clock period definitions
   constant clk_period : time := 1 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: Led_Controller
		generic map ( system_clk => 100000000 )
		PORT MAP (
          Pixel => Pixel,
          tx => tx,
          clk => clk,
          reset => reset,
          DataOut => DataOut
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
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;
		reset <= '1';
		wait for 75 us;
		reset <= '0';
		tx<='1';
		wait for 100 ns;
		tx <='0';
      -- insert stimulus here 

      wait;
   end process;

	Pixel <= "010100010101111010101011";
	
END;
