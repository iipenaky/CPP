// Libraries imported
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to calculate the score of student
int calculateScore(string rightAnswers, string studentAnswers) {
    int score = 0;
    // Loop through student's answer and compare with the right answers
    for (int i = 0; i < rightAnswers.size(); i++) {
        // If answer is right, add 2
        if (studentAnswers[i] == rightAnswers[i]) {
            score += 2; 
        } 
        // If answer is lank, add nothing
        else if (studentAnswers[i] == ' ') {
            score += 0; 
        } 
        // If answer is wrong deduct 1
        else {
            score -= 1; 
        }
    }
    // return the score
    return score;
}

// Function to calculate the grade based on score
char getGrade(float percentage) {
    if (percentage >= 90) {
        return 'A';
    } else if (percentage >= 80) {
        return 'B';
    } else if (percentage >= 70) {
        return 'C';
    } else if (percentage >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}

// main function
int main() {
    // Open the file "testData.txt" for reading.
    ifstream inputFile("testData.txt"); 

    // Open the file "testDataScores.txt" for appending the students' scores and grades.
    ofstream outputFile("testDataScores.txt", ios::app);

    // Declare a string variable to store the correct answers.
    string rightAnswers;

    // Read the correct answers from the first line of the file.
    if (getline(inputFile, rightAnswers)) {
        cout << "Right Answers: " << rightAnswers << endl;
    } else {
        cerr << "Error: File is empty or could not read the first line." << endl;
        return 1;
    }

    // Declare a string variable to store each student's line of data (ID and answers).
    string line;

    // Loop through each line in the input file, which contains a student's ID and their answers.
    while (getline(inputFile, line)) {
        string ID = "";      
        string answers = ""; 

        bool spaceFound = false; // A flag to indicate the first space that separates ID from Answers

        // Loop through each character in the line to separate the ID from the answers.
        for (char c : line) {
            if (c == ' ' && spaceFound == false) {
                // If the first space is found, set the flag to true.
                spaceFound = true;
            } else if (spaceFound == false) {
                // Before the space is found, add characters to the ID.
                ID += c;
            } else if (spaceFound == true) {
                // After the space is found, add characters to the answers.
                answers += c;
            }
        }

        // Calculate the score by comparing the student's answers to the correct answers.
        int score = calculateScore(rightAnswers, answers);

        // Calculate the percentage score.
        float percentage = score / float(40) * 100;

        // Determine the grade based on the percentage.
        char grade = getGrade(percentage);

        // Output the student's ID, answers, score, and grade.
        cout << "Student ID : " << ID << "\n" 
             << "Student's answers: " << answers << "\n" 
             << "Student's score: " << score << "\n" 
             << "Student's grade: " << grade << "\n\n";

        // Write the student's ID, answers, score, and grade to the testDataScores file, followed by "EOD" for end of data.
        outputFile << "Student ID : " << ID << "\n" 
                   << "Student's answers: " << answers << "\n" 
                   << "Student's score: " << score << "\n" 
                   << "Student's grade: " << grade << "\n" 
                   << "EOD\n";
    }

    // Close the input file.
    inputFile.close(); 
    return 0;
}
