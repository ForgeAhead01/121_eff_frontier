
#include "asset.h"
#include "parse.h"
#include <cmath>

class Asset{
        private:
        std::string name;
        float return_rate;
        float standard_deviation;
        int id;
        farray correlation;

public:
Asset::Asset(std::string givenname, float return_rat, float stdev,int index,farray mycorrelation){
        name = givenname;
        return_rate = return_rat;
        standard_deviation = stdev;
        id = id;
        correlation = mycorrelation;


}

~Asset(){

}

std::string Asset::get_name(){
        //std::cout<<name;
        return name;
}
float Asset::get_return(){
       return return_rate;
}

int Asset::get_id(){
        return id;
}
float Asset::get_std(){
        return standard_deviation;
}
float Asset::get_specfic_correlation(int index){
        return correlation[index];

}

}; 
