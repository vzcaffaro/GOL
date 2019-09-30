#include <iostream>

using namespace std;

class Reader{
    public:
    Reader(); //constructor
    ~Reader(); //destructor

string line;

double xcounter = 0.0;
double dashcounter = 0.0;


int getRows(string file);
int getColumns(string file);
double getDensity(string file);

};
