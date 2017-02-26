

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>

#include "project2_TermStructure.h"
#include "prject2_Bond.h"
#include "project1_YTM.h"

using namespace std;

int main() {
    string command;
	//settings for the first problem
	double FV = 1000.0;
    double coupon = 0;
    double price = 0;
    int Num_coupon = 0;
    int year_start = 0;
    int year_end = 0;
    int compound = 0;
    double tolerance  = 1.0e-6;
    double ytm = 0.0;
    
    
    
		//First task: Extract YTM
            read_num(price, coupon, year_start, year_end, compound);
            Num_coupon = (year_end - year_start) * compound;
            // using bisection method to calculate the YTM
            bisec(price, FV, coupon, tolerance, compound, Num_coupon, ytm);
            ytm *= 100.0;
            cout << "Using bisection method, YTM = " << ytm << "%" << endl;
     
        
 
    return 0;
}
