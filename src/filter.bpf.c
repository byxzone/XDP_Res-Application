#include <linux/bpf.h>
#include <linux/ip.h>
#include <linux/tcp.h>
#include <linux/udp.h>
#include <linux/in.h>
#include <linux/if_ether.h>

BPF_HASH(ipproto_map, u32, u32);
BPF_HASH(saddr_map, u32, u32);
BPF_HASH(daddr_map, u32, u32);
BPF_HASH(sport_map, u16, u32);
BPF_HASH(dport_map, u16, u32);
BPF_HASH(action_map,u32, u32);

struct metainfo{
   u32 ipproto;
   u32 saddr;
   u32 daddr;
   u16 sport;
   u16 dport;
};

static int match_rule(struct metainfo *info){
   int result_bit = 0;
   int *ipproto_bit = ipproto_map.lookup(&info->ipproto);
   int *saddr_bit = saddr_map.lookup(&info->saddr);
   int *daddr_bit = daddr_map.lookup(&info->daddr);
   int *sport_bit = sport_map.lookup(&info->sport);
   int *dport_bit = dport_map.lookup(&info->dport);
   int prio_rule = 0;
   if(ipproto_bit != NULL)
      result_bit = result_bit & *ipproto_bit;
   if(saddr_bit != NULL)
      result_bit = result_bit & *saddr_bit;
   if(daddr_bit != NULL)
      result_bit = result_bit & *daddr_bit;   
   if(sport_bit != NULL)
      result_bit = result_bit & *sport_bit;
   if(dport_bit != NULL)
      result_bit = result_bit & *dport_bit;
   if(result_bit == 0)
      return XDP_PASS;  
   #pragma unroll
   for(int i=32;i--;i>0){
      if(((result_bit >> 1) & 1) == 1){
         prio_rule = i;
      }
   }
   int *action = action_map.lookup(result_bit);
      if(action != NULL)
         return *action;

   return XDP_PASS;
}
 
int xdp_filter(struct xdp_md *ctx) {

    //从xdp程序的上下文参数获取数据包的起始地址和终止地址
   void *data = (void *)(long)ctx->data;
   void *data_end = (void *)(long)ctx->data_end;
   int offset = 0;

   struct metainfo info;

   //以太网头部
   struct ethhdr  *eth = data;
   //ip头部
   struct iphdr *ip;
   struct tcphdr *tcp;
   struct udphdr *udp;
   //以太网头部偏移量
   offset = sizeof(*eth);
   ip = data + offset;
   offset += sizeof(struct iphdr);
   //异常数据包，丢弃
   if(data + offset > data_end){
    return XDP_DROP;
   }
   //从ip头部获取信息
   info.ipproto = ip->protocol;
   info.saddr = ip->saddr;
   info.daddr = ip->daddr;
   if(info.ipproto == IPPROTO_TCP){
      tcp = data + offset;
      if(tcp + 1 > data_end)
         return XDP_DROP;
      //从tcp头部获取信息
      info.sport = tcp->source;
      info.dport = tcp->dest;
      return match_rule(&info);
   }
   else if(info.ipproto == IPPROTO_UDP){
      udp = data + offset;
      if(udp + 1 > data_end)
         return XDP_DROP;
      //从udp头部获取信息
      info.sport = udp->source;
      info.dport = udp->dest;
      return match_rule(&info);
   }
   else{
      int *ipproto_bit = ipproto_map.lookup(&info.ipproto);
      if(ipproto_bit != NULL){
         int *action = action_map.lookup(*ipproto_bit);
         if(action != NULL)
            return *action;
      }

   }
   return XDP_PASS;
}
