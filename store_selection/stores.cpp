/*
 * Methods for class Stores.
*/

#include "stores.hh"

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

Stores::Stores(const string& store_name):
    store_name_(store_name) {

}

// Add products or change the price of existing product.
// Input:
//  -string of product name
//  -double of product price
void Stores::add_product(string product,double price) {
    if (products_.find(product) != products_.end()) {
        products_.at(product) = price;
    }else {
        products_.insert({product,price});
    }
}

// Print the selection of store alphabetically.
void Stores::print_selection() {
    vector<pair<string,double>> product_vector;
    for(auto const &entry : products_) {
        product_vector.push_back(entry);

    }
    sort(product_vector.begin(),product_vector.end());
    for (auto const &entry :product_vector) {
        cout << entry.first << " " << setprecision(2) << fixed
             << entry.second << endl;
    }
}

// Get price of product in a store.
// Input:
//  -string of product name
double Stores::get_price(string product) {
    if (products_.find(product) != products_.end()) {
        return products_.at(product);
    }
    // Prices can't be negative, this implies product
    // is not in selection.
    return -1.0;
}

