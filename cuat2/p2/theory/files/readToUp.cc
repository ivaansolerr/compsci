#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <cctype>

using namespace std;

char upperCase(char c);

int main(int argc, char * argv[]){

    fstream fi;
    fstream pi;
    fi.open("hello.txt", ios::in);
    pi.open("FILE.TXT", ios::out);

    if (fi.is_open() && pi.is_open()){
        char c;
        while (fi.get(c)){
            pi << upperCase(c);
        }
        
        fi.close();
        pi.close();

    } else {
        cout << "ERROR 404" << endl;
    }

    return 0;
}

char upperCase(char c){
    if (c >= 'a' && c <= 'z'){
        c +=('A'-'a');
    } 

    return c;
}