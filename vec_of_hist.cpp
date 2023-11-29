//root
#include "TROOT.h"
#include "TString.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TFile.h"
#include "TRandom3.h"
#include "TGraph.h"
#include "TStyle.h"
#include "TMath.h"
#include "TCanvas.h"
#include "TPad.h"

//C, C++
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>

using namespace std;

void fill_hist(TRandom3* rnd, TH1D *h1);

void fill_hist_v(TRandom3* rnd, const vector<TH1D*> &v_h1);
void fill_hist_v_not_ref(TRandom3* rnd, vector<TH1D*> v_h1);
void fill_hist_v_ref(TRandom3* rnd, vector<TH1D*> &v_h1);

int main(){
  //
  clock_t start, finish;
  //
  TRandom3* rnd = new TRandom3(123123);
  //
  Int_t nn = 2700000;
  //
  vector<TH1D*> v_h1;
  //  
  TString h1_name_title;
  start = clock();
  for(Int_t i = 0;i<nn;i++){
    h1_name_title = "h1_";
    h1_name_title += i;
    TH1D *h1 = new TH1D(h1_name_title.Data(),h1_name_title.Data(),1000,0.0,1.0);
    fill_hist(rnd, h1);
    v_h1.push_back(h1);
  }  
  //
  //cout<<v_h1.at(0)->GetEntries()<<endl;
  //fill_hist_v(rnd,v_h1);
  //fill_hist_v_not_ref(rnd,v_h1);
  //fill_hist_v_ref(rnd,v_h1);
  cout<<v_h1.at(0)->GetEntries()<<endl;
  //fill_hist_v(rnd,v_h1);
  //cout<<v_h1.at(0)->GetEntries()<<endl;
  //
  //v_h1.at(0)->SaveAs("v_h1_at.C");
  //
  finish = clock();
  cout<<" "<<((finish - start)/CLOCKS_PER_SEC)<<" (sec)"<<endl;
  return 0;  
}

void fill_hist(TRandom3* rnd, TH1D *h1){
  for(Int_t i = 0;i<100;i++)
    h1->Fill(rnd->Uniform());
}

void fill_hist_v(TRandom3* rnd, const vector<TH1D*> &v_h1){
  for(unsigned int j = 0; j < v_h1.size(); j++)
    for(Int_t i = 0;i<100;i++)
      v_h1.at(j)->Fill(rnd->Uniform());
}

void fill_hist_v_not_ref(TRandom3* rnd, vector<TH1D*> v_h1){
  for(unsigned int j = 0; j < v_h1.size(); j++)
    for(Int_t i = 0;i<100;i++)
      v_h1.at(j)->Fill(rnd->Uniform());
}

void fill_hist_v_ref(TRandom3* rnd, vector<TH1D*> &v_h1){
  for(unsigned int j = 0; j < v_h1.size(); j++)
    for(Int_t i = 0;i<100;i++)
      v_h1.at(j)->Fill(rnd->Uniform());
}
