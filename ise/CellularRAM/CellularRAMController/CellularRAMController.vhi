
-- VHDL Instantiation Created from source file CellularRAMController.vhd -- 10:57:29 04/18/2016
--
-- Notes: 
-- 1) This instantiation template has been automatically generated using types
-- std_logic and std_logic_vector for the ports of the instantiated module
-- 2) To use this template to instantiate this entity, cut-and-paste and then edit

	COMPONENT CellularRAMController
	PORT(
		clk : IN std_logic;
		enable : IN std_logic;
		rw : IN std_logic;
		addr : IN std_logic_vector(23 downto 0);
		datain : IN std_logic_vector(7 downto 0);          
		dataout : OUT std_logic_vector(7 downto 0)
		);
	END COMPONENT;

	Inst_CellularRAMController: CellularRAMController PORT MAP(
		clk => ,
		enable => ,
		rw => ,
		addr => ,
		datain => ,
		dataout => 
	);


