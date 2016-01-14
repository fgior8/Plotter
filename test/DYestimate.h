#ifndef DYestimate_h
#define DYestimate_h

#include <vector>
#include <string>
#include <iostream>
using namespace std;

/// USAGE ///
/// dataIn, mcIn, and mcOut are the input vectors to be given to the function the ordering of the vector elements is crucial
/// dataIn containts the number of events inside the Z window in data for (IN ORDER) ee, mumu and emu channels
/// mcIn and mcOut contain, respectively, the events inside and outside the Z window, each element much be:
///// [0] ee channel (weighted events)
///// [1] mmu channel (weighted events)
///// [2] ee channel (number of MC entries to calculate error)
///// [3] mumu channel (number of MC entries to calculate error)

void  DYestimate(vector<float> &dataIn, vector<float> &mcIn, vector<float> &mcOut, vector<float> &result);

#endif
 
/// result is read as [SF_in_ee, err_SF_in_ee, SF_in_mumu, err_SF_in_mumu]
/// if needed contact Ferdinando.Giordano@cern.ch

