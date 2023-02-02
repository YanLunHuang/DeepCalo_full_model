# hls4ml on Alveo U50 (HLS C/C++ Kernel)
## Vitis version 2019.2
## Compile project
```bash
make check TARGET=sw_emu DEVICE=xilinx_u50_xdma_201920_1 all  # software emulation
make check TARGET=hw_emu DEVICE=xilinx_u50_xdma_201920_1 all  # hardware emulation
make TARGET=hw DEVICE=xilinx_u50_xdma_201920_1 all # build
```
## Run project
```bash
XCL_EMULATION_MODE=sw_emu ./host ./build_dir.sw_emu.xilinx_u50_xdma_201920_1/alveo_hls4ml.xclbin  # software emulation
XCL_EMULATION_MODE=hw_emu ./host ./build_dir.hw_emu.xilinx_u50_xdma_201920_1/alveo_hls4ml.xclbin  # hardware emulation
./host alveo_hls4ml.xclbin  # run on U50
```
## Latency
```bash
Test 10,000 times and calculate the average.
Total time : 1.03ms
Kernel time : 0.92ms
```
## Some detail
```bash
The pooling layer & dense_ss are the final version.
(It has the best performance and routing result.)
The slack in the model is a little worse than the one applying DSP.

In order to reduce the BRAM usage, I set the precision to 8 bits.
The reuse factors in all convolution layers are the same as the ones Dylan used.
```
