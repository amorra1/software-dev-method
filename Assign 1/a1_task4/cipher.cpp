// Substitution Cipher

#include <iostream>
#include <string>
#include <cstring>
using namespace std;


int main() {
    
    string alphabet {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    string key      {"XZNLWEBGJHQDYVTKFUOMPCIASRxznlwebgjhqdyvtkfuompciasr"};

    // insert your code here
    std::string word {}; 
    cout << endl;
    cout << "Hi there! this encrypts your text using a cipher" << endl; 
    cout << endl;
    cout << "Please enter text to encrypt:" << endl;
    getline (cin, word);

    //encrypt the text input
    string encrypted_text{};
    for (char c : word){
        for (int j = 0; j < alphabet.length(); j++){
            if (c == ' '){
                encrypted_text += ' ';
                break;
            } else if (c == alphabet[j]){
                encrypted_text += key[j];
                break;
            }
        }
    }

    cout << "Encrypted message: " << encrypted_text << endl;

    //decrypt text input
    string decrypted_text{};
    for (char c : encrypted_text){
        for (int i = 0; i < key.length(); i++){
            if (c == ' '){
                decrypted_text += ' ';
                break;
            } else if (c == key[i]){
                decrypted_text += alphabet[i];
                break;
            }
        }
    }

    cout << "Decrypted message: " << decrypted_text << endl;
    return 0;

}
