#ifndef __PORTFOLIO__H__
#define __PORTFOLIO__H__

//brought over 
#include <cstdlib>

#include <string>
#include "asset.h"
#include "parse.h"




class Portfolio{
  //State: name, time series rate of return, average return, and standard deviation. o 
  //Behavior: calculate the average return, standard deviation, covariance,correlation
  private:
    std::string name;
    float return_rate;
    float standard_deviation;
    int id;
    farray correlation;


  public:
    Asset();
    Asset(std::string name,float return_rate,float std,int id,farray correlation);
    std::string get_name();
    float get_std();
    float get_return();
    int get_id();
    float get_specfic_correlation(int id);

  
};
#endif

