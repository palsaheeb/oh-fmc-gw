target = "xilinx"
action = "synthesis"

syn_device = "xc6slx45t"
syn_grade = "-3"
syn_package = "fgg484"
syn_top = "spec_top_fmc_adc_100Ms"
syn_project = "spec_fmc_adc_100Ms.xise"
syn_tool = "ise"

files = [
    "../spec_top_fmc_adc_100Ms.ucf",
    "../../ip_cores/adc_sync_fifo.ngc",
    "../../ip_cores/multishot_dpram.ngc",
    "../../ip_cores/wb_ddr_fifo.ngc",
    "../../ip_cores/adc_serdes.vhd",
    "../../ip_cores/monostable/monostable_rtl.vhd",
    "../../ip_cores/ext_pulse_sync/ext_pulse_sync_rtl.vhd",
    "../../ip_cores/utils/utils_pkg.vhd"]

modules = { "local" : ["../rtl",
                       "../../adc/rtl",
                       "../../ip_cores/timetag_core/rtl"],
            "git" : ["git://ohwr.org/hdl-core-lib/general-cores.git@@c26ee857158e4a65fd9d2add8b63fcb6fb4691ea",
                     "git://ohwr.org/hdl-core-lib/ddr3-sp6-core.git@@16e3573085718fc728003b632cd9f0e28540d130",
                     "git://ohwr.org/hdl-core-lib/gn4124-core.git@@e0dcb3f9a3e6804f64c544743bdf46b5fcbbefab",
                     "git://ohwr.org/hdl-core-lib/wr-cores.git@@f3437dd82dd2267c63f3df341daac8972184cd9e"]}

fetchto="../../ip_cores"

ctrls = ["bank3_64b_32b" ]
