
-- VHDL Instantiation Created from source file ledDriver_LedStrip.vhd -- 04:14:40 05/21/2016
--
-- Notes: 
-- 1) This instantiation template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the instantiated module
-- 2) To use this template to instantiate this entity, cut-and-paste and then edit

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

	Inst_ledDriver_LedStrip: ledDriver_LedStrip PORT MAP(
		clk => ,
		New_Pixel => ,
		busy_signal => ,
		Reset_Leds => ,
		Pixel_value => ,
		LEDS_out => 
	);


