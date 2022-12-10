#ifndef __ASSET__H__
#define __ASSET__H__

//brought over 
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>
#include "asset.h"
#include "parse.h"
#include <cmath>


typedef std::vector <std::string> varray;
typedef std::vector <float> farray;

typedef std::vector <farray> vmatrix;

//brought over from asset need to delete
typedef std::vector <std::string> varray;
typedef std::vector <float> farray;
typedef std::vector <farray> vmatrix;
//typedef std::vector <Asset *> aarray;




class Asset{
        private:
        std::string name;
        float return_rate;
        float standard_deviation;
        int id;
        farray correlation;

public:
Asset(std::string givenname, float return_rat, float stdev,int index,farray mycorrelation){
        name = givenname;
        return_rate = return_rat;
        standard_deviation = stdev;
        id = index;
        correlation = mycorrelation;


}

~Asset(){
// for (int i = 0;i < correlation.size();i++){
//     //delete correlation[i];
// }
}

std::string get_name(){
        //std::cout<<name;
        return name;
}
float get_return(){
       return return_rate;
}

int get_id(){
        return id;
}
float get_std(){
        return standard_deviation;
}
float get_specfic_correlation(int index){
        return correlation[index];

}
float get_covariance(int index,float oppo_std){
        float corr = correlation[index];
        float cov = get_std() * oppo_std * corr;
        return cov;


}
}; 

#endif

