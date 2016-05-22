
# PlanAhead Launch Script for Post-Synthesis pin planning, created by Project Navigator

create_project -name ledDriver_LedStrip -dir "/home/bee/FinalProject/github/PhotoLite-Brite-X/ise4/ledDriver_LedStrip/planAhead_run_3" -part xc6slx16csg324-3
set_property design_mode GateLvl [get_property srcset [current_run -impl]]
set_property edif_top_file "/home/bee/FinalProject/github/PhotoLite-Brite-X/ise4/ledDriver_LedStrip/ledDriver_LedStrip_top.ngc" [ get_property srcset [ current_run ] ]
add_files -norecurse { {/home/bee/FinalProject/github/PhotoLite-Brite-X/ise4/ledDriver_LedStrip} }
set_param project.pinAheadLayout  yes
set_property target_constrs_file "ledDriver_LedStrip_top.ucf" [current_fileset -constrset]
add_files [list {ledDriver_LedStrip_top.ucf}] -fileset [get_property constrset [current_run]]
link_design
