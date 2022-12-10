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
    farray correlation;
    float average_return;
    float standard_deviation;
    int id;

  public:
    Asset();
    Asset(std::string name,float average,float std,int id,farray correlation);
    std::string get_name();
    farray get_correlation(int oppoid);
    float get_std();
    float get_average_return();

  
};
#endif