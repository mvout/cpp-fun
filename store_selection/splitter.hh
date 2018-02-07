/*
 * Ready made script to split user input and file contents.
 * Made by Ari Suntioinen, Tampere University of Technology.
*/

#ifndef SPLITTER_HH
#define SPLITTER_HH

#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <map>
#include <fstream>
#include <stdexcept>

using namespace std;

class Splitter
{
public:
    Splitter(const string& string_to_split = "");

    void set_string_to_split(const string& string_to_split);
    unsigned int split(char separator, bool skip_empty_fields = false);
    unsigned int number_of_fields() const;
    string fetch_field(unsigned int field_index) const;


  private:
    string original_string_;
    vector<string> split_result_;
};

#endif // SPLITTER_HH
