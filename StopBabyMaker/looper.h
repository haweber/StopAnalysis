#include "EventTree.h"
#include "GenParticleTree.h"
#include "LeptonTree.h"
#include "PhotonTree.h"
#include "JetTree.h"
#include "TauTree.h"
#include "IsoTracksTree.h"
#include "TFile.h"
#include "TTree.h"
#include "TRandom.h"
#include "TF1.h"
#include "TH1F.h"
#include "TH1D.h"
#include "TH2F.h"
#include "TH3D.h"
#include "Math/VectorUtil.h"
#include "TChain.h"
#include "Math/LorentzVector.h"

// typedefs
typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > LorentzVector;

#ifndef LOOPER_H
#define LOOPER_H

#pragma GCC diagnostic ignored "-Wwrite-strings"

using namespace std;

class babyMaker {

  public:
    // Constructor/destructor
    babyMaker ();
    babyMaker (const std::string &prefix);
    virtual ~babyMaker (){ delete BabyFile; }

    void MakeBabyNtuple(const char* output_name);
    void InitBabyNtuple();
    int looper(TChain* chain, char* output_name, int nEvents = -1, char* path = "./");
    char* babypath;
    
    // Variables for baby skim
    int skim_nvtx;
    float skim_met;

    int   skim_nGoodLep;
    float skim_goodLep_el_pt;
    float skim_goodLep_el_eta;
    float skim_goodLep_mu_pt;
    float skim_goodLep_mu_eta;
  
    float skim_looseLep_el_pt;
    float skim_looseLep_el_eta;
    float skim_looseLep_mu_pt;
    float skim_looseLep_mu_eta;
    
    float skim_vetoLep_el_pt;
    float skim_vetoLep_el_eta;
    float skim_vetoLep_mu_pt;
    float skim_vetoLep_mu_eta;
  
    int   skim_nJets;
    float skim_jet_pt;
    float skim_jet_eta;

    float skim_jet_ak8_pt;
    float skim_jet_ak8_eta;

    int   skim_nPhotons;
    float skim_ph_pt;
    float skim_ph_eta;

    bool applyJECfromFile;
    int JES_type;

    int skim_nBJets;
    bool skim_2ndlepveto;

    bool skim_applyBtagSFs;
    bool skim_applyLeptonSFs; 
    bool skim_isFastsim;

    void setSkimVariables(int nvtx, float met, int nGoodLep, float goodLep_el_pt, float goodLep_el_eta, float goodLep_mu_pt, float goodLep_mu_eta, float looseLep_el_pt, float looseLep_el_eta, float looseLep_mu_pt, float looseLep_mu_eta, float vetoLep_el_pt, float vetoLep_el_eta, float vetoLep_mu_pt, float vetoLep_mu_eta, bool apply2ndlepveto, int njets, float jet_pt, float jet_eta, float jet_ak8_pt, float jet_ak8_eta, int nbjets, int nphs, float phs_pt, float phs_eta, bool applyJEC, int JES_type_central_up_down, bool applyLeptonSFs ,bool applyBtagSFs, bool isFastsim);


  protected:
    TFile* BabyFile;
    TFile* histFile;
    TTree* BabyTree;
    TH1D*  histcounter;
  private:

    // Tree Branches
    EventTree StopEvt;
    LeptonTree lep1;
    LeptonTree lep2;
    PhotonTree ph;
    JetTree jets;
    TauTree Taus;
    IsoTracksTree Tracks;  
    //GenParticleTree gen_els;
    //GenParticleTree gen_mus;
    //GenParticleTree gen_taus;
    GenParticleTree gen_leps;
    GenParticleTree gen_nus;
    //GenParticleTree gen_nuels;
    //GenParticleTree gen_numus;
    //GenParticleTree gen_nutaus;
    GenParticleTree gen_tops;
    //GenParticleTree gen_bs;
    //GenParticleTree gen_cs;
    GenParticleTree gen_qs;
    //GenParticleTree gen_glus;
    GenParticleTree gen_bosons;
    //GenParticleTree gen_ws;
    //GenParticleTree gen_zs;
    //GenParticleTree gen_phs;
    //GenParticleTree gen_hs;
    GenParticleTree gen_susy;
    
  // for btag SFs
  BTagCalibration* calib;
  BTagCalibrationReader* reader_heavy;
  BTagCalibrationReader* reader_heavy_UP;
  BTagCalibrationReader* reader_heavy_DN;
  BTagCalibrationReader* reader_light;
  BTagCalibrationReader* reader_light_UP;
  BTagCalibrationReader* reader_light_DN;

  TH2D* h_btag_eff_b;
  TH2D* h_btag_eff_c;
  TH2D* h_btag_eff_udsg;
  
  BTagCalibration* calib_fastsim;
  BTagCalibrationReader* reader_fastsim;
  BTagCalibrationReader* reader_fastsim_UP;
  BTagCalibrationReader* reader_fastsim_DN;

  TH2D* h_btag_eff_b_fastsim;
  TH2D* h_btag_eff_c_fastsim;
  TH2D* h_btag_eff_udsg_fastsim;
  
};

struct val_err_t { float value; float error; };

#endif
