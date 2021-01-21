#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int NUM_QUESTION = 20;
const int NUM_STUDENT = 150;
//ogrencilerin scorelariyla alakali dosyaya yazdirma islemleri cart curt.
//elnglr
// global variables because we don't have classes
string key;
struct studentData {
    string ID;
    string Answers;
    studentData () {
        ID = " ";
    }
} Data[NUM_STUDENT];

char testScore(int score) {
    int score1 = score;
    cout << "Score: " << score << endl;
    if (score1 >= 36)
        return 'A';
    else if (score1 >= 32)
        return 'B';
    else if (score1 >= 28)
        return 'C';
    else if (score1>= 24)
        return 'D';
    else
        return 'F';
}

void gradeTest() {
    for (int i = 0; i < NUM_STUDENT; i++) {
        if (Data[i].ID == " ") continue;
        cout << "Student ID: " << Data[i].ID << endl;
        int score = 0;
        cout << "Answers: ";
        cout << Data[i].Answers;
        for (int j = 0; j < NUM_QUESTION; j++) {
            if (Data[i].Answers[j] == key[j])
                score += 2;
            else if (Data[i].Answers[j] != key[j] && Data[i].Answers[j] != 'X')
                score -= 1;
        }
        if (score < 0)
            score = 0;

        cout << endl;
        char grade = testScore(score);
        cout << "Grade: " << grade << endl << endl;
    }
}

int main()
{
    ifstream inFile;
    inFile.open("historytest.txt");

    // Read the correct answers first
    inFile >> key;
    int iter = 0;

    while (!inFile.eof()) {
        if(inFile >> Data[iter].ID) {
            inFile >> Data[iter].Answers;
        }
        iter++;
    }

    inFile.close();

    gradeTest();

    return 0;
}

