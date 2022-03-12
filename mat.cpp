#include "mat.hpp"

#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
using namespace std;
using namespace ariel;

const int MAX_VALID_CHAR = 126;
const int MIN_VALID_CHAR = 33;

string ariel::mat(int rows, int colls, char first, char second){

    // throwing an error whenever there is a bad input
    if (rows < 1 || colls < 1 || rows%2==0 || colls%2 == 0 || first > MAX_VALID_CHAR || first < MIN_VALID_CHAR || second > MAX_VALID_CHAR || second < MIN_VALID_CHAR)  
    {
        throw new bad_exception;
    } 
    
    vector<vector<char> >symbolsVector;
    string ans;             // this is gonna be the final answer
    int help = 0;           // this is gonna help me to switch between the first symbol and the the second symbol
    char mychar = ' ';      // A dynamic char that'll switch betweeb the two symbols 
    int rowsCopy = rows;    // i need a copy of the rows becasue i'm gonna change its value later
    int collsCopy = colls;  // same ^
    vector<char>temp(colls); // i'm using this vector to initialize the main vector 'symbolsVector'
    

    // initialize my main vector and fill it with the char 'space'
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < colls; j++)
        {
            temp[j] = ' ';
        }
        symbolsVector.push_back(temp);
    }
    

    while(max(rows,colls) != 0){
        for(int i =help; i < rows; i++){
            for(int j = help; j < colls; j++){

                if (help % 2 == 0)
                {
                    mychar = first; // if help is even it's time to use the first symbol
                } else {
                    mychar = second; // if help is odd it's time to use the second symbol
                }

                if(symbolsVector[rows-1][j] == ' ') { // if this cell is empty
                    symbolsVector[rows-1][j] = mychar; // i want to fill the last column of the current ring
                    }
                if(symbolsVector[help][j] == ' ') { // if this cell is empty
                    symbolsVector[help][j] = mychar; // i want to fill the first column of the current ring
                    }
                if(symbolsVector[i][help] == ' ') { // if this cell is empty
                    symbolsVector[i][help] = mychar; // i want to fill the first row of the current ring
                    }
                if(symbolsVector[i][colls-1] == ' ') { // if this cell is empty
                    symbolsVector[i][colls-1] = mychar; // i want to fill the last row of the current ring
                    } 
            }
        }
        help++; // moving on to the next symbol
        rows--; // moving on to the next ring
        colls--; // ^
    }

    // using the copies to push all of the chars that in the vector to the ans variable
    for (int i = 0; i < collsCopy; i++)
    {
        for (int j = 0; j < rowsCopy; j++)
        {
            ans.push_back(symbolsVector[j][i]);
        }
        
    }    

    return ans;
}


