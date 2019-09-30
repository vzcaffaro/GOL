#include "Grids.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

//do i need to write code in my destructor
//how can i make random operator randomly initialize array


Grids::Grids()
{

}

Grids::~Grids()
{
    cout<<"Object deleted"<<endl;
}

int** Grids::makeGrid(int rows, int columns, double density)
{
    int** myGrid = 0; //initializes pointer
    myGrid = new int*[rows]; //creates 1D array
    for(int r = 0; r<rows; ++r)
    {
        myGrid[r] = new int[columns]; //creates an array for every element in 1D array, making it 2D

        for (int c = 0; c<columns; ++c)
        {
            double a = ((double) rand() / RAND_MAX); //random num between 0 and 1
            if(a<=density)
            {
                myGrid[r][c] = 1; //living cell
            }
            else if(a>density)
            {
                myGrid[r][c] = 0; //lifeless cell
            }
        }
    }

    return myGrid; //returns pointer to 2d array
}


void Grids::printGrid(int** myGrid, int rows, int columns)
{
    for (int r = 0; r<rows; ++r)
    {
        cout<<'\n'<<string(columns*5,'_')<<endl; //formats horizontal lines
        for(int c=0; c<columns; ++c)
        {
            if(myGrid[r][c] == 0)
            {
                cout<<"| - |";
            }
            else
            {
                cout<<"| X |";
            }
        }
    }
    cout<<endl;
}



void Grids::streamGrid(int** myGrid, int rows, int columns, string file_name)
{
    ofstream outf; //new write stream
    outf.open(file_name, ios::app); //opens file in append mode
    for (int r = 0; r<rows; ++r)
    {
        outf<<'\n'<<string(columns*5,'_')<<endl;
        for(int c=0; c<columns; ++c)
        {
            if(myGrid[r][c] == 0)
            {
                outf<<"| - |";
            }
            else
            {
                outf<<"| X |";
            }
        }
    }
    outf<<endl;
}

bool Grids::simulate(int** myGrid, int rows, int columns, int mode)
{
    int** myGrid2 = 0; //initializes pointer
    myGrid2 = new int*[rows]; //creates 1D array
    for(int r = 0; r<rows; ++r)
    {
        myGrid2[r] = new int[columns]; //makes array 2D

        for (int c = 0; c<columns; ++c)
        {
            myGrid2[r][c]=myGrid[r][c]; //copies myGrid to myGrid2
        }
    }



    int neighbors; //stores how many neighbors a cell has
    for(int r = 0; r<rows; ++r) // iterates through rows
    {
        for(int c=0; c<columns; ++c)//iterates through columns
        {
            neighbors = 0; //sets to 0 before each time looping through


            if(mode==1) //classic mode
            {
                //if statements reading surrounding cells based on boundary mode

                if(r==0)
                {
                    if(c==0)
                    {
                        if(myGrid2[r+1][c]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r+1][c+1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r][c+1]==1)
                        {
                            ++neighbors;
                        }
                    }
                    else if(c>0 && c<columns-1)
                    {
                        if(myGrid2[r][c-1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r][c+1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r+1][c-1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r+1][c]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r+1][c+1]==1)
                        {
                            ++neighbors;
                        }
                    }
                    else if(c==columns-1)
                    {
                        if(myGrid2[r][c-1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r+1][c-1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r+1][c]==1)
                        {
                            ++neighbors;
                        }
                    }
                }



                else if(r>0 && r<rows-1)
                {
                    if(c==0)
                    {
                        if(myGrid2[r-1][c]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r+1][c]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r-1][c+1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r][c+1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r+1][c+1]==1)
                        {
                            ++neighbors;
                        }
                    }
                    else if(c>0 && c<columns-1)
                    {
                        if(myGrid2[r-1][c-1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r-1][c]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r-1][c+1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r][c-1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r][c+1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r+1][c-1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r+1][c]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r+1][c+1]==1)
                        {
                            ++neighbors;
                        }
                    }
                    else if(c==columns-1)
                    {
                        if(myGrid2[r-1][c-1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r-1][c]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r][c-1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r+1][c-1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r+1][c]==1)
                        {
                            ++neighbors;
                        }
                    }
                }

                else if(r==rows-1)
                {
                    if(c==0)
                    {
                        if(myGrid2[r-1][c]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r-1][c+1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r][c+1]==1)
                        {
                            ++neighbors;
                        }
                    }
                    else if(c>0 && c<columns-1)
                    {
                        if(myGrid2[r-1][c-1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r-1][c]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r-1][c+1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r][c-1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r][c+1]==1)
                        {
                            ++neighbors;
                        }
                    }
                    else if(c==columns-1)
                    {
                        if(myGrid2[r-1][c]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r-1][c-1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r][c-1]==1)
                        {
                            ++neighbors;
                        }
                    }
                }

            }





            else if(mode==2) //Doughnut mode
            {

                if(r==0)
                {
                    if(c==0)
                    {
                        if(myGrid2[rows-1][columns-1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[rows-1][c]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[rows-1][c+1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r][columns-1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r][c+1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r+1][columns-1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r+1][c]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r+1][c+1]==1)
                        {
                            ++neighbors;
                        }
                    }
                    else if(c>0 && c<columns-1)
                    {
                        if(myGrid2[rows-1][c-1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[rows-1][c]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[rows-1][c+1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r][c-1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r][c+1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r+1][c-1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r+1][c]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r+1][c+1]==1)
                        {
                            ++neighbors;
                        }
                    }
                    else if(c==columns-1)
                    {
                        if(myGrid2[rows-1][c-1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[rows-1][c]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[rows-1][0]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r][c-1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r][0]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r+1][c-1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r+1][c]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r+1][0]==1)
                        {
                            ++neighbors;
                        }
                    }
                }



                else if(r>0 && r<rows-1)
                {
                    if(c==0)
                    {
                        if(myGrid2[r-1][columns-1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r-1][c]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r-1][c+1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r][c+1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r][columns-1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r+1][columns-1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r+1][c]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r+1][c+1]==1)
                        {
                            ++neighbors;
                        }
                    }
                    else if(c>0 && c<columns-1)
                    {
                        if(myGrid2[r-1][c-1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r-1][c]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r-1][c+1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r][c-1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r][c+1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r+1][c-1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r+1][c]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r+1][c+1]==1)
                        {
                            ++neighbors;
                        }
                    }
                    else if(c==columns-1)
                    {
                        if(myGrid2[r-1][c-1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r-1][c]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r-1][0]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r][c-1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r][0]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r+1][c-1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r+1][c]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r+1][0]==1)
                        {
                            ++neighbors;
                        }
                    }
                }

                else if(r==rows-1)
                {
                    if(c==0)
                    {
                        if(myGrid2[r-1][columns-1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r-1][c]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r-1][c+1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r][c+1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r][columns-1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[0][columns-1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[0][c]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[0][c+1]==1)
                        {
                            ++neighbors;
                        }
                    }
                    else if(c>0 && c<columns-1)
                    {
                        if(myGrid2[r-1][c-1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r-1][c]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r-1][c+1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r][c-1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r][c+1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[0][c-1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[0][c]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[0][c+1]==1)
                        {
                            ++neighbors;
                        }
                    }
                    else if(c==columns-1)
                    {
                        if(myGrid2[r-1][c-1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r-1][c]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r-1][0]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r][c-1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r][0]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[0][c-1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[0][c]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[0][0]==1)
                        {
                            ++neighbors;
                        }
                    }
                }

            }






            else if(mode==3) //Mirror mode
            {
                if(r==0)
                {
                    if(c==0)
                    {
                        if(myGrid2[r][c]==1)
                        {
                            neighbors+=3;
                        }
                        if(myGrid2[r][c+1]==1)
                        {
                            neighbors+=2;
                        }
                        if(myGrid2[r+1][c]==1)
                        {
                            neighbors+=2;
                        }
                        if(myGrid2[r+1][c+1]==1)
                        {
                            ++neighbors;
                        }
                    }
                    else if(c>0 && c<columns-1)
                    {
                        if(myGrid2[r][c]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r][c-1]==1)
                        {
                            neighbors+=2;
                        }
                        if(myGrid2[r][c+1]==1)
                        {
                            neighbors+=2;
                        }
                        if(myGrid2[r+1][c-1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r+1][c]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r+1][c+1]==1)
                        {
                            ++neighbors;
                        }
                    }
                    else if(c==columns-1)
                    {
                        if(myGrid2[r][c]==1)
                        {
                            neighbors+=3;
                        }
                        if(myGrid2[r][c-1]==1)
                        {
                            neighbors+=2;
                        }
                        if(myGrid2[r+1][c]==1)
                        {
                            neighbors+=2;
                        }
                        if(myGrid2[r+1][c-1]==1)
                        {
                            ++neighbors;
                        }
                    }
                }



                else if(r>0 && r<rows-1)
                {
                    if(c==0)
                    {
                        if(myGrid2[r][c]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r-1][c]==1)
                        {
                            neighbors+=2;
                        }
                        if(myGrid2[r+1][c]==1)
                        {
                            neighbors+=2;
                        }
                        if(myGrid2[r-1][c+1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r][c+1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r+1][c+1]==1)
                        {
                            ++neighbors;
                        }
                    }
                    else if(c>0 && c<columns-1)
                    {
                        if(myGrid2[r-1][c-1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r-1][c]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r-1][c+1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r][c-1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r][c+1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r+1][c-1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r+1][c]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r+1][c+1]==1)
                        {
                            ++neighbors;
                        }
                    }
                    else if(c==columns-1)
                    {
                        if(myGrid2[r][c]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r-1][c]==1)
                        {
                            neighbors+=2;
                        }
                        if(myGrid2[r+1][c]==1)
                        {
                            neighbors+=2;
                        }
                        if(myGrid2[r-1][c-1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r][c-1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r+1][c-1]==1)
                        {
                            ++neighbors;
                        }
                    }
                }

                else if(r==rows-1)
                {
                    if(c==0)
                    {
                        if(myGrid2[r][c]==1)
                        {
                            neighbors+=3;
                        }
                        if(myGrid2[r][c+1]==1)
                        {
                            neighbors+=2;
                        }
                        if(myGrid2[r-1][c]==1)
                        {
                            neighbors+=2;
                        }
                        if(myGrid2[r-1][c+1]==1)
                        {
                            ++neighbors;
                        }
                    }
                    else if(c>0 && c<columns-1)
                    {
                        if(myGrid2[r][c]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r][c-1]==1)
                        {
                            neighbors+=2;
                        }
                        if(myGrid2[r][c+1]==1)
                        {
                            neighbors+=2;
                        }
                        if(myGrid2[r-1][c-1]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r-1][c]==1)
                        {
                            ++neighbors;
                        }
                        if(myGrid2[r-1][c+1]==1)
                        {
                            ++neighbors;
                        }
                    }
                    else if(c==columns-1)
                    {
                        if(myGrid2[r][c]==1)
                        {
                            neighbors+=3;
                        }
                        if(myGrid2[r][c-1]==1)
                        {
                            neighbors+=2;
                        }
                        if(myGrid2[r-1][c]==1)
                        {
                            neighbors+=2;
                        }
                        if(myGrid2[r-1][c-1]==1)
                        {
                            ++neighbors;
                        }
                    }
                }


            }



            if(neighbors<2) //underpopulation
            {
                myGrid[r][c]=0; //dead
            }
            //if cell has exactly 2 neighbors, nothing happens to it
            else if(neighbors==3)//reproduction
            {
                myGrid[r][c]=1;//alive
            }
            else if(neighbors>=4)//overpopulation
            {
                myGrid[r][c]=0;//dead
            }




            }
        }





    int diffCells=0; //stores how many differences between each generation
    for(int r = 0; r<rows; ++r) // iterates through rows
    {
        for(int c=0; c<columns; ++c)//iterates through columns
        {
            if(myGrid[r][c]!=myGrid2[r][c])//checks if data stored is different
            {
                ++diffCells;
            }
        }
    }

    if(diffCells==0)
    {
        return false;
    }

    else
    {
        return true;
    }
}

bool Grids::checkEmpty(int** myGrid, int rows, int columns)
{
    int alive = 0;
    for(int r = 0; r<rows; ++r) // iterates through rows
    {
        for(int c=0; c<columns; ++c)//iterates through columns
        {
            if(myGrid[r][c]==1)
            {
                ++alive;
            }
        }
    }

    if(alive>0) //if any cells are still surviving
    {
        return true;
    }
    else if(alive==0) //if all cells are dead
    {
        return false;
    }

}
