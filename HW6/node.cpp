#include "node.h"
#include <iostream>
#include <string>
using namespace std;

node::node(string d, int r) : data(d), rank(r), link(nullptr)
{}