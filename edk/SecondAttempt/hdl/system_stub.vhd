-------------------------------------------------------------------------------
-- system_stub.vhd
-------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

library UNISIM;
use UNISIM.VCOMPONENTS.ALL;

entity system_stub is
  port (
    RESET : in std_logic;
    GCLK : in std_logic;
    ledstrip_driver_0_dataOut_pin : out std_logic;
    ledstrip_driver_0_secondCLK_pin : out std_logic
  );
end system_stub;

architecture STRUCTURE of system_stub is

  component system is
    port (
      RESET : in std_logic;
      GCLK : in std_logic;
      ledstrip_driver_0_dataOut_pin : out std_logic;
      ledstrip_driver_0_secondCLK_pin : out std_logic
    );
  end component;

  attribute BOX_TYPE : STRING;
  attribute BOX_TYPE of system : component is "user_black_box";

begin

  system_i : system
    port map (
      RESET => RESET,
      GCLK => GCLK,
      ledstrip_driver_0_dataOut_pin => ledstrip_driver_0_dataOut_pin,
      ledstrip_driver_0_secondCLK_pin => ledstrip_driver_0_secondCLK_pin
    );

end architecture STRUCTURE;

