struct ipproto_saddr_key{
   u32 ipproto;
   u32 saddr;
};

struct ipproto_daddr_key{
   u32 ipproto;
   u32 daddr;
};

struct ipproto_sport_key{
   u32 ipproto;
   u16 sport;
};

struct ipproto_dport_key{
   u32 ipproto;
   u16 dport;
};

struct saddr_daddr_key{
   u32 saddr;
   u32 daddr;
};

struct saddr_sport_key{
   u32 saddr;
   u16 sport;
};

struct saddr_dport_key{
   u32 saddr;
   u16 dport;
};

struct daddr_sport_key{
   u32 daddr;
   u16 dport;
};

struct daddr_dport_key{
   u32 daddr;
   u16 dport;
};

struct sport_dport_key{
   u16 sport;
   u16 dport;
};

struct ipproto_saddr_daddr_key{
   u32 ipproto;
   u32 saddr;
   u32 daddr;
};

struct ipproto_saddr_sport_key{
   u32 ipproto;
   u32 saddr;
   u16 sport;
   
};

struct ipproto_saddr_dport_key{
   u32 ipproto;
   u32 saddr;
   u16 dport;
};

struct ipproto_daddr_sport_key{
   u32 ipproto;
   u32 daddr;
   u16 sport;
};

struct ipproto_daddr_dport_key{
   u32 ipproto;
   u32 daddr;
   u16 dport;
};

struct ipproto_sport_dport_key{
   u32 ipproto;
   u16 sport;
   u16 dport;
};

struct saddr_daddr_sport_key{
   u32 saddr;
   u32 daddr;
   u16 sport;
};

struct saddr_daddr_dport_key{
   u32 saddr;
   u32 daddr;
   u16 dport;
};

struct daddr_sport_dport_key{
   u32 daddr;
   u16 sport;
   u16 dport;
};

struct ipproto_saddr_daddr_sport_key{
   u32 ipproto;
   u32 saddr;
   u32 daddr;
   u16 sport;
};

struct ipproto_saddr_daddr_dport_key{
   u32 ipproto;
   u32 saddr;
   u32 daddr;
   u16 dport;
};

struct saddr_daddr_sport_dport_key{
   u32 saddr;
   u32 daddr;
   u16 sport;
   u16 dport;
};

struct ipproto_saddr_daddr_sport_dport_key{
   u32 ipproto;
   u32 saddr;
   u32 daddr;
   u16 sport;
   u16 dport;
};

struct ipproto_key{
   u32 ipproto;
};

struct saddr_key{
   u32 saddr;
};

struct daddr_key{
   u32 daddr;
};

struct sport_key{
   u16 sport;
};

struct dport_key{
   u16 dport;
};

struct action_key{
   
}

//
BPF_HASH(ipproto_map, struct ipproto_key, u16);
BPF_HASH(saddr_map, struct saddr_key, u16);
BPF_HASH(daddr_map, struct daddr_key, u16);
BPF_HASH(sport_map, struct sport_key, u16);
BPF_HASH(dport_map, struct dport_key, u16);
//

//
BPF_HASH(ipproto_saddr_map, struct ipproto_saddr_key, u16);
BPF_HASH(ipproto_daddr_map, struct ipproto_daddr_key, u16);
BPF_HASH(ipproto_sport_map, struct ipproto_sport_key, u16);
BPF_HASH(ipproto_dport_map, struct ipproto_dport_key, u16);
BPF_HASH(saddr_daddr_map, struct saddr_daddr_key, u16);
BPF_HASH(saddr_sport_map, struct saddr_sport_key, u16);
BPF_HASH(saddr_dport_map, struct saddr_dport_key, u16);
BPF_HASH(daddr_sport_map, struct daddr_sport_key, u16);
BPF_HASH(daddr_dport_map, struct daddr_dport_key, u16);
BPF_HASH(sport_dport_map, struct sport_dport_key, u16);
//
BPF_HASH(ipproto_saddr_daddr_map, struct ipproto_saddr_daddr_key, u16);
BPF_HASH(ipproto_saddr_sport_map, struct ipproto_saddr_sport_key, u16);
BPF_HASH(ipproto_saddr_dport_map, struct ipproto_saddr_dport_key, u16);
BPF_HASH(ipproto_daddr_sport_map, struct ipproto_daddr_sport_key, u16);
BPF_HASH(ipproto_daddr_dport_map, struct ipproto_daddr_dport_key, u16);
BPF_HASH(ipproto_sport_dport_map, struct ipproto_sport_dport_key, u16);
BPF_HASH(saddr_daddr_sport_map, struct saddr_daddr_sport_key, u16);
BPF_HASH(saddr_daddr_dport_map, struct saddr_daddr_dport_key, u16);
BPF_HASH(daddr_sport_dport_map, struct daddr_sport_dport_key, u16);
//
BPF_HASH(ipproto_saddr_daddr_sport_map, struct ipproto_saddr_daddr_sport_key, u16);
BPF_HASH(ipproto_saddr_daddr_dport_map, struct ipproto_saddr_daddr_dport_key, u16);
BPF_HASH(saddr_daddr_sport_dport_map, struct saddr_daddr_sport_dport_key, u16);
//
BPF_HASH(ipproto_saddr_daddr_sport_dport_map, struct ipproto_saddr_daddr_sport_dport_key, u16);