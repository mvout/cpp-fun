/*
 * File contains all the query methods that don't require the Class
 * functionality.
*/

#ifndef PRINTS_HH
#define PRINTS_HH

#include "splitter.hh"
#include "stores.hh"
#include "prints.hh"

#include <iostream>
#include <iomanip>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

void print_cheapest(map<string, map<string, Stores>>& chains, string product);

void print_chains(map<string, map<string, Stores>>& chains);

void print_stores(map<string, map<string, Stores>>& chains, string chain);

void print_error();



#endif // PRINTS_HH
