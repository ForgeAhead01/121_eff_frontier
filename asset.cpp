
#include "asset.h"
#include "parse.h"
#include <cmath>


Asset::Asset(std::string givenname, float return_rates, float average,std::string time_u):name(givenname),rate_of_return(return_rates),average_return(0.0),standard_deviation(0.0),time_unit(time_u){
}
std::string Asset::get_name(){
        //std::cout<<name;
        return name;
}
float Asset::get_average(){
       return average_return;
}
farray Asset::get_returns(){
       return rate_of_return;
}


void Asset::calculate_std(){
        float var = 0;
        for (int long unsigned i = 0; i < rate_of_return.size();i++){
                var += rate_of_return[i];
                var -= average_return;
                var = var * var;
        }
        float total_variance = var / ((rate_of_return.size()-1));
        standard_deviation = std::sqrt(total_variance);

}
float Asset::get_std(){
        return standard_deviation;
}
float Asset::get_specfic_return(int height){
        return rate_of_return[height];

}



