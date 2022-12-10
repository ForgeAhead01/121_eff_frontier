#ifndef __PARSE__H__
#define __PARSE__H__
#include "asset.h"

#include <math.h> 

//brought over from asset calss
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

float num_checker(std::string subject);
void print_matrix(vmatrix paint);
void cell_check(vmatrix return_rates);

typedef std::vector <Asset *> aarray;

farray corre_parser(std::string corremax, int row_num, int prev_length);
//aarray asset_population (varray column, vmatrix return_rates);
aarray populator (std::string universe_addr, std::string corre_addr);
#include "parse.h"
#include "asset.h"

//does not catch if correlation matrix has more rows than assets!!! beware
//test cases: universe has null; universe has too many numbers on one row; could not locate file; univ and correlation have different length/height; universe has null/bad data;universe has too many numbers on one row

aarray populator (std::string universe_addr, std::string corre_addr){
    std::ifstream universe (universe_addr.c_str());
    std::ifstream corremax (corre_addr.c_str());
    aarray assets;

    //test case: bad file name or no file
    if (!universe.good() || !corremax.good()){
        std::cerr<<"corrupt file name or could not locade file!";
        universe.close();
        corremax.close();
        exit(EXIT_FAILURE);        
        }
    else{

        std::string nextline;
        std::string line;
        int step;
        int row_num = 0;
        int prev_length = -1;

        //std::cout<<"nextline 1,0: "<<nextline<<"\n";

        while(universe.eof() == 0) {
            //std::getline(universe,nextline);
            std::getline(universe,nextline);

            //std::cout<<"nextline 2,0: "<<nextline<<"\n";


            std::stringstream ss (nextline);
            step = 0;
            std::string name;
            float return_rate;
            float std;

            //get the float array of correlation
            std::string corre_nextline;
            std::getline(corremax,corre_nextline);
            farray current_corre = corre_parser(corre_nextline,row_num,prev_length);
            size_t curr_corre_row_size = current_corre.size();

            //parse through the current line in universe, getting indivisual names and properties
            while(std::getline(ss,line,',')){
                //checks if result is null or some weird stuff. if so, exit; only activates after getting to the 2rd element
                step ++;

                if (step == 1){
                    name = line;

                }
                else{
                    float result = num_checker(line);
                    if (!isnormal(result)){
                        std::cerr<<"corrupted universe file information!"<<std::endl;
                        exit(EXIT_FAILURE);
                    }
                    if (step == 2){
                        return_rate = result;
                    }
                    else if (step == 3){
                        std = result;
                    }
                    else{
                        std::cerr<<"Too many data in a single line!"<<std::endl;
                        exit(EXIT_FAILURE);
                    }
                }
        }
        // std::cout<<"name: "<<name<<',';
        // std::cout<<"return rate: "<<return_rate<<',';
        // std::cout<<" std: "<<std<<',';
        // std::cout<<" row_num: "<<row_num<<'\n';


        //populating new assets, adding them to an array called assets
        Asset *indv_asset = new Asset(name,return_rate,std,row_num,current_corre);
        //std::cout<<"name: "<<indv_asset->get_name()<<"\n";
        assets.push_back(indv_asset);
        //std::cout<<"assets size: "<<assets.size<<"\n";



        prev_length = curr_corre_row_size;
        //std::getline(universe,nextline);
        //std::cout<<"nextline 3,0: "<<nextline<<"\n";
        row_num++;


        }
        row_num--;
        corremax.clear();
        corremax.seekg(0,corremax.beg);
        std::getline(corremax,nextline);
        size_t corre_row_count = 0;
        while (corremax >> nextline){
            corre_row_count++;
            std::getline(corremax,nextline);
        }
        if (row_num+1 != prev_length || row_num != (int)corre_row_count){
            std::cout<<"row_num: "<<row_num<<", prev_length: "<<prev_length<<"\n";

            std::cerr<<"universe and correlation doesn't match up in row length and column length!"<<std::endl;
            exit(EXIT_FAILURE);
        }



        // cell_check(return_rates);
        universe.close();
        corremax.close();
        //print_matrix(return_rates);
        // aarray all_assets = asset_population(column,return_rates);
        // return all_assets;
        
}
return assets;

}

farray corre_parser(std::string currentline,int row_num, int prev_length){
    std::string correline;
    //going through the rows
    farray corarray;
    std::stringstream strs (currentline);

    //start looping throuhgh to get the float array
    while(std::getline(strs,correline,',')){
        float result = num_checker(correline);
        //std::cout<<correline<<",";

        if (!isnormal(result)){
            std::cerr<<"corrupted correlation file information!"<<std::endl;
            exit(EXIT_FAILURE);
        }
        else if (result > 1.00 || result < -1.00){
            std::cerr<<"correlation is greater than 1 or less than -1!"<<std::endl;
            exit(EXIT_FAILURE);
        }
        corarray.push_back(result);

    }
    size_t corre_size = corarray.size();

    //error checking
    //std::cout<<"row_num: "<<row_num<<", corre_size: "<<corre_size<<"\n";

    if (row_num < (int)corre_size){
        if (corarray[row_num] != 1.0000){
            std::cerr<<"corrupted correlation file information! correlation with self not equal to 1!!!"<<std::endl;
            exit(EXIT_FAILURE);
        }
    }
    else{
            // for (int i = 0;i < corre_size; i++)
            //     {
            //         std::cout<<corarray[i]<<",";
            //     }
            std::cerr<<"corrupted correlation file information! Correlation matrix out of bonds!!!"<<std::endl;
            exit(EXIT_FAILURE);
    }
    if (prev_length != -1 && (int)corre_size != prev_length){
        std::cerr<<"Correlation maxtrix row length not consistent!!!"<<std::endl;
        exit(EXIT_FAILURE);
    }

    return corarray;
}


// void cell_check(vmatrix return_rates){
//         size_t table_height = return_rates.size();
//         size_t column_width = return_rates[table_height - 1].size();
//         for (long unsigned int i = 0; i < column_width; i++){
//             //at the bottom of the return rates table, there should not be any empty values
//             //every emppty / weird value above shoudl be replaced by some valid numbers
//             //the fact that a bottom cell is empty means every cell above it is, too
//             if (return_rates[table_height-1][i] == 0){
//                 std::cerr<<"There was a column of prices entirely made of null or blanks"<<std::endl;
//                 exit(EXIT_FAILURE);
//             }


//         }
    
// }

// void print_matrix(vmatrix paint){
//         for (long unsigned int i = 0; i < paint.size(); i++){

//         for (long unsigned int j = 0; j < paint[i].size(); j++){
//             std::cout << paint[i][j] << ',';
//         }
//         std::cout << '\n';
// }
// }
float num_checker(std::string subject){
    float result;
    std::stringstream test (subject);
    test>>result;
    test.clear();
    //check for whether the price string is equal to null or empty. Either case will result in 0
    if (!test.good() || subject.length() == 0){
        std::cout << "the result was bad: " << subject;
        std::cerr<<"corrupted file information!"<<std::endl;
        exit(EXIT_FAILURE);
        return 0.000;
    }
    else{
        //std::cout << "the result was good: " << subject;
        return result;
    }

 }

// aarray asset_population (varray column, vmatrix return_rates){
//     aarray assets;
//     float total = 0;
//     float average = 0;
//     farray returns (return_rates.size());
//     std::string time_unit = *(column.begin());
//     column.erase(column.begin());

//     for (size_t i = 0; i < column.size();i++){
//         for (size_t j = 0;j < return_rates.size();j++){
//             returns[j] = return_rates[j][i-1];
//             total += return_rates[j][i-1];
//         }
//         average = total / return_rates.size();
//         Asset *new_asset = new Asset(column[i],returns,average,time_unit);
//         assets.push_back(new_asset);
//         average = 0;
//         total = 0;
//     }
//     return assets;

// }

#endif

