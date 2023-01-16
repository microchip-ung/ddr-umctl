def ddr_process(params)
    ddr_clk_ns = (1000.0 / (params[:clock_speed] / 4.0)).round(2)

    $l.debug "clock = #{params[:clock_speed]}, ddr_clk_ns = #{ddr_clk_ns} ns"

    params[:dfi_clk_period] = ddr_clk_ns
    params[:phy_clk_period] = ddr_clk_ns
    params[:ctl_clk_period] = ddr_clk_ns

    ## For DDR4, dfi_unit = 1638 ns
    ## For DDR3, dfi_unit = 2048 ns
    params[:dfi_unit] = (1024 * params[:ctl_clk_period]).ceil()
    $l.debug "params(dfi_unit) = #{params[:dfi_unit]} ns"

    params[:reset_period] = 200000; ## 200 us
    params[:init_period]  = 500000; ## 500 us
    params[:wait_reset] = 12
    params[:wait_init]  = 30

    # Validation / reference board
    params[:pre_cke_x1024] =   (2.0 * (params[:init_period] / params[:dfi_unit])).ceil()
    params[:post_cke_x1024] =  (2.0 * (params[:tXPR] / params[:dfi_unit])).ceil()
    params[:dram_rstn_x1024] = (2.0 * (params[:reset_period] / params[:dfi_unit])).ceil()
    params[:tdinit0] = params[:pre_cke_x1024]
    params[:tdinit2] = params[:dram_rstn_x1024]
    params[:tpllgs] =   (4000.0 / params[:ctl_clk_period]).ceil()
    params[:tpllpd] =   (1000.0 / params[:ctl_clk_period]).ceil()
    params[:tplllock] = (100000 / params[:ctl_clk_period]).ceil()
    params[:tpllrst] =  (9000 / params[:ctl_clk_period]).ceil()

    return params
end
