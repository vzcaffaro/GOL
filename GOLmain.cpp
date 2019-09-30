#include "Reader.h"
#include "Grids.h"
#include <iostream>
#include <fstream>
#include <unistd.h> //allows for use of usleep(microseconds) to make the system sleep

using namespace std;

int main (int argc, char** argv)
{
    int startFile; //stores the user's choice to import or generate an 2d array

    int rows; //stores rows of grid
    int columns; //stores columns of grid
    double density; //stores the density of bacteria per cells

    //1. Ask the user if they wish to start with a random configuration, or specify a flatfile configuration. Prompt appropriately depending on the response.

    cout << "Would you like to import a flat-file configuration (1), or start with a randomized configuration (2)" << endl;
    cin >> startFile;

    while (startFile != 1 && startFile != 2) //while loop detecting any entries other than 1 or 2
    {
        cout << "That is not a valid entry. Enter '1' to import a map file and '2' to start with a randomized configuration. " << endl;
        cin >> startFile; //reassigns value to startFile
    }

    if (startFile==1) //if user wants to import file
    {
        string file; //variable to store name of file
        cout << "Please enter the name of the map file you want to read. " << endl;
        cin >> file;
        Reader fr;
        rows = fr.getRows(file); //retrieves rows
        columns = fr.getColumns(file); //retrieves columns
        density = fr.getDensity(file); //retrieves density
        cout<<"Rows: "<<rows<<"\nColumns: "<<columns<<"\nDensity: "<<density<<endl;
    }
    else if (startFile == 2) //if user wants to manually enter
    {
        cout << "Please enter the number of rows you want in digit format. " << endl;
        cin >> rows; //stores entry for rows
        cout << "Please enter the number of columns you want in digit format. " << endl;
        cin >> columns; //stores entry for columns
        cout << "Please enter a decimal between 0 and 1 representing population density" << endl;
        cin >> density; //stores entry for columns
    }


    //2. Ask the user what kind of boundary mode to run int

    int mode; //stores the user's choice for which mode to run
    cout<<"What boundary mode would you like to run? Enter 1 for classic mode, 2 for doughnut mode, and 3 for mirror mode."<<endl;
    cin>>mode;

    while (mode != 1 && mode != 2 && mode != 3) //while loop detecting any entries other than 1, 2, or 3
    {
        cout << "That is not a valid entry. Enter '1' to run classic mode, 2 for doughnut mode, and 3 for mirror mode. " << endl;
        cin >> mode; //reassigns value to mode
    }



    //3. Ask the user if they want a brief pause between generations, if they want to have to press the “enter” key, or if they want to output to a file.
    int parameter;
    cout<<"Would you like to:\n1. Have a brief pause between generations  \n2. Have to press the enter key  \n3. Output to a file"<<endl;
    cin>>parameter;
    while(parameter!=1 && parameter!=2 && parameter!=3)
    {
        cout<<"That is not a valid entry. Please enter: \n1. Have a brief pause between generations  \n2. Have to press the enter key  \n3. Output to a file"<<endl;
        cin>>parameter;
    }



    //4. Carry out the simulation

    Grids grid;
    int** myGridAddress = grid.makeGrid(rows,columns,density); //creates a grid and stores the grid's address
    int myGrid[rows][columns] = {**myGridAddress}; //stores the grid's data locally



    if(parameter==1)//if user wants a delay between generations
    {
        grid.printGrid(myGridAddress,rows,columns);//prints initial array
        while((grid.checkEmpty(myGridAddress,rows,columns)) && (grid.simulate(myGridAddress,rows,columns,mode)))//while the the array is not empty and not stable
        {
            grid.printGrid(myGridAddress,rows,columns);
            usleep(3000000); //sleeps for 3 seconds
        }
    }
    else if(parameter==2)//if user wants to hit 'enter' between generations
    {
        char userInput = '\n';
        grid.printGrid(myGridAddress,rows,columns);
        while(userInput=='\n')
        {
            while((grid.checkEmpty(myGridAddress,rows,columns)) && (grid.simulate(myGridAddress,rows,columns,mode)))
            {
                cin.get(userInput);
                grid.printGrid(myGridAddress,rows,columns);

            }
        }
    }

    else if(parameter==3)//if user wants to output to file
    {
        string file_name;
        cout<<"Please enter your file name: "<<endl;
        cin>>file_name;
        grid.streamGrid(myGridAddress,rows,columns,file_name);
        while((grid.checkEmpty(myGridAddress,rows,columns)) && (grid.simulate(myGridAddress,rows,columns,mode)))
        {
            grid.streamGrid(myGridAddress,rows,columns,file_name);
        }

    }

    cout<<"Please press 'enter' to exit the program."<<endl;
    char endprogram='\0';//stores final entry
    while(endprogram!='\n')
    {
        cin>>endprogram;
        cout<<"That is not a valid entry. Please press the 'enter' key."<<endl;
    }

}
