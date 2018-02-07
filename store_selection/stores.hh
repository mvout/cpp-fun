/*
 * Define class Stores.
 * Stores the product information for any store.
 *
*/

#ifndef STORES_HH
#define STORES_HH

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Stores
{
public:
    Stores(const string& store_name);
    void add_product(string product, double price);
    void print_selection();
    double get_price(string product);

private:
    string store_name_;
    map<string,double> products_;


};

#endif // STORES_HH
