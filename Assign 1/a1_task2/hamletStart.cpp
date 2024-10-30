/* The program allows users to find and report the frequency 
 * of a specific word within the text of "Hamlet." 
 * The program prompts the user to enter a word, 
 * reads the text from the "hamlet.txt" file, and searches
 * for occurrences of the word within the words of the text. 
 * It then displays the total number of words searched and the count 
 * of how many times the word was found within those words. */

#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std; 

//function protoype here
void countWordFrequency(ifstream& inData, const string& word, int& total_words, int& word_count);

int main() {
    string word {}; 
    cout << endl; 
    cout << "Hi there! this outputs the number of times"<< endl <<  "a word              appears in Hamlet by William Shakespeare" << endl; 
    cout << endl;
    cout << "Please enter the word to search for:" << endl;
    cin >> word;
    //convert input to lowercase for comparison
    string unchanged_word = word;
    transform(word.begin(), word.end(), word.begin(), ::tolower);
    
    // open file
    ifstream inData;
    ofstream outData;

    inData.open("hamlet.txt");
    
    // check file is successfully open 
    if (!inData)
       {
       cerr << "** Problem: cannot open hamlet.txt, ending program."
	    << endl;
       return 1;
       }

    // read file 
    
    int total_words = 0;
    int word_count = 0;
    // call function to find the word provided by the user
    countWordFrequency(inData, word, total_words, word_count);
    
    // close file
    inData.close();    

    // output to the console the total number of words searched, the word provided by the user and the number of occurrences of that word in the file
    cout << total_words << " words were searched and the word " << unchanged_word << " was found " << word_count << " times." << endl;
   
    return 0;  
}

    // implement function 
void countWordFrequency(ifstream& inData, const string& word, int& total_words, int& word_count) {
    string current_word;
    
    while (inData >> current_word) {
        // Convert to lowercase for comparison
        transform(current_word.begin(), current_word.end(), current_word.begin(), ::tolower);

        // Check for exact word or hyphenated version
        total_words++;
        if (current_word == word || 
            (current_word.find(word + "-") != string::npos) ){
            word_count++;
        }
    }
}