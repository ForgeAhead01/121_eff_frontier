#include <fstream>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <string>






int main(int argc, char ** argv){
    if (argc != 3 && argc != 4){
        std::cerr<<"Please enter a valid input! format: program_name -r(optional) universe_file_address correlation_file_address"<<std::endl;
        exit(EXIT_FAILURE);
    }
    else{
        std::string input = argv[1];
        //check if restricted mode is on; should return 1 if it is
        int restrict_check = 0;
        if (input.compare("-r") == 0){
            restrict_check = 1;
        };
        std::string universe_address = argv[1+restrict_check];
        std::string correlation_address = argv[2+restrict_check];
       

        //std::cout<<restrict_check<<'\n';
    
        exit(EXIT_SUCCESS);


        }





    }