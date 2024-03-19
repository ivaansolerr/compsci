// Programación 2 - Práctica 1
// DNI: 74530257E
// Nombre: Iván Soler Sánchez

#include <iostream>
#include <vector>
#include <string.h>
#include <cstring>

using namespace std;

const int MAXSUBJECT=50;

// Registro para las fechas
struct Date{
    int day;
    int month;
    int year;
};

// Registro para las frases épicas
struct Phrase{
    string text;
    Date date;
    int rating;
};

// Registro para los profesores
struct Teacher{
    string name;
    string nickname;
    char subject[MAXSUBJECT];
    int rating;
    vector<Phrase> listPhrases;
};

// Registro para los cursos
struct AcademicYear{
    int id;
    vector<Teacher> listTeachers;
};

// Tipos de error posibles
enum Error{
    ERR_OPTION,
    ERR_EMPTY,
    ERR_DUPLICATED,
    ERR_NOT_EXIST,
    ERR_RATING
};

/* Función que muestra los mensajes de error
e: tipo de error a mostrar
return: nada
*/
void error(Error e){
    switch(e){
        case ERR_OPTION: cout << "ERROR: wrong option" << endl;
            break;
        case ERR_EMPTY: cout << "ERROR: empty string" << endl;
            break;
        case ERR_DUPLICATED: cout << "ERROR: duplicated value" << endl;
            break;
        case ERR_NOT_EXIST: cout << "ERROR: value does not exist" << endl;
            break;
        case ERR_RATING: cout << "ERROR: number out of range" << endl;
    }
}

/* Función que muestra el menú de opciones
return: nada
*/
void showMenu(){
    cout << "1- Add academic year" << endl
         << "2- Delete academic year" << endl
         << "3- Add teacher" << endl
         << "4- Delete teacher" << endl
         << "5- Show teacher" << endl
         << "6- Add phrase" << endl
         << "7- Summary" << endl
         << "q- Quit" << endl
         << "Option: ";
}

vector<AcademicYear> addAcademicYear(vector<AcademicYear> years){
    bool check = false; 
    string yearString;

    do{
        bool repeated = false; // var for checking if the year has been already introduced
         // we are gonna handle the user input as an string
                           // to avoid type problems

        cout << "Enter academic year: ";
        getline(cin,yearString);

        // we handle if the string is empty or is not number
        if (yearString.empty()){
            error(ERR_EMPTY);
            return years;
        }

        // we convert the string into an integer
        int year = stoi(yearString.c_str());

        // we check if the year entered is repeated
        for (unsigned i = 0; i < years.size(); i++){
            if (year == years[i].id){
                repeated = true;
                error(ERR_DUPLICATED);
            } 
        }

        // if is not repeated we add it the our vector
        if (repeated == false){
            AcademicYear a;
            a.id = year;
            years.push_back(a);
            check = true;
        }
    } while (!check);

    return years;

}

vector<AcademicYear> deleteAcademicYear(vector<AcademicYear> years){

    // here we do the same process we did in the add function
    bool found = false;
    string yearString;

    do {
        cout << "Enter academic year: ";
        getline(cin,yearString);

        if (yearString.empty()){
            error(ERR_EMPTY);
            return years;
        }

        int year = stoi(yearString.c_str());

        // we check if the year exits, if it exists we erase it
        for (unsigned i = 0; i < years.size() && !found; i++){
            if (year == years[i].id){
                found = true;
                years.erase(years.begin() + i);
            }
        }

        // we check if the year is not found
        if (!found) {
            error(ERR_NOT_EXIST);
        }
    } while (!found);
    return years;
}

vector<AcademicYear> addTeacher(vector<AcademicYear> years){
    string yearString;
    string teacherNickname;
    string subjTeach;
    bool repeated = false;
    //char subjectTeacher[MAXSUBJECT];
    string teacherName;
    bool found = false;
    string stringRating;
    int rating;

    // we use the do while to get back

    do {
        cout << "Enter academic year: ";
        getline(cin,yearString);

        if (yearString.empty()){
            error(ERR_EMPTY);
            return years;
        }

        int year = stoi(yearString.c_str());

        // we check if the year exists and also the other errors,
        // if it exists we continue introducing the name

        for (unsigned i = 0; i < years.size(); i++){
            if (year == years[i].id){
                do{
                    found = false;
                    repeated = true;
                    cout << "Enter teacher name: ";
                    getline(cin, teacherName);
                    if (teacherName.empty()){
                        error(ERR_EMPTY);
                        return years;
                    }

                    for (unsigned j = 0; j < years[i].listTeachers.size(); j++){
                        if (years[i].listTeachers[j].name == teacherName){
                            error(ERR_DUPLICATED);
                            found = true;
                        }
                    }

                } while (found);

                if (!found){
                    Teacher aux;
                    cout << "Enter nickname: ";
                    getline(cin, teacherNickname);

                    cout << "Enter subject: ";
                    getline(cin, subjTeach);

                    if (subjTeach.empty()){
                        error(ERR_EMPTY);
                        return years;
                    }

                    bool found2 = false;

                    do {
                        cout << "Enter rating: ";
                        getline(cin, stringRating);
                        if (stringRating.empty()){
                            rating = 0;
                            found2 = true;
                        } else if(stoi(stringRating.c_str()) >= 1 && stoi(stringRating.c_str()) <= 5){
                            rating = stoi(stringRating.c_str());
                            found2 = true;
                        } else {
                            error(ERR_RATING);
                        }
                    } while (!found2);

                    aux.name = teacherName;
                    aux.nickname = teacherNickname;
                    strncpy(aux.subject, subjTeach.c_str(), MAXSUBJECT-1);
                    aux.subject[MAXSUBJECT-1] = '\0';
                    aux.rating = rating;
                    
                    years[i].listTeachers.push_back(aux);
                }
            }
        }

        // we check for all the possible errors
        
        if (repeated == false){
            error(ERR_NOT_EXIST);
        }

    } while (repeated == false);

    return years;

}

vector<AcademicYear> deleteTeacher(vector<AcademicYear> years){
    bool found = false;
    string name;
    do {
        cout << "Enter teacher name: ";
        getline(cin,name);

        if (name.empty()){
            error(ERR_EMPTY);
            return years;
        }

        // we check if the name exists
        for (unsigned i = 0; i < years.size(); i++){
            for (unsigned j = 0; j < years[i].listTeachers.size() && !found; j++){
               if (years[i].listTeachers[j].name == name){
                    found = true;
                    // if the name exists we delete it
                    years[i].listTeachers.erase(years[i].listTeachers.begin() + j);
               } 
            }
        }

        // if the name does not exists we show this error
        if (!found) {
            error(ERR_NOT_EXIST);
        }
    } while (!found);
    return years;
}

void showTeacher(vector <AcademicYear> years){
    bool found = false;
    string name;
    do {
        cout << "Enter teacher name: ";
        getline(cin,name);

        if (name.empty()){
            error(ERR_EMPTY);
        }

        // we check if the name exists
        for (unsigned i = 0; i < years.size(); i++){
            for (unsigned j = 0; j < years[i].listTeachers.size() && !found; j++){
               if (years[i].listTeachers[j].name == name){
                // if the name exists we start printing his information
                    found = true;
                    cout << "Academic year: " << years[i].id << endl;
                    cout << "Name: " << years[i].listTeachers[j].name << endl;
                    if (!(years[i].listTeachers[j].nickname.empty())){
                        cout << "Nickname: " <<  years[i].listTeachers[j].nickname << endl;
                    } else;
                    cout << "Subject: " <<  years[i].listTeachers[j].subject << endl;
                    if (years[i].listTeachers[j].rating > 0){
                        cout << "Rating: ";
                        for (int k = 0; k < years[i].listTeachers[j].rating; k++){
                            cout << "*";
                        }
                    }
                    // here im checking the differents possibilities while
                    // entering the date
                    for (unsigned z = 1; z < years[i].listTeachers[j].listPhrases.size() + 1; z++){
                        if (years[i].listTeachers[j].listPhrases[z-1].rating == 0 &&
                            years[i].listTeachers[j].listPhrases[z-1].date.year == 0){
                            cout << "Phrase " << z
                            << ": "<<years[i].listTeachers[j].listPhrases[z-1].text
                            << endl;                                       
                        }
                        else if (years[i].listTeachers[j].listPhrases[z-1].rating == 0){
                            cout << "Phrase " << z << " ("
                            << years[i].listTeachers[j].listPhrases[z-1].date.year
                            << "-"  << years[i].listTeachers[j].listPhrases[z-1].date.month
                            << "-" << years[i].listTeachers[j].listPhrases[z-1].date.day << ")"
                            << ": "<<years[i].listTeachers[j].listPhrases[z-1].text
                            << endl;    
                        } else if(years[i].listTeachers[j].listPhrases[z-1].date.year == 0){
                            cout << "Phrase " << z
                            << " [" << years[i].listTeachers[j].listPhrases[z-1].rating
                            << "]" << ": "<<years[i].listTeachers[j].listPhrases[z-1].text
                            << endl;
                        } else {
                            cout << "Phrase " << z << " ("
                            << years[i].listTeachers[j].listPhrases[z-1].date.year
                            << "-"  << years[i].listTeachers[j].listPhrases[z-1].date.month
                            << "-" << years[i].listTeachers[j].listPhrases[z-1].date.day << ")"
                            << " [" << years[i].listTeachers[j].listPhrases[z-1].rating << "]"
                            << ": "<<years[i].listTeachers[j].listPhrases[z-1].text
                            << endl;
                        }
                    }

                    cout << "\n";
               } 
            }
        }

        // if the name does not exists we show this error
        if (!found) {
            error(ERR_NOT_EXIST);
        }
    } while (!found);
}

vector<AcademicYear> addPhrase(vector<AcademicYear> years){
    bool found = false;
    string name;
    string phrase;
    string strDate;
    string stringRating;
    bool found2 = false;
    int rating;
    int position; // the position to perform correctly the date
    do {
        cout << "Enter teacher name: ";
        getline(cin,name);

        if (name.empty()){
            error(ERR_EMPTY);
            return years;
        }

        // we check if the name exists
        for (unsigned i = 0; i < years.size(); i++){
            for (unsigned j = 0; j < years[i].listTeachers.size() && !found; j++){
               if (years[i].listTeachers[j].name == name){
                    found = true;
                    // if the name exists we ask for his phrase
                    cout << "Enter phrase: ";
                    getline(cin, phrase);
                    if (phrase.empty()){
                        error(ERR_EMPTY);
                        return years;
                    } else {
                        Phrase aux;
                        aux.text = phrase;                     
                        // now I ask for the date
                        cout << "Enter date (year-month-day): ";
                        getline(cin,strDate);
                        // if it is empty we set it to 0
                        if (strDate.empty()){
                            aux.date.year = 0;
                            aux.date.day = 0;
                            aux.date.month = 0;
                            // if it is not we start by getting the first 4 digits (year)
                            // we continue by searching where the '-' is and the get the two
                            // substrings with the month and the day
                        } else {
                            aux.date.year = atoi(strDate.substr(0,4).c_str());
                            strDate.erase(0,5);

                            position = strDate.find("-");

                            aux.date.month = atoi(strDate.substr(0,position).c_str());
                            aux.date.day = atoi(strDate.substr(position+1, strDate.size()).c_str());
                        }
                         
                        do {
                            // know we check the rating and all the possiblities we 
                            // have to worry about
                            cout << "Enter rating: ";
                            getline(cin, stringRating);
                            if (stringRating.empty()){
                                rating = 0;
                                found2 = true;
                            } else if(stoi(stringRating.c_str()) >= 1 && stoi(stringRating.c_str()) <= 10){
                                rating = stoi(stringRating.c_str());
                                found2 = true;
                            } else {
                                error(ERR_RATING);
                            }
                        } while (!found2);

                        aux.rating = rating;

                        years[i].listTeachers[j].listPhrases.push_back(aux);
                    }
               } 
            }
        }

        // if the name does not exists we show this error
        if (!found) {
            error(ERR_NOT_EXIST);
        }
    } while (!found);
    return years; 
}

void summary(vector<AcademicYear> years){ 

    int maxYear = years[0].id;
    int pos = 0;
    bool full = false;

    for (unsigned i = 0; i < years.size(); i++){
        if (maxYear < years[i].id) {
            maxYear = years[i].id;
            pos = i;
        }

        if (i == (years.size()-1)){
            if (years[pos].listTeachers.size() > 0){

                // this loop if for checking if the listPhrasese is empty and if is
                //not to show the Academic year
                for (unsigned z = 0; z < years[pos].listTeachers.size() && !full; z++){
                    if (years[pos].listTeachers[z].listPhrases.size() > 0){
                        full = true;
                    }   
                }
                
                if (full){
                    cout << "Academic year: " << maxYear << endl;
                }

                for (unsigned j = 0; j < years[pos].listTeachers.size(); j++){
                    for (unsigned k = 0; k < years[pos].listTeachers[j].listPhrases.size(); k++){
                        if (years[pos].listTeachers[j].listPhrases[k].rating == 0){
                            cout <<
                            years[pos].listTeachers[j].name << " - " <<
                            years[pos].listTeachers[j].listPhrases[k].text << endl;
                        } else {
                            cout <<
                            years[pos].listTeachers[j].name << " - " <<
                            years[pos].listTeachers[j].listPhrases[k].rating << " - " <<
                            years[pos].listTeachers[j].listPhrases[k].text << endl;
                        }
                    }
                }
            }

            years.erase(years.begin() + pos);
            maxYear = years[0].id;
            i = -1;
            pos = 0;
        }
    }

}

// Función principal. Tendrás que añadir máscódigo tuyo
int main(){
    vector<AcademicYear> years;
    char option;
    
    do{
        showMenu();
        cin >> option;
        cin.get(); // Para evitar que el salto de línea se quede en el buffer de teclado y luego pueda dar problemas si usas "getline"
        
        switch(option){
            case '1': // Llamar a la función "addAcademicYear" para crear un nuevo curso
                years = addAcademicYear(years);
                break;
            case '2': // Llamar a la función "deleteAcademicYear" para eliminar un curso
                years = deleteAcademicYear(years);
                break;
            case '3': // Llamar a la función "addTeacher" para crear un nuevo profesor
                years = addTeacher(years);
                break;
            case '4': // Llamar a la función "deleteTeacher" parar eliminar un profesor
                years = deleteTeacher(years);
                break;
            case '5': // Llamar a la función "showTeacher" para mostrar la información del profesor
                showTeacher(years);
                break;
            case '6': // Llamar a la función "addPhrase" para añadir una nueva frase
                years = addPhrase(years);
                break;
            case '7': // Llamar a la función "summary" para mostrar un resumen de las frases por curso
                summary(years);
                break;
            case 'q': break;
            default: error(ERR_OPTION);
        }
    }while(option!='q');
}