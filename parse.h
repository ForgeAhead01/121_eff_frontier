#ifndef __PARSE__H__
#define __PARSE__H__
//#include "asset.h"

//#include "asset.h"
#include <math.h> 

//brought over from asset calss
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

//brought over from asset need to delete
typedef std::vector <std::string> varray;
typedef std::vector <float> farray;

typedef std::vector <farray> vmatrix;

float num_checker(std::string subject);
void print_matrix(vmatrix paint);
void cell_check(vmatrix return_rates);
//typedef std::vector <Asset *> aarray;

farray corre_parser(std::string corremax, int row_num, int prev_length);
//aarray asset_population (varray column, vmatrix return_rates);
int populator (std::string universe_addr, std::string corre_addr);

#endif

