#include <iostream>
#include <vector>
#include <string.h>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include <cctype>

using namespace std;

struct TStudent{
    char name[100];
    int group;
    float avgMark;
};

int main(){

    TStudent student;
    TStudent s;
    fstream fi;

    fi.open("myFile.dat", ios::in | ios::out | ios::binary);

    if (fi.is_open()){  
        strcpy(student.name, "Maricón");
        student.group = 6;
        student.avgMark = 7.6;
         
        fi.seekp(108, ios::beg);

        // Writing 
        fi.write((const char *)&student, sizeof(student));

        strcpy(student.name, "Marica");
        student.group = 7;
        student.avgMark = 6.6;

        fi.seekp(0, ios::beg);

        fi.write((const char *)&student, sizeof(student));

        // When reading we get to the final position of the file
        // so we have to go to the beginning

        fi.seekg(0, ios::beg);

        // Reading
        while (fi.read((char *)&s, sizeof(student))){
          cout << s.name << " is from group " << s.group
          << " and has reach " <<s.avgMark << endl;
        }
        // Closing file
        fi.close();

    } else {
        cout << "ERROR 404" << endl;
    }

    return 0;
}

