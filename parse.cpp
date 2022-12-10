
#include <math.h> 

aarray populator (std::string input){
    std::ifstream file (input.c_str());
    //test case: bad file name or no file
    if (!file.good()){
        std::cerr<<"corrupt file name or could not locade file!";
        exit(EXIT_FAILURE);        
        }
    else{
        varray varr;
        varray column;
        farray row;

        std::string nextline;
        std::string line;
        std::getline(file,nextline);
        std::stringstream ss (nextline);
        while(std::getline(ss,line,',')){
                column.push_back(line);
        }
        //size_t asset_count = column.size() - 1;
        //std::string time_unit = column[0];

        float result;
        vmatrix total_info;
        vmatrix return_rates;
        farray same_time_return;
        while(std::getline(file,nextline)){
            std::stringstream ss (nextline);
            while(std::getline(ss,line,',')){
                result = num_checker(line);
                if (!isnormal(result)){
                    result = 0.00;
                }
                row.push_back(result);
          
                //std::cout<<line<<',';
            }
            (total_info).push_back(row);
            int time_size = total_info.size();
            size_t column_size = row.size();
            if (time_size> 1){
                for (long unsigned int i = 1; i < column_size; i++){
                    float current_pos = total_info[time_size-1][i];
                    float prior_pos = total_info[time_size-2][i];
                    if (current_pos == 0 && prior_pos != 0){
                        //std::cout<<"got it!!\n";
                        current_pos = prior_pos;
                        total_info[time_size-1][i] = total_info[time_size-2][i];
                    }
                    float rate = (current_pos / prior_pos)-1;
                    same_time_return.push_back(rate);
                }
                return_rates.push_back(same_time_return);
                same_time_return.clear();
            }
            row.clear();
            //std::cout<<'\n';

        }

        cell_check(return_rates);
        file.close();
        //print_matrix(return_rates);
        aarray all_assets = asset_population(column,return_rates);
        return all_assets;
        }
}

void cell_check(vmatrix return_rates){
        size_t table_height = return_rates.size();
        size_t column_width = return_rates[table_height - 1].size();
        for (long unsigned int i = 0; i < column_width; i++){
            //at the bottom of the return rates table, there should not be any empty values
            //every emppty / weird value above shoudl be replaced by some valid numbers
            //the fact that a bottom cell is empty means every cell above it is, too
            if (return_rates[table_height-1][i] == 0){
                std::cerr<<"There was a column of prices entirely made of null or blanks"<<std::endl;
                exit(EXIT_FAILURE);
            }


        }
    
}

void print_matrix(vmatrix paint){
        for (long unsigned int i = 0; i < paint.size(); i++){

        for (long unsigned int j = 0; j < paint[i].size(); j++){
            std::cout << paint[i][j] << ',';
        }
        std::cout << '\n';
}
}
float num_checker(std::string subject){
    float result;
    std::stringstream test (subject);
    test>>result;
    test.clear();
    //check for whether the price string is equal to null or empty. Either case will result in 0
    if (!test.good() || subject.length() == 0){
        std::cout << "the result was bad: " << subject;
        return 0.000;
    }
    else{
        //std::cout << "the result was good: " << subject;
        return result;
    }


}

aarray asset_population (varray column, vmatrix return_rates){
    aarray assets;
    float total = 0;
    float average = 0;
    farray returns (return_rates.size());
    std::string time_unit = *(column.begin());
    column.erase(column.begin());

    for (size_t i = 0; i < column.size();i++){
        for (size_t j = 0;j < return_rates.size();j++){
            returns[j] = return_rates[j][i-1];
            total += return_rates[j][i-1];
        }
        average = total / return_rates.size();
        Asset *new_asset = new Asset(column[i],returns,average,time_unit);
        assets.push_back(new_asset);
        average = 0;
        total = 0;
    }
    return assets;

}
