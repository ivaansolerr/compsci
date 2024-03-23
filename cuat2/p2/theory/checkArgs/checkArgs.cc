#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

bool checkArgs(int argc, char * argv[]);

int main(int argc, char * argv[]){

    if (checkArgs(argc, argv)){
        cout << "CORRECT" << endl;
    } else {
        cout << "ERROR: " << argv[0] << " [-L] [-N] [n]" << endl;
    }

    return 0;
}

bool checkArgs(int argc, char * argv[]){
    bool correct = true;

    if (argc > 4){
        correct = false;
    } else{
        for (int i = 1; i<argc; i++){

            if (i == 1){
                if (!(strcmp(argv[i],"-L")==0) && !(strcmp(argv[i],"-N")==0)) {
                    correct = false;
                }
            }

            if (i + 1 < argc){
                if ((strcmp(argv[i],"-N")==0) && (atoi(argv[i+1])) == 0){
                    correct = false;
                } 
                if ((strcmp(argv[i],"-L")==0) && !(strcmp(argv[i+1],"-N")==0)){
                    correct = false;
                }
            } else if (i + 1 == argc){
                if (strcmp(argv[i],"-N")==0){
                    correct = false;
                }
            }
        }
        
    }

    return correct;
}