def max (a,b)
  a>b ? a : b
end

def ddr_process(params)
    ddr_clk_ns = (1000.0 / (params[:clock_speed] / 4.0)).round(2)

    $l.debug "clock = #{params[:clock_speed]}, ddr_clk_ns = #{ddr_clk_ns} ns"

    params[:dfi_clk_period] = ddr_clk_ns
    params[:phy_clk_period] = ddr_clk_ns
    params[:ctl_clk_period] = ddr_clk_ns

    ## dfi_unit is 1024 dfi clocks
    params[:dfi_unit] = (1024 * params[:dfi_clk_period]).ceil()
    $l.debug "params(dfi_unit) = #{params[:dfi_unit]} ns"

    params[:reset_period] = 200000; ## 200 us (jsa: tPW_RESET_L)
    params[:init_period]  = 500000; ## 500 us (jsa: OK)
    params[:wait_reset] = 12;       ## (jsa: Unused)
    params[:wait_init]  = 30;       ## (jsa: Unused)

    # Validation / reference board
    params[:pre_cke_x1024] =   (2.0 * (params[:init_period] / params[:dfi_unit])).ceil()
    params[:post_cke_x1024] =  max(2,(2.0 * (params[:tXPR] / (1000*params[:dfi_unit]))).ceil());  ## tXPR is ps, dfi_unit is ns !
    #$l.debug "params(tXPR) = #{params[:tXPR]} ps";  ## /jsa
    params[:dram_rstn_x1024] = (2.0 * (params[:reset_period] / params[:dfi_unit])).ceil()
    params[:tdinit0] = 1024*params[:pre_cke_x1024];   ## tdinit0 is in tCK
    params[:tdinit2] = 1024*params[:dram_rstn_x1024]; ## tdinit2 is in tCK
    params[:tpllgs] =   (4000.0 / params[:ctl_clk_period]).ceil()
    params[:tpllpd] =   (1000.0 / params[:ctl_clk_period]).ceil()
    params[:tplllock] = (100000 / params[:ctl_clk_period]).ceil()
    params[:tpllrst] =  (9000 / params[:ctl_clk_period]).ceil()

    return params
end
