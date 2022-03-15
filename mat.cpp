#include "mat.hpp"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <sstream>

 using namespace std;
namespace ariel{
    string mat(int col, int row, char symb1, char symb2) {
        if(col < 0 || row < 0 ) {
            throw invalid_argument("The inputs are non positive, even or invalid");}
         if (col%2 == 0 || row%2 == 0 ){ 
               throw invalid_argument("even inputs invalid");  }
        if (symb1 < '!' || symb2 < '!' ) {
		throw invalid_argument("Invalid charcters -> OUT OF RANGE");}
		if( symb1 > '~' || symb2 > '~'){
			throw invalid_argument("Invalid charcters -> OUT OF RANGE");
		}

        string str;
		int temp = 0;
        vector <vector<string>> arr(row, vector<string>(col));
        char symbol =' ';
		
do{
			if(temp%2 == 0){
                symbol = symb1;
            }
			else{
				symbol = symb2;
				}
				      for(int i = temp; i<col-temp; i++){
                arr[temp][i] = symbol;
				arr[row-temp-1][i] = symbol;
            }
            temp++;
		}
        while(temp <= (row/2));
    
		temp = 0;
		
		do{
			if(temp%2 == 0){
                symbol = symb1;
            }
			else{
				symbol = symb2;
				}
			for(int j=temp; j<row-temp; j++){
                arr[j][temp] = symbol;
				arr[j][col-1-temp] = symbol;
            }
            temp++;
		}
        while(temp<=(col/2));

         

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
            str+=arr[i][j];
             }
         str+="\n";
         }
        return str;
      
	}
}