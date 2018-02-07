
/*
 * Methods for class Bmi.
*/

#include "bmi.hh"

using namespace std;

Bmi::Bmi():
    gender_(), weight_(),height_(),
    interpretation_(), bmi_val_() {

}

// Reset class variables.
void Bmi::reset() {
    gender_ = 0;
    weight_ = 0;
    height_= 0.0;
    interpretation_= "";
    bmi_val_ = 0.0;
}

// Change gender.
// Input: int
//              0 = female
//              1 = male
void Bmi::change_gender(int gender) {
    gender_ = gender;
}

// Return gender as int.
int Bmi::get_gender() {
    return gender_;
}

// Change weight.
// Input: weight as integer from QSlider.
void Bmi::change_weight(int weight) {
    weight_ = weight;
}

// Return weight as int.
int Bmi::get_weight() {
    return weight_;
}

// Change height.
// Divide by 100 to change from cm to m.
// Input: height as double from QSlider.
void Bmi::change_height(double height) {
    height_ = height / 100;
}

// Return height as double.
double Bmi::get_height(){
    return height_;
}

// Calculate BMI with following formula:
// BMI = weight(kg) / height²(m)
void Bmi::calculate_bmi() {
    bmi_val_ = weight_ / pow(height_,2);
}

// Return BMI as double.
double Bmi::get_bmi() {
    return bmi_val_;
}

// Interpret the BMI value with annotation depending
// on certain thresholds. The threshold and therefore
// annotation depends on the gender.
void Bmi::interpret() {
    // Female
    if (gender_ == 0) {
        if (bmi_val_ <= 19.1) {
            interpretation_ = "Underweight";
        }else if (bmi_val_ <= 25.8) {
            interpretation_ = "Normal";
        }else if (bmi_val_ <= 27.3) {
            interpretation_ = "Slight overweight";
        }else if (bmi_val_ <= 32.2) {
            interpretation_ = "Overweight";
        }else {
            interpretation_ = "Much overweight";
        }
    }
    // Male
    if (gender_ == 1) {
        if (bmi_val_ <= 20.7) {
            interpretation_ = "Underweight";
        }else if (bmi_val_ <= 26.4) {
            interpretation_ = "Normal";
        }else if (bmi_val_ <= 27.8) {
            interpretation_ = "Slight overweight";
        }else if (bmi_val_ <= 31.1) {
            interpretation_ = "Overweight";
        }else {
            interpretation_ = "Much overweight";
        }
    }

}

// Return interpretation as string.
string Bmi::get_interpretation() {
    return interpretation_;
}
