from bcc import BPF
import time

b = BPF(src_file = "filter.bpf.c")

b.attach_xdp(dev="ens37", fn=b.load_func("xdp_filter", BPF.XDP))

while 1:
    try:
        time.sleep(1)
    except KeyboardInterrupt:
        print("Removing filter from device")
        break


b.remove_xdp("ens37", BPF.XDP_FLAGS_SKB_MODE)