#include "Reader.h"
#include <iostream>
#include <fstream>

using namespace std;

Reader::Reader() //default constructor
{

}
Reader::~Reader() //default destructor
{
    cout << "object deleted" << endl;
}


int Reader::getRows(string file) //function to return the first number which stands for rows
{
    int rows; //returned variable
    ifstream inf; //opens a reading stream
    inf.open(file); //opens the file into the stream
    while(line.empty())
    {
        getline(inf,line); // stores first line in variable line
    }
    rows = line[0]-'0';// reads the first digit and turns it to an int by subtracting '0'
    inf.close(); //closes file
    return rows;
}


int Reader::getColumns(string file)
{
    int columns;
    string line1;
    string line2;
    ifstream inf2;
    inf2.open(file);
    getline(inf2,line1);
    getline(inf2,line2);
    columns=line2[0]-'0'; //reads first char of second line and converts to int
    inf2.close();
    return columns;
}

double Reader::getDensity(string file)
{
    double density;
    string densityline;
    ifstream inf3;
    inf3.open(file);
    while (!inf3.eof()) //while loop only true while the file has not reached its end
    {
        getline(inf3,densityline);
        for (int x=0; x<densityline.size();++x) //loops through every char in each line
        {
            if(densityline[x]=='-') //checks for dashes
            {
                ++dashcounter;
            }
            else if(densityline[x]=='X' || densityline[x]=='x') //checks for X's
            {
                ++xcounter;
            }
        }
    }
    density = xcounter / (xcounter+dashcounter); //calculation for density
    inf3.close();
    return density;

}
