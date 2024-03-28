#include "precomputed.h"

// each basis entry is a triple of the form P,Q,P+Q
// this is initializing the point using the classical representation {0,...,p-1} for elements in GF(p).
// We don't use this representation for actual computation but rather the montgomery representation (the conversion is made in init_precomputations using the fp_enc function)
// hence the ***_uintbig[] defined below should not be used in any actual piece of code.

const uintbig torsion_basis_sum_uintbig[3][2][2] = 
{ { { { 0x9709fd321fbc9e82ULL, 0x2d1631122f467b7ULL, 0x2bb338e64d4fb77cULL, 0x2f0b4ee49b4247a1ULL },
  { 0xe6d305fda756a4bfULL, 0x2e2a64686dabbfd7ULL, 0x96dc3f4340218803ULL, 0x45eb34dfc873c9fULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x73c7b44b6855bb28ULL, 0x14a107bdbcd2df8aULL, 0x925005ff6cb1528cULL, 0x111393bbb7d372dULL },
  { 0xde66c42a94052061ULL, 0x4fe85436249dd880ULL, 0xc46336de27ee1bULL, 0x1de6e0d6586e8c4bULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x4cbd4f994aa530beULL, 0xb9eb22dfcb6501c9ULL, 0xd243d4934d2cdf6aULL, 0x1159a0132104660bULL },
  { 0xb49773834c497447ULL, 0x85775d8528d97f2eULL, 0x280437b029a44060ULL, 0x1b1a88c2f45ea060ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } };
const uintbig torsion_basis_twist_sum_uintbig[3][2][2] = 
{ { { { 0x4f10f1ec147d7675ULL, 0x3cca1e25e0d4b7dbULL, 0x8faf0e3e1327bcbdULL, 0xb905e7c70908b2fULL },
  { 0xb7297ff28ab4e425ULL, 0x8a5df1ad3b33be5bULL, 0xceae98b5dc0bc9bfULL, 0xbdb82f08d9af036ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xba8a9556da0435ecULL, 0x38e4f17908769090ULL, 0x426297e965770674ULL, 0x2748ef5357407353ULL },
  { 0x2112fee0170c1483ULL, 0x94f86e45323f131bULL, 0x321d84cd5b5a4a10ULL, 0x31c7ccdbc9c04bd8ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x8e2dea340cd679a4ULL, 0x4a4514e9c38c8845ULL, 0xd7c40484037cf68aULL, 0x2fdaf3b51cc54ab2ULL },
  { 0x3484e74ec453753aULL, 0xe7d3c72278375e25ULL, 0x2889e46c14af0cefULL, 0x580a85ae4733971ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } };

const uintbig torsion_basis_ted_sum_uintbig[3][4][2] = 
{ { { { 0xcab4d8437b6e7d4ULL, 0x792359eac370a4d2ULL, 0xafa774b2ab253d23ULL, 0x15cf15c296372e9cULL },
  { 0xf6526e701d6f5995ULL, 0xbc6b8e570856cf71ULL, 0x5ce56448a3237e6ULL, 0x86dde8d6fbc0326ULL } },
  { { 0xe3f5b5c05c7de496ULL, 0x87ed4870422b953dULL, 0x73afea60f93d1afaULL, 0x344c1be4fcb20587ULL },
  { 0x45d6f174dbb00772ULL, 0x40ea244bd64ea858ULL, 0xf2456ab096908d5fULL, 0x1768bcdf3c983cdfULL } },
  { { 0xc263aa93dc2a33d4ULL, 0xef86b2ddd2cea050ULL, 0x535187de607fc61dULL, 0xe51c87d8c46f754ULL },
  { 0xcb4860fd2c6d86e4ULL, 0xeff760aacd5268bfULL, 0x144c375cdf9d7ed2ULL, 0x592d74ffcc643ULL } },
  { { 0xfab73711252decddULL, 0xae8dd3c240b7bfeaULL, 0xd846926a02b02d0aULL, 0x1842f87398b2d767ULL },
  { 0xe6ee934aa6f51cd9ULL, 0x8442f9c4d131bbd0ULL, 0x251fe7bc072b5c66ULL, 0x2acbaae34fa58e15ULL } } },
 { { { 0xd245eb3284c631f7ULL, 0xfb9e543566cfa7d1ULL, 0x648974755457d250ULL, 0xcb189dc94c78414ULL },
  { 0x454244687ea369d1ULL, 0xfd50a42b01acdeb3ULL, 0x66b2357be9a486d2ULL, 0x2d119c162ea0ed33ULL } },
  { { 0xe3d174f80e2618f0ULL, 0x136ce1c005489d44ULL, 0x9ae2be897bd91978ULL, 0x1782c62a69f9e69cULL },
  { 0x90c5aa8e9f0cb7d1ULL, 0x67469f1eb0260c53ULL, 0xbe43f4b0b6cc14caULL, 0x1185c1a3c0e3e5b0ULL } },
  { { 0x909fc5319a2bec07ULL, 0x1dc7267a6b257185ULL, 0x992d828fe7d72503ULL, 0x30b6bb89eb0e802ULL },
  { 0x7b1114c5f3786e30ULL, 0x607687204160478eULL, 0xc73960faa0d5d7dcULL, 0x117a9084dfbd1906ULL } },
  { { 0x3a14f373628b585dULL, 0x19708f137e5f1b8bULL, 0x2253d0b8b5ed85f1ULL, 0x175c99301f3eaaa6ULL },
  { 0xdfdcabbc82ebcc3ULL, 0x6c9fabcf20269b89ULL, 0xfe7743c1c98b0a8fULL, 0x225c5157757a9d0bULL } } },
 { { { 0xc41af12d1c752025ULL, 0xee0b486e486b9652ULL, 0x8e56a844fccef6c3ULL, 0x207c1a9ba45b6486ULL },
  { 0x699b46b39efdbbe1ULL, 0x2aca389f39121229ULL, 0xc3ed8e0e63e2b044ULL, 0x41706299514812cULL } },
  { { 0x26e17a6350aa1085ULL, 0xa5095a13090c2690ULL, 0xc16385b5db05e91aULL, 0x322880cdd7d56ab3ULL },
  { 0xf06e6c5a825993aeULL, 0xa57a947eb070e307ULL, 0xcbea21a9dfe204e7ULL, 0xe8fd2c2448282a8ULL } },
  { { 0x66539213e3d5a658ULL, 0x134495e43813b5f0ULL, 0x22851451f5059f47ULL, 0xa6b6ce481754e6dULL },
  { 0x10332447d1234694ULL, 0x301a56e355d6aaaeULL, 0x86f7ea56ea91a03dULL, 0x10e6cb054b7cef96ULL } },
  { { 0x5802f4d8869aa6f6ULL, 0x50387e9d8866ab46ULL, 0xa94062c94bf253b7ULL, 0x18a426182e3bda33ULL },
  { 0x80cd2a97b59006f1ULL, 0xe7278775908c04e7ULL, 0xbd52c9691722c35eULL, 0x113920fb94df10d9ULL } } } };
const uintbig torsion_basis_twist_ted_sum_uintbig[3][4][2] = 
{ { { { 0xce1a6c5e97f06f7eULL, 0xb07b1582a1da4a36ULL, 0x97024aa6079c4d6aULL, 0xe19bc71eb91c8c1ULL },
  { 0x59399fd206531bf9ULL, 0x80ed9fd6e83250b8ULL, 0x67e06cf79e89bc6aULL, 0xa7ca528d1c5b939ULL } },
  { { 0x7d0bdf444259af6dULL, 0x3d210587917ed2eaULL, 0x2e9c89d9153f18d3ULL, 0x6a127e5e45fdcf9ULL },
  { 0x237081adadde0f54ULL, 0x7496e798744cd454ULL, 0x152bf054d6bfb45eULL, 0xd74533c528b805cULL } },
  { { 0x5f028dc399a77336ULL, 0xbe192f5a9a5cf48ULL, 0x1543fff343a6fd6aULL, 0x19a2711507075e3bULL },
  { 0x9467561e9f21a684ULL, 0x1a283479b445e4eaULL, 0x43977bc3be59a550ULL, 0x159e576718a44e0aULL } },
  { { 0xc9eed57fba545f68ULL, 0xb8d18235d0e34cf3ULL, 0xd1c2254be00f814eULL, 0x1eda21ca3b7d4af5ULL },
  { 0xd346d7358f83d728ULL, 0xb08e0ba1ff95078dULL, 0x53dfc04a275fc957ULL, 0x1f9b9a55122981d7ULL } } },
 { { { 0xf17dc3e35989063dULL, 0x651b6fb2c72e0e70ULL, 0x1ffecae3d370f8fcULL, 0x1c8c74b8f0025f9dULL },
  { 0xb6ee565b094d2f91ULL, 0xb54823f923ded932ULL, 0x7799536c0f5d73b1ULL, 0x1310473d51394384ULL } },
  { { 0x23d690fa4797e9dcULL, 0xbcc04386b48c5c8ULL, 0x366bf36bde20da44ULL, 0x3134e0899918ba50ULL },
  { 0xf08f28119c62aa36ULL, 0xd19168e3b9a6bb21ULL, 0x9041598e47e50bfaULL, 0x274225ea4e03111eULL } },
  { { 0x332b59971b6a3076ULL, 0xf651cc893cba9633ULL, 0x668d0268e67ccadbULL, 0x1faf9e0c4f98ea9dULL },
  { 0x32da225e36f3f190ULL, 0xec83387d741427b2ULL, 0xd1d19177abeee342ULL, 0x16e65a2b01a3d3cbULL } },
  { { 0x9494afa4c32668f8ULL, 0x68e325b47dfadb8ULL, 0x8e39d3f38bffa2a2ULL, 0x2c5f4bab6de0b4c2ULL },
  { 0x49878d727f94595eULL, 0x983476230175685bULL, 0xc69f3209019d49c0ULL, 0x1cd6f948cb13e3e6ULL } } },
 { { { 0x24857e0c2ff745baULL, 0x203916c592f96b8eULL, 0x39655e67ae111694ULL, 0x11f7647653bc83baULL },
  { 0x4bf610abc0bd71afULL, 0xbddf236227ccca52ULL, 0x46453e25e5fb706aULL, 0x1c991479290181adULL } },
  { { 0x8dffe998a920ffe0ULL, 0xc934935e88609adcULL, 0x3ac9c2e4734dbd58ULL, 0x1ce6fc9ffb27e56cULL },
  { 0xf57a302fe7ec6cc0ULL, 0xac270e8d4dee5037ULL, 0x42f7b6e8bf101e0ULL, 0xd0c30d3211da48fULL } },
  { { 0xda4a0bcc23fcf715ULL, 0x14f7f71370e3b40fULL, 0x121211cf5a877e3cULL, 0x326009038a57fcfeULL },
  { 0xe975177c18d041aeULL, 0x487dd2bb4ba6a37dULL, 0xb552a6a8038c6201ULL, 0x1463a8cc80159796ULL } },
  { { 0x1563917e0cbe675dULL, 0x1c3eaf01b5fdc409ULL, 0xd09f15649d2a30c0ULL, 0xa6cd7958ac3f5e5ULL },
  { 0xe014f84c6e94f53cULL, 0xc07097aedf608021ULL, 0xe865c9d9e472048dULL, 0x280ac838c930b33fULL } } } };

const uintbig torsion_basis_uintbig[13][3][2][2] = {
{ { { { 0x5e8cdf8948fc41acULL, 0x5f55339df2931697ULL, 0xbf10985b1d46854ULL, 0x31e23fefbec30e49ULL },
  { 0xff8fa6b212bfaac6ULL, 0x65ef0521e24fbd04ULL, 0x7f01802e9c5162b5ULL, 0x2c905b27d8ea32a5ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x86cec5626f6c0093ULL, 0x73d97d50a00e8548ULL, 0xbd28f5649d7d0109ULL, 0x256bf7d3c2f863edULL },
  { 0x89b2ac8fc7919152ULL, 0xdbe7ec4d7d2c2ad2ULL, 0x4a1ff8d5e59dbc86ULL, 0x67b570afc755215ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x8ef1c955035be97dULL, 0xd76ae4c4608ce8edULL, 0x5bdaad8946605dd8ULL, 0x1c01931e02d69ebbULL },
  { 0xfd5998507224bd77ULL, 0x98a05b39d0647bbcULL, 0x4c09a8a7ffe95be1ULL, 0x948876a1718cb74ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0xae96eac9f758e4feULL, 0xf7070b410c4840e4ULL, 0x2255699aa1b8c4cfULL, 0x2d4f53eaba693adbULL },
  { 0x5e0aa07b02ff4fd4ULL, 0x6a31cc2a46fd9c98ULL, 0x36739cd988951837ULL, 0x4c3252cc7360d07ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xd4e99475990e8483ULL, 0x281f64b28856a49aULL, 0x705966ebff4df65dULL, 0x50e1686ae1ce9dbULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0xb513c55167998015ULL, 0x6e995a614512e63bULL, 0x3a39d4b64709df44ULL, 0x23988e3cc236ebfaULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0xeb920a83ca9be210ULL, 0x99bbff7817348ee0ULL, 0x5ac7c3e1c2a3b226ULL, 0x211bafedb8e55393ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x2ac8ee18f677b224ULL, 0xe27b43e7d4398cdeULL, 0x94fe11ffeac069ecULL, 0x14b4c22926193b50ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x146df57c35641defULL, 0xb99c06825769b9d1ULL, 0x5c695681a09b51b4ULL, 0x136ba7fd2677419dULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0x148829fbb232e724ULL, 0x8f51d450b16f130bULL, 0xb5e22ad30629b7fcULL, 0x1677fe5bee98f056ULL },
  { 0x5ee5ce66c9879e8bULL, 0xe459951f06b3be47ULL, 0xd4d73f91dab009a5ULL, 0xb0b7ee66a11b84bULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xd3109a048d9c82e6ULL, 0x1b5a6c263ee77ae6ULL, 0x45ba4a2905f49574ULL, 0x1c1d13e6efac4766ULL },
  { 0xba2826ab9af00377ULL, 0xaa85f94919635a47ULL, 0x598e5a8e75a7c38bULL, 0x196a72a4b728ce4eULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x6ba0604d8d63ae56ULL, 0x35c6d7dc130e18a5ULL, 0xa694cce81c72694bULL, 0x64e15fa329c3992ULL },
  { 0x8a1307b0daf22609ULL, 0x27aa4816495796a9ULL, 0xdfeed557f92a480fULL, 0x26efe9062e621413ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0xb0c5627aa96dc74eULL, 0xc21be8705c0aa0d0ULL, 0x553f2ea219b4970cULL, 0x11dd8c335b3c8da5ULL },
  { 0x3f57fa43b6cdad89ULL, 0x75e565a47b3242fdULL, 0xc3e6ea6e5191c7f1ULL, 0xbd6ebaa2c2413b6ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xa4a33ad9e8759b86ULL, 0xde67975189f1d2c8ULL, 0x2b929815204a0767ULL, 0x1f6a59c42bc8af8dULL },
  { 0x903ccab71e8a9df0ULL, 0x3ef9afd7a4dda00eULL, 0x5a30098b701ddcfcULL, 0x55288fea3780979ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xacc0880042b4a3dfULL, 0x6e1c66df8348c7edULL, 0x9a4c2d0def9fcc9fULL, 0x899c4563ad98afULL },
  { 0xd69f80b60a1d62dcULL, 0xd256cf0663a8a753ULL, 0xbc56bae68991383eULL, 0x928776fb030d80cULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0xfb2ee9ea44eaf4eULL, 0x72565765e174c0aeULL, 0x73079f1a93fb9e3cULL, 0xb053eefd818e3b7ULL },
  { 0xf8161fa6cabd9af3ULL, 0xb5a9b1312972315eULL, 0xcc0d48d11acb487bULL, 0x253539124869d637ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x10c3edec92c03c4bULL, 0xc394074bc27474c2ULL, 0x578980cbb55dc411ULL, 0x17c67fc10c6a809cULL },
  { 0xa8e5c9aa9ad1a5edULL, 0xaae9635fd5b170cULL, 0x3a42057f7419d2c1ULL, 0x2fab920aa20ab9ceULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x6faba67579e0b940ULL, 0xa84522a48b69eb48ULL, 0x8e628ed433ffa478ULL, 0x1cdb4ae578eb5a61ULL },
  { 0xd58a33073eb60ce1ULL, 0x5d0ef1ab44dc9efcULL, 0x11a0056792f7e873ULL, 0x867df7c77e0d98dULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0x560ee1263d33c363ULL, 0x258303f362dc4d1ULL, 0x5d06b9030fe38916ULL, 0x25cb4cb4253cdf11ULL },
  { 0x8f7ab4a3c8926feULL, 0x25a5a5ecdf0ad161ULL, 0xa3d79fef9582696fULL, 0x323716ba61ac09e9ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x243cf3f05a0d3b70ULL, 0x4007d53c3002f15aULL, 0xc396c21313a354a6ULL, 0xc27b215e98efa68ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xa2e248c0e805ae8dULL, 0x7c2226ce3f64a41dULL, 0x62e0f4c89693799aULL, 0xbbf51f1409415bULL },
  { 0xf5981e926a0a31caULL, 0xaf4064a1528d6b50ULL, 0x6a26c1621d39a291ULL, 0x2b35ad04d85704b3ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0xe6904d967a5a6a46ULL, 0x872c711222e3ec73ULL, 0x24ed89d257df6c3ULL, 0xb2427f4dfbe7c8aULL },
  { 0xd12592bee981f5dbULL, 0x7c046c3b15499e80ULL, 0x2e21056b3d6828d0ULL, 0x330805b525636855ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x73f05328f0c143b6ULL, 0x961a681bce194dbULL, 0x40936450f39a4065ULL, 0x19546aee668f5ff4ULL },
  { 0x1b55f20099b5a6ffULL, 0x5ee7dba6caf8f7feULL, 0x84e9c5917bd1f6bfULL, 0x28dbac4e6395eb31ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x819d867add5e9deeULL, 0x2a7f6f276edcd03aULL, 0xda26fe130f056ffdULL, 0x121661428776926ULL },
  { 0xc8623d7ea61dea1bULL, 0x5efc2766e4c67f5eULL, 0x9e1ccf6b881d2033ULL, 0x13e264b8ce96b9aULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0xc6b757a664c35d53ULL, 0x6b16d012332256b8ULL, 0x82bc846fc2246a31ULL, 0x2e97040af6084e74ULL },
  { 0xc4a33f6e78c2ffb1ULL, 0x7a38ce0c9fa119ULL, 0xdd4d6ab1e536f419ULL, 0x18832e7f2374de0ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x28023b292f7f1c11ULL, 0xa715b6e64b646643ULL, 0x9dc75cdcb1c6d996ULL, 0x251474b28b806a96ULL },
  { 0xb63d7bae56370feaULL, 0xbbbcfddc831646dfULL, 0x2e13c7364da14d85ULL, 0x8e7bf12bb7f1f2aULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x130087dcc6f56463ULL, 0xd40416223a1ad510ULL, 0x8d3f5ae8c0dad85bULL, 0x6d6a1c988c7e9cULL },
  { 0xde868db0d8a8f414ULL, 0xd1fddbe387fe057bULL, 0xb8fba96623e0f058ULL, 0x1caa62421ea88554ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0x67ecdc6f42fdc994ULL, 0x3e0943b081061c36ULL, 0x5107738bbbf43d55ULL, 0x177bf12a27366887ULL },
  { 0xf347ae066ccf4fa0ULL, 0x54f569583896dbc2ULL, 0xce88b0c65897db88ULL, 0xa76726abcd934edULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xac7f160e8532f7f2ULL, 0x4a08d75f0e0f15f9ULL, 0x5b5307b1e2d6b3b9ULL, 0x746c87d5fbbd7b1ULL },
  { 0x114a0ed03bc1d95dULL, 0x754db9ec612da2caULL, 0x56e61da03bcdb395ULL, 0x1aabb6b8eaadcbccULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x77c6590d6e0429a2ULL, 0xddffab17d9c3392bULL, 0x90f1ef6cbded7188ULL, 0xb8b1f234fdde258ULL },
  { 0xf868dc81097d8ceULL, 0x460e64d0dd4dfd6dULL, 0x6f7b6ce93cee6104ULL, 0x1908758b4bcab1e2ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0xb48532bc4bafdbdfULL, 0xd5cab084d18adbc5ULL, 0x14f06f409fd77709ULL, 0x321493e7db50cd87ULL },
  { 0x92df9da806e34668ULL, 0xfebd806c0c11fb0eULL, 0xba9c82f048a8e0a1ULL, 0xabfcd27b0f25633ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xf04d6cff1dfd6f23ULL, 0x97dfd5e5fa12aaceULL, 0x498547b0464f7453ULL, 0x278484dece130b56ULL },
  { 0x75ae0f7b74fd10b6ULL, 0xaa7df7516049671fULL, 0xc91f4646f67c5d56ULL, 0xc44fd6538a85e93ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x1c82696bcb57bc66ULL, 0xde39266982cd89b4ULL, 0x923263c2e6b2576bULL, 0x2383f09ad4786c0bULL },
  { 0x50de66365e795baeULL, 0x70c0aea3bd4dc5dfULL, 0xad9e0afb036c7800ULL, 0x17f04251ca0be775ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0xec676e1cacf63c88ULL, 0x16a1c3863460dad5ULL, 0xae963b2ff8753220ULL, 0x28c2531ff6e21d31ULL },
  { 0x2de854ad9174923bULL, 0x6f8ce7965d4707e9ULL, 0x13291ef643c92d5aULL, 0xafd3ba746d76802ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xfbb7cd9a69845a6ULL, 0xc5d524fcd9a65607ULL, 0xb0cf25b88185b155ULL, 0x2464725a6d0a01fbULL },
  { 0x2e0b0c9901044142ULL, 0x96e2dfdc108ac4eeULL, 0xad54a2b5cc23625fULL, 0x24533d0537a8c692ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x8535b6e24ad1018bULL, 0x38091efbcf811016ULL, 0xfa10625cbbe6b5f4ULL, 0x2c0f4e91e289ca61ULL },
  { 0xa29604dbbcfaa3aULL, 0x8602ff96511ac1ULL, 0x24af444a97091d03ULL, 0xae1f41edee92963ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0x513def1708e80079ULL, 0xdde431d178b56d8ULL, 0xbcc20963f79494dbULL, 0x134af27cd5581b02ULL },
  { 0x732e602979498770ULL, 0x4ae30151d4e7b9d8ULL, 0x6459febee8680b6dULL, 0x29d3ae3f6f936676ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x78440f287814ebddULL, 0xc91feb524fbb99a3ULL, 0xb93947f6e2cd3b48ULL, 0x2334a7c53bd7baeaULL },
  { 0x5e4505e6d8370971ULL, 0xdb5d6d627a1d51d7ULL, 0x5f7bccb82a67e834ULL, 0x3434dc51e58b0e75ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xe5ba278401017113ULL, 0x422fbce534a842d6ULL, 0x2264424db847283dULL, 0xfaba9ca0ca52faeULL },
  { 0x1ce029a5adcb434aULL, 0x1c7fca67a4d5a9aULL, 0xb1e961f079a8baf2ULL, 0x7a58d445b1c8bfULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
};

const uintbig torsion_basis_twist_uintbig[18][3][2][2] = {
{ { { { 0xf9e1c902921b5ff5ULL, 0x670df78c187f7d49ULL, 0x610b35d6ea36308fULL, 0xdc1e581e2af2825ULL },
  { 0xf3a1fa673c772c56ULL, 0xa42ceeda2bd695b6ULL, 0xfdbfab844d44443fULL, 0x109f72a596ff8049ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x2ac0e6525f824c16ULL, 0x86076a084a37050dULL, 0xbe732781e26042aeULL, 0x1be7f93e1abcbfd5ULL },
  { 0xb94c6ab3c78c8cffULL, 0x83741cbc280ac651ULL, 0xe5ce960d8cd28556ULL, 0x33d73e9b8da2861aULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x9d57c0a0a4f53e5cULL, 0x8514bf3ae1b7456cULL, 0xb62b0a05eb3ddd75ULL, 0x523cb74dafb29d7ULL },
  { 0xd7758af2ed13d98aULL, 0x9297f105621e3708ULL, 0x3ace5d267ed190c8ULL, 0x1d04fda65fc9f389ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0x9a3d5ff0b7a81866ULL, 0x483ae4095b40bd43ULL, 0xee86bb3bd003d502ULL, 0x20b5d273348d0050ULL },
  { 0x722e5e32c61d8c80ULL, 0xfacd634caedd9d20ULL, 0xca1ee161dbcdc9f7ULL, 0x33138fa82521f19eULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xd09d535a7864add1ULL, 0xaeb831b53fb2fd97ULL, 0xca9a7abb36fc2619ULL, 0x90dca97dd008034ULL },
  { 0xf8c63eea9b85ee77ULL, 0x94784ec2f7c870e3ULL, 0x6e1fb951f3b52a81ULL, 0x19714392d96c6356ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x1b24c92029eb783dULL, 0xa7fe7edf9365b9deULL, 0xd6c78ca38ca86138ULL, 0x2ddf7fb333ec87eaULL },
  { 0x655fd50d3e072fa6ULL, 0xf60c804b53d9db40ULL, 0x91bfe40549dd3b4fULL, 0x2dcb7a5174210c9fULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0x6cb30eb0bb8ec473ULL, 0x4d13bd3c7d415682ULL, 0x88fac70f5a6210fcULL, 0x16b1b69ba6cc6df2ULL },
  { 0x822a97cf28d8b85bULL, 0x69cb63138c88734bULL, 0xeb0d19ae3bdf1c83ULL, 0x28038cf82929837aULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x718d86952b74b01cULL, 0xbd94ea0caf11a5feULL, 0x705354a1ef215e2aULL, 0x781dc9ef580e6caULL },
  { 0x25f7d4f5b1c7b077ULL, 0x4bd044217ac8664cULL, 0xb403f86560111e59ULL, 0x1a5c6b91077dd955ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x44796ac656b3f164ULL, 0xc52725ac24d7e1b0ULL, 0xea1a67ece2c79508ULL, 0x1a1023f217a861c8ULL },
  { 0xcd5af75a750e5362ULL, 0x93536f5300eb032ULL, 0x679979f715f9a88eULL, 0x2e7633b2bd1e9652ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0xabaa6bb24dc3472dULL, 0xbe74434efb9d017cULL, 0xf829348816ae7243ULL, 0x330a7daeeb4e0e56ULL },
  { 0xe20e430ee7897ef5ULL, 0x958d81e5284b6f81ULL, 0x9214bedc0a9c8f31ULL, 0x25bd2650f51a68f4ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xab3f882906cfc6e0ULL, 0xb9e0074683f7fb74ULL, 0xb9446e0649e58d19ULL, 0x1253169a2e83aab9ULL },
  { 0x83a250310bf60a68ULL, 0xdce678bfbad0f597ULL, 0xa179918c099d0ad0ULL, 0xff389ce5cd2a54bULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x9f3cab75db356fcdULL, 0xa519d70b5b64626dULL, 0xa8d5b4e9989fdb79ULL, 0x2ac478229f2024aeULL },
  { 0x121093cc5adc2f5bULL, 0x9f09dcc535a23dfaULL, 0xa349e42485afc4afULL, 0x1ed6496e7e16dd3eULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0xae2bc4d86b80fa7aULL, 0x959f315b3fcc87c3ULL, 0xaecb714e06c73c4cULL, 0x3112ae3d0259c7feULL },
  { 0x36af203eb316f30eULL, 0x1dc889333e4ba5bfULL, 0x6ee65ddb3d792f4fULL, 0x17b8e7f157e4deULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x7da61da9123867caULL, 0xbf3c04c0de38dca6ULL, 0x150e2b6e66e14c0eULL, 0x4c92b321971d0efULL },
  { 0xda5a24d88f630227ULL, 0x9ad03ad9cc7e6285ULL, 0x677e4f6983b7da66ULL, 0x315cec98c55fea11ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xd3e8be8d9f7ceb68ULL, 0xddb0301909f15a29ULL, 0xe440d42c6eb55153ULL, 0x1b09b0dba0a79726ULL },
  { 0xb9838575825558e9ULL, 0x2cebe2f055fd1f31ULL, 0x9d802976601a3538ULL, 0x24047fcb77fd5c09ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0x17dd803872d7e53cULL, 0x10f7a70820a1febbULL, 0xc962db27afbaea26ULL, 0x61ba46b3d86bda0ULL },
  { 0x2b9f28358327c662ULL, 0xa91e194e9f88051ULL, 0x6f0c7f8762874738ULL, 0x10c2ebc7b207d8e9ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xf9dbd4ad1d4e470cULL, 0xb3a6321f782d5128ULL, 0xcdbf197a89859b89ULL, 0x1a65b3280aa9a855ULL },
  { 0x2b0c3d6bd98fcc81ULL, 0x84fd9fa9d59ba561ULL, 0x4991524bcf2d0ad1ULL, 0x24cb4ad51d4b19c8ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x902948509e18edf3ULL, 0xa2c63429e3ebcb19ULL, 0x60a0772309418a13ULL, 0x14f4b79b76e7b766ULL },
  { 0xbbc20fcbfa8a07dbULL, 0x667c56159b4789f9ULL, 0x43467321ed2f71bdULL, 0x1e0c605375c2a19cULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0x34bec8f17fee579bULL, 0x26018bf5e9b61a6cULL, 0x91f6e2dcd82d666cULL, 0x2f1c666e313fe6f6ULL },
  { 0xf6198082b94c74ddULL, 0x6e8d3266038840a9ULL, 0x60afb7bd8d37ecf4ULL, 0xb11e5dfbd767567ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x87941301e66204cfULL, 0x2ebfc5c1b02e0b93ULL, 0xfd80b1f368964845ULL, 0x2afee6f1b478cb4ULL },
  { 0x9e2ec7785a4ea51eULL, 0x55406f910e10e44cULL, 0xb4b79d8e308abbfdULL, 0x2c47e7e234570e7cULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x3ad509c32b21c85aULL, 0xab4ff6b1f38f5319ULL, 0x36833ac093c06bbULL, 0x7ba239d8c901498ULL },
  { 0x27f8c8f34e856aaeULL, 0xff5d7a6c3b0c608dULL, 0x376928e4b36767baULL, 0x30d22715432ba76ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0xcc9efb82760a0fcbULL, 0x714b067d437abf2bULL, 0xf61a6c822d94483eULL, 0xc9a18e2abd75f5fULL },
  { 0x8bb8d2b48f1ee63aULL, 0x8567393c1c7c9112ULL, 0xc42bed4e2852e13eULL, 0xfc82a4cad91cff0ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x6d324d6d92fb729fULL, 0x87d89b0e8c81babdULL, 0x5e1b2206a2ef01c8ULL, 0x245aeab8da09a47cULL },
  { 0xf67e47a1bc4e0d2aULL, 0x47b82d320bb16a75ULL, 0xc0c71894883726b1ULL, 0x2bfda227ab8afb34ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xaddfe1e1f2e1fc60ULL, 0xc44f5bfbe61821d8ULL, 0x5d293358eae9607cULL, 0x1ffc14cbb0976acULL },
  { 0xf70e942654073b89ULL, 0xc533c79ded06f1aULL, 0x517a5fe8973e75faULL, 0xa027d4c3dd7ec14ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0xd42af151c3de25a8ULL, 0xd2e4e76780af5944ULL, 0x1e9effaf88a469a2ULL, 0x2445362d0a9fab78ULL },
  { 0x518055192943c5c1ULL, 0xb5255a334e46ab14ULL, 0x7680affa34e2db84ULL, 0x23973e69c3bcc67cULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xc28575c66f8913cULL, 0xe88e87bdfb54472bULL, 0xe44718ec8f002c1cULL, 0x10473d739dc62d6eULL },
  { 0xcfc00dfa14665cdcULL, 0x209db40717adfec9ULL, 0x4ecb31b0e55e5070ULL, 0x302e5aebdd6cd639ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xcd42fc0da4ab690eULL, 0x2fe7e90a9894c8e0ULL, 0xf868b2e9b35257e0ULL, 0x33e2fcaef00260bdULL },
  { 0x9969c412c91e1873ULL, 0x311a93d5b23c0005ULL, 0x9b795e91c5756307ULL, 0xd366f4c1aa2a3b0ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0xda80979015d29e37ULL, 0xb2052a7125d14e43ULL, 0x779027e7d5a088e7ULL, 0x329c20baf76cefcfULL },
  { 0xa01abfe804036b4ULL, 0x5e1c8e89dcb320b4ULL, 0x4f59e316ce565fb8ULL, 0x1e647fb18ec8df9eULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x9529fb6a5b9d7293ULL, 0xdc00182760e922bbULL, 0xebc6097b67127420ULL, 0x7c4a1866924f78aULL },
  { 0xf327b02219d9ddeULL, 0x775e99e2690683a9ULL, 0x8a45e9d7b8005d26ULL, 0xc7bd4eaab9d131bULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xfcb4313ccb506740ULL, 0xd96d6e75b7b5429fULL, 0x38cb984beeb86168ULL, 0x18c002dade807d36ULL },
  { 0x446ccdc238c24222ULL, 0xa306eca35237b064ULL, 0xd21f8c4fc81b5351ULL, 0x161cde3704568af3ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0x9b24511b2297d3c0ULL, 0xb4a618bba02588c9ULL, 0x56819e702dda7762ULL, 0x1ae3ad12d547e682ULL },
  { 0xeb4a3a7b2bf97873ULL, 0xf7febad43ac9ad35ULL, 0x264670bce476fdbeULL, 0x60fde703b078430ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xbf555f1351bd41ULL, 0xf4264646792e75fbULL, 0x65a354feb4dc2ec0ULL, 0x3095eb8076342639ULL },
  { 0x31078b9fec39eb60ULL, 0x8a4833c5a1ec9d8bULL, 0x34c6ed05b923181ULL, 0x1233e746795405e9ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xb3d3cfa8fff8a2fcULL, 0x27bc6feebced5192ULL, 0x47ad27e11b609538ULL, 0x1ed290db53f8b11fULL },
  { 0x8e6686e6d4d46069ULL, 0xb94369f232bcafdULL, 0x96d01c349a07b522ULL, 0x201610b492b5c2fcULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0xd460a7e365849f44ULL, 0xd93376ad848bbddULL, 0xe6d6f16667c8faf5ULL, 0x1a8a702820ea0172ULL },
  { 0x8fac04d86f4c750dULL, 0x1d4002ac632fc316ULL, 0x5a7fae876ef2f2f6ULL, 0x29b7110fe4df60a9ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x5e1f47266fe51e34ULL, 0x95737e9599a87d5aULL, 0xecfde2e9394f935fULL, 0x2f4e847bd424b3d2ULL },
  { 0x6d8c8d7d4f137b86ULL, 0x979355d3eb0878a2ULL, 0x52c2ec0b4f97b00fULL, 0x2783ea91980cc0d8ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x250d64966c78646ULL, 0x6726199e3215fc69ULL, 0xe9ea338d730cecc7ULL, 0x1d0338194f92010dULL },
  { 0xa1970359c663b1d3ULL, 0x1f9cbbcd036527f7ULL, 0x859d199624198338ULL, 0x10b08cd42675d112ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0xcb848374a6ca8acbULL, 0xaf85dcb8ed10ba47ULL, 0xdd8ff4743b70c657ULL, 0x1e79087461ad323cULL },
  { 0x845ca493efdaf963ULL, 0x948ee132b457ea61ULL, 0x78a7aac6f3f5dc62ULL, 0x25fad140b7ebc5fULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x6d5f0ad7cac3b4c0ULL, 0x98adbc9140e74726ULL, 0x90a15ff8c9d32017ULL, 0x22fcc66158304d59ULL },
  { 0xa0cfc5b4536d7665ULL, 0x1660686644f85b2ULL, 0xc55dd968f483a4f4ULL, 0x814a45d42767b67ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x1a43e7003ab5d5cdULL, 0x7d00db42222a2755ULL, 0xe2c7260805f154a9ULL, 0x1ee010797be03bULL },
  { 0x428735b105428d3fULL, 0x823cd1ce1745cd75ULL, 0x795213f97f73f6b6ULL, 0x2b9bf19a747cbfc4ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0x3f9c6659342e370fULL, 0xf1f47a243a64e669ULL, 0x224eef4d946ae957ULL, 0x5cf999c6825c44eULL },
  { 0x2596fd4e81c708e2ULL, 0x1ca466b68cb6d78eULL, 0xdee76157756312eeULL, 0x140a74736e24e29bULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0xfda81c784826e31ULL, 0xe9eed91be48d3c3aULL, 0x183e49325cf08d8eULL, 0x33f6c3a61235bcdfULL },
  { 0xa07cf7577ab616ccULL, 0xae5e199b367e7eefULL, 0xab3b2e403d16de17ULL, 0x312ff64fb63d8920ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x3f644eacb251b410ULL, 0x5faae7d86dffd611ULL, 0xd72a38d3575406bcULL, 0x2f977f60a886c472ULL },
  { 0xf004097ce8356630ULL, 0xc412b63b208a6238ULL, 0x5841daf92c5aa53ULL, 0xa15dfc328b9bdaeULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0x7880cf22a255a2d0ULL, 0xa43c193d6b077fd4ULL, 0xe4ba3aacb21d1118ULL, 0x32b7183d5c80039ULL },
  { 0xaa9bad34610f86ceULL, 0xfb053d450f0efc8ULL, 0x2fb1941b069d00bbULL, 0x30536ccca79b4edULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x96dca5b20fe0a312ULL, 0x757cb5f3b6cf4666ULL, 0xb692e0ea731c1521ULL, 0x26f70d629eda4e3fULL },
  { 0xaf2edadb429b5599ULL, 0x2ca2e2e37c8ea357ULL, 0x4a8dc22b4d97ebf1ULL, 0x1c466e487b8fd8e1ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x54ceb470937ac5cfULL, 0xcbfdd39420269d90ULL, 0x8770e78dfc2fbe38ULL, 0x1695534dc7b1f081ULL },
  { 0x3b376233cac748ULL, 0x43b45cbca4f5e94aULL, 0x4cf211c7c87b5e84ULL, 0x28462a2668110aa5ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0x2c5bd5c66a78680bULL, 0x457d82d7c8d8d73bULL, 0xd0a388fb132af00aULL, 0x1b2ee5d1dad3efb4ULL },
  { 0xf73e3a362316815eULL, 0xee5161ac4d71aacdULL, 0xc903506bb9633471ULL, 0x73351b11e899e45ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x7b105784a4a23edULL, 0xf60443ba0d9b1133ULL, 0xddf9f51d2453a230ULL, 0x37101faca77474aULL },
  { 0x73109526a0864900ULL, 0x300c10b60bd731d8ULL, 0xcb9e8a508ea3af1cULL, 0x19c7b8bbc0e859d8ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x992e8c38415d1660ULL, 0xda7e903fdcdb4c2bULL, 0xc1df71e92a6a5fc4ULL, 0xa103aefa5a4bf82ULL },
  { 0x1a739ebf331f6bc6ULL, 0x702f45148f5008c6ULL, 0x3fa56a637b3f419fULL, 0x7b81a3ea6d582fcULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0xcca76cac14d523acULL, 0x3de2fa21765d25e0ULL, 0x683ddab76bac27b8ULL, 0x13789737654d2d9eULL },
  { 0x50b46aff6e313cacULL, 0x16cfac15345f1678ULL, 0xe4d9d2ea61aca77cULL, 0x1d436ba48a31d499ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x3646af40b6578902ULL, 0x2170a7507f8c558eULL, 0xf9fe42bb31db731cULL, 0x240763a00fc8bb9cULL },
  { 0xc1112bb118a4c3adULL, 0xda3b510858d1ef92ULL, 0xe83ce088ba4eae21ULL, 0x239d334b20768baeULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x440945df5877cc2ULL, 0xdd77f7b1b68f4e8dULL, 0x244b95b64d0b2537ULL, 0x33d8753d2d045c32ULL },
  { 0x59e096e6fdd17bdeULL, 0x745b7930893a1d92ULL, 0x4a10e9573a452d9dULL, 0x563f9ad0fd89f3aULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
{ { { { 0x5659e9eb0ea2bdbdULL, 0xc7dbd92ca6c82713ULL, 0x32b09b2e8b4c0968ULL, 0x2744ee8fc479c431ULL },
  { 0x938b1b8364ef6983ULL, 0xabc32fc766a4f7efULL, 0xa7a46d0952c5089dULL, 0x1d834e17b68f2f37ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x74a0e562bcda166aULL, 0x1d0eceafccf46a73ULL, 0xe6440f1a9af2ecb3ULL, 0x1930a4d421eeb321ULL },
  { 0x65131e624db26ab8ULL, 0x327078a51dcadcfcULL, 0xf8c756479ebbdb00ULL, 0x2a0523707d99f898ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x3ade114cb1a7fc03ULL, 0xbc0238b94b599849ULL, 0x775a61138fd23986ULL, 0x245dcd782edb7f1bULL },
  { 0xc09dd4f03c029d76ULL, 0x8c232d7284a30ba2ULL, 0x473e44cd624d803eULL, 0x1ea09ee142054cb1ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } },
};

const uintbig torsion_basis_two_uintbig[3][2][2] = 
{ { { { 0x8866ae14c4dfa062ULL, 0x2cba1eebb69fa792ULL, 0x2452d1852c43cd9ULL, 0xf939462ae560649ULL },
  { 0x37b25d4c1cde278cULL, 0x8a857aa744cd3febULL, 0x578dee317b487826ULL, 0xad3aac3b16bafc1ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x7938dad38f4426dcULL, 0x11b208f486a29ca7ULL, 0x6eb63309ceb9556aULL, 0x2bcf8c8507c3627fULL },
  { 0x96fa6bb5bc533c17ULL, 0x24d963c5018dbbcULL, 0xdd3706dbc23733d6ULL, 0x10477981f4d53065ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } },
 { { { 0x674cabbf457d8385ULL, 0xfa47857bca10ed43ULL, 0x989df8ef746d18a6ULL, 0xdf789e99a0b79c8ULL },
  { 0x4fd3cbd004af08d9ULL, 0x4a016cf295beabd9ULL, 0xffe92b94a2f3d973ULL, 0x1b9d4af710c1a9d9ULL } },
  { { 0x1ULL, 0x0ULL, 0x0ULL, 0x0ULL },
  { 0x0ULL, 0x0ULL, 0x0ULL, 0x0ULL } } } };


proj torsion_basis[13][3];
proj torsion_basis_sum[3];
point torsion_basis_ted_sum[3];
proj torsion_basis_twist[18][3];
proj torsion_basis_twist_sum[3];
point torsion_basis_twist_ted_sum[3];
proj torsion_basis_two[3];


void init_precomputations_generated() {
	global_setup.action_2 = malloc(13*sizeof(GEN));
	global_setup.action_3 = malloc(13*sizeof(GEN));
	global_setup.action_4 = malloc(13*sizeof(GEN));
	global_setup.action_twist_2 = malloc(18*sizeof(GEN));
	global_setup.action_twist_3 = malloc(18*sizeof(GEN));
	global_setup.action_twist_4 = malloc(18*sizeof(GEN));

	global_setup.action_2[0] = mkmat2(mkcol2(stoi(14ULL),stoi(19ULL)),mkcol2(stoi(12ULL),stoi(11ULL)));
	global_setup.action_3[0] = mkmat2(mkcol2(stoi(10ULL),stoi(22ULL)),mkcol2(stoi(5ULL),stoi(16ULL)));
	global_setup.action_4[0] = mkmat2(mkcol2(stoi(10ULL),stoi(12ULL)),mkcol2(stoi(0ULL),stoi(15ULL)));
	global_setup.action_2[1] = mkmat2(mkcol2(stoi(4ULL),stoi(1ULL)),mkcol2(stoi(4ULL),stoi(3ULL)));
	global_setup.action_3[1] = mkmat2(mkcol2(stoi(2ULL),stoi(1ULL)),mkcol2(stoi(5ULL),stoi(6ULL)));
	global_setup.action_4[1] = mkmat2(mkcol2(stoi(6ULL),stoi(3ULL)),mkcol2(stoi(2ULL),stoi(1ULL)));
	global_setup.action_2[2] = mkmat2(mkcol2(stoi(1ULL),stoi(1ULL)),mkcol2(stoi(9ULL),stoi(10ULL)));
	global_setup.action_3[2] = mkmat2(mkcol2(stoi(0ULL),stoi(5ULL)),mkcol2(stoi(0ULL),stoi(1ULL)));
	global_setup.action_4[2] = mkmat2(mkcol2(stoi(0ULL),stoi(6ULL)),mkcol2(stoi(0ULL),stoi(0ULL)));
	global_setup.action_2[3] = mkmat2(mkcol2(stoi(14ULL),stoi(1ULL)),mkcol2(stoi(12ULL),stoi(5ULL)));
	global_setup.action_3[3] = mkmat2(mkcol2(stoi(6ULL),stoi(11ULL)),mkcol2(stoi(18ULL),stoi(14ULL)));
	global_setup.action_4[3] = mkmat2(mkcol2(stoi(7ULL),stoi(16ULL)),mkcol2(stoi(10ULL),stoi(12ULL)));
	global_setup.action_2[4] = mkmat2(mkcol2(stoi(510ULL),stoi(238ULL)),mkcol2(stoi(522ULL),stoi(331ULL)));
	global_setup.action_3[4] = mkmat2(mkcol2(stoi(523ULL),stoi(580ULL)),mkcol2(stoi(524ULL),stoi(319ULL)));
	global_setup.action_4[4] = mkmat2(mkcol2(stoi(377ULL),stoi(0ULL)),mkcol2(stoi(720ULL),stoi(464ULL)));
	global_setup.action_2[5] = mkmat2(mkcol2(stoi(336ULL),stoi(404ULL)),mkcol2(stoi(361ULL),stoi(1033ULL)));
	global_setup.action_3[5] = mkmat2(mkcol2(stoi(80ULL),stoi(1340ULL)),mkcol2(stoi(690ULL),stoi(1290ULL)));
	global_setup.action_4[5] = mkmat2(mkcol2(stoi(353ULL),stoi(779ULL)),mkcol2(stoi(1021ULL),stoi(1016ULL)));
	global_setup.action_2[6] = mkmat2(mkcol2(stoi(20ULL),stoi(29ULL)),mkcol2(stoi(4ULL),stoi(27ULL)));
	global_setup.action_3[6] = mkmat2(mkcol2(stoi(34ULL),stoi(3ULL)),mkcol2(stoi(2ULL),stoi(14ULL)));
	global_setup.action_4[6] = mkmat2(mkcol2(stoi(33ULL),stoi(43ULL)),mkcol2(stoi(2ULL),stoi(14ULL)));
	global_setup.action_2[7] = mkmat2(mkcol2(stoi(36ULL),stoi(111ULL)),mkcol2(stoi(109ULL),stoi(161ULL)));
	global_setup.action_3[7] = mkmat2(mkcol2(stoi(136ULL),stoi(142ULL)),mkcol2(stoi(101ULL),stoi(62ULL)));
	global_setup.action_4[7] = mkmat2(mkcol2(stoi(150ULL),stoi(174ULL)),mkcol2(stoi(156ULL),stoi(47ULL)));
	global_setup.action_2[8] = mkmat2(mkcol2(stoi(214ULL),stoi(223ULL)),mkcol2(stoi(231ULL),stoi(49ULL)));
	global_setup.action_3[8] = mkmat2(mkcol2(stoi(26ULL),stoi(146ULL)),mkcol2(stoi(64ULL),stoi(238ULL)));
	global_setup.action_4[8] = mkmat2(mkcol2(stoi(111ULL),stoi(158ULL)),mkcol2(stoi(200ULL),stoi(152ULL)));
	global_setup.action_2[9] = mkmat2(mkcol2(stoi(49ULL),stoi(157ULL)),mkcol2(stoi(178ULL),stoi(232ULL)));
	global_setup.action_3[9] = mkmat2(mkcol2(stoi(52ULL),stoi(77ULL)),mkcol2(stoi(13ULL),stoi(230ULL)));
	global_setup.action_4[9] = mkmat2(mkcol2(stoi(93ULL),stoi(262ULL)),mkcol2(stoi(189ULL),stoi(188ULL)));
	global_setup.action_2[10] = mkmat2(mkcol2(stoi(323ULL),stoi(173ULL)),mkcol2(stoi(231ULL),stoi(138ULL)));
	global_setup.action_3[10] = mkmat2(mkcol2(stoi(74ULL),stoi(337ULL)),mkcol2(stoi(51ULL),stoi(388ULL)));
	global_setup.action_4[10] = mkmat2(mkcol2(stoi(455ULL),stoi(334ULL)),mkcol2(stoi(160ULL),stoi(6ULL)));
	global_setup.action_2[11] = mkmat2(mkcol2(stoi(166ULL),stoi(75ULL)),mkcol2(stoi(98ULL),stoi(355ULL)));
	global_setup.action_3[11] = mkmat2(mkcol2(stoi(148ULL),stoi(331ULL)),mkcol2(stoi(290ULL),stoi(374ULL)));
	global_setup.action_4[11] = mkmat2(mkcol2(stoi(470ULL),stoi(157ULL)),mkcol2(stoi(229ULL),stoi(51ULL)));
	global_setup.action_2[12] = mkmat2(mkcol2(stoi(674ULL),stoi(2586ULL)),mkcol2(stoi(1355ULL),stoi(3249ULL)));
	global_setup.action_3[12] = mkmat2(mkcol2(stoi(3679ULL),stoi(515ULL)),mkcol2(stoi(2969ULL),stoi(245ULL)));
	global_setup.action_4[12] = mkmat2(mkcol2(stoi(833ULL),stoi(3853ULL)),mkcol2(stoi(2459ULL),stoi(3090ULL)));
	global_setup.action_twist_2[0] = mkmat2(mkcol2(strtoi("1368537545567957016548814229814"),strtoi("3948157707852996199243031137379")),mkcol2(strtoi("1456144039057873796226216284021"),strtoi("8932513915309580437424733038029")));
	global_setup.action_twist_3[0] = mkmat2(mkcol2(strtoi("8349243571534214212353033009524"),strtoi("407140549410666337291473153041")),mkcol2(strtoi("3429468218175452910797139794692"),strtoi("1951807889343323241620514258320")));
	global_setup.action_twist_4[0] = mkmat2(mkcol2(strtoi("3141500583425614010986462236750"),strtoi("9028529805164723815232559721517")),mkcol2(strtoi("5714947132252523258317883127212"),strtoi("7159550877451923442987085031093")));
	global_setup.action_twist_2[1] = mkmat2(mkcol2(stoi(5ULL),stoi(0ULL)),mkcol2(stoi(11ULL),stoi(8ULL)));
	global_setup.action_twist_3[1] = mkmat2(mkcol2(stoi(12ULL),stoi(12ULL)),mkcol2(stoi(9ULL),stoi(2ULL)));
	global_setup.action_twist_4[1] = mkmat2(mkcol2(stoi(8ULL),stoi(8ULL)),mkcol2(stoi(9ULL),stoi(5ULL)));
	global_setup.action_twist_2[2] = mkmat2(mkcol2(stoi(9ULL),stoi(8ULL)),mkcol2(stoi(11ULL),stoi(8ULL)));
	global_setup.action_twist_3[2] = mkmat2(mkcol2(stoi(10ULL),stoi(4ULL)),mkcol2(stoi(5ULL),stoi(8ULL)));
	global_setup.action_twist_4[2] = mkmat2(mkcol2(stoi(11ULL),stoi(15ULL)),mkcol2(stoi(14ULL),stoi(6ULL)));
	global_setup.action_twist_2[3] = mkmat2(mkcol2(stoi(18ULL),stoi(8ULL)),mkcol2(stoi(40ULL),stoi(25ULL)));
	global_setup.action_twist_3[3] = mkmat2(mkcol2(stoi(28ULL),stoi(22ULL)),mkcol2(stoi(35ULL),stoi(16ULL)));
	global_setup.action_twist_4[3] = mkmat2(mkcol2(stoi(10ULL),stoi(8ULL)),mkcol2(stoi(17ULL),stoi(33ULL)));
	global_setup.action_twist_2[4] = mkmat2(mkcol2(stoi(65ULL),stoi(70ULL)),mkcol2(stoi(57ULL),stoi(14ULL)));
	global_setup.action_twist_3[4] = mkmat2(mkcol2(stoi(68ULL),stoi(47ULL)),mkcol2(stoi(35ULL),stoi(12ULL)));
	global_setup.action_twist_4[4] = mkmat2(mkcol2(stoi(76ULL),stoi(24ULL)),mkcol2(stoi(21ULL),stoi(3ULL)));
	global_setup.action_twist_2[5] = mkmat2(mkcol2(stoi(75ULL),stoi(134ULL)),mkcol2(stoi(33ULL),stoi(82ULL)));
	global_setup.action_twist_3[5] = mkmat2(mkcol2(stoi(30ULL),stoi(149ULL)),mkcol2(stoi(99ULL),stoi(128ULL)));
	global_setup.action_twist_4[5] = mkmat2(mkcol2(stoi(130ULL),stoi(67ULL)),mkcol2(stoi(2ULL),stoi(27ULL)));
	global_setup.action_twist_2[6] = mkmat2(mkcol2(stoi(156ULL),stoi(83ULL)),mkcol2(stoi(84ULL),stoi(83ULL)));
	global_setup.action_twist_3[6] = mkmat2(mkcol2(stoi(152ULL),stoi(121ULL)),mkcol2(stoi(74ULL),stoi(88ULL)));
	global_setup.action_twist_4[6] = mkmat2(mkcol2(stoi(218ULL),stoi(129ULL)),mkcol2(stoi(29ULL),stoi(21ULL)));
	global_setup.action_twist_2[7] = mkmat2(mkcol2(stoi(143ULL),stoi(202ULL)),mkcol2(stoi(100ULL),stoi(128ULL)));
	global_setup.action_twist_3[7] = mkmat2(mkcol2(stoi(166ULL),stoi(81ULL)),mkcol2(stoi(65ULL),stoi(106ULL)));
	global_setup.action_twist_4[7] = mkmat2(mkcol2(stoi(12ULL),stoi(204ULL)),mkcol2(stoi(259ULL),stoi(259ULL)));
	global_setup.action_twist_2[8] = mkmat2(mkcol2(stoi(67ULL),stoi(157ULL)),mkcol2(stoi(112ULL),stoi(216ULL)));
	global_setup.action_twist_3[8] = mkmat2(mkcol2(stoi(279ULL),stoi(187ULL)),mkcol2(stoi(267ULL),stoi(5ULL)));
	global_setup.action_twist_4[8] = mkmat2(mkcol2(stoi(50ULL),stoi(13ULL)),mkcol2(stoi(58ULL),stoi(233ULL)));
	global_setup.action_twist_2[9] = mkmat2(mkcol2(stoi(279ULL),stoi(305ULL)),mkcol2(stoi(239ULL),stoi(28ULL)));
	global_setup.action_twist_3[9] = mkmat2(mkcol2(stoi(140ULL),stoi(2ULL)),mkcol2(stoi(17ULL),stoi(168ULL)));
	global_setup.action_twist_4[9] = mkmat2(mkcol2(stoi(37ULL),stoi(222ULL)),mkcol2(stoi(166ULL),stoi(270ULL)));
	global_setup.action_twist_2[10] = mkmat2(mkcol2(stoi(333ULL),stoi(458ULL)),mkcol2(stoi(225ULL),stoi(230ULL)));
	global_setup.action_twist_3[10] = mkmat2(mkcol2(stoi(393ULL),stoi(247ULL)),mkcol2(stoi(43ULL),stoi(171ULL)));
	global_setup.action_twist_4[10] = mkmat2(mkcol2(stoi(242ULL),stoi(114ULL)),mkcol2(stoi(353ULL),stoi(321ULL)));
	global_setup.action_twist_2[11] = mkmat2(mkcol2(stoi(324ULL),stoi(23ULL)),mkcol2(stoi(358ULL),stoi(275ULL)));
	global_setup.action_twist_3[11] = mkmat2(mkcol2(stoi(546ULL),stoi(238ULL)),mkcol2(stoi(329ULL),stoi(54ULL)));
	global_setup.action_twist_4[11] = mkmat2(mkcol2(stoi(578ULL),stoi(484ULL)),mkcol2(stoi(220ULL),stoi(21ULL)));
	global_setup.action_twist_2[12] = mkmat2(mkcol2(stoi(376ULL),stoi(355ULL)),mkcol2(stoi(390ULL),stoi(231ULL)));
	global_setup.action_twist_3[12] = mkmat2(mkcol2(stoi(524ULL),stoi(203ULL)),mkcol2(stoi(12ULL),stoi(84ULL)));
	global_setup.action_twist_4[12] = mkmat2(mkcol2(stoi(367ULL),stoi(530ULL)),mkcol2(stoi(145ULL),stoi(240ULL)));
	global_setup.action_twist_2[13] = mkmat2(mkcol2(stoi(541ULL),stoi(329ULL)),mkcol2(stoi(53ULL),stoi(78ULL)));
	global_setup.action_twist_3[13] = mkmat2(mkcol2(stoi(81ULL),stoi(138ULL)),mkcol2(stoi(507ULL),stoi(539ULL)));
	global_setup.action_twist_4[13] = mkmat2(mkcol2(stoi(164ULL),stoi(56ULL)),mkcol2(stoi(509ULL),stoi(455ULL)));
	global_setup.action_twist_2[14] = mkmat2(mkcol2(stoi(498ULL),stoi(200ULL)),mkcol2(stoi(376ULL),stoi(245ULL)));
	global_setup.action_twist_3[14] = mkmat2(mkcol2(stoi(343ULL),stoi(514ULL)),mkcol2(stoi(144ULL),stoi(401ULL)));
	global_setup.action_twist_4[14] = mkmat2(mkcol2(stoi(490ULL),stoi(336ULL)),mkcol2(stoi(45ULL),stoi(253ULL)));
	global_setup.action_twist_2[15] = mkmat2(mkcol2(stoi(685ULL),stoi(666ULL)),mkcol2(stoi(567ULL),stoi(142ULL)));
	global_setup.action_twist_3[15] = mkmat2(mkcol2(stoi(671ULL),stoi(234ULL)),mkcol2(stoi(42ULL),stoi(157ULL)));
	global_setup.action_twist_4[15] = mkmat2(mkcol2(stoi(504ULL),stoi(212ULL)),mkcol2(stoi(212ULL),stoi(323ULL)));
	global_setup.action_twist_2[16] = mkmat2(mkcol2(stoi(306ULL),stoi(834ULL)),mkcol2(stoi(110ULL),stoi(635ULL)));
	global_setup.action_twist_3[16] = mkmat2(mkcol2(stoi(769ULL),stoi(189ULL)),mkcol2(stoi(562ULL),stoi(173ULL)));
	global_setup.action_twist_4[16] = mkmat2(mkcol2(stoi(154ULL),stoi(742ULL)),mkcol2(stoi(131ULL),stoi(787ULL)));
	global_setup.action_twist_2[17] = mkmat2(mkcol2(stoi(987ULL),stoi(880ULL)),mkcol2(stoi(2241ULL),stoi(1370ULL)));
	global_setup.action_twist_3[17] = mkmat2(mkcol2(stoi(1996ULL),stoi(939ULL)),mkcol2(stoi(1082ULL),stoi(362ULL)));
	global_setup.action_twist_4[17] = mkmat2(mkcol2(stoi(1889ULL),stoi(857ULL)),mkcol2(stoi(1594ULL),stoi(468ULL)));
	global_setup.action_two_2 = mkmat2(mkcol2(strtoi("31479152875545029957"),stoi(480731893264431870ULL)),mkcol2(strtoi("26250023622549539277"),stoi(5414335271874073275ULL)));
	global_setup.action_two_3 = mkmat2(mkcol2(strtoi("31479152875545029957"),stoi(480731893264431870ULL)),mkcol2(strtoi("26250023622549539277"),stoi(5414335271874073275ULL)));
	global_setup.action_two_4 = mkmat2(mkcol2(strtoi("31479152875545029957"),stoi(480731893264431870ULL)),mkcol2(strtoi("26250023622549539277"),stoi(5414335271874073275ULL)));
	for (int i = 0; i < 3; ++i) {
		fp_enc( &(&(&torsion_basis_two[i])->x)->re, &(torsion_basis_two_uintbig[i][0][0]) );
		fp_enc( &(&(&torsion_basis_two[i])->x)->im, &(torsion_basis_two_uintbig[i][0][1]) );
		fp_enc( &(&(&torsion_basis_two[i])->z)->re, &(torsion_basis_two_uintbig[i][1][0]) );
		fp_enc( &(&(&torsion_basis_two[i])->z)->im, &(torsion_basis_two_uintbig[i][1][1]) );
	}
	for (int i = 0; i < 3; ++i) {
		fp_enc( &(&(&torsion_basis_sum[i])->x)->re, &(torsion_basis_sum_uintbig[i][0][0]) );
		fp_enc( &(&(&torsion_basis_sum[i])->x)->im, &(torsion_basis_sum_uintbig[i][0][1]) );
		fp_enc( &(&(&torsion_basis_sum[i])->z)->re, &(torsion_basis_sum_uintbig[i][1][0]) );
		fp_enc( &(&(&torsion_basis_sum[i])->z)->im, &(torsion_basis_sum_uintbig[i][1][1]) );
	}
	for (int i = 0; i < 3; ++i) {
		fp_enc( &(&(&torsion_basis_twist_sum[i])->x)->re, &(torsion_basis_twist_sum_uintbig[i][0][0]) );
		fp_enc( &(&(&torsion_basis_twist_sum[i])->x)->im, &(torsion_basis_twist_sum_uintbig[i][0][1]) );
		fp_enc( &(&(&torsion_basis_twist_sum[i])->z)->re, &(torsion_basis_twist_sum_uintbig[i][1][0]) );
		fp_enc( &(&(&torsion_basis_twist_sum[i])->z)->im, &(torsion_basis_twist_sum_uintbig[i][1][1]) );
	}
	for (int j=0;j<13;j++){
		for (int i = 0; i < 3; ++i) {
			fp_enc( &(&(&torsion_basis[j][i])->x)->re, &(torsion_basis_uintbig[j][i][0][0]) );
			fp_enc( &(&(&torsion_basis[j][i])->x)->im, &(torsion_basis_uintbig[j][i][0][1]) );
			fp_enc( &(&(&torsion_basis[j][i])->z)->re, &(torsion_basis_uintbig[j][i][1][0]) );
			fp_enc( &(&(&torsion_basis[j][i])->z)->im, &(torsion_basis_uintbig[j][i][1][1]) );
		}
	}
	for (int j=0;j<18;j++){
		for (int i = 0; i < 3; ++i) {
			fp_enc( &(&(&torsion_basis_twist[j][i])->x)->re, &(torsion_basis_twist_uintbig[j][i][0][0]) );
			fp_enc( &(&(&torsion_basis_twist[j][i])->x)->im, &(torsion_basis_twist_uintbig[j][i][0][1]) );
			fp_enc( &(&(&torsion_basis_twist[j][i])->z)->re, &(torsion_basis_twist_uintbig[j][i][1][0]) );
			fp_enc( &(&(&torsion_basis_twist[j][i])->z)->im, &(torsion_basis_twist_uintbig[j][i][1][1]) );
		}
	}
    	for (int i=0;i<3;i++){
    		fp_enc( &(&(&torsion_basis_ted_sum[i])->x)->re, &(torsion_basis_ted_sum_uintbig[i][0][0]) );
    		fp_enc( &(&(&torsion_basis_ted_sum[i])->x)->im, &(torsion_basis_ted_sum_uintbig[i][0][1]) );
    		fp_enc( &(&(&torsion_basis_ted_sum[i])->y)->re, &(torsion_basis_ted_sum_uintbig[i][1][0]) );
    		fp_enc( &(&(&torsion_basis_ted_sum[i])->y)->im, &(torsion_basis_ted_sum_uintbig[i][1][1]) );
    		fp_enc( &(&(&torsion_basis_ted_sum[i])->z)->re, &(torsion_basis_ted_sum_uintbig[i][2][0]) );
    		fp_enc( &(&(&torsion_basis_ted_sum[i])->z)->im, &(torsion_basis_ted_sum_uintbig[i][2][1]) );
    		fp_enc( &(&(&torsion_basis_ted_sum[i])->t)->re, &(torsion_basis_ted_sum_uintbig[i][3][0]) );
    		fp_enc( &(&(&torsion_basis_ted_sum[i])->t)->im, &(torsion_basis_ted_sum_uintbig[i][3][1]) );
  	}
  	for (int i=0;i<3;i++){
    		fp_enc( &(&(&torsion_basis_twist_ted_sum[i])->x)->re, &(torsion_basis_twist_ted_sum_uintbig[i][0][0]) );
    		fp_enc( &(&(&torsion_basis_twist_ted_sum[i])->x)->im, &(torsion_basis_twist_ted_sum_uintbig[i][0][1]) );
    		fp_enc( &(&(&torsion_basis_twist_ted_sum[i])->y)->re, &(torsion_basis_twist_ted_sum_uintbig[i][1][0]) );
    		fp_enc( &(&(&torsion_basis_twist_ted_sum[i])->y)->im, &(torsion_basis_twist_ted_sum_uintbig[i][1][1]) );
    		fp_enc( &(&(&torsion_basis_twist_ted_sum[i])->z)->re, &(torsion_basis_twist_ted_sum_uintbig[i][2][0]) );
    		fp_enc( &(&(&torsion_basis_twist_ted_sum[i])->z)->im, &(torsion_basis_twist_ted_sum_uintbig[i][2][1]) );
    		fp_enc( &(&(&torsion_basis_twist_ted_sum[i])->t)->re, &(torsion_basis_twist_ted_sum_uintbig[i][3][0]) );
    		fp_enc( &(&(&torsion_basis_twist_ted_sum[i])->t)->im, &(torsion_basis_twist_ted_sum_uintbig[i][3][1]) );
  	}

}

