//
//  Header.h
//  MF703Project1
//
//  Created by Yijie Ren on 10/2/15.
//  Copyright © 2015 Yijie Ren. All rights reserved.
//

#ifndef Header_h
#define Header_h
using namespace std;

void welcome(string &command);

double bond_price(double FV, double coupon, double ytm, int Num_coupon);

double bond_price_prime(double FV, double coupon, double ytm, int Num_coupon);

void read_num(double &price, double &coupon, int &year_start, int &year_end, int &compound);

void bisec(double price, double FV, double coupon, double tolerance, int compound, int Num_coupon, double &ytm);

void newton(double price, double FV, double coupon, double tolerance, int compound, int Num_coupon, double &ytm);





#endif /* problem1_h */
