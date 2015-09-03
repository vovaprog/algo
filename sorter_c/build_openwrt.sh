
WRT=/home/vova/tools/openwrt_mips_toolchain/bin
set PATH=$WRT:$PATH

$WRT/mips-openwrt-linux-g++ -O3 ./sorter.cpp ./small_utils.cpp -o ./sorter_wrt