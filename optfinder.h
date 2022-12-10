 #include "./Eigen/Eigen/Dense"
#include "asset.h"
#include "parse.h"

#include "portfolio.h"




int matrix_transformer (aarray assets, float required_return){
/**
 * takes in the assets, required rate of return, and transpose them correctly into matrixes for calculation
 * 
 * 
**/
    int asset_num = (int)assets.size();
    Eigen::Matrix2Xf asset_returns (2,asset_num);
    for (int i = 0;i < asset_num;i++){
        asset_returns (0,i) = 1;
        asset_returns (1,i) = assets[i]->get_return();
    }
    Eigen::MatrixXf cov_matrix (asset_num,asset_num);
    for (int i = 0;i < asset_num;i++){
        for (int j = 0;j < asset_num;j++){
        cov_matrix (i,j) = assets[i]->get_covariance(j,assets[j]->get_std());
    }
    }

    //std::cout << "Here is the matrix asset_returns:\n" << cov_matrix << std::endl;






    return 0;
}