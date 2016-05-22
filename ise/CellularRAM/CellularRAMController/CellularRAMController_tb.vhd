--------------------------------------------------------------------------------
-- Company: 
-- Engineer:
--
-- Create Date:   22:40:40 04/17/2016
-- Design Name:   
-- Module Name:   /home/bee/git/PhotoLite-Brite-X/ise/CellularRAM/CellularRAMController/CellularRAMController_tb.vhd
-- Project Name:  CellularRAMController
-- Target Device:  
-- Tool versions:  
-- Description:   
-- 
-- VHDL Test Bench Created by ISE for module: CellularRAMController
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
 
ENTITY CellularRAMController_tb IS
END CellularRAMController_tb;
 
ARCHITECTURE behavior OF CellularRAMController_tb IS 
 
    -- Component Declaration for the Unit Under Test (UUT)
 
    COMPONENT CellularRAMController
    PORT(
         clk : IN  std_logic;
         enable : IN  std_logic;
         rw : IN  std_logic;
         addr : IN  std_logic_vector(25 downto 0);
         datain : IN  std_logic_vector(7 downto 0);
         dataout : OUT  std_logic_vector(7 downto 0)
        );
    END COMPONENT;
    

   --Inputs
   signal s_clk : std_logic := '0';
   signal s_enable : std_logic := '0';
   signal s_rw : std_logic := '0';
   signal s_addr : std_logic_vector(25 downto 0) := (others => '0');
   signal s_datain : std_logic_vector(7 downto 0) := (others => '0');

 	--Outputs
   signal s_dataout : std_logic_vector(7 downto 0);

   -- Clock period definitions
   constant clk_period : time := 12.5 ns;
 
BEGIN
 
	-- Instantiate the Unit Under Test (UUT)
   uut: CellularRAMController PORT MAP (
          clk => s_clk,
          enable => s_enable,
          rw => s_rw,
          addr => s_addr,
          datain => s_datain,
          dataout => s_dataout
        );

   -- Clock process definitions
   clk_process :process
   begin
		s_clk <= '0';
		wait for clk_period/2;
		s_clk <= '1';
		wait for clk_period/2;
   end process;
 

   -- Stimulus process
   stim_proc: process
   begin		
      -- hold reset state for 100 ns.
      wait for 100 ns;	

      wait for clk_period*10;

      -- insert stimulus here
		
		-- write "10000001" to address 0
		s_enable <= '1';
		s_rw <= '1';
		s_addr <= (others => '0');
		s_datain <= x"81";
		
		wait for clk_period;
		
		-- read "10000001" from address 0
		s_rw <= '0';

      wait;
   end process;

END;
