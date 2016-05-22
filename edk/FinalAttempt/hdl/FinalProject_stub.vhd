-------------------------------------------------------------------------------
-- FinalProject_stub.vhd
-------------------------------------------------------------------------------
library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

library UNISIM;
use UNISIM.VCOMPONENTS.ALL;

entity FinalProject_stub is
  port (
    RS232_Uart_1_sout : out std_logic;
    RS232_Uart_1_sin : in std_logic;
    RESET : in std_logic;
    GCLK : in std_logic;
    led_strip_controller_0_LEDS_OUT_pin : out std_logic;
    led_strip_controller_0_C_out_pin : out std_logic
  );
end FinalProject_stub;

architecture STRUCTURE of FinalProject_stub is

  component FinalProject is
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
  attribute BOX_TYPE of FinalProject : component is "user_black_box";

begin

  FinalProject_i : FinalProject
    port map (
      RS232_Uart_1_sout => RS232_Uart_1_sout,
      RS232_Uart_1_sin => RS232_Uart_1_sin,
      RESET => RESET,
      GCLK => GCLK,
      led_strip_controller_0_LEDS_OUT_pin => led_strip_controller_0_LEDS_OUT_pin,
      led_strip_controller_0_C_out_pin => led_strip_controller_0_C_out_pin
    );

end architecture STRUCTURE;

