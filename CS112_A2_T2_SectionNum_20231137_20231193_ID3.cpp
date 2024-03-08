// Program: This code has 6 programs that the user is going to choose which one he wants to use
// Authors: Mohamed Ayman Fayz and he solved cipher 7 morse and his ID: 20231137
//          Nour Eldin Hany Mohamed and he solved cipher 3 do vingere his ID: 20231193
//          Jerome Nabil and he solved problem 2 and problem 3 his ID: 20231137
// Version: version 5
// Date:    25/2/2024




#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <cstring>
#include <cctype>
using namespace std;

// This function for do vingere cipher to check the input of the user
bool checkstring(const std::string &str)
{ // this function is used to check if input is string or not
    bool hasDecimalPoint = false;

    for (char ch : str)
    {
        if (!isdigit(ch))
        {
            if (ch == '.' && !hasDecimalPoint)
            {
                hasDecimalPoint = true;
            }
            else
            {
                return true;
            }
        }
    }

    return false;
}

void morse()
{

    while (true)
    {

        // Create a map of characters to string
        map<char, string> encrypt;

        // Insert morse values into the map
        encrypt[' '] = "   ";
        encrypt['A'] = ".-";
        encrypt['B'] = "-...";
        encrypt['C'] = "-.-.";
        encrypt['D'] = "-..";
        encrypt['E'] = ".";
        encrypt['F'] = "..-.";
        encrypt['G'] = "--.";
        encrypt['H'] = "....";
        encrypt['I'] = "..";
        encrypt['J'] = ".---";
        encrypt['K'] = "-.-";
        encrypt['L'] = ".-..";
        encrypt['M'] = "--";
        encrypt['N'] = "-.";
        encrypt['O'] = "---";
        encrypt['P'] = ".--.";
        encrypt['Q'] = "--.-";
        encrypt['R'] = ".-.";
        encrypt['S'] = "...";
        encrypt['T'] = "-";
        encrypt['U'] = "..-";
        encrypt['V'] = "...-";
        encrypt['W'] = ".--";
        encrypt['X'] = "-..-";
        encrypt['Y'] = "-.--";
        encrypt['Z'] = "--..";
        encrypt['0'] = "-----";
        encrypt['1'] = ".----";
        encrypt['2'] = "..---";
        encrypt['3'] = "...--";
        encrypt['4'] = "....-";
        encrypt['5'] = ".....";
        encrypt['6'] = "-....";
        encrypt['7'] = "--...";
        encrypt['8'] = "---..";
        encrypt['9'] = "----.";

        // Create a map of string to characters
        map<string, char> decrypt = {
            {".-", 'A'},
            {"-...", 'B'},
            {"-.-.", 'C'},
            {"-..", 'D'},
            {".", 'E'},
            {"..-.", 'F'},
            {"--.", 'G'},
            {"....", 'H'},
            {"..", 'I'},
            {".---", 'J'},
            {"-.-", 'K'},
            {".-..", 'L'},
            {"--", 'M'},
            {"-.", 'N'},
            {"---", 'O'},
            {".--.", 'P'},
            {"--.-", 'Q'},
            {".-.", 'R'},
            {"...", 'S'},
            {"-", 'T'},
            {"..-", 'U'},
            {"...-", 'V'},
            {".--", 'W'},
            {"-..-", 'X'},
            {"-.--", 'Y'},
            {"--..", 'Z'},
            {".----", '1'},
            {"..---", '2'},
            {"...--", '3'},
            {"....-", '4'},
            {".....", '5'},
            {"-....", '6'},
            {"--...", '7'},
            {"---..", '8'},
            {"----.", '9'},
            {"-----", '0'}};

        string result;
        string text;

        // Iterate through the Morse code string

        // Get an iterator pointing to the first element in the
        // map

        char choise;
        cout << "welcome to morse cipher." << endl;
        cout << "A)Encrypt your text to morse code\nB)Decrypt your morse code to text\nC)Exit" << endl;

        cin >> choise;
        if (choise == 'A' || choise == 'a')
        {
            string inp;
            cout << "enter phrase" << endl;
            cin.ignore(1, '\n');
            getline(cin, inp);

            transform(inp.begin(), inp.end(), inp.begin(), ::toupper);

            for (char i : inp)
            {
                cout << encrypt[i] << " ";
            }
            cout << endl;
        }
        else if (choise == 'B' || choise == 'b')
        {
            string inpp;
            cout << "enter morse code" << endl;
            cin.ignore(1, '\n');
            getline(cin, inpp);
            for (char c : inpp)
            {
                if (c == ' ')
                {
                    // Look up Morse code in the map and append corresponding character
                    if (!text.empty())
                    {
                        result += decrypt[text];
                        text.clear();
                    }
                    else
                    {
                        // If multiple consecutive spaces, append space
                        result += ' ';
                    }
                }
                else
                {
                    // Add characters until space
                    text += c;
                }
            }

            // Process the last Morse code sequence if any
            if (!text.empty())
            {
                result += decrypt[text];
            }
            cout << result << endl;
        }
        else if (choise == 'C' || choise == 'c')
        {

            break;
        }
        else
        {
            cout << "Error try again ";
        }
    }
}

void do_vingere_cipher()
{
    int choice;
    string rep_keyword;
    // to enter keyword to use in encryption
    cout << "Choose the keyword to be used: ";
    getline(cin, rep_keyword);
    // check if keyword string
    while (checkstring(rep_keyword) == false)
    {
        cout << "This is not a valid keyword. Enter again: ";
        getline(cin, rep_keyword);
    }
    // to enter what you want to do encryption or decryption
    cout << "Choose what you want to do:\n";
    cout << "1) Encryption\n"
         << "2) Decryption\n";
    cin >> choice;

    cin.ignore(); // i knew this function from google and it Clearing the newline character from the input buffer

    while (true)
    { // loop for encrption process by vingere cipher method
        // condtion if you want to encrypation
        if (choice == 1)
        {
            string word_cipher;
            cout << "Please enter the message you want to be encrypted: ";
            getline(cin, word_cipher);
            // check message is string
            while (checkstring(word_cipher) == false)
            {
                cout << "This is not a valid message. Enter again: ";
                getline(cin, word_cipher);
            }
            // to make all character captial
            for (auto &k : word_cipher)
            {
                k = toupper(k);
            }
            // to repeat keyword like length of message
            for (int i = 0; i < word_cipher.length(); i++)
            {
                rep_keyword += rep_keyword[i % rep_keyword.length()];
                rep_keyword[i] = toupper(rep_keyword[i]);
            }

            string encryptedmessage;
            for (int i = 0; i < word_cipher.length(); i++)
            {
                // condtion to not add digit or space and print them
                if (isspace(word_cipher[i]) || isdigit(word_cipher[i]))
                {
                    encryptedmessage.push_back(word_cipher[i]);
                }
                else
                {
                    // calculate and append characters that had been encrypted
                    int result = ((word_cipher[i] + rep_keyword[i]) % 26) + 'A';
                    encryptedmessage.push_back(result);
                }
            }

            cout << "The encrypted message is: " << encryptedmessage << endl;
            break;
        }
        // condtion if you want to decrypation
        else if (choice == 2)
        {
            string word_discipher;
            cout << "Please enter the message you want to be decrypted: ";
            getline(cin, word_discipher);
            // check message is string
            while (checkstring(word_discipher) == false)
            {
                cout << "This is not a valid message. Enter again: ";
                getline(cin, word_discipher);
            }
            // to captial all characters
            for (auto &k : word_discipher)
            {
                k = toupper(k);
            }
            // to repeat keyword like length of message
            for (int i = 0; i < word_discipher.length(); i++)
            {
                rep_keyword += rep_keyword[i % rep_keyword.length()];
                rep_keyword[i] = toupper(rep_keyword[i]);
            }

            string decryptedmessage;
            for (int i = 0; i < word_discipher.length(); i++)
            {
                // condtion to not add digit or space and print them
                if (isspace(word_discipher[i]) || isdigit(word_discipher[i]))
                {
                    decryptedmessage.push_back(word_discipher[i]);
                }
                else
                {
                    // calculate and append characters that had been decrypted
                    int result = ((word_discipher[i] - rep_keyword[i]) + 26) % 26 + 'A';
                    decryptedmessage.push_back(result);
                }
            }

            cout << "The decrypted message is: " << decryptedmessage << endl;
            break;
        }
        else
        { // condtion if you dont add any choices from up
            cout << "Invalid choice. Please enter 1 or 2." << endl;
            break;
        }
    }
}

void The_German_mathematician_Leibniz()
{
}

int main()
{
    cout << "\nHello and Welcome to our program" << endl;
    cout << "Here you have 3 ciphers to use\n"
         << endl;
    while (true)
    {
        cout << "\nJust select which cipher you want:" << endl;
        cout << "1) Morse cipher" << endl;
        cout << "2) Atbash Cipher" << endl;
        cout << "3) The German mathematician Leibniz(π)" << endl;
        cout << "4) Exit program" << endl;

        string choice;
        cin >> choice;

        if (choice == "1")
        { // To choose game 1
            morse();
        }
        else if (choice == "2")
        { // To choose game 2
            do_vingere_cipher();
        }
        else if (choice == "3")
        {
            The_German_mathematician_Leibniz();
        }
        else if (choice == "4")
        { // To choose exit
            cout << "Thanks for using our program " << endl;
            break;
        }
        else
        {
            cout << "Invalid choice, please enter a valid choice: " << endl;
        }
    }
    return 0;
}
