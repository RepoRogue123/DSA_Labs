#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

// Class to handle document editing operations
class DocEditor {
public:
    // Function to process the input and edit the document according to the rules
    void processInput() {
        char ch;
        string word;
        bool newSentence = true;
        bool lastWasSpace = false;

        // Read characters until EOF
        while (cin.get(ch)) {
            if (isSpace(ch)) {
                if (!lastWasSpace) {
                    handleWordBoundary(ch, word);
                }
                cout << ch;  // Ensure to print consecutive spaces
                lastWasSpace = true;
            } else if (isPunctuation(ch)) {
                handleWordBoundary(ch, word);
                cout << ch;  // Print punctuation directly
                newSentence = true;
                lastWasSpace = false;
            } else {
                if (newSentence && isalpha(ch)) {
                    ch = toupper(ch);
                    newSentence = false;
                }
                word += ch;
                lastWasSpace = false;
            }
        }
        handleWordBoundary(' ', word); // Process the last word
    }

private:
    // Function to check if the given word is an article
    bool isArticle(const string &word) {
        string lowercaseWord = word;
        transform(lowercaseWord.begin(), lowercaseWord.end(), lowercaseWord.begin(), ::tolower);
        return lowercaseWord == "a" || lowercaseWord == "an" || lowercaseWord == "the";
    }

    // Function to print the word, underlining articles with underscores
    void printWord(const string &word) {
        string processedWord = word;
        if (processedWord == "school" || processedWord == "School") {
            processedWord = "garden";
            if (isupper(word[0])) processedWord[0] = toupper(processedWord[0]);
        }

        if (isArticle(word)) {
            cout << "_" << processedWord << "_";
        } else {
            cout << processedWord;
        }
    }

    // Function to check if a character is a space
    bool isSpace(char ch) {
        return ch == ' ' || ch == '\t' || ch == '\n';
    }

    // Function to check if a character is a punctuation mark
    bool isPunctuation(char ch) {
        return ch == '.' || ch == '!' || ch == '?';
    }

    // Function to handle word boundaries and manage input characters
    void handleWordBoundary(char ch, string &word) {
        if (!word.empty()) {
            printWord(word);
            word.clear();
        }
    }
};

int main() {
    DocEditor editor;
    editor.processInput();
    return 0;
}
