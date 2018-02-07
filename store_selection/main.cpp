/*
 * This program let's user to query things about stores.
 * Program reads a text file with info about stores and their products.
 * User can query the data.
 *
*/
#include "splitter.hh"
#include "stores.hh"
#include "prints.hh"

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

// The user interface. Asks user to input commands and checks their validity.
// Input:
//  -map of data
void user_interface(map<string, map<string,Stores>>& chains) {
    bool quit = false;
    while (!quit) {
        string input;
        string cmd;
        cout << "product search> ";
        getline(cin,input);
        Splitter query(input);
        query.split(' ');
        if (query.number_of_fields() == 1) {
             cmd = query.fetch_field(0);
            if (cmd == "quit") {
                quit = true;
            }else if (cmd == "chains") {
                print_chains(chains);
            }else {
                print_error();
            }
        }else if (query.number_of_fields() == 2) {
            cmd = query.fetch_field(0);
            string arg = query.fetch_field(1);
            if (cmd == "stores") {
                if (chains.find(arg) != chains.end()) {
                    print_stores(chains,arg);
                }else {
                    print_error();
                }
            }else if (cmd == "cheapest") {
                print_cheapest(chains,arg);
            }else {
                print_error();
            }
        }else if (query.number_of_fields() == 3) {
            cmd = query.fetch_field(0);
            string chain = query.fetch_field(1);
            string store = query.fetch_field(2);
            if (cmd == "selection") {
                if (chains.find(chain) != chains.end()) {
                    if (chains.at(chain).find(store) != chains.at(chain).end()) {
                        chains.at(chain).at(store).print_selection();
                    }else {
                        print_error();
                    }
                }else {
                    print_error();
                }
            }else {
                print_error();
            }
        }else {
            print_error();
        }
    }
}

// Main function reads the text file, checks it's validity and parses it to
// data container.
int main()
{
    // Main data container.
    // map<CHAIN_NAME,map<STORE_NAME,STORE_OBJECT>>
    map<string, map<string,Stores>> chains;
    map<string,Stores> stores;
    ifstream filename;
    string line;

    // Read file and parse to data container.
    filename.open("products.txt");
    while(getline(filename, line)) {
        try {
        if (line.find(" ") != string::npos) {
            throw invalid_argument("Error: the input file can not be read.");
        }

        Splitter splitter_object(line);
        splitter_object.split(';');
        if (splitter_object.number_of_fields() != 4) {
            throw invalid_argument("Error: the input file can not be read.");
        }

        string chain = splitter_object.fetch_field(0);
        string store = splitter_object.fetch_field(1);
        string prod = splitter_object.fetch_field(2);
        double price = stod(splitter_object.fetch_field(3));

        // Check if chain is in chains map
        if (chains.find(chain) != chains.end()) {
            // Check if store is in map
            if(chains.at(chain).find(store) != chains.at(chain).end()) {
                chains.at(chain).at(store).add_product(prod,price);
            }else {
                Stores new_store(store);
                new_store.add_product(prod,price);
                chains.at(chain).insert({store,new_store});
            }
        }else {
            Stores new_store(store);
            new_store.add_product(prod,price);
            stores.insert({store,new_store});
            chains.insert({chain,stores});
        }
        stores.clear();
        }catch(invalid_argument& e) {
            cerr << e.what() << endl;
            filename.close();
            exit(1);
        }
    }

    filename.close();
    // Start user interface
    user_interface(chains);
}


