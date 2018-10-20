make clean
echo "-----PERF_TEST:time make -j2 -l2 1>/dev/null"
time make -j2 -l2 1>/dev/null
make clean
echo "-----PERF_TEST:time make -j4 -l4 1>/dev/null"
time make -j4 -l4 1>/dev/null
make clean
echo "-----PERF_TEST:time -j1 -l1 1>/dev/null"
time make -j1 -l1 1>/dev/null
make clean
echo "-----PERF_TEST:time time make -j6 -l6 1>/dev/null"
time make -j6 -l6 1>/dev/null
