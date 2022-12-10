
#include "asset.h"
#include "parse.h"
#include <cmath>


Asset::Asset(std::string givenname, float return_rate, float std,int id,farray correlation):name(givenname),return_rate(return_rate),standard_deviation(0.0),id(id),correlation(correlation){
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



