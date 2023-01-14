# Converted from 4Gb_ddr3_timing_parameter.tcl

#// Mode Register
CL_MIN =                     5; #// CL         tCK   Minimum CAS Latency
CL_MAX =                    14; #// CL         tCK   Maximum CAS Latency
AL_MIN =                     0; #// AL         tCK   Minimum Additive Latency
AL_MAX =                     2; #// AL         tCK   Maximum Additive Latency
WR_MIN =                     5; #// WR         tCK   Minimum Write Recovery
WR_MAX =                    16; #// WR         tCK   Maximum Write Recovery
BL_MIN =                     4; #// BL         tCK   Minimum Burst Length
BL_MAX =                     8; #// BL         tCK   Minimum Burst Length
CWL_MIN =                    5; #// CWL        tCK   Minimum CAS Write Latency
CWL_MAX =                   10; #// CWL        tCK   Maximum CAS Write Latency

def ParamInClks(param_in_ps, tCK_in_ps)
    return (param_in_ps / (1.0 * tCK_in_ps)).ceil
end

def ddr3(params)

    #// Timing parameters based on 4Gb_DDR3_SDRAM.pdf - Rev. L 2/13 EN
                                    #// SYMBOL     UNITS DESCRIPTION
                                    #// ------     ----- -----------
case params[:speed_grade]
when "sg093"                        #// sg093  is equivalent to the JEDEC DDR3-2133 (14-14-14) speed bin
    tCK_MIN =                  938; #// tCK        ps    Minimum Clock Cycle Time
    tJIT_PER =                  50; #// tJIT(per)  ps    Period JItter
    tJIT_CC =                  100; #// tJIT(cc)   ps    Cycle to Cycle jitter
    tERR_2PER =                 74; #// tERR(2per) ps    Accumulated Error (2-cycle)
    tERR_3PER =                 87; #// tERR(3per) ps    Accumulated Error (3-cycle)
    tERR_4PER =                 97; #// tERR(4per) ps    Accumulated Error (4-cycle)
    tERR_5PER =                105; #// tERR(5per) ps    Accumulated Error (5-cycle)
    tERR_6PER =                111; #// tERR(6per) ps    Accumulated Error (6-cycle)
    tERR_7PER =                116; #// tERR(7per) ps    Accumulated Error (7-cycle)
    tERR_8PER =                121; #// tERR(8per) ps    Accumulated Error (8-cycle)
    tERR_9PER =                125; #// tERR(9per) ps    Accumulated Error (9-cycle)
    tERR_10PER =               128; #// tERR(10per)ps    Accumulated Error (10-cycle)
    tERR_11PER =               132; #// tERR(11per)ps    Accumulated Error (11-cycle)
    tERR_12PER =               134; #// tERR(12per)ps    Accumulated Error (12-cycle)
    tDS =                        5; #// tDS        ps    DQ and DM input setup time relative to DQS
    tDH =                       20; #// tDH        ps    DQ and DM input hold time relative to DQS
    tDQSQ =                     70; #// tDQSQ      ps    DQS-DQ skew, DQS to last DQ valid, per group, per access
    tDQSS =                   0.27; #// tDQSS      tCK   Rising clock edge to DQS/DQS# latching transition
    tDSS =                    0.18; #// tDSS       tCK   DQS falling edge to CLK rising (setup time)
    tDSH =                    0.18; #// tDSH       tCK   DQS falling edge from CLK rising (hold time)
    tDQSCK =                   180; #// tDQSCK     ps    DQS output access time from CK/CK#
    tQSH =                    0.40; #// tQSH       tCK   DQS Output High Pulse Width
    tQSL =                    0.40; #// tQSL       tCK   DQS Output Low Pulse Width
    tDIPW =                    280; #// tDIPW      ps    DQ and DM input Pulse Width
    tIPW =                     400; #470; #// tIPW       ps    Control and Address input Pulse Width
    tIS =                       35; #// tIS        ps    Input Setup Time
    tIH =                       75; #// tIH        ps    Input Hold Time
    tRAS_MIN =               33000; #// tRAS       ps    Minimum Active to Precharge command time
    tRC =                    46130; #// tRC        ps    Active to Active/Auto Refresh command time
    tRCD =                   13090; #// tRCD       ps    Active to Read/Write command time
    tRP =                    14090; #// tRP        ps    Precharge command period
    tXP =                     6000; #// tXP        ps    Exit power down to a valid command
    tCKE =                    5000; #// tCKE       ps    CKE minimum high or low pulse width
    tAON =                     180; #// tAON       ps    RTT turn-on from ODTLon reference
    tWLS =                     122; #// tWLS       ps    Setup time for tDQS flop
    tWLH =                     122; #// tWLH       ps    Hold time of tDQS flop
    tWLO =                    7500; #// tWLO       ps    Write levelization output delay
    tAA_MIN =                13090; #// TAA        ps    Internal READ command to first data
    nCL_TIME =               13090; #// CL         ps    Minimum CAS Latency
    nCLc =                      14; #// CL               CAS Latency
    nCWLc =                     10; #// CWL              CAS Write Latency
when "sg107"                      ; #// sg107 is equivalent to the JEDEC DDR3-1866 (13-13-13) speed bin
    tCK_MIN =                 1071; #// tCK        ps    Minimum Clock Cycle Time
    tJIT_PER =                  60; #// tJIT(per)  ps    Period JItter
    tJIT_CC =                  120; #// tJIT(cc)   ps    Cycle to Cycle jitter
    tERR_2PER =                 88; #// tERR(2per) ps    Accumulated Error (2-cycle)
    tERR_3PER =                105; #// tERR(3per) ps    Accumulated Error (3-cycle)
    tERR_4PER =                117; #// tERR(4per) ps    Accumulated Error (4-cycle)
    tERR_5PER =                126; #// tERR(5per) ps    Accumulated Error (5-cycle)
    tERR_6PER =                133; #// tERR(6per) ps    Accumulated Error (6-cycle)
    tERR_7PER =                139; #// tERR(7per) ps    Accumulated Error (7-cycle)
    tERR_8PER =                145; #// tERR(8per) ps    Accumulated Error (8-cycle)
    tERR_9PER =                150; #// tERR(9per) ps    Accumulated Error (9-cycle)
    tERR_10PER =               154; #// tERR(10per)ps    Accumulated Error (10-cycle)
    tERR_11PER =               158; #// tERR(11per)ps    Accumulated Error (11-cycle)
    tERR_12PER =               161; #// tERR(12per)ps    Accumulated Error (12-cycle)
    tDS =                       10; #// tDS        ps    DQ and DM input setup time relative to DQS
    tDH =                       20; #// tDH        ps    DQ and DM input hold time relative to DQS
    tDQSQ =                     80; #// tDQSQ      ps    DQS-DQ skew, DQS to last DQ valid, per group, per access
    tDQSS =                   0.27; #// tDQSS      tCK   Rising clock edge to DQS/DQS# latching transition
    tDSS =                    0.18; #// tDSS       tCK   DQS falling edge to CLK rising (setup time)
    tDSH =                    0.18; #// tDSH       tCK   DQS falling edge from CLK rising (hold time)
    tDQSCK =                   200; #// tDQSCK     ps    DQS output access time from CK/CK#
    tQSH =                    0.40; #// tQSH       tCK   DQS Output High Pulse Width
    tQSL =                    0.40; #// tQSL       tCK   DQS Output Low Pulse Width
    tDIPW =                    320; #// tDIPW      ps    DQ and DM input Pulse Width
    tIPW =                     535; #// tIPW       ps    Control and Address input Pulse Width
    tIS =                       50; #// tIS        ps    Input Setup Time
    tIH =                      100; #// tIH        ps    Input Hold Time
    tRAS_MIN =               34000; #// tRAS       ps    Minimum Active to Precharge command time
    tRC =                    47910; #// tRC        ps    Active to Active/Auto Refresh command time
    tRCD =                   13910; #// tRCD       ps    Active to Read/Write command time
    tRP =                    13910; #// tRP        ps    Precharge command period
    tXP =                     6000; #// tXP        ps    Exit power down to a valid command
    tCKE =                    5000; #// tCKE       ps    CKE minimum high or low pulse width
    tAON =                     200; #// tAON       ps    RTT turn-on from ODTLon reference
    tWLS =                     140; #// tWLS       ps    Setup time for tDQS flop
    tWLH =                     140; #// tWLH       ps    Hold time of tDQS flop
    tWLO =                    7500; #// tWLO       ps    Write levelization output delay
    tAA_MIN =                13910; #// TAA        ps    Internal READ command to first data
    nCL_TIME =               13910; #// CL         ps    Minimum CAS Latency
    nCLc =                      13; #// CL               CAS Latency
    nCWLc =                      9; #// CWL              CAS Write Latency
when "sg125"                      ; #// sg125 is equivalent to the JEDEC DDR3-1600 (11-11-11) speed bin
    tCK_MIN =                 1250; #// tCK        ps    Minimum Clock Cycle Time
    tJIT_PER =                  70; #// tJIT(per)  ps    Period JItter
    tJIT_CC =                  140; #// tJIT(cc)   ps    Cycle to Cycle jitter
    tERR_2PER =                103; #// tERR(2per) ps    Accumulated Error (2-cycle)
    tERR_3PER =                122; #// tERR(3per) ps    Accumulated Error (3-cycle)
    tERR_4PER =                136; #// tERR(4per) ps    Accumulated Error (4-cycle)
    tERR_5PER =                147; #// tERR(5per) ps    Accumulated Error (5-cycle)
    tERR_6PER =                155; #// tERR(6per) ps    Accumulated Error (6-cycle)
    tERR_7PER =                163; #// tERR(7per) ps    Accumulated Error (7-cycle)
    tERR_8PER =                169; #// tERR(8per) ps    Accumulated Error (8-cycle)
    tERR_9PER =                175; #// tERR(9per) ps    Accumulated Error (9-cycle)
    tERR_10PER =               180; #// tERR(10per)ps    Accumulated Error (10-cycle)
    tERR_11PER =               184; #// tERR(11per)ps    Accumulated Error (11-cycle)
    tERR_12PER =               188; #// tERR(12per)ps    Accumulated Error (12-cycle)
    tDS =                       10; #// tDS        ps    DQ and DM input setup time relative to DQS
    tDH =                       45; #// tDH        ps    DQ and DM input hold time relative to DQS
    tDQSQ =                    100; #// tDQSQ      ps    DQS-DQ skew, DQS to last DQ valid, per group, per access
    tDQSS =                   0.27; #// tDQSS      tCK   Rising clock edge to DQS/DQS# latching transition
    tDSS =                    0.18; #// tDSS       tCK   DQS falling edge to CLK rising (setup time)
    tDSH =                    0.18; #// tDSH       tCK   DQS falling edge from CLK rising (hold time)
    tDQSCK =                   225; #// tDQSCK     ps    DQS output access time from CK/CK#
    tQSH =                    0.40; #// tQSH       tCK   DQS Output High Pulse Width
    tQSL =                    0.40; #// tQSL       tCK   DQS Output Low Pulse Width
    tDIPW =                    360; #// tDIPW      ps    DQ and DM input Pulse Width
    tIPW =                     560; #// tIPW       ps    Control and Address input Pulse Width
    tIS =                      170; #// tIS        ps    Input Setup Time
    tIH =                      120; #// tIH        ps    Input Hold Time
    tRAS_MIN =               35000; #// tRAS       ps    Minimum Active to Precharge command time
    tRC =                    48750; #// tRC        ps    Active to Active/Auto Refresh command time
    tRCD =                   13750; #// tRCD       ps    Active to Read/Write command time
    tRP =                    13750; #// tRP        ps    Precharge command period
    tXP =                     6000; #// tXP        ps    Exit power down to a valid command
    tCKE =                    5000; #// tCKE       ps    CKE minimum high or low pulse width
    tAON =                     250; #// tAON       ps    RTT turn-on from ODTLon reference
    tWLS =                     165; #// tWLS       ps    Setup time for tDQS flop
    tWLH =                     165; #// tWLH       ps    Hold time of tDQS flop
    tWLO =                    7500; #// tWLO       ps    Write levelization output delay
    tAA_MIN =                13750; #// TAA        ps    Internal READ command to first data
    nCL_TIME =               13750; #// CL         ps    Minimum CAS Latency
    nCLc =                      11; #// CL               CAS Latency
    nCWLc =                      8; #// CWL              CAS Write Latency
when "sg15E"                      ; #// sg15E is equivalent to the JEDEC DDR3-1333H (9-9-9) speed bin
    tCK_MIN =                 1500; #// tCK        ps    Minimum Clock Cycle Time
    tJIT_PER =                  80; #// tJIT(per)  ps    Period JItter
    tJIT_CC =                  160; #// tJIT(cc)   ps    Cycle to Cycle jitter
    tERR_2PER =                118; #// tERR(2per) ps    Accumulated Error (2-cycle)
    tERR_3PER =                140; #// tERR(3per) ps    Accumulated Error (3-cycle)
    tERR_4PER =                155; #// tERR(4per) ps    Accumulated Error (4-cycle)
    tERR_5PER =                168; #// tERR(5per) ps    Accumulated Error (5-cycle)
    tERR_6PER =                177; #// tERR(6per) ps    Accumulated Error (6-cycle)
    tERR_7PER =                186; #// tERR(7per) ps    Accumulated Error (7-cycle)
    tERR_8PER =                193; #// tERR(8per) ps    Accumulated Error (8-cycle)
    tERR_9PER =                200; #// tERR(9per) ps    Accumulated Error (9-cycle)
    tERR_10PER =               205; #// tERR(10per)ps    Accumulated Error (10-cycle)
    tERR_11PER =               210; #// tERR(11per)ps    Accumulated Error (11-cycle)
    tERR_12PER =               215; #// tERR(12per)ps    Accumulated Error (12-cycle)
    tDS =                       30; #// tDS        ps    DQ and DM input setup time relative to DQS
    tDH =                       65; #// tDH        ps    DQ and DM input hold time relative to DQS
    tDQSQ =                    125; #// tDQSQ      ps    DQS-DQ skew, DQS to last DQ valid, per group, per access
    tDQSS =                   0.25; #// tDQSS      tCK   Rising clock edge to DQS/DQS# latching transition
    tDSS =                    0.20; #// tDSS       tCK   DQS falling edge to CLK rising (setup time)
    tDSH =                    0.20; #// tDSH       tCK   DQS falling edge from CLK rising (hold time)
    tDQSCK =                   255; #// tDQSCK     ps    DQS output access time from CK/CK#
    tQSH =                    0.40; #// tQSH       tCK   DQS Output High Pulse Width
    tQSL =                    0.40; #// tQSL       tCK   DQS Output Low Pulse Width
    tDIPW =                    400; #// tDIPW      ps    DQ and DM input Pulse Width
    tIPW =                     620; #// tIPW       ps    Control and Address input Pulse Width
    tIS =                      190; #// tIS        ps    Input Setup Time
    tIH =                      140; #// tIH        ps    Input Hold Time
    tRAS_MIN =               36000; #// tRAS       ps    Minimum Active to Precharge command time
    tRC =                    49500; #// tRC        ps    Active to Active/Auto Refresh command time
    tRCD =                   13500; #// tRCD       ps    Active to Read/Write command time
    tRP =                    13500; #// tRP        ps    Precharge command period
    tXP =                     6000; #// tXP        ps    Exit power down to a valid command
    tCKE =                    5625; #// tCKE       ps    CKE minimum high or low pulse width
    tAON =                     250; #// tAON       ps    RTT turn-on from ODTLon reference
    tWLS =                     195; #// tWLS       ps    Setup time for tDQS flop
    tWLH =                     195; #// tWLH       ps    Hold time of tDQS flop
    tWLO =                    9000; #// tWLO       ps    Write levelization output delay
    tAA_MIN =                13500; #// TAA        ps    Internal READ command to first data
    nCL_TIME =               13500; #// CL         ps    Minimum CAS Latency
    nCLc =                       9; #// CL               CAS Latency
    nCWLc =                      7; #// CWL              CAS Write Latency
when "sg15"                       ; #// sg15 is equivalent to the JEDEC DDR3-1333J (10-10-10) speed bin
    tCK_MIN =                 1500; #// tCK        ps    Minimum Clock Cycle Time
    tJIT_PER =                  80; #// tJIT(per)  ps    Period JItter
    tJIT_CC =                  160; #// tJIT(cc)   ps    Cycle to Cycle jitter
    tERR_2PER =                118; #// tERR(2per) ps    Accumulated Error (2-cycle)
    tERR_3PER =                140; #// tERR(3per) ps    Accumulated Error (3-cycle)
    tERR_4PER =                155; #// tERR(4per) ps    Accumulated Error (4-cycle)
    tERR_5PER =                168; #// tERR(5per) ps    Accumulated Error (5-cycle)
    tERR_6PER =                177; #// tERR(6per) ps    Accumulated Error (6-cycle)
    tERR_7PER =                186; #// tERR(7per) ps    Accumulated Error (7-cycle)
    tERR_8PER =                193; #// tERR(8per) ps    Accumulated Error (8-cycle)
    tERR_9PER =                200; #// tERR(9per) ps    Accumulated Error (9-cycle)
    tERR_10PER =               205; #// tERR(10per)ps    Accumulated Error (10-cycle)
    tERR_11PER =               210; #// tERR(11per)ps    Accumulated Error (11-cycle)
    tERR_12PER =               215; #// tERR(12per)ps    Accumulated Error (12-cycle)
    tDS =                       30; #// tDS        ps    DQ and DM input setup time relative to DQS
    tDH =                       65; #// tDH        ps    DQ and DM input hold time relative to DQS
    tDQSQ =                    125; #// tDQSQ      ps    DQS-DQ skew, DQS to last DQ valid, per group, per access
    tDQSS =                   0.25; #// tDQSS      tCK   Rising clock edge to DQS/DQS# latching transition
    tDSS =                    0.20; #// tDSS       tCK   DQS falling edge to CLK rising (setup time)
    tDSH =                    0.20; #// tDSH       tCK   DQS falling edge from CLK rising (hold time)
    tDQSCK =                   255; #// tDQSCK     ps    DQS output access time from CK/CK#
    tQSH =                    0.40; #// tQSH       tCK   DQS Output High Pulse Width
    tQSL =                    0.40; #// tQSL       tCK   DQS Output Low Pulse Width
    tDIPW =                    400; #// tDIPW      ps    DQ and DM input Pulse Width
    tIPW =                     620; #// tIPW       ps    Control and Address input Pulse Width
    tIS =                      190; #// tIS        ps    Input Setup Time
    tIH =                      140; #// tIH        ps    Input Hold Time
    tRAS_MIN =               36000; #// tRAS       ps    Minimum Active to Precharge command time
    tRC =                    51000; #// tRC        ps    Active to Active/Auto Refresh command time
    tRCD =                   15000; #// tRCD       ps    Active to Read/Write command time
    tRP =                    15000; #// tRP        ps    Precharge command period
    tXP =                     6000; #// tXP        ps    Exit power down to a valid command
    tCKE =                    5625; #// tCKE       ps    CKE minimum high or low pulse width
    tAON =                     250; #// tAON       ps    RTT turn-on from ODTLon reference
    tWLS =                     195; #// tWLS       ps    Setup time for tDQS flop
    tWLH =                     195; #// tWLH       ps    Hold time of tDQS flop
    tWLO =                    9000; #// tWLO       ps    Write levelization output delay
    tAA_MIN =                15000; #// TAA        ps    Internal READ command to first data
    nCL_TIME =               15000; #// CL         ps    Minimum CAS Latency
    nCLc =                      10; #// CL               CAS Latency
    nCWLc =                      7; #// CWL              CAS Write Latency
when "sg187E"                     ; #// sg187E is equivalent to the JEDEC DDR3-1066 (7-7-7) speed bin
    tCK_MIN =                 1875; #// tCK        ps    Minimum Clock Cycle Time
    tJIT_PER =                  90; #// tJIT(per)  ps    Period JItter
    tJIT_CC =                  180; #// tJIT(cc)   ps    Cycle to Cycle jitter
    tERR_2PER =                132; #// tERR(2per) ps    Accumulated Error (2-cycle)
    tERR_3PER =                157; #// tERR(3per) ps    Accumulated Error (3-cycle)
    tERR_4PER =                175; #// tERR(4per) ps    Accumulated Error (4-cycle)
    tERR_5PER =                188; #// tERR(5per) ps    Accumulated Error (5-cycle)
    tERR_6PER =                200; #// tERR(6per) ps    Accumulated Error (6-cycle)
    tERR_7PER =                209; #// tERR(7per) ps    Accumulated Error (7-cycle)
    tERR_8PER =                217; #// tERR(8per) ps    Accumulated Error (8-cycle)
    tERR_9PER =                224; #// tERR(9per) ps    Accumulated Error (9-cycle)
    tERR_10PER =               231; #// tERR(10per)ps    Accumulated Error (10-cycle)
    tERR_11PER =               237; #// tERR(11per)ps    Accumulated Error (11-cycle)
    tERR_12PER =               242; #// tERR(12per)ps    Accumulated Error (12-cycle)
    tDS =                       75; #// tDS        ps    DQ and DM input setup time relative to DQS
    tDH =                      100; #// tDH        ps    DQ and DM input hold time relative to DQS
    tDQSQ =                    150; #// tDQSQ      ps    DQS-DQ skew, DQS to last DQ valid, per group, per access
    tDQSS =                   0.25; #// tDQSS      tCK   Rising clock edge to DQS/DQS# latching transition
    tDSS =                    0.20; #// tDSS       tCK   DQS falling edge to CLK rising (setup time)
    tDSH =                    0.20; #// tDSH       tCK   DQS falling edge from CLK rising (hold time)
    tDQSCK =                   300; #// tDQSCK     ps    DQS output access time from CK/CK#
    tQSH =                    0.38; #// tQSH       tCK   DQS Output High Pulse Width
    tQSL =                    0.38; #// tQSL       tCK   DQS Output Low Pulse Width
    tDIPW =                    490; #// tDIPW      ps    DQ and DM input Pulse Width
    tIPW =                     780; #// tIPW       ps    Control and Address input Pulse Width
    tIS =                      275; #// tIS        ps    Input Setup Time
    tIH =                      200; #// tIH        ps    Input Hold Time
    tRAS_MIN =               37500; #// tRAS       ps    Minimum Active to Precharge command time
    tRC =                    50625; #// tRC        ps    Active to Active/Auto Refresh command time
    tRCD =                   13125; #// tRCD       ps    Active to Read/Write command time
    tRP =                    13125; #// tRP        ps    Precharge command period
    tXP =                     7500; #// tXP        ps    Exit power down to a valid command
    tCKE =                    5625; #// tCKE       ps    CKE minimum high or low pulse width
    tAON =                     300; #// tAON       ps    RTT turn-on from ODTLon reference
    tWLS =                     245; #// tWLS       ps    Setup time for tDQS flop
    tWLH =                     245; #// tWLH       ps    Hold time of tDQS flop
    tWLO =                    9000; #// tWLO       ps    Write levelization output delay
    tAA_MIN =                13125; #// TAA        ps    Internal READ command to first data
    nCL_TIME =               13125; #// CL         ps    Minimum CAS Latency
    nCLc =                       7; #// CL               CAS Latency
    nCWLc =                      6; #// CWL              CAS Write Latency
when "sg187"                      ; #// sg187  is equivalent to the JEDEC DDR3-1066G (8-8-8) speed bin
    tCK_MIN =                 1875; #// tCK        ps    Minimum Clock Cycle Time
    tJIT_PER =                  90; #// tJIT(per)  ps    Period JItter
    tJIT_CC =                  180; #// tJIT(cc)   ps    Cycle to Cycle jitter
    tERR_2PER =                132; #// tERR(2per) ps    Accumulated Error (2-cycle)
    tERR_3PER =                157; #// tERR(3per) ps    Accumulated Error (3-cycle)
    tERR_4PER =                175; #// tERR(4per) ps    Accumulated Error (4-cycle)
    tERR_5PER =                188; #// tERR(5per) ps    Accumulated Error (5-cycle)
    tERR_6PER =                200; #// tERR(6per) ps    Accumulated Error (6-cycle)
    tERR_7PER =                209; #// tERR(7per) ps    Accumulated Error (7-cycle)
    tERR_8PER =                217; #// tERR(8per) ps    Accumulated Error (8-cycle)
    tERR_9PER =                224; #// tERR(9per) ps    Accumulated Error (9-cycle)
    tERR_10PER =               231; #// tERR(10per)ps    Accumulated Error (10-cycle)
    tERR_11PER =               237; #// tERR(11per)ps    Accumulated Error (11-cycle)
    tERR_12PER =               242; #// tERR(12per)ps    Accumulated Error (12-cycle)
    tDS =                       75; #// tDS        ps    DQ and DM input setup time relative to DQS
    tDH =                      100; #// tDH        ps    DQ and DM input hold time relative to DQS
    tDQSQ =                    150; #// tDQSQ      ps    DQS-DQ skew, DQS to last DQ valid, per group, per access
    tDQSS =                   0.25; #// tDQSS      tCK   Rising clock edge to DQS/DQS# latching transition
    tDSS =                    0.20; #// tDSS       tCK   DQS falling edge to CLK rising (setup time)
    tDSH =                    0.20; #// tDSH       tCK   DQS falling edge from CLK rising (hold time)
    tDQSCK =                   300; #// tDQSCK     ps    DQS output access time from CK/CK#
    tQSH =                    0.38; #// tQSH       tCK   DQS Output High Pulse Width
    tQSL =                    0.38; #// tQSL       tCK   DQS Output Low Pulse Width
    tDIPW =                    490; #// tDIPW      ps    DQ and DM input Pulse Width
    tIPW =                     780; #// tIPW       ps    Control and Address input Pulse Width
    tIS =                      275; #// tIS        ps    Input Setup Time
    tIH =                      200; #// tIH        ps    Input Hold Time
    tRAS_MIN =               37500; #// tRAS       ps    Minimum Active to Precharge command time
    tRC =                    52500; #// tRC        ps    Active to Active/Auto Refresh command time
    tRCD =                   15000; #// tRCD       ps    Active to Read/Write command time
    tRP =                    15000; #// tRP        ps    Precharge command period
    tXP =                     7500; #// tXP        ps    Exit power down to a valid command
    tCKE =                    5625; #// tCKE       ps    CKE minimum high or low pulse width
    tAON =                     300; #// tAON       ps    RTT turn-on from ODTLon reference
    tWLS =                     245; #// tWLS       ps    Setup time for tDQS flop
    tWLH =                     245; #// tWLH       ps    Hold time of tDQS flop
    tWLO =                    9000; #// tWLO       ps    Write levelization output delay
    tAA_MIN =                15000; #// TAA        ps    Internal READ command to first data
    nCL_TIME =               15000; #// CL         ps    Minimum CAS Latency
    nCLc =                       8; #// CL               CAS Latency
    nCWLc =                      6; #// CWL              CAS Write Latency
when "sg25E"                      ; #// sg25E is equivalent to the JEDEC DDR3-800D (5-5-5) speed bin
    tCK_MIN =                 2500; #// tCK        ps    Minimum Clock Cycle Time
    tJIT_PER =                 100; #// tJIT(per)  ps    Period JItter
    tJIT_CC =                  200; #// tJIT(cc)   ps    Cycle to Cycle jitter
    tERR_2PER =                147; #// tERR(2per) ps    Accumulated Error (2-cycle)
    tERR_3PER =                175; #// tERR(3per) ps    Accumulated Error (3-cycle)
    tERR_4PER =                194; #// tERR(4per) ps    Accumulated Error (4-cycle)
    tERR_5PER =                209; #// tERR(5per) ps    Accumulated Error (5-cycle)
    tERR_6PER =                222; #// tERR(6per) ps    Accumulated Error (6-cycle)
    tERR_7PER =                232; #// tERR(7per) ps    Accumulated Error (7-cycle)
    tERR_8PER =                241; #// tERR(8per) ps    Accumulated Error (8-cycle)
    tERR_9PER =                249; #// tERR(9per) ps    Accumulated Error (9-cycle)
    tERR_10PER =               257; #// tERR(10per)ps    Accumulated Error (10-cycle)
    tERR_11PER =               263; #// tERR(11per)ps    Accumulated Error (11-cycle)
    tERR_12PER =               269; #// tERR(12per)ps    Accumulated Error (12-cycle)
    tDS =                      125; #// tDS        ps    DQ and DM input setup time relative to DQS
    tDH =                      150; #// tDH        ps    DQ and DM input hold time relative to DQS
    tDQSQ =                    200; #// tDQSQ      ps    DQS-DQ skew, DQS to last DQ valid, per group, per access
    tDQSS =                   0.25; #// tDQSS      tCK   Rising clock edge to DQS/DQS# latching transition
    tDSS =                    0.20; #// tDSS       tCK   DQS falling edge to CLK rising (setup time)
    tDSH =                    0.20; #// tDSH       tCK   DQS falling edge from CLK rising (hold time)
    tDQSCK =                   400; #// tDQSCK     ps    DQS output access time from CK/CK#
    tQSH =                    0.38; #// tQSH       tCK   DQS Output High Pulse Width
    tQSL =                    0.38; #// tQSL       tCK   DQS Output Low Pulse Width
    tDIPW =                    600; #// tDIPW      ps    DQ and DM input Pulse Width
    tIPW =                     900; #// tIPW       ps    Control and Address input Pulse Width
    tIS =                      350; #// tIS        ps    Input Setup Time
    tIH =                      275; #// tIH        ps    Input Hold Time
    tRAS_MIN =               37500; #// tRAS       ps    Minimum Active to Precharge command time
    tRC =                    50000; #// tRC        ps    Active to Active/Auto Refresh command time
    tRCD =                   12500; #// tRCD       ps    Active to Read/Write command time
    tRP =                    12500; #// tRP        ps    Precharge command period
    tXP =                     7500; #// tXP        ps    Exit power down to a valid command
    tCKE =                    7500; #// tCKE       ps    CKE minimum high or low pulse width
    tAON =                     400; #// tAON       ps    RTT turn-on from ODTLon reference
    tWLS =                     325; #// tWLS       ps    Setup time for tDQS flop
    tWLH =                     325; #// tWLH       ps    Hold time of tDQS flop
    tWLO =                    9000; #// tWLO       ps    Write levelization output delay
    tAA_MIN =                12500; #// TAA        ps    Internal READ command to first data
    nCL_TIME =               12500; #// CL         ps    Minimum CAS Latency
    nCLc =                       5; #// CL               CAS Latency
    nCWLc =                      5; #// CWL              CAS Write Latency
when "sg25"                       ; #// sg25 is equivalent to the JEDEC DDR3-800E (6-6-6) speed bin
    tCK_MIN =                 2500; #// tCK        ps    Minimum Clock Cycle Time
    tJIT_PER =                 100; #// tJIT(per)  ps    Period JItter
    tJIT_CC =                  200; #// tJIT(cc)   ps    Cycle to Cycle jitter
    tERR_2PER =                147; #// tERR(2per) ps    Accumulated Error (2-cycle)
    tERR_3PER =                175; #// tERR(3per) ps    Accumulated Error (3-cycle)
    tERR_4PER =                194; #// tERR(4per) ps    Accumulated Error (4-cycle)
    tERR_5PER =                209; #// tERR(5per) ps    Accumulated Error (5-cycle)
    tERR_6PER =                222; #// tERR(6per) ps    Accumulated Error (6-cycle)
    tERR_7PER =                232; #// tERR(7per) ps    Accumulated Error (7-cycle)
    tERR_8PER =                241; #// tERR(8per) ps    Accumulated Error (8-cycle)
    tERR_9PER =                249; #// tERR(9per) ps    Accumulated Error (9-cycle)
    tERR_10PER =               257; #// tERR(10per)ps    Accumulated Error (10-cycle)
    tERR_11PER =               263; #// tERR(11per)ps    Accumulated Error (11-cycle)
    tERR_12PER =               269; #// tERR(12per)ps    Accumulated Error (12-cycle)
    tDS =                      125; #// tDS        ps    DQ and DM input setup time relative to DQS
    tDH =                      150; #// tDH        ps    DQ and DM input hold time relative to DQS
    tDQSQ =                    200; #// tDQSQ      ps    DQS-DQ skew, DQS to last DQ valid, per group, per access
    tDQSS =                   0.25; #// tDQSS      tCK   Rising clock edge to DQS/DQS# latching transition
    tDSS =                    0.20; #// tDSS       tCK   DQS falling edge to CLK rising (setup time)
    tDSH =                    0.20; #// tDSH       tCK   DQS falling edge from CLK rising (hold time)
    tDQSCK =                   400; #// tDQSCK     ps    DQS output access time from CK/CK#
    tQSH =                    0.38; #// tQSH       tCK   DQS Output High Pulse Width
    tQSL =                    0.38; #// tQSL       tCK   DQS Output Low Pulse Width
    tDIPW =                    600; #// tDIPW      ps    DQ and DM input Pulse Width
    tIPW =                     900; #// tIPW       ps    Control and Address input Pulse Width
    tIS =                      350; #// tIS        ps    Input Setup Time
    tIH =                      275; #// tIH        ps    Input Hold Time
    tRAS_MIN =               37500; #// tRAS       ps    Minimum Active to Precharge command time
    tRC =                    52500; #// tRC        ps    Active to Active/Auto Refresh command time
    tRCD =                   15000; #// tRCD       ps    Active to Read/Write command time
    tRP =                    15000; #// tRP        ps    Precharge command period
    tXP =                     7500; #// tXP        ps    Exit power down to a valid command
    tCKE =                    7500; #// tCKE       ps    CKE minimum high or low pulse width
    tAON =                     400; #// tAON       ps    RTT turn-on from ODTLon reference
    tWLS =                     325; #// tWLS       ps    Setup time for tDQS flop
    tWLH =                     325; #// tWLH       ps    Hold time of tDQS flop
    tWLO =                    9000; #// tWLO       ps    Write levelization output delay
    tAA_MIN =                15000; #// TAA        ps    Internal READ command to first data
    nCL_TIME =               15000; #// CL         ps    Minimum CAS Latency
    nCLc =                       6; #// CL               CAS Latency
    nCWLc =                      5; #// CWL              CAS Write Latency
end

tDQSCK_DLLDIS =        tDQSCK;      #// tDQSCK     ps    for DLLDIS mode, timing not guaranteed

case params[:CONFIGURED_DQ_BITS]
when "x16"
    case params[:speed_grade]
    when "sg093"
      tRRD =                    6000; #// tRRD       ps     (2KB page size) Active bank a to Active bank b command time
      tFAW =                   35000; #// tFAW       ps     (2KB page size) Four Bank Activate window
    when "sg107"
      tRRD =                    6000; #// tRRD       ps     (2KB page size) Active bank a to Active bank b command time
      tFAW =                   35000; #// tFAW       ps     (2KB page size) Four Bank Activate window
    when "sg125"
      tRRD =                    7500; #// tRRD       ps     (2KB page size) Active bank a to Active bank b command time
      tFAW =                   40000; #// tFAW       ps     (2KB page size) Four Bank Activate window
    when "sg15E"
      tRRD =                    7500; #// tRRD       ps     (2KB page size) Active bank a to Active bank b command time
      tFAW =                   45000; #// tFAW       ps     (2KB page size) Four Bank Activate window
    when "sg15"
      tRRD =                    7500; #// tRRD       ps     (2KB page size) Active bank a to Active bank b command time
      tFAW =                   45000; #// tFAW       ps     (2KB page size) Four Bank Activate window
    else  ;#// sg187E, sg187, sg25, sg25E
      tRRD =                   10000; #// tRRD       ps     (2KB page size) Active bank a to Active bank b command time
      tFAW =                   50000; #// tFAW       ps     (2KB page size) Four Bank Activate window
    end
else #// x4, x8
    case params[:speed_grade]
    when "sg093"
      tRRD =                    5000; #// tRRD       ps     (1KB page size) Active bank a to Active bank b command time
      tFAW =                   25000; #// tFAW       ps     (1KB page size) Four Bank Activate window
    when "sg107"
      tRRD =                    5000; #// tRRD       ps     (1KB page size) Active bank a to Active bank b command time
      tFAW =                   25000; #// tFAW       ps     (1KB page size) Four Bank Activate window
    when "sg125"
      tRRD =                    6000; #// tRRD       ps     (1KB page size) Active bank a to Active bank b command time
      tFAW =                   30000; #// tFAW       ps     (1KB page size) Four Bank Activate window
    when "sg15E"
      tRRD =                    6000; #// tRRD       ps     (1KB page size) Active bank a to Active bank b command time
      tFAW =                   30000; #// tFAW       ps     (1KB page size) Four Bank Activate window
    when "sg15"
      tRRD =                    6000; #// tRRD       ps     (1KB page size) Active bank a to Active bank b command time
      tFAW =                   30000; #// tFAW       ps     (1KB page size) Four Bank Activate window
    when "sg187E"
      tRRD =                    7500; #// tRRD       ps     (1KB page size) Active bank a to Active bank b command time
      tFAW =                   37500; #// tFAW       ps     (1KB page size) Four Bank Activate window
    when "sg187"
      tRRD =                    7500; #// tRRD       ps     (1KB page size) Active bank a to Active bank b command time
      tFAW =                   37500; #// tFAW       ps     (1KB page size) Four Bank Activate window
    else ;#// sg25, sg25E
      tRRD =                   10000; #// tRRD       ps     (1KB page size) Active bank a to Active bank b command time
      tFAW =                   40000; #// tFAW       ps     (1KB page size) Four Bank Activate window
    end
end

    #// Timing Parameters

    #// Clock
    tCK_MAX =                 3300; #// tCK        ps    Maximum Clock Cycle Time
    tCH_AVG_MIN =             0.47; #// tCH        tCK   Minimum Clock High-Level Pulse Width
    tCL_AVG_MIN =             0.47; #// tCL        tCK   Minimum Clock Low-Level Pulse Width
    tCH_AVG_MAX =             0.53; #// tCH        tCK   Maximum Clock High-Level Pulse Width
    tCL_AVG_MAX =             0.53; #// tCL        tCK   Maximum Clock Low-Level Pulse Width
    tCH_ABS_MIN =             0.43; #// tCH        tCK   Minimum Clock High-Level Pulse Width
    tCL_ABS_MIN =             0.43; #// tCL        tCK   Maximum Clock Low-Level Pulse Width
    params[:tCK_min] = tCK_MIN
    params[:tCKEc] = ParamInClks(tCKE, tCK_MIN); #// tCKE       tCK   CKE minimum high or low pulse width
    tAA_MAX =                 20000; #// TAA        ps    Internal READ command to first data

    #// Data OUT
    tQH =                     0.38; #// tQH        ps    DQ output hold time from DQS, DQS#
    #// Data Strobe OUT
    tRPRE =                   0.90; #// tRPRE      tCK   DQS Read Preamble
    tRPST =                   0.30; #// tRPST      tCK   DQS Read Postamble
    #// Data Strobe IN
    tDQSH =                   0.45; #// tDQSH      tCK   DQS input High Pulse Width
    tDQSL =                   0.45; #// tDQSL      tCK   DQS input Low Pulse Width
    tWPRE =                   0.90; #// tWPRE      tCK   DQS Write Preamble
    tWPST =                   0.30; #// tWPST      tCK   DQS Write Postamble
    #// Command and Address
    #int   tZQCS;                   #// tZQCS      tCK   ZQ Cal (Short) time
    tZQinit =               640000; #// tZQinit    ps   ZQ Cal (Long) time
    params[:tZQinitc] =    ParamInClks(tZQinit, tCK_MIN); #// tZQinit    tCK   ZQ Cal (Long) time
    #int   tZQOPER;                 #// tZQoper    tCK   ZQ Cal (Long) time
    params[:tCCDc] =            4; #// tCCD       tCK   Cas to Cas command delay
    params[:tCCD_DGc] =         2; #// tCCD_DG    tCK   Cas to Cas command delay to different group
    tRAS_MAX =                60e9; #// tRAS       ps    Maximum Active to Precharge command time
    tWR =                    15000; #// tWR        ps    Write recovery time
    params[:tMRDc] =            4; #// tMRD       tCK   Load Mode Register command cycle time
    tMOD =                   15000; #// tMOD       ps    LOAD MODE to non-LOAD MODE command cycle time
    tMODc =                  ParamInClks(tMOD, tCK_MIN); #// tMOD       tCK   LOAD MODE to non-LOAD MODE command cycle time
    params[:tRRDc] =        ParamInClks(tRRD, tCK_MIN); #// tRRD       tck   Active bank a to Active bank b command time
    tRRD_DG =                 3000; #// tRRD_DG    ps    Active bank a to Active bank b command time to different group
    params[:tRRD_DGc] =         2; #// tRRD_DG    tCK   Active bank a to Active bank b command time to different group
    tRTP =                    7500; #// tRTP       ps    Read to Precharge command delay
    params[:tRTPc] =        ParamInClks(tRTP, tCK_MIN); #// tRTP       tCK   Read to Precharge command delay
    tWTR =                    7500; #// tWTR       ps    Write to Read command delay
    tWTR_DG =                 3750; #// tWTR_DG    ps    Write to Read command delay to different group
    params[:tWTRc] =        ParamInClks(tWTR, tCK_MIN); #// tWTR       tCK   Write to Read command delay
    params[:tWTR_DGc] =         2; #// tWTR_DG    tCK   Write to Read command delay to different group
    params[:tDLLKc] =         512; #// tDLLK      tCK   DLL locking time
    #// Refresh - 4Gb
    tRFC_MIN =              260000; #// tRFC       ps    Refresh to Refresh Command interval minimum value
    tRFC_MAX =            70200000; #// tRFC       ps    Refresh to Refresh Command Interval maximum value
    #// Power Down
    params[:tXPc] =         ParamInClks(tXP, tCK_MIN); #// tXP        tCK   Exit power down to a valid command
    tXPDLL =                 24000; #// tXPDLL     ps    Exit precharge power down to READ or WRITE command (DLL-off mode)
    params[:tXPDLLc] =      ParamInClks(tXPDLL, tCK_MIN); #// tXPDLL     tCK   Exit precharge power down to READ or WRITE command (DLL-off mode)
    params[:tACTPDENc] =        1; #// tACTPDEN   tCK   Timing of last ACT command to power down entry
    params[:tPRPDENc] =         1; #// tPREPDEN   tCK   Timing of last PRE command to power down entry
    params[:tREFPDENc] =        1; #// tARPDEN    tCK   Timing of last REFRESH command to power down entry
    params[:tCPDEDc] =          1; #// tCPDED     tCK   Command pass disable/enable delay
    tPD_MAX =            tRFC_MAX; #// tPD        ps    Power-down entry-to-exit timing
    params[:tXPR] =      tRFC_MIN + 10000; #// tXPR       ps    Exit Reset from CKE assertion to a valid command
    params[:tXS_tRFC] = tRFC_MIN + 10000; # tXS: Exit Self Refresh to commands not requiring a locked DLL.
    params[:tXS_tRFCc] = ParamInClks(params[:tXS_tRFC], tCK_MIN); # # tXS in tck: Exit Self Refresh to commands not requiring a locked DLL.
    #// Self Refresh
    tXS =                   260000; #// tXS        ps    Exit self refesh to a non-read or write command
    params[:tXSc] =        ParamInClks(tXS, tCK_MIN); #// tXS        tCK   Exit self refesh to a non-read or write command
    params[:tXSDLLc] = params[:tDLLKc]; #// tXSRD      tCK   Exit self refresh to a read or write command
    #tISXR =                  tTIS; #// tISXR      ps    CKE setup time during self refresh exit.
    tCKSRE =                 10000; #// tCKSRE     ps    Valid Clock requirement after self refresh entry (SRE)
    params[:tCKSREc] =          5; #// tCKSRE     tCK   Valid Clock requirement after self refresh entry (SRE)
    tCKSRX =                 10000; #// tCKSRX     ps    Valid Clock requirement prior to self refresh exit (SRX)
    params[:tCKSRXc] =          5; #// tCKSRX     tCK   Valid Clock requirement prior to self refresh exit (SRX)
    params[:tCKESRc] =          4; #// tCKESR     tCK   Minimum CKE low width for Self Refresh entry to exit timing
    #// ODT
    params[:tAOFc] =                 0.7; #// tAOF       tCK   RTT turn-off from ODTLoff reference
    tAONPD =                  8500; #// tAONPD     ps    Asynchronous RTT turn-on delay (Power-Down with DLL frozen)
    tAOFPD =                  8500; #// tAONPD     ps    Asynchronous RTT turn-off delay (Power-Down with DLL frozen)
    params[:ODTH4c] =           4; #// ODTH4      tCK   ODT minimum HIGH time after ODT assertion or write (BL4)
    params[:ODTH8c] =           6; #// ODTH8      tCK   ODT minimum HIGH time after write (BL8)
    params[:tADCc] =          0.7; #// tADC       tCK   RTT dynamic change skew
    #// Write Levelization
    params[:tWLMRDc] =         40; #// tWLMRD     tCK   First DQS pulse rising edge after tDQSS margining mode is programmed
    params[:tWLDQSENc] =       25; #// tWLDQSEN   tCK   DQS/DQS delay after tDQSS margining mode is programmed
    tWLOE =                   2000; #// tWLOE      ps    Write levelization output error

    #// Size Parameters based on Part Width
case params[:CONFIGURED_DQ_BITS]
when "x4"
    params[:DM_BITS] =                  1; #// Set this set to control how many Data Mask bits are used
    params[:ADDR_BITS] =               16; #// MAX Address Bits
    params[:ROW_BITS] =                16; #// Set this parameter to control how many Address bits are used
    params[:COL_BITS] =                11; #// Set this parameter to control how many Column bits are used
    params[:DQ_BITS] =                  4; #// Set this parameter to control how many Data bits are used       **Same as part bit width**
    params[:DQS_BITS] =                 1; #// Set this parameter to control how many Dqs bits are used
when "x8"
    params[:DM_BITS] =                  1; #// Set this parameter to control how many Data Mask bits are used
    params[:ADDR_BITS] =               16; #// MAX Address Bits
    params[:ROW_BITS] =                16; #// Set this parameter to control how many Address bits are used
    params[:COL_BITS] =                10; #// Set this parameter to control how many Column bits are used
    params[:DQ_BITS] =                  8; #// Set this parameter to control how many Data bits are used       **Same as part bit width**
    params[:DQS_BITS] =                 1; #// Set this parameter to control how many Dqs bits are used
when "x16"
    params[:DM_BITS] =                  2; #// Set this parameter to control how many Data Mask bits are used
    params[:ADDR_BITS] =               15; #// MAX Address Bits
    params[:ROW_BITS] =                15; #// Set this parameter to control how many Address bits are used
    params[:COL_BITS] =                10; #// Set this parameter to control how many Column bits are used
    params[:DQ_BITS] =                 16; #// Set this parameter to control how many Data bits are used       **Same as part bit width**
    params[:DQS_BITS] =                 2; #// Set this parameter to control how many Dqs bits are used
end

    #// Size Parameters
    params[:BA_BITS] =          3; #// Set this parmaeter to control how many Bank Address bits are used
    # MEM_BITS =                  10; #// Set this parameter to control how many write data bursts can be stored in memory.  The default is 2^10 1024.
    # AP =                        10; #// the address bit that controls auto-precharge and precharge-all
    # BC =                        12; #// the address bit that controls burst chop
    # BL_BITS =                    3; #// the number of bits required to count to BL_MAX
    # BO_BITS =                    2; #// the number of Burst Order Bits

    #// monika : added parameters
    tREFI =                      7800000 ;# 7.8 us
    params[:tWR_MPRc] =         tMODc
    params[:tRPc] =             ParamInClks(tRP, tCK_MIN)      ; #// tRP        tCK    Precharge command period
    params[:tFAWc] =            ParamInClks(tFAW, tCK_MIN)     ; #// tFAW       tCK    Four Bank Activate window
    params[:tRFCc] =            ParamInClks(tRFC_MIN, tCK_MIN) ; #// tRFC_MIN   tCK    Refresh to Refresh Command interval
    params[:tRCDc] =            ParamInClks(tRCD, tCK_MIN)     ; #// tRCD       tCK    Active to Read/Write command time
    params[:tRCc] =             ParamInClks(tRC, tCK_MIN)      ; #// tRC        tCK    Active to Active/Auto Refresh command time
    params[:tWRc] =             ParamInClks(tWR, tCK_MIN)      ; #// tWR        tCK    Write recovery
    tRAS_max =                   9*tREFI
    params[:tRASc_min] =        ParamInClks(tRAS_MIN, tCK_MIN) ; #// tRAS       tCK    Minimum Active to Precharge command time
    params[:tRAS_max] =         tRAS_max
    params[:tRASc_max] =        ParamInClks(tRAS_max, tCK_MIN); #// tRAS  tCK    Maximun Active to Precharge command time
    params[:tREFIc] =           ParamInClks(tREFI, tCK_MIN)


    ################################################################################################

    ################################################################################################
    ## CAS latency : binay value for mode register
    params[:CLc] = nCLc
    case params[:CLc]
    when 5
       mr0_CL =      "0010"
    when 6
       mr0_CL =      "0100"
    when 7
       mr0_CL =      "0110"
    when 8
       mr0_CL =      "1000"
    when 9
       mr0_CL =      "1010"
    when 10
       mr0_CL =      "1100"
    when 11
       mr0_CL =      "1110"
    when 12
       mr0_CL =      "0001"
    when 13
       mr0_CL =      "0011"
    when 14
       mr0_CL =      "0101"
    when 15
       mr0_CL =      "0111"
    when 16
       mr0_CL =      "1001"
     else
       mr0_CL =      "1111"
    end
    $l.debug "CL_bin is #{mr0_CL} and CLc is #{nCLc}"
    mr0_A2 =      mr0_CL[3]
    mr0_A6_A4 =   mr0_CL[0..2]
    $l.debug "mr0_A2 is #{mr0_A2} and mr0_A6_A4 is #{mr0_A6_A4}"

    ## Write Recovery : binay value for mode register
    case params[:tWRc]
    when 16
       mr0_WR =      "000"
    when 5
       mr0_WR =      "001"
    when 6
       mr0_WR =      "010"
    when 7
       mr0_WR =      "011"
    when 8
       mr0_WR =      "100"
    when 10
       mr0_WR =      "101"
    when 12
       mr0_WR =      "110"
    when 14
       mr0_WR =      "111"
    else
        raise "Error: 4Gb_ddr3_timing_parameter.tcl:: Incorrect Write recovery"
    end
    $l.debug "WR_bin is #{mr0_WR} and WRc is #{params[:tWRc]}"

    # ## Write CAS latency : binay value for mode register
    params[:CWLc] = nCWLc
    case params[:CWLc]
    when 5
       mr2_CWL =      "000"
    when 6
       mr2_CWL =      "001"
    when 7
       mr2_CWL =      "010"
    when 8
       mr2_CWL =      "011"
    when 9
       mr2_CWL =      "100"
    when 10
       mr2_CWL =      "101"
    when 11
       mr2_CWL =      "110"
    when 12
       mr2_CWL =      "111"
    else
        error "Error: 4Gb_ddr3_timing_parameter.tcl:: Incorrect Write CAS latency"
    end
    $l.debug "CWLc_bin is #{mr2_CWL} and CWLc is #{params[:CWLc]}"

    case tMODc
    when 12
      params[:tMOD] = 0
    when 13
      params[:tMOD] = 1
    when 14
      params[:tMOD] = 2
    when 15
      params[:tMOD] = 3
    when 16
      params[:tMOD] = 4
    when 17
      params[:tMOD] = 5
    else
        raise "Error: Reserved tMOD #{tMODc}"
    end

    params[:AL] =     0 ; #CLc - 2;       # FIX ME : Additive Latency in binary
    params[:BL] =     8 ; # Burst Length : FIX ME, Burst length in binary 8(fixed) for

    # Write Latency = AL + CWL
    params[:WL] =     params[:AL] + params[:CWLc]; #// WL         tCK           write Latency

    # Read Latency  = AL + CL
    params[:RL] =     params[:AL] + params[:CLc];  #// RL         tCK           read Latency

    ###############################################################################################
    # Configure MODE Register based on JEDEC DDR3
    # fields are defined in binary
    ###############################################################################################

    ########################################
    ## MODE Register 0
    ########################################
    mr0_A15_A13 =                "000"; # // mr0[15:13]
    mr0_A12 =                      "1"; # // mr0[12]   : PPD
    mr0_A11_A9 =                mr0_WR; # // mr0[11:9] : Write Recovery and read to precharge for Auto precharge
    mr0_A8 =                       "1"; # // mr0[8]    : DLL Reset
    mr0_A7 =                       "0"; # // mr0[7]    : TM
    mr0_A6_A4 =              mr0_A6_A4; # // mr0[6:4]  : CAS latency bit [A6:A4]
    mr0_A3 =                       "0"; # // mr0[3:3]  : Read burst type
    mr0_A2 =                    mr0_A2; # // mr0[2:2]  : CAS latency bit A2
    mr0_A1_A0 =                   "00"; # // mr0[1:0]  : Burst length

    mr0_bits = mr0_A15_A13 + mr0_A12 + mr0_A11_A9 + mr0_A8 + mr0_A7 + mr0_A6_A4 + mr0_A3 + mr0_A2 + mr0_A1_A0
    params[:reg_ddrc_mr] = mr0_bits.to_i(2)
    $l.debug "mr0_bits is .......... #{mr0_bits}"
    $l.debug "reg_ddrc_mr is ....... #{params[:reg_ddrc_mr]}"

    ########################################
    ## MODE Register 1
    ########################################
    mr1_A15_A11 =             "00000" ; # // mr1[15:11]: TDQS and output buffer enable
    mr1_A10_A8 =                "000" ; # // mr1[10:8] : RTT_NOM
    mr1_A7 =                      "0" ; # // mr1[7]    : Write Leveling Enable
    mr1_A6 =                      "0" ; # // mr1[6]    : RTT_NOM
    mr1_A5 =                      "0" ; # // mr1[5]    : Output Driver Impedance control
    mr1_A4_A3 =                  "00" ; # // mr1[4:3]  : Additive Latency
    mr1_A2 =                      "0" ; # // mr1[2]    : RTT nom
    mr1_A1 =                      "0" ; # // mr1[1]    : Output Driver Impedance control
    mr1_A0 =                      "0" ; # // mr1[0]    : 0 = DLL enable, 1 = DLL disable

    mr1_bits = mr1_A15_A11 + mr1_A10_A8 + mr1_A7 + mr1_A6 + mr1_A5 + mr1_A4_A3 + mr1_A2 + mr1_A1 + mr1_A0
    params[:reg_ddrc_emr] = mr1_bits.to_i(2)
    $l.debug "reg_ddrc_emr is ...... #{params[:reg_ddrc_emr]}"

    ########################################
    ## MODE Register 2
    ########################################
    mr2_A15_A13 =              "000" ; # // mr2[15:13] :
    mr2_A12 =                    "0" ; # // mr2[12]    :
    mr2_A11 =                    "0" ; # // mr2[11]    :
    mr2_A10_A9 =                "00" ; # // mr2[10:9]  : RTT_WR : FIX ME
    mr2_A8 =                     "0" ; # // mr2[8]     : RFU
    mr2_A7_A6 =                 "00" ; # // mr2[7:6]   : SRT & ASR
    mr2_A5_A3 =              mr2_CWL ; # // mr2[5:3]   : CAS write latency
    mr2_A2_A0 =                "000" ; # // mr2[2:0]   : Partial array self refresh

    mr2_bits = mr2_A15_A13 + mr2_A12 + mr2_A11 + mr2_A10_A9 + mr2_A8 + mr2_A7_A6 + mr2_A5_A3 + mr2_A2_A0
    params[:reg_ddrc_emr2] = mr2_bits.to_i(2)
    $l.debug "reg_ddrc_emr2 is ..... #{params[:reg_ddrc_emr2]}"

    ########################################
    ## MODE Register 3
    ########################################
    mr3_A15_A3 =      "0000000000000"; # // mr2[15:3]   : RFU
    mr3_A2 =                      "0"; # // mr3[2]      : MPR Operation
    mr3_A1_A0 =                  "00"; # // mr3[1:0]    : MPR Page Selection

    mr3_bits = mr3_A15_A3+ mr3_A2 + mr3_A1_A0
    params[:reg_ddrc_emr3] = mr3_bits.to_i(2)
    $l.debug "reg_ddrc_emr3 is ..... #{params[:reg_ddrc_emr3]}"

    return params
end
