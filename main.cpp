#include "mat.hpp"
#include "mat.cpp"
#include <iostream>
#include <stdexcept>

using namespace std;

int main(){
    const int ROWS = 9;
    const int COLLS = 7;
    const char FIRST = 'E';
    const char SECOND = '-';

    string rug = ariel::mat(ROWS, COLLS, FIRST, SECOND);
    int index = 0;

    for (int i = 0; i < COLLS; i++){
        cout << endl;
        for (int j = 0; j < ROWS; j++){
            cout << rug[j + index];
        }
          index += ROWS;
    }
}
