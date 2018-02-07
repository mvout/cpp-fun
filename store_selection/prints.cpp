/*
 * File contains all the query methods that don't require the Class
 * functionality.
*/

#include "prints.hh"
#include "splitter.hh"
#include "stores.hh"

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;


// Find cheapest product across all the stores and print the results.
// Input:
//  -map of store information
//  -string of the product to query
void print_cheapest(map<string, map<string, Stores>>& chains, string product) {
    vector<pair<string,string>> cheapest;
    double price;
    // Here's to hope no product in stores is more expensive than this.
    // Needed to set the first entry as the cheapest one.
    double cheapest_price = 999999999;

    for (auto const &entry:chains) {
        for (auto const &store_entry:entry.second) {
            price = chains.at(entry.first).at(store_entry.first).get_price(product);
            if (price != -1.0 && price <= cheapest_price) {
                if (price < cheapest_price) {
                    cheapest.clear();
                    cheapest.push_back({entry.first,store_entry.first});
                    cheapest_price = price;
                }else {
                    cheapest.push_back({entry.first,store_entry.first});
                }
            }
        }
    }
    sort(cheapest.begin(),cheapest.end());

    if (cheapest.size() > 0) {
        cout << setprecision(2) << fixed << cheapest_price << endl;
        for (auto const entry:cheapest) {
            cout << entry.first << " " << entry.second << endl;
        }
    }else {
        cout << "This product is not available anywhere." << endl;
    }
}


// Print the chains alphabetically
// Input:
//  -map of store information
void print_chains(map<string, map<string, Stores>>& chains){
    vector<string> chain_names;
    for(auto const &entry : chains) {
        chain_names.push_back(entry.first);
    }
    sort(chain_names.begin(),chain_names.end());
    for (auto const &entry : chain_names) {
        cout << entry <<endl;
    }
}


// Print the stores of chain alphabetically.
// Input:
//  -map of store information
//  -string of chain name
void print_stores(map<string, map<string, Stores>>& chains, string chain) {
    //map<string, map<string,double>> stores = chains.at(chain);
    vector<string> store_names;
    for(auto const &entry : chains.at(chain)) {
        store_names.push_back(entry.first);
    }
    sort(store_names.begin(),store_names.end());
    for (auto const &entry :store_names) {
        cout << entry << endl;
    }
}

// Print error message when input is invalid.
void print_error() {
    string error_message = "Error: Not a valid input!";
    cout << error_message <<endl;
}



