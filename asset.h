#ifndef __ASSET__H__
#define __ASSET__H__

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>



typedef std::vector <std::string> varray;
typedef std::vector <float> farray;

typedef std::vector <farray> vmatrix;

class Asset{
  //State: name, time series rate of return, average return, and standard deviation. o 
  //Behavior: calculate the average return, standard deviation, covariance,correlation
  private:
    std::string name;
    farray rate_of_return;
    float average_return;
    float standard_deviation;
    std::string time_unit;

  public:
    Asset();
    Asset(std::string name,farray return_rate,float average,std::string time_unit);
    std::string get_name();
    float get_average();
    farray get_returns();
    void calculate_std();

    float get_std();
    float get_specfic_return(int height);
  
};
#endif