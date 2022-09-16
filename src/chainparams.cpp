// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2018 The PIVX developers
// Copyright (c) 2019 The FIX developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "libzerocoin/Params.h"
#include "chainparams.h"
#include "random.h"
#include "util.h"
#include "utilstrencodings.h"

#include <assert.h>

#include <boost/assign/list_of.hpp>

using namespace std;
using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

/**
 * Main network
 */

//! Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress>& vSeedsOut, const SeedSpec6* data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7 * 24 * 60 * 60;
    for (unsigned int i = 0; i < count; i++) {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

//   What makes a good checkpoint block?
// + Is surrounded by blocks with reasonable timestamps
//   (no blocks before with a timestamp after, none after with
//    timestamp before)
// + Contains no strange transactions
static Checkpoints::MapCheckpoints mapCheckpoints =
    boost::assign::map_list_of
    (0,     uint256("000000428366d3a156c38c5061d74317d201781f539460aeeeaae1091de6e4cc")) // genesis
    (8680,  uint256("14f995ab768b0081e79880d121e47c594c92da552580233e91b09991966dc0ba"))
    (10000, uint256("dc3aa2f99360505cac010d7dfeaec876d407e46474c2d95d39fe3f671c2ea57e"))
    (50000, uint256("735787e35b83aa74f23fdfefd0394c7376d13578761edf9b5f2e5938e4bac661"))
    (100000,uint256("590423e112f6fc5697e76018b3efd135c4c0675f2afac75958d36b863819b8e0"))
    (128771,uint256("13ae08ef23f7e3a374014d41b9674650470a3d073b4fb1d73fb08ce1ad4bd5f2"))
    (150000,uint256("16aaad4e853bafe9c874888e5a964b85caaa135e52750badc0029da25bfb6539"))
    (180000,uint256("1e75fb201ccacbec7778d0225d4afc36c8d1fc1355181d4bd8f431e51930c505"))
    (205547,uint256("7d645caf64dbd949682f492efba6c8f93e95b6da06932a5612a9f33f4fdc75a7"))
    (220870,uint256("78af47364586abb9ca5919524740cdb406c6acba4b0c0b442ca7e16a4d477103"))
    (221961,uint256("7a38a37b90a09843c60b921e603c70310cfe47f3dcbf9af18490fe6d29a86885"))
    (221962,uint256("dd6bac54bccfe62d51ab95e29f0b72fb3a30f25a7a1bdea44881f833247abe66")) // known split
    (222280,uint256("76473a9ef532e6eb61c214f258b5c2328d211b36041ec245fb9db682129cdbd8"))
    (223000,uint256("7a48e2590b17c67e17c8bd71aae9ff240d92dea5c1d889d9ac0b44ba3d93b9a4")) // min stake enforcement
    (223090,uint256("2d82005d70894c5bc7d15e965faed7bffcda9a0fad535673bfea38237db3eff5"))
    (223460,uint256("c0aebe9999f1fdd1f1dc908ecddbf4c1f1c94ad54c7f34cf596ce6b8dca466c5"))
    (240000,uint256("694996ac2425e7e1f3a8d0dc64a550354fe352ad92d6a89127cddba6209573cb"))
    (250000,uint256("770220fe034632ab77ae732390308328f98d7b3dd214851b907a74607f5a3f6a"))
    (264400,uint256("b0568911a34d78138f2e3873457bea6c16a9fd98cb05f4dfeb87c39c768e5d36"))
    (285995,uint256("5ec97787dd77fc97dcdf2708e07561c31a49e9d104824f36e933a2a3da7c148a"))
    (300000,uint256("04439d73a64502015c058af5096706d83ece1989da12247e6b9bea9a093e4807"))
    (400000,uint256("0c4bf326b115482a22faac9cf7e25901c70279c0c461d50d18974761251c16ab"))
    (500000,uint256("e4fed8d4d06e7aab50a2ce4dd92d42214e07e558f105275cb6adf7455353fd51"))
    (600000,uint256("a4ba1e07d11bd279a77474aec2533b3e20f241271c8ce7033ce8c6c7bb85dc15"))
    (614023,uint256("a73967277c5987be9bae93425d2f6a207c536bb08fa29c6a8ce8d58710561bf4"))
    (700000,uint256("783ee4ffa301e67dbe1cc24036c6ab8db001215d843f3735831065efdf0eb526"))
    (800000,uint256("dcee34f8cd4089c531f4f051e36ddad0cbea7fe128d79e5fa6796f23b104b262"))
    (824630,uint256("3111b3dd3c58adab1d5abfffda313ffc4efba1f51f087ae0862957a819dff918"))
    (825649,uint256("ddec372c78f2eee285d2327e96567e8af31a70cf6161ce549e16c0017d6251be")) // known split
    (825650,uint256("2f22c5a12f743fdd9c4fd1d683ef5e4cdad65c950ee6bf8a27f0ab59784eae90")
    (825750,uint256("5cd379f9884cc40bbc3798e2d38ec4e9bc1a8e40a9b1127e3b60ddba6cd5691c"))
    (836337,uint256("5f518cc640587a8e29fad49ad2b0b1dec90273e8fd982df936ccf0217742e7b5")) // - decision point
    (836525,uint256("90f481c53230d9f0bc5608a23551e527c6e08bf35dcc7dfc72e928b2f7b3df82"))
    ;
static const Checkpoints::CCheckpointData data = {
    &mapCheckpoints,
    1663350846, // * UNIX timestamp of last checkpoint block
    2010258,    // * total number of transactions between genesis and last checkpoint
                //   (the tx=... number in the SetBestChain debug.log lines)
    0           // * estimated number of transactions per day after checkpoint
};

static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
    boost::assign::map_list_of
    (0,     uint256("000002849e7ad33536de6c50b3efb55fe8f20f219de408be70a6614c105e6bff"))
    (5000,  uint256("c6b04dcafad808edfd8dca95be127809f4fcd40aa194728e895a86c6c0c80b2d"))
    (9200,  uint256("73ff600a73400badcc9b5f09f3bc3db917906e5188975806c3fff4a2f7524ec8"))
    (10000, uint256("32dd5d45b7904772a5311dbbc4e25aab7efafa3401465a123cd2f1aefbc422f2"))
    (11000, uint256("735ec49a6b2cec9595723133d932540ef55bf937f9ec0ca1f50cb6ccc39a1872"))
    (12000, uint256("67e93f3c2a06a91f8c57f990f0fdedd521e8c1be8f7386f887b78beee0988be6"))
    ;
static const Checkpoints::CCheckpointData dataTestnet = {
    &mapCheckpointsTestnet,
    1560668520,   // * UNIX timestamp of last checkpoint block
    24122,        // * total number of transactions between genesis and last checkpoint
    0};           // * estimated number of transactions per day after checkpoint

static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
    boost::assign::map_list_of(0, uint256("0x001"));
static const Checkpoints::CCheckpointData dataRegtest = {
    &mapCheckpointsRegtest,
    1454124731,
    0,
    100};

libzerocoin::ZerocoinParams* CChainParams::Zerocoin_Params(bool useModulusV1) const
{
    assert(this);
    static CBigNum bnHexModulus = 0;
    if (!bnHexModulus)
        bnHexModulus.SetHex(zerocoinModulus);
    static libzerocoin::ZerocoinParams ZCParamsHex = libzerocoin::ZerocoinParams(bnHexModulus);
    static CBigNum bnDecModulus = 0;
    if (!bnDecModulus)
        bnDecModulus.SetDec(zerocoinModulus);
    static libzerocoin::ZerocoinParams ZCParamsDec = libzerocoin::ZerocoinParams(bnDecModulus);

    if (useModulusV1)
        return &ZCParamsHex;

    return &ZCParamsDec;
}

class CMainParams : public CChainParams
{
public:
    CMainParams()
    {
        networkID = CBaseChainParams::MAIN;
        strNetworkID = "main";
        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */
        pchMessageStart[0] = 0x74;
        pchMessageStart[1] = 0x2c;
        pchMessageStart[2] = 0x4d;
        pchMessageStart[3] = 0x64;
        vAlertPubKey = ParseHex("04a5444604ff432916a1e55f15deae3fde6f7d9349c5987dd5202398224dfd929b8a3059253cdb97fd47c3fcf45aa9bd98ab2bfabab0db48f817eac0448a770ccb");
        nDefaultPort = 17464;
        bnProofOfWorkLimit = ~uint256(0) >> 20; // FIX starting difficulty is 1 / 2^12
        nSubsidyHalvingInterval = 0;
        nMaxReorganizationDepth = 100;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 0;
        nTargetTimespan = 1 * 60;
        nTargetSpacing = 2 * 60;  // FIX: 2 minute
        nMaturity = 60;
        nMasternodeCountDrift = 20;
        nMaxMoneyOut = 1000000000 * COIN;

        nTier1mCollateral =     1000000 * COIN;
        nTier1mProbability =                 1;
        nTier5mCollateral =     5000000 * COIN;
        nTier5mProbability =                 5;
        // nTier10mCollateral =   10000000 * COIN;
        // nTier10mProbability =               10;
        nTier20mCollateral =   20000000 * COIN;
        nTier20mProbability =               20;
        nTier100mCollateral = 100000000 * COIN;
        nTier100mProbability =             100;
        nStakeMinInput = 12000 * COIN;

        /** Height or Time Based Activations **/
        nLastPOWBlock = 400;
        nModifierUpdateBlock = 200;
        nZerocoinStartHeight = 15000000;
        nZerocoinStartTime = 4070908800;
        nBlockEnforceSerialRange = 895400; //Enforce serial range starting this block
        // nBlockRecalculateAccumulators = 908000; //Trigger a recalculation of accumulators
        nBlockRecalculateAccumulators = 6569605; //Trigger a recalculation of accumulators
        nBlockFirstFraudulent = 891737; //First block that bad serials emerged
        nBlockLastGoodCheckpoint = 891730; //Last valid accumulator checkpoint
        nBlockEnforceInvalidUTXO = 902850; //Start enforcing the invalid UTXO's
        nInvalidAmountFiltered = 268200*COIN; //Amount of invalid coins filtered through exchanges, that should be considered valid
        nBlockZerocoinV2 = 104153160; //!> The block that zerocoin v2 becomes active - roughly Tuesday, May 8, 2018 4:00:00 AM GMT
        nEnforceNewSporkKey = 1547424000; //!> Sporks signed after (GMT): Monday, January 14, 2019 00:00:00 AM GMT must use the new spork key
        nRejectOldSporkKey = 1547510400; //!> Fully reject old spork key after (GMT): Tuesday, Janurary 15, 2019 00:00:00 AM GMT

        /**
         * Build the genesis block. Note that the output of the genesis coinbase cannot
         * be spent as it did not originally exist in the database.
         *
         * CBlock(hash=00000ffd590b14, ver=1, hashPrevBlock=00000000000000, hashMerkleRoot=e0028e, nTime=1390095618, nBits=1e0ffff0, nNonce=28917698, vtx=1)
         *   CTransaction(hash=e0028e, ver=1, vin.size=1, vout.size=1, nLockTime=0)
         *     CTxIn(COutPoint(000000, -1), coinbase 04ffff001d01044c5957697265642030392f4a616e2f3230313420546865204772616e64204578706572696d656e7420476f6573204c6976653a204f76657273746f636b2e636f6d204973204e6f7720416363657074696e6720426974636f696e73)
         *     CTxOut(nValue=50.00000000, scriptPubKey=0xA9037BAC7050C479B121CF)
         *   vMerkleTree: e0028e
         */
        const char* pszTimestamp = "Economist 2019/05/30 Facebook's planned new currency may be based on a blockchain";
        CMutableTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].nValue = 1 * COIN;
        txNew.vout[0].scriptPubKey = CScript() << ParseHex("04f0cd5da4335ab317a47e6cb15b0fd73b996c74de4640ea0b3d2e30516767d4033e71de6f69eb8c0f7f9ce9b6fc3200832aeeb1b876135b897d58d713c4d03656") << OP_CHECKSIG;
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime = 1559224740;
        genesis.nBits = 0x1e0ffff0;
        genesis.nNonce = 3617423;

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x000000428366d3a156c38c5061d74317d201781f539460aeeeaae1091de6e4cc"));
        assert(genesis.hashMerkleRoot == uint256("0x17d377a8a6d988698164f5fc9ffa8d5d03d0d1187e3a0ed886c239b3eae4be2f"));

        vSeeds.push_back(CDNSSeedData("45.77.64.171", "45.77.64.171"));   //Germany
        vSeeds.push_back(CDNSSeedData("67.219.107.45", "67.219.107.45")); //Australia
        vSeeds.push_back(CDNSSeedData("104.238.185.162", "104.238.185.162")); //UK
        vSeeds.push_back(CDNSSeedData("208.85.21.121", "208.85.21.121")); //Spain
        vSeeds.push_back(CDNSSeedData("45.77.118.66", "45.77.118.66")); //FL
        vSeeds.push_back(CDNSSeedData("65.20.69.84", "65.20.69.84"));   //IN
        vSeeds.push_back(CDNSSeedData("140.82.15.118", "140.82.15.118")); //NJ
        vSeeds.push_back(CDNSSeedData("158.247.239.189", "158.247.239.189"));   //SK
        vSeeds.push_back(CDNSSeedData("216.128.182.65", "216.128.182.65"));   //CA
        vSeeds.push_back(CDNSSeedData("149.28.149.146", "149.28.149.146"));   //Singapore
        vSeeds.push_back(CDNSSeedData("45.32.36.145", "45.32.36.145"));   //Japan

        devAddress = "FCoB1M2CxxN1fAezRAZC31AWtMBZ3zSvyF";

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 35);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 95);
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 60);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x02)(0x2D)(0x25)(0x33).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x02)(0x21)(0x31)(0x2B).convert_to_container<std::vector<unsigned char> >();
        // 	BIP44 coin type is from https://github.com/satoshilabs/slips/blob/master/slip-0044.md
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x01)(0x50).convert_to_container<std::vector<unsigned char> >();
        nExtCoinType = 336;

        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = false;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fSkipProofOfWorkCheck = false;
        fTestnetToBeDeprecatedFieldRPC = false;
        fHeadersFirstSyncingActive = false;

        nPoolMaxTransactions = 3;
        strSporkKey = "046a1535627b95db35cb8a13703ef86c3c381e787c604ff50620e5d6e97bfc02e466a8699c7c7ab742a5b1b559dc180facb8a406da2d9ecff0f00923371d8beae7";
        strSporkKeyOld = "046a1535627b95db35cb8a13703ef86c3c381e787c604ff50620e5d6e97bfc02e466a8699c7c7ab742a5b1b559dc180facb8a406da2d9ecff0f00923371d8beae7";
        strObfuscationPoolDummyAddress = "AMwZqSp6C5fWeXKf7ahGjo2WVers4nAUps";
        nStartMasternodePayments = 1559390400;

        /** Zerocoin */
        zerocoinModulus = "25195908475657893494027183240048398571429282126204032027777137836043662020707595556264018525880784"
            "4069182906412495150821892985591491761845028084891200728449926873928072877767359714183472702618963750149718246911"
            "6507761337985909570009733045974880842840179742910064245869181719511874612151517265463228221686998754918242243363"
            "7259085141865462043576798423387184774447920739934236584823824281198163815010674810451660377306056201619676256133"
            "8441436038339044149526344321901146575444541784240209246165157233507787077498171257724679629263863563732899121548"
            "31438167899885040445364023527381951378636564391212010397122822120720357";
        nMaxZerocoinSpendsPerTransaction = 7; // Assume about 20kb each
        nMinZerocoinMintFee = 1 * CENT; //high fee required for zerocoin mints
        nMintRequiredConfirmations = 20; //the maximum amount of confirmations until accumulated in 19
        nRequiredAccumulation = 1;
        nDefaultSecurityLevel = 100; //full security level for accumulators
        nZerocoinHeaderVersion = 4; //Block headers must be this version once zerocoin is active
        nZerocoinRequiredStakeDepth = 200; //The required confirmations for a zfix to be stakable

        nBudget_Fee_Confirmations = 6; // Number of confirmations for the finalization fee
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return data;
    }
};
static CMainParams mainParams;

/**
 * Testnet (v3)
 */
class CTestNetParams : public CMainParams
{
public:
    CTestNetParams()
    {
        networkID = CBaseChainParams::TESTNET;
        strNetworkID = "test";
        pchMessageStart[0] = 0x44;
        pchMessageStart[1] = 0x6a;
        pchMessageStart[2] = 0xa4;
        pchMessageStart[3] = 0xcc;
        vAlertPubKey = ParseHex("04ff51b2587285c8f26deb67784b29a43d30b6e29d09afe8ae7900770622cb5191d5d1806d1c2b425582b1fcb81d94e7cd65bd3c38995203d8783761faa8612e5a");
        nDefaultPort = 5447;
        nEnforceBlockUpgradeMajority = 51;
        nRejectBlockOutdatedMajority = 75;
        nToCheckBlockUpgradeMajority = 100;
        nMinerThreads = 0;
        nTargetTimespan = 1 * 60;
        nTargetSpacing = 2 * 60;  // FIX: 2 minute
        nLastPOWBlock = 200;
        nMaturity = 15;
        nMasternodeCountDrift = 4;
        nModifierUpdateBlock = 51197; //approx Mon, 17 Apr 2017 04:00:00 GMT
        nMaxMoneyOut = 1000000000 * COIN;

        nTier1mCollateral =     1000000 * COIN;
        nTier1mProbability =                 1;
        nTier5mCollateral =     5000000 * COIN;
        nTier5mProbability =                 5;
        // nTier10mCollateral =   10000000 * COIN;
        // nTier10mProbability =               10;
        nTier20mCollateral =   20000000 * COIN;
        nTier20mProbability =               20;
        nTier100mCollateral = 100000000 * COIN;
        nTier100mProbability =             100;
        nStakeMinInput = 12000 * COIN;

        nZerocoinStartHeight = 200;
        nZerocoinStartTime = 4070908800;
        nBlockEnforceSerialRange = 1; //Enforce serial range starting this block
        nBlockRecalculateAccumulators = 9908000; //Trigger a recalculation of accumulators
        nBlockFirstFraudulent = 9891737; //First block that bad serials emerged
        nBlockLastGoodCheckpoint = 9891730; //Last valid accumulator checkpoint
        nBlockEnforceInvalidUTXO = 9902850; //Start enforcing the invalid UTXO's
        nInvalidAmountFiltered = 0; //Amount of invalid coins filtered through exchanges, that should be considered valid
        nBlockZerocoinV2 = 444020; //!> The block that zerocoin v2 becomes active
        nEnforceNewSporkKey = 1547424000; //!> Sporks signed after (GMT): Monday, January 14, 2019 00:00:00 AM GMT must use the new spork key
        nRejectOldSporkKey = 1547510400; //!> Fully reject old spork key after (GMT): Tuesday, Janurary 15, 2019 00:00:00 AM GMT

        //! Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime = 1559224740;
        genesis.nNonce = 6529523;

        hashGenesisBlock = genesis.GetHash();
        assert(hashGenesisBlock == uint256("0x000002849e7ad33536de6c50b3efb55fe8f20f219de408be70a6614c105e6bff"));

        vFixedSeeds.clear();
        vSeeds.clear();

        // vSeeds.push_back(CDNSSeedData("18.228.216.158", "18.228.216.158")); //Brazil
        // vSeeds.push_back(CDNSSeedData("13.210.111.12", "13.210.111.12"));   //Australia
        vSeeds.push_back(CDNSSeedData("46.19.210.197", "46.19.210.197"));   //Germany
        vSeeds.push_back(CDNSSeedData("46.19.214.68", "46.19.214.68"));     //Singapore
        vSeeds.push_back(CDNSSeedData("142.93.145.197", "142.93.145.197")); //Toronto
        vSeeds.push_back(CDNSSeedData("159.65.84.118", "159.65.84.118"));   //London
        vSeeds.push_back(CDNSSeedData("167.99.223.138", "167.99.223.138")); //Amsterdam
        vSeeds.push_back(CDNSSeedData("68.183.161.44", "68.183.161.44"));   //San Fransisco
        vSeeds.push_back(CDNSSeedData("46.19.212.68", "46.19.212.68"));     //LA
        vSeeds.push_back(CDNSSeedData("46.19.213.68", "46.19.213.68"));     //Miami
        vSeeds.push_back(CDNSSeedData("46.19.209.68", "46.19.209.68"));     //New York

        devAddress = "XmQ5FfZzs76PTHRb2tXcLLsFBJ6A9EjbMV"; // old
        devAddressNew = "XiAHWrbngwovQPdtWzuehx4BL4dvCFKSW3"; //new

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 76);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 137);
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 237);
        // Testnet fix BIP32 pubkeys start with 'DRKV'
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x3a)(0x80)(0x61)(0xa0).convert_to_container<std::vector<unsigned char> >();
        // Testnet fix BIP32 prvkeys start with 'DRKP'
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x3a)(0x80)(0x58)(0x37).convert_to_container<std::vector<unsigned char> >();
        // Testnet fix BIP44 coin type is '1' (All coin's testnet default)
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x01).convert_to_container<std::vector<unsigned char> >();
        nExtCoinType = 1;

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = true;

        nPoolMaxTransactions = 2;
        strSporkKey = "04c9ac467e88caca60e5048efa9d254098422a877f1ffcbb506c4e2b3786b8ae16ae45b586e4106661e4f157da64eeb1486b19940a25511ebcbd07bc8c2f85fdca";
        strSporkKeyOld = "04c9ac467e88caca60e5048efa9d254098422a877f1ffcbb506c4e2b3786b8ae16ae45b586e4106661e4f157da64eeb1486b19940a25511ebcbd07bc8c2f85fdca";
        strObfuscationPoolDummyAddress = "xznpVZnXKi7XDgUd3NXdqVhUftyHKi1L1K";
        nStartMasternodePayments = 1420837558; //Fri, 09 Jan 2015 21:05:58 GMT
        nBudget_Fee_Confirmations = 3; // Number of confirmations for the finalization fee. We have to make this very short
                                       // here because we only have a 8 block finalization window on testnet
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataTestnet;
    }
};
static CTestNetParams testNetParams;

/**
 * Regression test
 */
class CRegTestParams : public CTestNetParams
{
public:
    CRegTestParams()
    {
        networkID = CBaseChainParams::REGTEST;
        strNetworkID = "regtest";
        strNetworkID = "regtest";
        pchMessageStart[0] = 0x2a;
        pchMessageStart[1] = 0xfc;
        pchMessageStart[2] = 0xc7;
        pchMessageStart[3] = 0xca;
        nSubsidyHalvingInterval = 150;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 1;
        nTargetTimespan = 24 * 60 * 60; // FIX: 1 day
        nTargetSpacing = 2 * 60;        // FIX: 2 minutes
        bnProofOfWorkLimit = ~uint256(0) >> 1;
        genesis.nTime = 1537120201;
        genesis.nBits = 0x207fffff;
        genesis.nNonce = 12345;

        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 5467;
       /// assert(hashGenesisBlock == uint256("0x35495958253258ba1a6967ba6b846a297774efc4a010da004b044b0de6b3788e"));

        vFixedSeeds.clear(); //! Testnet mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Testnet mode doesn't have any DNS seeds.

        fMiningRequiresPeers = false;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        fTestnetToBeDeprecatedFieldRPC = false;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataRegtest;
    }
};
static CRegTestParams regTestParams;

/**
 * Unit test
 */
class CUnitTestParams : public CMainParams, public CModifiableParams
{
public:
    CUnitTestParams()
    {
        networkID = CBaseChainParams::UNITTEST;
        strNetworkID = "unittest";
        nDefaultPort = 51478;
        vFixedSeeds.clear(); //! Unit test mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Unit test mode doesn't have any DNS seeds.

        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fAllowMinDifficultyBlocks = false;
        fMineBlocksOnDemand = true;
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        // UnitTest share the same checkpoints as MAIN
        return data;
    }

    //! Published setters to allow changing values in unit test cases
    virtual void setSubsidyHalvingInterval(int anSubsidyHalvingInterval) { nSubsidyHalvingInterval = anSubsidyHalvingInterval; }
    virtual void setEnforceBlockUpgradeMajority(int anEnforceBlockUpgradeMajority) { nEnforceBlockUpgradeMajority = anEnforceBlockUpgradeMajority; }
    virtual void setRejectBlockOutdatedMajority(int anRejectBlockOutdatedMajority) { nRejectBlockOutdatedMajority = anRejectBlockOutdatedMajority; }
    virtual void setToCheckBlockUpgradeMajority(int anToCheckBlockUpgradeMajority) { nToCheckBlockUpgradeMajority = anToCheckBlockUpgradeMajority; }
    virtual void setDefaultConsistencyChecks(bool afDefaultConsistencyChecks) { fDefaultConsistencyChecks = afDefaultConsistencyChecks; }
    virtual void setAllowMinDifficultyBlocks(bool afAllowMinDifficultyBlocks) { fAllowMinDifficultyBlocks = afAllowMinDifficultyBlocks; }
    virtual void setSkipProofOfWorkCheck(bool afSkipProofOfWorkCheck) { fSkipProofOfWorkCheck = afSkipProofOfWorkCheck; }
};
static CUnitTestParams unitTestParams;


static CChainParams* pCurrentParams = 0;

CModifiableParams* ModifiableParams()
{
    assert(pCurrentParams);
    assert(pCurrentParams == &unitTestParams);
    return (CModifiableParams*)&unitTestParams;
}

const CChainParams& Params()
{
    assert(pCurrentParams);
    return *pCurrentParams;
}

CChainParams& Params(CBaseChainParams::Network network)
{
    switch (network) {
    case CBaseChainParams::MAIN:
        return mainParams;
    case CBaseChainParams::TESTNET:
        return testNetParams;
    case CBaseChainParams::REGTEST:
        return regTestParams;
    case CBaseChainParams::UNITTEST:
        return unitTestParams;
    default:
        assert(false && "Unimplemented network");
        return mainParams;
    }
}

void SelectParams(CBaseChainParams::Network network)
{
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}

bool SelectParamsFromCommandLine()
{
    CBaseChainParams::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParams::MAX_NETWORK_TYPES)
        return false;

    SelectParams(network);
    return true;
}
