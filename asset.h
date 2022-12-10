#ifndef __ASSET__H__
#define __ASSET__H__

//brought over 
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>



typedef std::vector <std::string> varray;
typedef std::vector <float> farray;

typedef std::vector <farray> vmatrix;

//brought over from asset need to delete
typedef std::vector <std::string> varray;
typedef std::vector <float> farray;
typedef std::vector <farray> vmatrix;
//typedef std::vector <Asset *> aarray;

class Asset{
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
    Asset(std::string givenname, float return_rat, float stdev,int index,farray mycorrelation);
    ~Asset();
    std::string get_name();
    float get_std();
    float get_return();
    int get_id();
    float get_specfic_correlation(int id);

  
};
#endif

