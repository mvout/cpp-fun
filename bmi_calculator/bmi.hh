
/*
 * Define class Bmi.
 * Handles the class variable manipulation and
 * BMI related calculations.
*/

#ifndef BMI_H
#define BMI_H

#include <string>
#include <math.h>

using namespace std;

class Bmi
{
public:
    Bmi();
    void reset();
    void change_gender(int gender);
    void change_weight(int weight);
    void change_height(double height);
    void calculate_bmi();
    double get_bmi();
    void interpret();
    string get_interpretation();
    int get_gender();
    int get_weight();
    double get_height();

private:
    // Gender marked with int:
    // female = 0
    // male = 1
    int gender_ = 0;
    int weight_ = 0;
    double height_= 0.0;
    string interpretation_= "";
    double bmi_val_ = 0.0;
};

#endif // BMI_H
