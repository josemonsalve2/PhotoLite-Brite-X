----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date:    19:40:10 04/16/2016 
-- Design Name: 
-- Module Name:    CellularRAMController - Behavioral 
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

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
--use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx primitives in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

-- system controller is in charge of resetting the Cellular RAM

entity CellularRAMController is
    Port (
			  -- Simple signals (Front end)
			  clk    	 : in    std_logic;
           enable 	 : in    std_logic := '0';
           rw     	 : in    std_logic;
           addr   	 : in    std_logic_vector (25 downto 0);
           datain 	 : in    std_logic_vector (7 downto 0);
           dataout	 : out   std_logic_vector (7 downto 0);
			  
			  -- Control signals (Back end)
			  MemOE  	 : out   std_logic;  -- Output enable (read enable)
			  MemWR  	 : out   std_logic;  -- Write enable
			  
			  RamAdv 	 : out   std_logic;  -- Address valid
			  RamCS  	 : out   std_logic;  -- Enable Cellular RAM
--			  RamClk 	 : out   std_logic;  -- Clock
			  RamCRE 	 : out   std_logic;  -- Control register enable
			  RamLB  	 : out   std_logic;  -- Access lower byte (7 downto 0)
			  RamUB  	 : out   std_logic;  -- Access upper byte (15 downto 8)
			  RamWait	 : out   std_logic;  -- Wait
			  
			  MemAdr 	 : out   std_logic_vector (25 downto 0);	 -- Cellular RAM Address
			  MemDB  	 : inout std_logic_vector (15 downto 0)   	 -- Cellular RAM Data Bus
--			  MemDB_I	 : in    std_logic_vector(15 downto 0); 	 -- Cellular RAM Data Bus In
--			  MemDB_O	 : out   std_logic_vector(15 downto 0); 	 -- Cellular RAM Data Bus Out
--		     MemDB_T	 : out   std_logic                      	 -- Cellular RAM Data Bus In/Out
	 );
end CellularRAMController;

architecture Behavioral of CellularRAMController is

begin

--	s_CLK <= clk;

	main: process(clk)
	begin
		if rising_edge(clk) then
			if enable = '1' then    -- enabled
				RamCS <= '1';
				RamCRE <= '1';
				RamAdv <= '1';
				RamWait <= '0';
				MemAdr <= addr;
				if rw = '0' then     -- read
					-- not writing
					MemWR <= '0';
					-- reading
					MemOE <= '1';
--					MemDB_T <= '1';
--					dataout <= MemDB_I(7 downto 0);
					dataout <= MemDB(7 downto 0);
				elsif rw = '1' then  -- write
					-- not reading
					MemOE <= '0';
					-- writing
					MemWR <= '1';
--					MemDB_T <= '0';
--					MemDB_O <= x"00" & datain;
					MemDB <= x"00" & datain;
				else
					-- not reading
					MemOE <= '0';
					-- not writing
					MemWR <= '0';
				end if;
			else
				RamCS <= '0';
				dataout <= (others => 'X');
			end if;
		end if;
	end process main;

end Behavioral;

