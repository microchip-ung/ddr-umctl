# Converted from ddr4_timing_parameter.tcl
#===========================================================================
##
## DESCRIPTION : DDR4 package for timing parameter generation.
##
##               SYMBOL         UNITS  CLASS  DESCRIPTION
##               ------         -----  -----  -----------
##               tck            ps     dram   Minimum Clock Cycle Time
##               txp            ps     ddr4   Exit power down to a valid command
##               txpdll         ps     ddr4   Exit precharge power down to READ or WRITE command (DLL-off mode)
##               txsdll         tck    ddr4   SelfRefresh to commands requiring a locked DLL
##               tras_min       ps     ddr4   Minimum Active to Precharge command time
##               tras_max       ps     ddr4   Maximum Active to Precharge command time
##               trfc_nom       ps     ddr4   ???
##               trfc_min       ps     ddr4   Refresh to Refresh Command interval minimum value
##               trfc_min2      ps     ddr4   Refresh to Refresh Command interval minimum value
##               trfc_min4      ps     ddr4   Refresh to Refresh Command interval minimum value
##               trfc_max       ps     ddr4   Refresh to Refresh Command Interval maximum value
##               twtr_l_tck     tck    ddr4   Write to Read command delay in clocks (sometimes higher than twtr/tck)
##               twtr_s_tck     tck    ddr4   Write to Read command delay in clocks (sometimes higher than twtr/tck)
##               tfaw           ps     ddr4   Four Bank Activate window
##               tzqinit        tck    ddr4   ZQ Cal (Init) time
##               tzqoper        tck    ddr4   ZQ Cal (Long) time
##               tzqcs          tck    ddr4   ZQ Cal (Short) time
##               tmrd           tck    ddr4   Load Mode Register command cycle time
##               tcke           ps     ddr4   CKE minimum high or low pulse width
##               tccd_l         tck    ddr4   Cas to Cas command delay to same bank group
##               tccd_s         tck    ddr4   Cas to Cas command delay to different bank group
##               tmod           ps     ddr4   LOAD MODE to non-LOAD MODE command cycle time
##               trtp           ps     ddr4   Read to Precharge command delay
##               twr            ps     ddr4   Write recovery time
##               trc            ps     dram   Active to Active/Auto Refresh command time
##               trcd           ps     dram   Active to Read/Write command time
##               trp            ps     dram   Precharge command period
##               trpa           ps     dram   ???
##               trrd_l         tck    dram   Active bank a to Active bank b command time to same bank group
##               trrd_s         tck    dram   Active bank a to Active bank b command time to different bank group
##               tckmpe         ps     ddr4   Valid clock requirement after MPSM entry
##               tmpx_s         tck    ddr4   CS setup time to CKE
##               tmpx_lh        ps     ddr4   CS_n Low hold time to CKE rising edge
##               tpl            tck    ddr4   C/A parity latency
##               wcl            tck    ddr4   Write Command Latency
##               twr_crc_dm     tck    ddr4   Write recovery time when CRC and DM are enabled (tWR_CRC_DM = twr + twr_crc_dm)
##               twtr_l_crc_dm  tck    ddr4   tWTR_L's additional delay when CRC and DM are enabled (tWTR_L_CRC_DM = twtr_l_tck + twtr_l_crc_dm)
##               twtr_s_crc_dm  tck    ddr4   tWTR_S's additional delay when CRC and DM are enabled (tWTR_S_CRC_DM = twtr_s_tck + twtr_s_crc_dm)
##               tcrc_alert_pw  tck    ddr4   CRC ALERT_n pulse width (Max)
##               tcrc_alert     ps     ddr4   CRC error to ALERT_n pulse width
##               tpar_alert_pw  tck    ddr4   Pulse width of ALERT_N signal when C/A Parity Error is detected (Max)
##               tpar_unknown   ps     ddr4   Commands not guaranteed to be executed during this time
##               tpar_alert_on  ps     ddr4   Delay from errant command to ALERT_n assertion
##               cal            tck    ddr4   CS to Command Address Latency when cal mode is enabled (and not in geardown mode)
##               tdqsck_dll_off ps     ddr4   Read data Clock to Data Strobe relationship with DLL-off mode
##               tstab          ps     ddr4   Stabilization time
##               trfc_dlr       ps     ddr4   Refresh to Refresh Command to different logical rank
##               trfc_dlr2      ps     ddr4   Refresh to Refresh Command to different logical rank
##               trfc_dlr4      ps     ddr4   Refresh to Refresh Command to different logical rank
##               trrd_dlr       tck    ddr4   Active bank a to Active bank b command time to different logical rank
##               tfaw_dlr       tck    ddr4   Four Bank Activate window to different logical rank
##               tccd_dlr       tck    ddr4   Cas to Cas command delay to different logical rank
##
##
##***************************************************************************
##===========================================================================

#CL_MIN =            9; #// CL         tCK   Minimum CAS Latency
#CL_MAX =           24; #// CL         tCK   Maximum CAS Latency
#AL_MIN =            0; #// AL         tCK   Minimum Additive Latency
#AL_MAX =            2; #// AL         tCK   Maximum Additive Latency
#WR_MIN =           10; #// WR         tCK   Minimum Write Recovery
#WR_MAX =           24; #// WR         tCK   Maximum Write Recovery
#BL_MIN =            4; #// BL         tCK   Minimum Burst Length
#BL_MAX =            8; #// BL         tCK   Minimum Burst Length
#CWL_MIN =           9; #// CWL        tCK   Minimum CAS Write Latency
#CWL_MAX =          18; #// CWL        tCK   Maximum CAS Write Latency

def ParamInClks(param_in_ps, tCK_in_ps)
    return (param_in_ps / (1.0 * tCK_in_ps)).ceil
end

def ddr4_find_speed_grade(clock_speed)
    # find the best suitable DDR4 speed grade given the platform DDR
    # clock speed
    if (clock_speed <= 1066)
        return 0
    elsif (clock_speed <= 1333)
        return 1
    elsif (clock_speed <= 1600)
        return 2
    elsif (clock_speed <= 1866)
        return 3
    elsif (clock_speed <= 2133)
        return 4
    elsif (clock_speed <= 2400)
        return 5
    elsif (clock_speed <= 2667)
        return 6
    elsif (clock_speed <= 2934)
        return 7
    elsif (clock_speed <= 3200)
        return 8
    end
    raise "Unsupported clock speed: #{clock_speed}"
end

def ddr4(params)

ddr4_speed_grade = params[:speed_grade]

###############################################################################################################################
##  ddr4_speed_grade             0        1         2         3         4      5         6       7        8
    pDDR4 =                 [ 1066,    1333,     1600,     1866,    2133,   2400,    2667,    2934,    3200][ddr4_speed_grade]
    pUTYPE_TS =          %w(TS_1875 TS_1500   TS_1250    TS_1072   TS_938  TS_833   TS_750   TS_682  TS_625)[ddr4_speed_grade]
    itCK_min =              [ 1875,    1500,      1250,     1072,    938,    833,     750,     682,     625][ddr4_speed_grade]
    itCK_max =              [ 4000,    1874,      1499,     1249,   1071,    937,     832,     749,     681][ddr4_speed_grade]
    itDQSQ =                [    0,       0,         0,        0,      0,      0,       0,       0,       0][ddr4_speed_grade]
    itDS =                  [  125,     125,       125,      125,    125,    125,     125,     125,     125][ddr4_speed_grade]
    itDH =                  [  125,     125,       125,      125,    125,    125,     125,     125,     125][ddr4_speed_grade]
    itIPW =                 [  938,     750,       560,      535,    470,    416,     375,     341,     312][ddr4_speed_grade]
    itDQSCK =               [    0,       0,         0,        0,      0,      0,       0,       0,       0][ddr4_speed_grade]
    itDQSCK_min =           [ -375,    -300,      -225,     -195,   -180,   -166,    -150,    -136,    -125][ddr4_speed_grade]
    itDQSCK_max =           [  375,     300,       225,      195,    180,    166,     150,     136,     125][ddr4_speed_grade]
    itDLLKc_min =           [  512,     512,       597,      597,    768,    768,     854,     940,    1024][ddr4_speed_grade]
    itRTP =                 [ 7500,    7500,      7500,     7500,   7500,   7500,    7500,    6000,    6000][ddr4_speed_grade]
    itWTRc_S =              [    2,       2,         2,        3,      3,      3,       4,       4,       4][ddr4_speed_grade]
    itWTRc_L =              [    4,       5,         6,        7,      8,      9,      10,      11,      12][ddr4_speed_grade]
    itWTRc_S_CRC_DM =       [    4,       4,         4,        5,      5,      5,       5,       6,       6][ddr4_speed_grade]
    itWTRc_L_CRC_DM =       [    4,       4,         4,        5,      5,      5,       5,       6,       6][ddr4_speed_grade]
    itWR =                  [15000,   15000,     15000,    15000,  15000,  15000,   15000,   15000,   15000][ddr4_speed_grade]
    itWR_CRC_DM =           [    4,       4,         4,        5,      5,      5,       5,       6,       6][ddr4_speed_grade]
    itRCD =                 [17000,   16000,     15000,    13920,  15000,  12750,   13500,   12500,   12500][ddr4_speed_grade]
    itRC =                  [56000,   55000,     50000,    49000,  48000,  44500,   45500,   44960,   44500][ddr4_speed_grade]
    itRP =                  [17000,   15000,     12500,    12850,  15000,  12750,   13500,   12575,   12500][ddr4_speed_grade]
    itRP_ref =              [30000,   30000,     30000,    30000,  30000,  30000,   30000,   30000,   30000][ddr4_speed_grade]
    itCCDc_S =              [    4,       4,         4,        4,      4,      4,       4,       4,       4][ddr4_speed_grade]
    itCCDc_L =              [    5,       5,         5,        5,      6,      6,       7,       7,       7][ddr4_speed_grade]
    itCCD_L =               [ 9375,    7500,      6250,     5355,   5355,   5000,    5000,    5000,    5000][ddr4_speed_grade]
    itRAS_min =             [39000,   39000,     35000,    34000,  33000,  32000,   32000,   32000,   32000][ddr4_speed_grade]
    itRRDc_S_1k =           4
    itRRDc_S_2k =           4
    itRRDc_L_1k =           4
    itRRDc_L_2k =           4
    itRRD_S_1k =            [ 7500,    6000,      5000,     4200,   3700,   3300,    3000,    2700,    2500][ddr4_speed_grade]
    itRRD_S_2k =            [ 7500,    6000,      6000,     5300,   5300,   5300,    5300,    5300,    5300][ddr4_speed_grade]
    itRRD_L_1k =            [ 7500,    6000,      6000,     5300,   5300,   4900,    4900,    4900,    4900][ddr4_speed_grade]
    itRRD_L_2k =            [ 7500,    7500,      7500,     6400,   6400,   6400,    6400,    6400,    6400][ddr4_speed_grade]
    itFAW_1k =              [25000,   25000,     25000,    23000,  21000,  21000,   21000,   21000,   21000][ddr4_speed_grade]
    itFAW_2k =              [35000,   35000,     35000,    30000,  30000,  30000,   30000,   30000,   30000][ddr4_speed_grade]
    itFAWc_1k =             20
    itFAWc_2k =             28
    itIS =                  [  170,     170,       170,      170,    170,    170,     170,     170,     170][ddr4_speed_grade]
    itIH =                  [  120,     120,       120,      120,    120,    120,     120,     120,     120][ddr4_speed_grade]
    itDIPW =                [  560,     450,       360,      320,    280,    250,     230,     200,     190][ddr4_speed_grade]
    itCKE =                 [ 5625,    5000,      5000,     5000,   5000,   5000,    5000,    5000,    5000][ddr4_speed_grade]
    itCPDEDc =              [    4,       4,         4,        4,      4,      4,       4,       4,       4][ddr4_speed_grade]
    itXP =                  [ 7500,    6000,      6000,     6000,   6000,   6000,    6000,    6000,    6000][ddr4_speed_grade]
    itXPDLL =               [24000,   24000,     24000,    24000,  24000,  24000,   24000,   24000,   24000][ddr4_speed_grade]
    itACTPDENc =            [    0,       0,         0,        0,      1,      1,       1,       1,       1][ddr4_speed_grade]
    itPREPDENc =            [    0,       0,         0,        0,      1,      1,       1,       1,       1][ddr4_speed_grade]
    itREFPDENc =            [    0,       0,         0,        0,      1,      1,       1,       1,       1][ddr4_speed_grade]
    itZQinitc =             [ 1024,    1024,      1024,     1024,   1024,   1024,    1024,    1024,    1024][ddr4_speed_grade]
    itZQoperc =             [  512,     512,       512,      512,    512,    512,     512,     512,     512][ddr4_speed_grade]
    itZQCSc =               [  128,     128,       128,      128,    128,    128,     128,     128,     128][ddr4_speed_grade]
    itWLS =                 [  244,     195,       163,      140,    122,    109,      98,      89,      82][ddr4_speed_grade]
    itWLH =                 [  244,     195,       163,      140,    122,    109,      98,      89,      82][ddr4_speed_grade]
    itAON_min =             [ -225,    -225,      -225,     -195,   -180,   -180,    -180,    -180,    -180][ddr4_speed_grade]
    itAON_max =             [  225,     225,       225,      195,    180,    180,     180,     180,     180][ddr4_speed_grade]
    itPAR_ALERT_PWc =       [   48,      47,        72,       84,     96,    108,     108,     108,     108][ddr4_speed_grade]
    itPAR_ALERT_PWc_min =   [   32,      40,        48,       56,     64,     72,      72,      72,      72][ddr4_speed_grade]
    itPAR_ALERT_PWc_max =   [   80,     100,        96,      112,    128,    144,     160,     176,     192][ddr4_speed_grade]
    itCLc =                 [   10,      10,        12,       13,     16,     16,      18,      20,      20][ddr4_speed_grade] ;# CL   tCK  CAS Latency # FIX ME: recheck the value
    itCWLc =                [    9,       9,        11,       10,     14,     12,      14,      16,      16][ddr4_speed_grade] ;# CWL  tCK  CAS write Latency
    itPLc =                 [    4,       4,         4,        4,      4,      5,       6,       6,       6][ddr4_speed_grade] ;# PL   tCK   Parity Latency

# Calculate *real* itCK
itCK = 1000000 / (params[:clock_speed] / 2)
$l.debug "clock = #{params[:clock_speed]}, itCK_min = #{itCK_min}, itCK_max = #{itCK_max}, itCK = #{itCK}"

# itMOD = Max(15ns, 24clk) - by JEDEC standard (DDR4 <= 3200 MHz)
itMOD = max(15000, (24 * itCK))

##      DDR4_               [ 1066,    1333,     1600,     1866,    2133,   2400,    2667,    2934,    3200][ddr4_speed_grade]
##      UTYPE_TS            [ TS_1875, TS_1500,  TS_1250,  TS_1072, TS_938, TS_833,  TS_750,  TS_682,  TS_625][ddr4_speed_grade]

###############################################################################################################################
  # programmable preamble feature is NOT suppoted in current DDR4 MultiPHY(v3.20 : pub/fb3.11a)
  params[:write_preamble] = 0
  params[:read_preamble] =  0
  if params.key?(:ca_parity_mode)
      params[:ca_parity_en] = params[:ca_parity_mode]
  else
      params[:ca_parity_en] = 0
  end
  params[:additive_latency] = 0

    ##// Clock timing.
    nClockDutyCycle =    50
    tCK_min =           itCK_min
    params[:tCK_min] = itCK_min
    tCK_max =           itCK_max
    tCHp_min =          48
    tCHp_min =          52

    ##// Data timing.
    tDQSQ =             itDQSQ
    tQHp =              38
    tDS =               itDS
    tDH =               itDH
    tIPW =              itIPW

    ##// Data strobe timing.
    tRPREp =            100
    tRPSTp =            50
    tQSHp =             40
    tQSLp =             40
    tWPSTp =            50
    tWPREp =            100
    tDQSCK =            itDQSCK
    tDQSCK_dll_on =     itDQSCK
    tDQSCK_min =        itDQSCK_min
    tDQSCK_max =        itDQSCK_max
    tDQSCK_dll_off =    5800
    tDQSCK_dll_off_min =    1000
    tDQSCK_dll_off_max =    9000
    tDQSLp =            50
    tDQSLp_min =        45
    tDQSLp_max =        55
    tDQSHp =            50
    tDQSHp_min =        45
    tDQSHp_max =        55
    tDQSSp =            0
    tDQSSp_1tCK_min =   -27
    tDQSSp_1tCK_max =   27
    tDQSSp_2tCK_min =   tDQSSp_1tCK_min
    tDQSSp_2tCK_max =   tDQSSp_1tCK_max
    tDQSSp_min =        tDQSSp_1tCK_min
    tDQSSp_max =        tDQSSp_1tCK_max

    ## // Command and address timing.
    params[:tPLc] =          params[:ca_parity_en] == 1 ? itPLc : 0;
    params[:tDLLKc] =        itDLLKc_min
    tRTP =                    itRTP
    tRTPc =                   ParamInClks(itRTP, itCK)
    params[:tRTPc] =         params[:write_preamble] == 1 ? tRTPc + 1 : tRTPc;
    tRTP_min =                itRTP
    params[:tRTPc_min] =     4
    params[:tWTRc_S] =       itWTRc_S
    params[:tWTRc_S_CRC_DM] = params[:tWTRc_S] + itWTRc_S_CRC_DM
    params[:tWTRc] =         itWTRc_L ;# added by monika
    params[:tWTRc_L_CRC_DM] = params[:tWTRc] + itWTRc_L_CRC_DM
    tWTR_S_CRC_DM =           3750
    tWTRc_S_CRC_DM =          ParamInClks(tWTR_S_CRC_DM, itCK)
    tWTR_L_CRC_DM =           3750
    tWTRc_L_CRC_DM =          ParamInClks(tWTR_L_CRC_DM, itCK)
    tWR =                     itWR
    params[:tWRc] =          ParamInClks(itWR, itCK)
    params[:tWR_CRC_DMc] =   5
    if params[:write_crc_en]
      params[:tWRc_CRC_DM] =   params[:tWRc] + itWR_CRC_DM
    else
      params[:tWRc_CRC_DM] =   params[:tWRc]
    end
    tMOD =                    itMOD
    tMODc =                   ParamInClks(itMOD, itCK)
    params[:tMPRRc] =        1
    tMRD_PDA =                12000;    # in ps
    if params[:pda_en]
      params[:tMRD_PDAc] =   ParamInClks(tMRD_PDA, itCK)
    end
    if params[:ca_parity_en]
      params[:tMRDc] = tMODc
    else
      params[:tMRDc] = 8
    end

    $l.debug "params[:tMRDc] = #{params[:tMRDc]}"
    params[:tWR_MPRc] =      tMODc
    $l.debug "params[:tWR_MPRc] = tMODc = #{tMODc}"
    tRCD =                    itRCD
    params[:tRCDc] =         ParamInClks(itRCD, itCK)
    tRP =                     itRP
    params[:tRPc] =          ParamInClks(itRP, itCK)
    tRP_ref_internal =        itRP_ref
    tRPc_ref_internal =       ParamInClks(itRP_ref, itCK)
    tRC =                     itRC
    params[:tRCc] =          ParamInClks(itRC, itCK)
    tCCD_S =                  itCCDc_S * itCK
    params[:tCCDc_S] =       itCCDc_S
    itCCDc_L =               max(itCCDc_L, ParamInClks(itCCD_L, itCK))
    if params[:write_preamble] == 1
      params[:tCCDc_L] =     itCCDc_L + 1
    else
      params[:tCCDc_L] =     itCCDc_L;
    end
    # tREFI =                   7800000 ;# 7.8 us
    tREFI =                  3900000 ;# 3.9 us - ROWHAMMER recommendation
    params[:tREFIc] =        ParamInClks(tREFI, itCK)
    tRAS_min =                itRAS_min
    tRAS_max =                9*tREFI
    params[:tRASc_min] =     ParamInClks(itRAS_min, itCK)
    params[:tRAS_max] =      tRAS_max
    params[:tRASc_max] =     ParamInClks(tRAS_max, itCK)
    tPAR_CLOSE_BANKS =        tRAS_max
    tPAR_ALERT_ON =           1400
    tPAR_ALERT_ON_max =       6000
    tPAR_ALERT_ON_CYCLES =    4
    tPAR_ALERT_OFF =          3000
    tPAR_tRP_tRAS_adjustment =       2000
    tPAR_tRP_holdoff_adjustment =    1450
    params[:tPAR_ALERT_PWc] =       itPAR_ALERT_PWc
    tPAR_ALERT_PWc_min =             itPAR_ALERT_PWc_min
    tPAR_ALERT_PWc_max =             itPAR_ALERT_PWc_max
    tPAR_ALERT_PW =                  params[:tPAR_ALERT_PWc] * itCK
    tPAR_ALERT_PW_min =              tPAR_ALERT_PWc_min * itCK
    tPAR_ALERT_PW_max =              tPAR_ALERT_PWc_max * itCK
    tCRC_ALERT =                     9000
    tCRC_ALERT_min =                 3000
    tCRC_ALERT_max =                 13000
    tCRC_ALERT_PWc_min =             6
    tCRC_ALERT_PWc_max =             10
    params[:tCRC_ALERT_PWc] =       7

    case params[:device_bus_width]
    when "x8"
        params[:tFAWc] =    max(itFAWc_1k, ParamInClks(itFAW_1k, itCK))
        params[:tRRDc_S] =  max(itRRDc_S_1k, ParamInClks(itRRD_S_1k, itCK))
        params[:tRRDc_L] =  max(itRRDc_L_1k, ParamInClks(itRRD_L_1k, itCK))
    when "x16"
        params[:tFAWc] =    max(itFAWc_2k, ParamInClks(itFAW_2k, itCK))
        params[:tRRDc_S] =  max(itRRDc_S_2k, ParamInClks(itRRD_S_2k, itCK))
        params[:tRRDc_L] =  max(itRRDc_L_2k, ParamInClks(itRRD_L_2k, itCK))
    else
        raise "Invalid device_bus_width: #{params[:device_bus_width]}"
    end

    params[:tRRDc] = params[:tRRDc_L]
    tIS =            itIS
    tIH =            itIH
    tDIPW =          itDIPW
    # Valid Clock Requirement before Self Refresh Exit (SRX) or Power-Down Exit (PDX) or ReExit =
    tCKSRX =         10000; # in ps
    params[:tCKSRXc] = ParamInClks(tCKSRX, itCK)
    # Valid Clock Requirement after Self Refresh Entry (SRE) or Power-Down Entry (PDE) or ReEntry =
    tCKSRE =         10000; # in ps
    params[:tCKSREc] = ParamInClks(tCKSRE, itCK)

    case params[:configured_density]
    when "2G"
        tRFC1 =    160000
        tRFC2 =    110000
        tRFC4 =    90000
    when "4G"
        tRFC1 =    260000
        tRFC2 =    160000
        tRFC4 =    110000
    when "8G"
        tRFC1 =    350000
        tRFC2 =    260000
        tRFC4 =    160000
    when "16G"
        tRFC1 =    550000
        tRFC2 =    350000
        tRFC4 =    260000
    else
        raise "Invalid configured_density: #{params[:configured_density]}"
    end

    tRFC =      tRFC1
    params[:tRFCc] =  ParamInClks(tRFC1, itCK)
    params[:tRFC1c] = ParamInClks(tRFC1, itCK)
    params[:tRFC2c] = ParamInClks(tRFC2, itCK)
    params[:tRFC4c] = ParamInClks(tRFC4, itCK)


    ##// Retiming =  .
    params[:tXPR] =        tRFC + 10000

    ## // Power down timing.
    if tCK_min > 1500
        params[:tXPc] = 4
        tXP =     4 * tCK_min
    else
        tXP =     6000
        params[:tXPc] = ParamInClks(tXP, itCK)
    end
    params[:tXS_tRFC4] =  tRFC4 + 10000
    params[:tXS_tRFC4c] = ParamInClks(params[:tXS_tRFC4], itCK)
    params[:tXS_tRFC] =   tRFC + 10000
    params[:tXS_tRFCc] =  ParamInClks(params[:tXS_tRFC], itCK)
    tXPDLL =            itXPDLL
    params[:tXPDLLc] =        ParamInClks(itXPDLL, itCK)
    params[:tCKEc] =          ParamInClks(itCKE, itCK)
    params[:tCPDEDc] =        itCPDEDc
    tPD =               itCKE
    params[:tPDc] =           ParamInClks(tPD, itCK)


    ## // Initialization timing.
    tPWRUP =            100000;
    tRESET =            100000; ## // Stable power @100ns ramp @200us.
    tRESETCKE =         100000; ##// Spec is 500us.
    params[:tODTHc] =         4;
    params[:tZQinitc] =       itZQinitc
    params[:tZQoperc] =       itZQoperc
    params[:tZQCSc] =         itZQCSc
    #tZQRTT =                  44_000
    #params[:tZQRTTc] =        ParamInClks(tZQRTT, itCK)

    ## // Write leveling.
    params[:tWLMRDc] =        40;
    params[:tWLDQSENc] =      25;
    params[:tWLSc] =          ParamInClks(itWLS, itCK)
    params[:tWLHc] =          ParamInClks(itWLH, itCK)
    tWLO_min =          0
    tWLOc_min =         0
    tWLO_max =          7500
    tWLOc_max =         ParamInClks(tWLO_max, itCK)
    tWLOE_min =         0
    tWLOEc_min =        0
    #tWLOEc_max =        ParamInClks(tWLOE_max, itCK)
    tWLO_nominal =      (tWLO_min + tWLO_max)/2
    #tWLOE_nominal =     (tWLOE_min + tWLOE_max)/2

#######################################################################################
case params[:device_bus_width]
when "x8"
    params[:DM_BITS] =                  1; #// this =   parameter to control how many Data Mask bits are used
    params[:ADDR_BITS] =               16; #// MAX Address Bits
    params[:BG_BITS] =                  2; #// this =   parameter to control how many Bank groups bits are used
    params[:BA_BITS] =                  2; #// this =   parameter to control how many Bank Address bits are used
    params[:ROW_BITS] =                16; #// this =   parameter to control how many Address bits are used
    params[:COL_BITS] =                10; #// this =   parameter to control how many Column bits are used
    params[:DQ_BITS] =                  8; #// this =   parameter to control how many Data bits are used       **Same as part bit width**
    params[:DQS_BITS] =                 1; #// this =   parameter to control how many Dqs bits are used
when "x16"
    params[:DM_BITS] =                  2; #// this =   parameter to control how many Data Mask bits are used
    params[:ADDR_BITS] =               16; #// MAX Address Bits
    params[:BG_BITS] =                  1; #// this =   parameter to control how many Bank groups bits are used
    params[:BA_BITS] =                  2; #// this =   parameter to control how many Bank Address bits are used
    params[:ROW_BITS] =                16; #// this =   parameter to control how many Address bits are used
    params[:COL_BITS] =                10; #// this =   parameter to control how many Column bits are used
    params[:DQ_BITS] =                 16; #// this =   parameter to control how many Data bits are used       **Same as part bit width**
    params[:DQS_BITS] =                 2; #// this =   parameter to control how many Dqs bits are used
else
    raise "Invalid device_bus_width: #{params[:device_bus_width]}"
end


#######################################################################################


    if params[:write_dbi_en]
      mr5_write_dbi =       params[:write_dbi_en]
      params[:wr_dbi_en] = params[:write_dbi_en]
    else
      mr5_write_dbi =       0
      params[:wr_dbi_en] = 0
    end
    ## // DDR4 Mode Register
    if params[:read_dbi_en]
      #params[:CLc] =  params[:read_dbi_en] ? [expr itCLc + 3] : itCLc; # CAS Latency when read DBI is enabled and speed grade = DDR4_2666
      params[:CLc] =  params[:read_dbi_en] ? 18 : itCLc; # CAS Latency when read DBI is enabled and speed grade = DDR4_2666
      params[:rd_dbi_en] = params[:read_dbi_en]
      mr5_read_dbi =   params[:read_dbi_en]
    else
      params[:CLc] =  itCLc
      params[:rd_dbi_en] = 0
      mr5_read_dbi =   0
    end
    case params[:CLc]
    when 9
        mr0_CL =     "0000"
    when 10
       mr0_CL =      "0001"
    when 11
       mr0_CL =      "0010"
    when 12
       mr0_CL =      "0011"
    when 13
       mr0_CL =      "0100"
    when 14
       mr0_CL =      "0101"
    when 15
       mr0_CL =      "0110"
    when 16
       mr0_CL =      "0111"
    when 18
       mr0_CL =      "1000"
    when 20
       mr0_CL =      "1001"
    when 21
       mr0_CL =      "1111"
    when 22
       mr0_CL =      "1010"
    when 24
       mr0_CL =      "1011"
    else
       mr0_CL =      "1111"
    end
    #$l.debug "CL_bin is mr0_CL and CLc is CLc"

    mr0_A2 =      mr0_CL[3]
    mr0_A6_A4 =   mr0_CL[0..2]
    #$l.debug "mr0_A2 is mr0_A2 and mr0_A6_A4 is mr0_A6_A4 "

    #WRc =              ParamInClks(itWR, itCK); # Write Recovery is in tCK
    nWRc =              params[:tWRc_CRC_DM]; # Write Recovery is in tCK
    mr0_WR_A13 =       "0"
    case nWRc
    when 10
        mr0_WR =      "000"
    when 11, 12
        mr0_WR =      "001"
    when 13, 14
        mr0_WR =      "010"
    when 15, 16
        mr0_WR =      "011"
    when 17, 18
        mr0_WR =      "100"
    when 19, 20
        mr0_WR =      "101"
    when 21, 22
        mr0_WR =      "111"
    when 23, 24
        mr0_WR =      "110"
    when 25, 26
        mr0_WR =      "000"
        mr0_WR_A13 =  "1"
    else
        mr0_WR =      "000"
    end
    $l.debug "WR_bin is #{mr0_WR} and WRc is #{nWRc}"

    params[:CWLc] = params[:write_preamble] == 1 ? itCWLc + 2 : itCWLc; #  CAS Write Latency in tCK
    $l.debug "params[:CWLc] = #{params[:CWLc]}"
    case params[:CWLc]
    when 9
       mr2_CWL =      "000"
    when 10
       mr2_CWL =      "001"
    when 11
       mr2_CWL =      "010"
    when 12
       mr2_CWL =      "011"
    when 14
       mr2_CWL =      "100"
    when 16
       mr2_CWL =      "101"
    when 18
       mr2_CWL =      "110"
    else
        mr2_CWL =     "111"
    end
    $l.debug "CWLc_bin is #{mr2_CWL} and CWLc is #{params[:CWLc]}"

    tCAL_ps =        3748;    # TCAL(min) ps CS_n to Command Address Latency
    tCAL_tck =       ParamInClks(tCAL_ps, itCK) + 1; # TCAL(min) tck CS_n to Command Address Latency

    if params[:cal_en]
        params[:tCAL] = tCAL_tck
        case tCAL_tck
        when 0
            mr4_CAL =   "000"
        when 3
            mr4_CAL =   "001"
        when 4
            mr4_CAL =   "010"
        when 5
            mr4_CAL =   "011"
        when 6
            mr4_CAL =   "100"
        when 8
            mr4_CAL =   "101"
        else
            mr4_CAL =   "000"
        end
    else
        params[:tCAL] = 0
        mr4_CAL =   "000"
    end
    $l.debug "params[:tCAL] = #{params[:tCAL]}, mr4_CAL = #{mr4_CAL}"

    case tMODc
    when 24
        params[:tMOD] = 0
    when 25
        params[:tMOD] = 1
    when 26
        params[:tMOD] = 2
    when 27
        params[:tMOD] = 3
    when 28
        params[:tMOD] = 4
    when 29
        params[:tMOD] = 5
    when 30
        params[:tMOD] = 6
    else
        raise "Error: Reserved tMOD '#{tMODc}'"
    end

    case params[:tCCDc_L]
    when 4
        mr6_tCCD_L =      "000"
    when 5
        mr6_tCCD_L =      "001"
    when 6
        mr6_tCCD_L =      "010"
    when 7
        mr6_tCCD_L =      "011"
    when 8
        mr6_tCCD_L =      "100"
    else
        error "Error: Reserved tCCD_L"
    end

    case params[:tPLc]
    when 0
       mr5_tPLc =      "000"
    when 4
       mr5_tPLc =      "001"
    when 5
       mr5_tPLc =      "010"
    when 6
       mr5_tPLc =      "011"
    when 8
       mr5_tPLc =      "100"
    else
        error "Error: Reserved tPLc "
    end

    if params[:additive_latency] == 0
        mr1_AL =        "00"
        params[:AL] =   0
    elsif params[:additive_latency] == 1
        mr1_AL =        "01"
        params[:AL] =  params[:CLc] - 1;
    elsif params[:additive_latency] == 2
        mr1_AL =        "10"
        params[:AL] =  params[:CLc] - 2;
    else
        error "Error: Reserved Additive latency "
        mr1_AL =        "00"
        params[:AL] =  0
    end

    #params[:write_crc] = write_crc

    if params[:write_crc_en]
        mr2_write_CRC =       params[:write_crc_en]
        params[:write_crc] = params[:write_crc_en]
    else
        mr2_write_CRC =       0
        params[:write_crc] = 0
    end

     if params[:write_dm]
       # Using below setting only for chip level DDR bringup TC.
       # This is to aviod X propagation from DDR memory to AXI level.
         mr5_write_DM =   params[:write_dm]
         params[:dm_en] = 1
     else
       mr5_write_DM =    params[:wr_dbi_en] == 1 ? 0 : 1
       params[:dm_en] = mr5_write_DM
     end

     if mr5_write_DM && mr2_write_CRC
       if ddr4_speed_grade < 3                                      ; # speed_grade = 1600
         mr3_WCL =        "00"
       # As per JEDEC DDR4 Spec, mr3_WCL should be configured to 5nCK ("01") for speed grade = 1866, 2133, 2400 and 2666.
       # However, after configuring as per JEDEC spec, I am getting an error message from DDR4 model (saying tck SPEC_VIOLATION),
       # while running the write_crc_ca_parity test case. After changing the mr3_WCL value from 5nCK to 6nCK ("10") for speed grade
       # = 2666, it resolves the error. Hence, the value for write command latency field in MR3[A10:A9] for speed grade = 2666
       # is not configured as per the JEDEC spec.
       elsif (ddr4_speed_grade > 2 ) && (ddr4_speed_grade < 6)  ; # speed_grade = 1866, 2133, 2400
           mr3_WCL =        "01"
       else                                                          ; # speed_grade >= 2666
           mr3_WCL =        "10"
       end
     else
       mr3_WCL =    "00"
     end
     params[:mr3_WCL] = mr3_WCL
     #$l.debug "mr3_WCL = #{mr3_WCL}"

     params[:BL] =     8     ; # Burst Length : FIX ME, Burst length in binary 8(fixed) for

    # Write Latency = AL + CWL + PL
    params[:WL] =     params[:AL] + params[:CWLc] + params[:tPLc]; #// WL         tCK           write Latency
    $l.debug "write Latency = #{params[:WL]}"

    # Read Latency  = AL + CL + PL
    params[:RL] =     params[:AL] + params[:CLc] + params[:tPLc]; #// RL         tCK           read Latency
    $l.debug "read Latency = #{params[:RL]}"

    params[:WR_PREAMBLE] =  params[:write_preamble] == 1 ? 2 : 1;
    params[:RD_PREAMBLE] =  params[:read_preamble] == 1  ? 2 : 1;


################################################################################################
## Configure MODE Register based on JEDEC DDR4
## fields are defined in binary
################################################################################################

  ########################################
  ## MODE Register 0
  ########################################
  mr0_A15_A14 =                    "00"; # // mr0[15:14]
  mr0_A13 =               mr0_WR_A13; # // mr0[A13]
  mr0_A12 =                         "0"; # // mr0[12]   : RFU
  mr0_A11_A9 =                mr0_WR; # // mr0[11:9] : Write Recovery and read to precharge for Auto precharge
  mr0_A8 =                          "0"; # // mr0[8]    : DLL Reset : FIX ME
  mr0_A7 =                          "0"; # // mr0[7]    : TM
  mr0_A6_A4 =              mr0_A6_A4; # // mr0[6:4]  : CAS latency bit [A6:A4]
  mr0_A3 =                          "0"; # // mr0[3:3]  : Read burst type
  mr0_A2 =                    mr0_A2; # // mr0[2:2]  : CAS latency bit A2
  mr0_A1_A0 =                      "00"; # // mr0[1:0]  : Burst length : BC8/BC4

  mr0_bits =                  mr0_A15_A14 + mr0_WR_A13 + mr0_A12 + mr0_A11_A9 + mr0_A8 + mr0_A7 + mr0_A6_A4 + mr0_A3 + mr0_A2 + mr0_A1_A0
  params[:reg_ddrc_mr] =      mr0_bits.to_i(2)
  $l.debug "mr0_bits is .......... #{mr0_bits}"
  $l.debug "reg_ddrc_mr is ....... #{params[:reg_ddrc_mr]}"

  ########################################
  ## MODE Register 1
  ########################################
  mr1_A15_A11 =                "00000" ; # // mr1[15:11]:
  mr1_A10_A8 =                   "101" ; # // mr1[10:8] : RTT_NOM
  mr1_A7 =                         "0" ; # // mr1[7]    : Write Leveling Enable
  mr1_A6_A5 =                     "00" ; # // mr1[6:5]  : RFU
  mr1_A4_A3 =                mr1_AL ; # // mr1[4:3]  : Additive Latency
  mr1_A2_A1 =                     "00" ; # // mr1[2:1]  : Output Driver Impedance control
  mr1_A0 =                         "1" ; # // mr1[0]    : 0 = DLL disable, 1 = DLL enable

  mr1_bits =                  mr1_A15_A11 + mr1_A10_A8 + mr1_A7 + mr1_A6_A5 + mr1_A4_A3 + mr1_A2_A1 + mr1_A0
  params[:reg_ddrc_emr] =     mr1_bits.to_i(2)
  $l.debug "mr1_bits is .......... #{mr1_bits}"
  $l.debug "reg_ddrc_emr is ...... #{params[:reg_ddrc_emr]}"

  ########################################
  ## MODE Register 2
  ########################################
  mr2_A15_A13 =                 "000" ; # // mr2[15:13] :
  mr2_A12 =          mr2_write_CRC.to_s ; # // mr2[12]    : Write CRC
  mr2_A11 =                       "0" ; # // mr2[11]    : RFU
  mr2_A10_A9 =                   "00" ; # // mr2[10:9]  : RTT_WR : FIX ME
  mr2_A8 =                        "0" ; # // mr2[8]     : RFU
  mr2_A7_A6 =                    "00" ; # // mr2[7:6]   : Low power array self refresh
  mr2_A5_A3 =              mr2_CWL ; # // mr2[5:3]   : CAS write latency
  mr2_A2_A0 =                   "000" ; # // mr2[2:0]   : RFU

  mr2_bits =                   mr2_A15_A13 + mr2_A12 + mr2_A11 + mr2_A10_A9 + mr2_A8 + mr2_A7_A6 + mr2_A5_A3 + mr2_A2_A0
  params[:reg_ddrc_emr2] =     mr2_bits.to_i(2)
  $l.debug "mr2_bits is .......... #{mr2_bits}"
  $l.debug "reg_ddrc_emr2 is ..... #{params[:reg_ddrc_emr2]}"

  ########################################
  ## MODE Register 3
  ########################################
  mr3_A15_A13 =                 "000"; # // mr2[15:13]   :
  mr3_A12_A11 =                  "00"; # // mr3[12:11]   : MPR read format
  mr3_A10_A9 =             mr3_WCL; # // mr3[10:9]    : Write Command Latency when CRC and DM are enabled
  mr3_A8_A6 =                   "000"; # // mr3[8:6]     : Fine Granularity Refresh mode
  mr3_A5 =                        "0"; # // mr3[5]       : TSR
  mr3_A4 =                        "0"; # // mr3[4]       : Per DRAM addressability
  mr3_A3 =                        "0"; # // mr3[3]       : Geardown Mode
  mr3_A2 =                        "0"; # // mr3[2]       : MPR Operation
  mr3_A1_A0 =                    "00"; # // mr3[1:0]     : MPR Page Selection

  mr3_bits =                   mr3_A15_A13 + mr3_A12_A11 + mr3_A10_A9 + mr3_A8_A6 + mr3_A5 + mr3_A4 + mr3_A3 + mr3_A2 + mr3_A1_A0
  params[:reg_ddrc_emr3] =     mr3_bits.to_i(2)
  $l.debug "mr3_bits is .......... #{mr3_bits}"
  $l.debug "reg_ddrc_emr3 is ..... #{params[:reg_ddrc_emr3]}"

  ########################################
  ## MODE Register 4
  ########################################
  mr4_A5_A13 =                  "000"; # // mr4[15:13] :
  mr4_A12 =   params[:write_preamble].to_s; # // mr4[12]    : write preamble
  mr4_A11 =    params[:read_preamble].to_s; # // mr4[11]    : read preamble
  mr4_A10 =                       "0"; # // mr4[10]    : read preamble training mode
  mr4_A9 =                        "0"; # // mr4[9]     : self refresh abort
  mr4_A8_A6 =              mr4_CAL; # // mr4[8:6]   : CS to CMD/ADDR latency mode
  mr4_A5_A4 =                    "00"; # // mr4[5:4]   : 5: RFU and 4 : Internal Vref Monitor
  mr4_A3 =                        "0"; # // mr4[3]     : Temperature Controlled refresh mode
  mr4_A2 =                        "0"; # // mr4[2]     : Temperature Controlled refresh range
  mr4_A1 =                        "0"; # // mr4[1]     : Maximum power down mode
  mr4_A0 =                        "0"; # // mr4[0]     : RFU

  mr4_bits =                    mr4_A5_A13 + mr4_A12 + mr4_A11 + mr4_A10 + mr4_A9 + mr4_A8_A6 + mr4_A5_A4 + mr4_A3 + mr4_A2 + mr4_A1 + mr4_A0
  params[:reg_ddrc_mr4] =       mr4_bits.to_i(2)
  $l.debug "mr4_bits is .......... #{mr4_bits}"
  $l.debug "reg_ddrc_mr4 is ...... #{params[:reg_ddrc_mr4]}"

  ########################################
  ## MODE Register 5
  ########################################
  mr5_A15_A13 =                 "000"; #  // mr5[15:13]  :
  mr5_A12 =           mr5_read_dbi.to_s; #  // mr5[12]     :  read_dbi
  mr5_A11 =          mr5_write_dbi.to_s; #  // mr5[11]     :  write_dbi
  mr5_A10 =           mr5_write_DM.to_s; #  // mr5[10]     :  data_mask
  mr5_A9 =                        "0"; #  // mr5[9]      :  ca_parity_persistent
  mr5_A8_A6 =                   "000"; #  // mr5[8:6]    :  rtt_park
  mr5_A5 =                        "0"; #  // mr5[5]      :  odt
  mr5_A4 =                        "0"; #  // mr5[4]      :  ca_parity_err_sts
  mr5_A3 =                        "0"; #  // mr5[3]      :  crc_err_clear
  mr5_A2_A0 =             mr5_tPLc; #  // mr5[2:0]    :  parity_latency_mode

  mr5_bits =                    mr5_A15_A13 + mr5_A12 + mr5_A11 + mr5_A10 + mr5_A9 + mr5_A8_A6 + mr5_A5 + mr5_A4 + mr5_A3 + mr5_A2_A0
  params[:reg_ddrc_mr5] =       mr5_bits.to_i(2)
  $l.debug "mr5_bits is .......... #{mr5_bits}"
  $l.debug "reg_ddrc_mr5 is ...... #{params[:reg_ddrc_mr5]}"

  ########################################
  ## MODE Register 6
  ########################################
  mr6_A15_A13 =                 "000"; # // mr6[15:13]  :
  mr6_A12_A10 =         mr6_tCCD_L; # // mr6[12:10]  : tccd_l
  mr6_A9_A8 =                    "00"; # // mr6[9:8]    : RFU
  mr6_A7 =                        "0"; # // mr6[7]      : VRefDQ Training Enable
  mr6_A6 =                        "0"; # // mr6[6]      : VRefDQ Training range
  mr6_A5_A0 =                "011001"; # // mr6[5:0]    : VRefDQ Training value

  mr6_bits =                   mr6_A15_A13 + mr6_A12_A10 + mr6_A9_A8 + mr6_A7 + mr6_A6 + mr6_A5_A0
  params[:reg_ddrc_mr6] =      mr6_bits.to_i(2)
  $l.debug "mr6_bits is .......... #{mr6_bits}"
  $l.debug "reg_ddrc_mr6 is ...... #{params[:reg_ddrc_mr6]}"

  return params

end
