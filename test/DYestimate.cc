#include "DYestimate.h"


void DYestimate(vector<float> &dataIn, vector<float> &mcIn, vector<float> &mcOut, vector<float> &result){
  
  result.clear();
 
  float DYMC_in_ee  = mcIn[0];
  float DYMC_out_ee = mcOut[0];
    
  float DYMC_in_mumu  = mcIn[1];
  float DYMC_out_mumu = mcOut[1];
    
  float Entries_DYMC_in_ee  = mcIn[2];
  float Entries_DYMC_out_ee = mcIn[2];
    
  float Entries_DYMC_in_mumu  = mcIn[3];
  float Entries_DYMC_out_mumu = mcIn[3];
 
  float EvData_in_ee = dataIn[0];
  float EvData_in_mumu = dataIn[1];
  float EvData_in_mue = dataIn[2];

    
  // R 
  float R_ee = DYMC_out_ee / DYMC_in_ee;
  float R_mumu = DYMC_out_mumu / DYMC_in_mumu;


 // cout << "R = " << R << " = " << DYMC_out << "/" << DYMC_in << endl;
  
  // k
  float k_mumu = 0.5 * sqrt((double)EvData_in_mumu/(double)EvData_in_ee);
  float k_ee = 0.5 * sqrt((double)EvData_in_ee/(double)EvData_in_mumu);
  
 // cout << "k = " << k << endl;

  // Calculated event yields and Scale Factors
  float NDY_DD_ee   = R_ee   * (EvData_in_ee - k_ee*EvData_in_mue);
  float NDY_DD_mumu = R_mumu * (EvData_in_mumu - k_mumu*EvData_in_mue);
  
  float SF_in_ee =  (EvData_in_ee - k_ee*EvData_in_mue) / DYMC_in_ee;
  float SF_in_mumu =  (EvData_in_mumu - k_mumu*EvData_in_mue) / DYMC_in_mumu;

//  cout << "EvData_in=" << EvData_in << " k=" << k << " EvData_in_mue=" << EvData_in_mue <<endl;

  ///////////// evaluate uncertainties /////////////

 // cout << "Entries_DYMC_out = " << Entries_DYMC_out << endl;

  float err_DYMC_in_ee  = sqrt(Entries_DYMC_in_ee)  * (DYMC_in_ee  / Entries_DYMC_in_ee);
  float err_DYMC_out_ee = sqrt(Entries_DYMC_out_ee) * (DYMC_out_ee / Entries_DYMC_out_ee);
    
  float err_DYMC_in_mumu  = sqrt(Entries_DYMC_in_mumu)  * (DYMC_in_mumu  / Entries_DYMC_in_mumu);
  float err_DYMC_out_mumu = sqrt(Entries_DYMC_out_mumu) * (DYMC_out_mumu / Entries_DYMC_out_mumu);

  float err_R2_ee = R_ee*R_ee * ( (err_DYMC_out_ee/DYMC_out_ee)*(err_DYMC_out_ee/DYMC_out_ee) +
                                 (err_DYMC_in_ee/DYMC_in_ee)  *(err_DYMC_in_ee/DYMC_in_ee) );
  float err_R2_mumu = R_mumu*R_mumu * ( (err_DYMC_out_mumu/DYMC_out_mumu)*(err_DYMC_out_mumu/DYMC_out_mumu) +
                                 (err_DYMC_in_mumu/DYMC_in_mumu)  *(err_DYMC_in_mumu/DYMC_in_mumu) );

  float err_k2_mumu = 0.25 * ( (1./(4.*EvData_in_ee)) + (EvData_in_mumu/(4.*EvData_in_ee*EvData_in_ee)) );
  float err_k2_ee   = 0.25 * ( (1./(4.*EvData_in_mumu)) + (EvData_in_ee/(4.*EvData_in_mumu*EvData_in_mumu)) );

  float err_tmp_ee   = sqrt(EvData_in_ee)   + k_ee*sqrt(EvData_in_mue) + EvData_in_mue*sqrt(err_k2_ee);
  float err_tmp_mumu = sqrt(EvData_in_mumu) + k_mumu*sqrt(EvData_in_mue) + EvData_in_mue*sqrt(err_k2_mumu);

  float err_DY_DD2_ee   = pow(NDY_DD_ee,2)   * ( (err_R2_ee/pow(R_ee,2)) +  (pow(err_tmp_ee,2)*pow(R_ee,2)/pow(NDY_DD_ee,2)) );
  float err_DY_DD2_mumu = pow(NDY_DD_mumu,2) * ( (err_R2_mumu/pow(R_mumu,2)) +  (pow(err_tmp_mumu,2)*pow(R_mumu,2)/pow(NDY_DD_mumu,2)) );

  float err_R_ee     = sqrt(err_R2_ee);
  float err_R_mumu   = sqrt(err_R2_mumu);

  float err_DY_DD_ee   = sqrt(err_DY_DD2_ee);
  float err_DY_DD_mumu = sqrt(err_DY_DD2_mumu);


//  cout << "SF_in = " << SF_in << endl;

  float err_SF_in_ee   = sqrt ( pow(err_tmp_ee / (EvData_in_ee - k_ee*EvData_in_mue), 2) + pow( sqrt(Entries_DYMC_in_ee)/Entries_DYMC_in_ee, 2) ) * SF_in_ee;
  float err_SF_in_mumu = sqrt ( pow(err_tmp_mumu / (EvData_in_mumu - k_mumu*EvData_in_mue), 2) + pow( sqrt(Entries_DYMC_in_mumu)/Entries_DYMC_in_mumu, 2) ) * SF_in_mumu;

    
 // cout << "err_SF_in = " << err_SF_in << endl;

  // Output
  cout << "--------------------------------"  << endl;
  cout << " SF_in_ee :  "   << SF_in_ee     << " +- " << err_SF_in_ee << endl;
  cout << " SF_in_mumu :  " << SF_in_mumu   << " +- " << err_SF_in_mumu    << endl;
  cout << "-------------------------------" << endl;

  result.push_back(SF_in_ee); // [0]
  result.push_back(err_SF_in_ee); // [1]
  result.push_back(SF_in_mumu); // [2]
  result.push_back(err_SF_in_mumu); // [3]

}
