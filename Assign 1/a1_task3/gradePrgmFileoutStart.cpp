#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

void ruler() {
    //  outFile << "\n12345678901234567890123456789012345678901234567890123456789012345678901234567890" << endl;
}

int main() {
    std::ifstream file("QuizResponses.txt");
    std::ofstream outFile("newFile.txt");
    const int total_width{33};
    const int column_width{11};
    string answer_key;
    string line;
    bool is_employee_ID = true;
    std::vector<int> scores;
    // ruler();

    //title
    string title = "Employee Quiz Responses";

    int title_length = title.length();
    outFile << setw((total_width - title_length )/ 2) << "" << title;

    //headers
    outFile << endl;
    outFile << setw(column_width) << left << "Employee ID"  
                   << setw(column_width) << left << "   Score"
                   << setw(column_width) << right << "Redo Quiz  "
                   << endl;

    outFile << setw(total_width)
                << setfill('-')
                << ""
                << endl;   // display total_width dashes
    outFile << setfill(' ');

    //get first line as answer key
    std::getline(file, answer_key);

    //parse each line
    int line_num = 1;
    while (std::getline(file, line)) {
            // empty  lines get ignored
            if (line.empty()) {
                continue;
            }

            //looking for employee id
            if (is_employee_ID){
                outFile << line_num << " ";
                outFile << setw(column_width) << left << line;
                line_num++;
                is_employee_ID = false; //set flag to false
            } else{ //test score line
            string response = line;
            int correct_answers = 0;
            for (size_t i = 0; i < response.length() && i < answer_key.length(); ++i) {
                //checking to see if they filled out all answers
                if (response.length() < 5){
                    correct_answers = -1;
                }
                //incrementing score
                if (response[i] == answer_key[i]) {
                    correct_answers++;
                }
            }
            //adding scores to vector to compute average
            if (correct_answers == -1){
                scores.push_back(0);
            } else{
                scores.push_back(correct_answers);
            }

            //printing to centre of column
            outFile << std::setw(((column_width - std::to_string(correct_answers).length()) / 2) - 2) << "";
            outFile << std::setw(std::to_string(correct_answers).length()) << std::left << correct_answers;
            outFile << std::setw((column_width - std::to_string(correct_answers).length()) / 2) << "";

            string redo_quiz = (correct_answers < 3) ? "yes" : "no";
            outFile << std::setw(column_width);
            outFile << std::setw((column_width - redo_quiz.length()) / 2) << "";
            outFile << std::left << redo_quiz;
            outFile << std::setw((column_width - redo_quiz.length()) / 2) << "";
            outFile << endl;

            is_employee_ID = true;
        }
    }

    outFile << setw(total_width)
                << setfill('-')
                << ""
                << endl;  
    outFile << setfill(' ');

    //compute average
    int sum = 0;
    for (int num : scores) {
        sum += num;
    }

    double average = static_cast<double>(sum) / scores.size();
    outFile << std::fixed << std::setprecision(2);
    outFile << "Average        " << average << std::endl;

    return 0;
}