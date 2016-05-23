-------------------------------------------------------------------------------
-- system_stub.vhd
-------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

library UNISIM;
use UNISIM.VCOMPONENTS.ALL;

entity system_stub is
  port (
    RS232_Uart_1_sout : out std_logic;
    RS232_Uart_1_sin : in std_logic;
    RESET : in std_logic;
    GCLK : in std_logic;
    led_strip_controller_0_LEDS_OUT_pin : out std_logic;
    led_strip_controller_0_C_out_pin : out std_logic
  );
end system_stub;

architecture STRUCTURE of system_stub is

  component system is
    port (
      RS232_Uart_1_sout : out std_logic;
      RS232_Uart_1_sin : in std_logic;
      RESET : in std_logic;
      GCLK : in std_logic;
      led_strip_controller_0_LEDS_OUT_pin : out std_logic;
      led_strip_controller_0_C_out_pin : out std_logic
    );
  end component;

  attribute BOX_TYPE : STRING;
  attribute BOX_TYPE of system : component is "user_black_box";

begin

  system_i : system
    port map (
      RS232_Uart_1_sout => RS232_Uart_1_sout,
      RS232_Uart_1_sin => RS232_Uart_1_sin,
      RESET => RESET,
      GCLK => GCLK,
      led_strip_controller_0_LEDS_OUT_pin => led_strip_controller_0_LEDS_OUT_pin,
      led_strip_controller_0_C_out_pin => led_strip_controller_0_C_out_pin
    );

end architecture STRUCTURE;

