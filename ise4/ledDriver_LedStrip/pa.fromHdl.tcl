
# PlanAhead Launch Script for Pre-Synthesis Floorplanning, created by Project Navigator

create_project -name ledDriver_LedStrip -dir "/home/bee/FinalProject/github/PhotoLite-Brite-X/ise4/ledDriver_LedStrip/planAhead_run_2" -part xc6slx16csg324-3
set_param project.pinAheadLayout yes
set srcset [get_property srcset [current_run -impl]]
set_property target_constrs_file "ledDriver_LedStrip_top.ucf" [current_fileset -constrset]
set hdlfile [add_files [list {ledDriver_LedStrip.vhd}]]
set_property file_type VHDL $hdlfile
set_property library work $hdlfile
set hdlfile [add_files [list {ledDriver_LedStrip_top.vhd}]]
set_property file_type VHDL $hdlfile
set_property library work $hdlfile
set_property top ledDriver_LedStrip_top $srcset
add_files [list {ledDriver_LedStrip_top.ucf}] -fileset [get_property constrset [current_run]]
open_rtl_design -part xc6slx16csg324-3
