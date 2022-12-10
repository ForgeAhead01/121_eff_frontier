#ifndef __PORTFOLIO__H__
#define __PORTFOLIO__H__

//brought over 
#include <cstdlib>

#include <string>
#include "asset.h"
#include "parse.h"




class Portfolio{
  //State: required rate of return, volatility (risk), list of assets, and their respective weight. 
  //Behavior: undecided
  private:
    float required_return;
    float volatility;
    aarray assets;
    farray weight;


  public:
    Portfolio();
    Portfolio(float _required_return,float _volatility,aarray _assets,farray _weight){
            required_return = _required_return;
            volatility = _volatility;
            assets = _assets;
            weight = _weight;
    }
    ~Portfolio(){

    }
    
    float get_return(){
      return required_return;
    }
    float get_volatility(){
      return volatility;
    }
    aarray get_assets(){
      return assets;
    }
    farray get_weight(){
      return weight;
    }

  
};
#endif

