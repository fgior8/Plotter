#include "TFile.h"
#include "TH1F.h"
#include "TTree.h"
#include "TKey.h"
//#include "Riostream.h"

#include "DYestimate.h"

  const TString directory = "/Users/ferdi/cernbox/files/4/";

void normZ() {
  //gROOT->ProcessLine(".L DYestimate.cc+g");

  TFile *file[3];
  TFile *file[0] = TFile::Open(directory+"Data_4.root");
  TFile *file[1] = TFile::Open(directory+"Tot_MC_4.root");
  TFile *file[2] = TFile::Open(directory+"ZDYJets_4.root");

  TString channel_name[] = {"ee", "mumu", "emu"};
  TString cut_name[] = {"twoLeptons", "twoJets", "MET", "oneBtag", "twoBtag"};
  TH1F *data_in[3][5], *MC_in[3][5], *ZDY_in[3][5];
  TH1F *data_out[3][5], *MC_out[3][5], *ZDY_out[3][5];
  /*
  TH1F *data_in_mumu, *MC_in_mumu, *ZDY_in_mumu;
  TH1F *data_out_mumu, *MC_out_mumu, *ZDY_out_mumu;
  TH1F *data_in_emu, *MC_in_emu, *ZDY_in_emu;
  TH1F *data_out_emu, *MC_out_emu, *ZDY_out_emu;
  */

  for(UInt_t i=0;i<3;i++) 
    for(UInt_t j=0;j<5;j++) {
      data_in[i][j]=(TH1F*)file[0]->Get( "ZDY/h_ZDY_"+cut_name[j]+"_"+channel_name[i]+"_DY_in" );
      data_out[i][j]=(TH1F*)file[0]->Get( "ZDY/h_ZDY_"+cut_name[j]+"_"+channel_name[i]+"_DY_out" );

      MC_in[i][j]=(TH1F*)file[1]->Get( "ZDY/h_ZDY_"+cut_name[j]+"_"+channel_name[i]+"_DY_in" );
      MC_out[i][j]=(TH1F*)file[1]->Get( "ZDY/h_ZDY_"+cut_name[j]+"_"+channel_name[i]+"_DY_out" );
    
      ZDY_in[i][j]=(TH1F*)file[2]->Get( "ZDY/h_ZDY_"+cut_name[j]+"_"+channel_name[i]+"_DY_in" );
      ZDY_out[i][j]=(TH1F*)file[2]->Get( "ZDY/h_ZDY_"+cut_name[j]+"_"+channel_name[i]+"_DY_out" );
    }

  vector<float> dataIn;
  vector<float> mcIn;
  vector<float> mcOut;
  vector<float> result;
  for(UInt_t j=0;j<5;j++) {
    for(UInt_t i=0;i<3;i++)
      dataIn.push_back(data_in[i][j]->Integral());
    for(UInt_t i=0;i<2;i++) {
      mcIn.push_back(ZDY_in[i][j]->Integral());
      mcOut.push_back(ZDY_out[i][j]->Integral());
    }
    for(UInt_t i=0;i<2;i++) {
      mcIn.push_back(ZDY_in[i][j]->GetEntries());
      mcOut.push_back(ZDY_out[i][j]->GetEntries());  
    }
    cout << "CUT: " << cut_name[j] << endl;
    DYestimate(dataIn, mcIn, mcOut, result);
      cout << " SF_in_mumu " << result[2] << endl;
    dataIn.clear();
    mcIn.clear();
    mcOut.clear();
    result.clear();
  }
    
}
