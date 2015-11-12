#include <vector>

#include "SinglePlot.h"
#include "Single2dPlot.h"

void loadCFO(std::vector<TString>& filename, std::vector<TString>& legendname, std::vector<TString>& plotlabel, std::vector<int>& color, std::vector<int>& linecol, std::vector<std::string>& type, std::vector<SinglePlot>& hist1d, std::vector<Single2dPlot>& hist2d, std::vector<double>& weight, std::vector<bool>& legend) {

  const double luminosity = 1.0;
  //  const double luminosity = 0.004;

  const TString directory = "/Users/ferdi/cernbox/files/1/";
  std::vector<TString> classe;
  enum logbool {      nolog,         log };
  enum normbool {     nonorm,        norm };
  enum normfirstbool {nonormToFirst, normToFirst };
  enum stackbool {    nostack,       stack };
  enum overflowbool { nooverflow,    overflow };

  Bool_t ttbar=true; Bool_t ZDY_jets=true; Bool_t W_jets=true; Bool_t QCD=false;
  Bool_t tW = true; Bool_t ttW=true; Bool_t ttZ=true;
  Bool_t WW=true; Bool_t WZ=true; Bool_t ZZ=true;
  Bool_t T2tt_425LSP325=false; Bool_t T2tt_850LSP100=true;
  Bool_t data=true;
  Bool_t signal=true;
  TString cut [10] = {"particle", "twoLeptons", "twoJets", "MET", "oneBtag", "twoBtag", "Ctrl_Z", "Ctrl_noB", "Ctrl_ZornoB", "Ctrl_ZandnoB"};
  TString channel[5] = {"all", "sameF","ee", "mumu", "emu"};;
  
  if(signal) {
    for (UInt_t k=0;k<6;k++)
      for (UInt_t w=0;w<5;w++) {
      if (k>0) {
	hist1d.push_back( SinglePlot("h_MET_signal_"+cut[k]+"_"+channel[w], 2,  log, nonorm, nonormToFirst, 1.0, overflow, stack, "", "Missing Energy (GeV)","Events/10 GeV") );
	hist1d.push_back( SinglePlot("h_METexp_signal_"+cut[k]+"_"+channel[w], 1,  log, nonorm, nonormToFirst, 200.0, overflow, stack, "", "MET^{2}/HT#times exp[-MET/HT] (GeV)","Events/10 GeV") );
	hist1d.push_back( SinglePlot("h_MET2HT_signal_"+cut[k]+"_"+channel[w], 1,  log, nonorm, nonormToFirst, 300.0, overflow, stack, "", "MET^{2}/HT (GeV)","Events/10 GeV") );
	hist1d.push_back( SinglePlot("h_HT_signal_"+cut[k]+"_"+channel[w], 5,  log, nonorm, nonormToFirst, 3000.0, nooverflow, stack, "", "HT (GeV)","Events/10 GeV") );
	hist1d.push_back( SinglePlot("h_MET_phi_signal_"+cut[k]+"_"+channel[w], 1,  nolog, nonorm, nonormToFirst, 1.0, nooverflow, stack, "", "Missing Energy #phi","Events") );
	hist1d.push_back( SinglePlot("h_MT2ll_signal_"+cut[k]+"_"+channel[w], 1,  log, nonorm, nonormToFirst, 1.0, nooverflow, stack, "", "MT_{2}(ll) (GeV)","Events/10 GeV") );
	hist1d.push_back( SinglePlot("h_MT2bb_signal_"+cut[k]+"_"+channel[w], 1,  log, nonorm, nonormToFirst, 1.0, nooverflow, stack, "", "MT_{2}(bb) (GeV)","Events/10 GeV") );
	hist1d.push_back( SinglePlot("h_MT2lblb_signal_"+cut[k]+"_"+channel[w], 1,  log, nonorm, nonormToFirst, 1.0, nooverflow, stack, "", "MT_{2}(lblb) (GeV)","Events/10 GeV") );
	hist1d.push_back( SinglePlot("h_llmass_signal_"+cut[k]+"_"+channel[w], 1,  log, nonorm, nonormToFirst, 1.0, nooverflow, stack, "", "di-lepton invariant mass (GeV)","Events/10 GeV") );
	hist1d.push_back( SinglePlot("h_dijetsmass_signal_"+cut[k]+"_"+channel[w], 1,  log, nonorm, nonormToFirst, 1.0, nooverflow, stack, "", "di-jet invariant mass (GeV)","Events/10 GeV") );
	hist1d.push_back( SinglePlot("h_lljjmass_signal_"+cut[k]+"_"+channel[w], 1,  log, nonorm, nonormToFirst, 1.0, nooverflow, stack, "", "4 particles invariant mass (GeV)","Events/10 GeV") );
	hist1d.push_back( SinglePlot("h_PV_signal_"+cut[k]+"_"+channel[w], 1,  log, nonorm, nonormToFirst, 1.0, nooverflow, stack, "", "Number of Vertices","Events") );
	/*
	hist1d.push_back( SinglePlot("h_DeltaPhiZ_signal_"+cut[k]+"_"+channel[w], 1,  log, nonorm, nonormToFirst, 1.0, nooverflow, stack, "", "cos#phi Z MET","Events") );
	hist1d.push_back( SinglePlot("h_DeltaPhiLep1_signal_"+cut[k]+"_"+channel[w], 1,  log, nonorm, nonormToFirst, 1.0, nooverflow, stack, "", "cos#phi lep_1 MET","Events") );
	hist1d.push_back( SinglePlot("h_DeltaPhiLep2_signal_"+cut[k]+"_"+channel[w], 1,  log, nonorm, nonormToFirst, 1.0, nooverflow, stack, "", "cos#phi lep_2 MET","Events") );
	hist1d.push_back( SinglePlot("h_DeltaPhiJet1_signal_"+cut[k]+"_"+channel[w], 1,  log, nonorm, nonormToFirst, 1.0, nooverflow, stack, "", "cos#phi jet_1 MET","Events") );
	hist1d.push_back( SinglePlot("h_DeltaPhiJet2_signal_"+cut[k]+"_"+channel[w], 1,  log, nonorm, nonormToFirst, 1.0, nooverflow, stack, "", "cos#phi jet_2 MET","Events") );
	*/
	hist1d.push_back( SinglePlot("h_DeltaPhiJetMin_signal_"+cut[k]+"_"+channel[w], 1,  log, nonorm, nonormToFirst, 1.0, nooverflow, stack, "", "cos#phi min(jet_1,jet_2) MET","Events") );
      }
      if (((k==0 && w==0) || k>0)) {
	hist1d.push_back( SinglePlot("Muons/h_muons_"+cut[k]+"_"+channel[w]+"_N", 1,  log, nonorm, nonormToFirst, 1.0, nooverflow, stack, "", "Number of Muons","Events") );
	hist1d.push_back( SinglePlot("Muons/h_muons_"+cut[k]+"_"+channel[w]+"_pt", 1,  log, nonorm, nonormToFirst, 1.0, nooverflow, stack, "", "Muons p_{T}","Events/10 GeV") );
	hist1d.push_back( SinglePlot("Muons/h_muons_"+cut[k]+"_"+channel[w]+"_eta", 1,  nolog, nonorm, nonormToFirst, 1.0, nooverflow, stack, "", "Muons #eta","Events") );
	hist1d.push_back( SinglePlot("Muons/h_muons_"+cut[k]+"_"+channel[w]+"_phi", 1,  nolog, nonorm, nonormToFirst, 1.0, nooverflow, stack, "", "Muons #phi","Events") );
      
	hist1d.push_back( SinglePlot("Electrons/h_electrons_"+cut[k]+"_"+channel[w]+"_N", 1,  log, nonorm, nonormToFirst, 1.0, nooverflow, stack, "", "Number of Electrons","Events") );
	hist1d.push_back( SinglePlot("Electrons/h_electrons_"+cut[k]+"_"+channel[w]+"_pt", 1,  log, nonorm, nonormToFirst, 1.0, nooverflow, stack, "", "Electrons p_{T}","Events/10 GeV") );
	hist1d.push_back( SinglePlot("Electrons/h_electrons_"+cut[k]+"_"+channel[w]+"_eta", 1,  nolog, nonorm, nonormToFirst, 1.0, nooverflow, stack, "", "Electrons #eta","Events") );
	hist1d.push_back( SinglePlot("Electrons/h_electrons_"+cut[k]+"_"+channel[w]+"_phi", 1,  nolog, nonorm, nonormToFirst, 1.0, nooverflow, stack, "", "Electrons #phi","Events") );
      
	hist1d.push_back( SinglePlot("Jets/h_jets_"+cut[k]+"_"+channel[w]+"_N", 1,  log, nonorm, nonormToFirst, 1.0, nooverflow, stack, "", "Number of Jets","Events") );
	hist1d.push_back( SinglePlot("Jets/h_jets_"+cut[k]+"_"+channel[w]+"_pt", 1,  log, nonorm, nonormToFirst, 1.0, nooverflow, stack, "", "Jets p_{T}","Events/10 GeV") );
	hist1d.push_back( SinglePlot("Jets/h_jets_"+cut[k]+"_"+channel[w]+"_eta", 1,  nolog, nonorm, nonormToFirst, 1.0, nooverflow, stack, "", "Jets #eta","Events") );
	hist1d.push_back( SinglePlot("Jets/h_jets_"+cut[k]+"_"+channel[w]+"_phi", 1,  nolog, nonorm, nonormToFirst, 1.0, nooverflow, stack, "", "Jets #phi","Events") );
      
	hist1d.push_back( SinglePlot("Jets/h_bjets_"+cut[k]+"_"+channel[w]+"_N", 1,  log, nonorm, nonormToFirst, 1.0, nooverflow, stack, "", "Number of b Tag","Events") );
	hist1d.push_back( SinglePlot("Jets/h_bjets_"+cut[k]+"_"+channel[w]+"_pt", 1,  log, nonorm, nonormToFirst, 1.0, nooverflow, stack, "", "b jets p_{T}","Events/10 GeV") );
	hist1d.push_back( SinglePlot("Jets/h_bjets_"+cut[k]+"_"+channel[w]+"_eta", 1,  nolog, nonorm, nonormToFirst, 1.0, nooverflow, stack, "", "b jets #eta","Events") );
	hist1d.push_back( SinglePlot("Jets/h_bjets_"+cut[k]+"_"+channel[w]+"_phi", 1,  nolog, nonorm, nonormToFirst, 1.0, nooverflow, stack, "", "b jets #phi","Events") );
      }
    }
    // hist2d.push_back( Single2dPlot("h_leadingJetPtvsMassLog_control", "h_leadingJetPtvsMassLog_control", "COLZ", 1, 1) );
    //hist2d.push_back( Single2dPlot("h_leadingJetPtvsMassLog_smoothing", "h_leadingJetPtvsMassLog_smoothing", "COLZ", 1, 1) );
  }
  
  if (signal && ttZ) {
    filename.push_back(directory+"TTZ_1.root");
    legendname.push_back("t#bar{t}Z");
    plotlabel.push_back("t#bar{t}Z");
    color.push_back(kOrange); linecol.push_back(kBlack);
    legend.push_back(true);
    type.push_back("mc");
   // weight.push_back(0.70*1000./249275.);
    weight.push_back(luminosity);
  }
  
  if (signal && ttW) {
    filename.push_back(directory+"TTW_1.root");
    legendname.push_back("t#bar{t}W");
    plotlabel.push_back("t#bar{t}W");
    color.push_back(kOrange+7); linecol.push_back(kBlack);
    legend.push_back(true);
    type.push_back("mc");
    //weight.push_back(0.72*1000./246521.);
    weight.push_back(luminosity);
  }
    
  if (signal && ZZ) {
    filename.push_back(directory+"ZZ_1.root");
    legendname.push_back("ZZ");
    plotlabel.push_back("ZZ");
    color.push_back(kSpring+10); linecol.push_back(kBlack);
    legend.push_back(true);
    type.push_back("mc");
    //weight.push_back(2.2*1000./237484.);
    weight.push_back(luminosity);
  }
  
  if (signal && WZ) {
    filename.push_back(directory+"WZ_1.root");
    //filename.push_back(directory+"WZTo3LNu_14.root");
    legendname.push_back("WZ");
    plotlabel.push_back("WZ");
    color.push_back(kSpring); linecol.push_back(kBlack);
    legend.push_back(true);
    type.push_back("mc");
    //weight.push_back(2.2*1000./237484.);
    weight.push_back(luminosity);
  }
  
  if (signal && WW) {
    filename.push_back(directory+"WW_1.root");
    //filename.push_back(directory+"WWTo2L2Nu_Powheg_14.root");
    legendname.push_back("WW");
    plotlabel.push_back("WW");
    color.push_back(kGreen-7); linecol.push_back(kBlack);
    legend.push_back(true);
    type.push_back("mc");
    //weight.push_back(12.5*1000./899900.);
    weight.push_back(luminosity);
  }
  
  if (signal && tW) {
    filename.push_back(directory+"TW_1.root");
    legendname.push_back("tW");
    plotlabel.push_back("tW");
    color.push_back(kPink-9); linecol.push_back(kBlack);
    legend.push_back(true);
    type.push_back("mc");
    //weight.push_back(0.03610181523);
    weight.push_back(luminosity);
  }

  if (signal && tW) {
    filename.push_back(directory+"TbarW_1.root");
    legendname.push_back("#bar{t}W");
    plotlabel.push_back("#bar{t}W");
    color.push_back(kPink-9); linecol.push_back(kBlack);
    legend.push_back(false);
    type.push_back("mc");
    //weight.push_back(0.03663305207);
    weight.push_back(luminosity);
  }
  
  if (signal && ttbar) {
    filename.push_back(directory+"TTJets_1.root");
    //filename.push_back(directory+"TTLep_pow_1.root ");
    legendname.push_back("t#bar{t}");
    plotlabel.push_back("t#bar{t}");
    color.push_back(kRed); linecol.push_back(kBlack);
    legend.push_back(true);
    type.push_back("mc");
    //weight.push_back(0.03269);
    weight.push_back(luminosity);
  }
  
  if (signal && ZDY_jets) {
    filename.push_back(directory+"ZDYJets_1.root");
    //filename.push_back(directory+"ZJets_Madgraph_14.root ");
    legendname.push_back("Zjets");
    plotlabel.push_back("Zjets");
    color.push_back(kYellow); linecol.push_back(kBlack);
    legend.push_back(true);
    type.push_back("mc");
    //weight.push_back(2.129675056);
    weight.push_back(luminosity);
  }
  
  if (signal && W_jets) {
    filename.push_back(directory+"WJetsToLNu_1.root");
    //filename.push_back(directory+"WJets_Madgraph_14.root");
    legendname.push_back("Wjets");
    plotlabel.push_back("Wjets");
    color.push_back(kGreen); linecol.push_back(kBlack);
    legend.push_back(true);
    type.push_back("mc");
    //weight.push_back(6.141944936);
    weight.push_back(luminosity);
  }
  
  
  if (signal && QCD) {
    filename.push_back(directory+"QCD_MuEnrichedPt15_14.root");
    legendname.push_back("QCD");
    plotlabel.push_back("QCD");
    color.push_back(kOrange); linecol.push_back(kBlack);
    legend.push_back(true);
    type.push_back("mc");
    //weight.push_back(0.3965);
    weight.push_back(luminosity);
  }

  if (signal && T2tt_425LSP325) {
    filename.push_back(directory+"T2tt_425LSP325_14.root");
    legendname.push_back("T2tt_425LSP325");
    plotlabel.push_back("T2tt_425LSP325");
    color.push_back(kMagenta); linecol.push_back(kMagenta);
    legend.push_back(true);
    type.push_back("signal");
    weight.push_back(luminosity);
  }

  if (signal && T2tt_850LSP100) {
        filename.push_back(directory+"T2tt_850_100_1.root");
        legendname.push_back("T2tt_850LSP100");
        plotlabel.push_back("T2tt_850LSP100");
        color.push_back(kMagenta); linecol.push_back(kMagenta);
        legend.push_back(true);
        type.push_back("signal");
        weight.push_back(luminosity*100);
    }
  
  if (signal && data) {
    filename.push_back(directory+"Data_1.root");
    legendname.push_back("Data");
    plotlabel.push_back("Data");
    color.push_back(kBlack); linecol.push_back(kBlack);
    legend.push_back(true);
    type.push_back("data");
    weight.push_back(1.0);
  }

  /////////////////////
  //   Formatting    //
  /////////////////////

  // SinglePlot(std::string name, unsigned int rebin, bool log, bool normalize, bool normToFirst, double scaleXmax,
  //            bool overflowbin, bool stacked, TString title)

  // Single2dPlot(std::string name, std::string title, std::string drawOption, unsigned int rebinX, unsigned int rebinY)

} 

