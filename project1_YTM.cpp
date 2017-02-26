
#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;


// calculate bond price
double bond_price(double FV, double coupon, double ytm, int Num_coupon)
{
    double PV = 0.0;
    for (int i = 1; i <= Num_coupon; i++)
    {
        PV += coupon * FV / pow(1.0+ytm, i);
    }
    PV += FV / pow(1.0+ytm, Num_coupon);
    return PV;
}

// calculate the derivative of bond pricing function
double bond_price_prime(double FV, double coupon, double ytm, int Num_coupon)
{
    double PV_prime = 0.0;
    for (int i = 1; i <= Num_coupon; i++)
    {
        PV_prime += coupon * (-i) * FV / pow(1.0+ytm, i+1);
    }
    PV_prime += coupon * (-Num_coupon) * FV / pow(1.0+ytm, Num_coupon+1);
    return PV_prime;
}

// read price, coupon rate, starting year, endding year and compoundding frequency from screen
void read_num(double price, double coupon, int year_start, int year_end, int compound)
{
    
    cout << "Please enter the price of the bond: ";
	cin >> price;
    cout << "Please enter the coupon rate of the bond (in decimal): ";
    cin >> coupon;
    
    cout << "Please enter the starting year of the bond: ";
    cin >> year_start;
    cout << "Please enter the end year of the bond: ";
    cin >> year_end;

    cout << "What is the compounding frequency per annum? ";
    cin >> compound;
    
}

// function to calculate ytm using bisection method
void bisec(double price, double FV, double coupon, double tolerance, int compound, int Num_coupon, double &ytm)
{
    double a = 0.0;
    double b = 1.0;
    double c = 0.0;
    bool i = true;
    while (i)
    {
        double bond_a = bond_price(FV, coupon/compound, a/compound, Num_coupon) - price * FV / 100.0;
        double bond_b = bond_price(FV, coupon/compound, b/compound, Num_coupon) - price * FV / 100.0;
        if (abs(bond_a) <= tolerance)
        {
            ytm = a;
            i = false;
        }
        else if (abs(bond_b) <= tolerance)
        {
            ytm = b;
            i = false;
        }
        else if ((bond_a * bond_b) < 0.0)
        {
            c = (a + b) / 2.0;
            double bond_c = bond_price(FV, coupon/compound, c/compound, Num_coupon) - price * FV / 100.0;
            if (abs(bond_c) < tolerance)
            {
                ytm = c;
                i = false;
            }
            if ((bond_c * bond_b) < 0.0)
            {
                a = c;
            }
            else b = c;
        }
        else
        {
            cout << "Cannot find the YTM in this scenario. ";
            i = false;
        }
    }
}


