//creator: Robert Ward
//homework 10
/*
this program calculates the 10 inputed test scores and takes the outputs, 
it then outputs to the other txt file.
*/


#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstdlib>

using namespace std;

double avg (double nums[10]) {

    double average = 0.0;

    for (int i = 0; i < 10; i++) {
        average += nums[i];
    }

    return (double) (average / 10);
}

int getNumberOfGrades(const string& filename) {
    ifstream file(filename);
    
    if (!file.is_open()) {
        cerr << "Error opening file: " << filename << endl;
        return -1; // Return -1 to indicate an error
    }

    int count = 0;
    int grade;

    while (file >> grade) {
        // Assuming each grade is on a new line in the file
        count++;
    }

    file.close();
    
    return count;
}



int main () {

    const char* username = getenv("USER");

    string filePath = "/Users/" + string(username) + "/Desktop/homework 10/StudentScores.txt";
    string filePath1 = "/users/" + string(username) + "/Desktop/homework 10/StudentAverages.txt";
    string input, last, first;

    ifstream inputFile(filePath);
    ofstream outputFile(filePath1);

    double num[getNumberOfGrades(filePath)];

    int count = 0;

    string setNumberOfGrades;

    for (int i = 0; i < getNumberOfGrades(filePath); i++) {
        setNumberOfGrades += to_string(num[i]) + " ";
    }

/*  << ": " 
            << num[0]  << ", " << num[1] << ", " << num[2] << ", " << num[3] << ", " << num[4] << ", " << num[5] << ", " 
            << num[6] << ", " << num[7] << ", " << num[8] << ", " << num[9] 
*/
while (true) {
    if (inputFile.is_open()) {
        if (inputFile >> last >> first >> num[0] >> num[1] >> num[2]  >> num[3] >> num[4] >> num[5] >> num[6] >> num[7] >> num[8] >> num[9]) {

            cout << "Name and numbers read from the file: " << first << ", " << last  << ": " << num[0]  << ", " << num[1] << ", " << num[2] << ", " << num[3] << ", " << num[4] << ", " << num[5] << ", " 
            << num[6] << ", " << num[7] << ", " << num[8] << ", " << num[9] << endl << endl;

            //make this work
            cout << setNumberOfGrades << endl << endl;

            outputFile << "name: " << last << ", " << first << endl << endl;
            outputFile << "Average Score: " << avg(num) << endl << endl;

            cout << "the average that we have counted for this student is: " << avg(num) << endl << endl;
        }
    } else {
        cerr << "Error: Unable to open the file." << endl;
        return 1;
    }
}
}