#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// Function to determine FLAMES result
string DetermineFlameResult(const string& Name1, const string& Name2){

// Convert names to uppercase for case-insensitive comparison
    string Name1upper = Name1;
    string Name2upper = Name2;
    transform(Name1upper.begin(), Name1upper.end(), Name1upper.begin(), ::toupper);
    transform(Name2upper.begin(), Name2upper.end(), Name2upper.begin(), ::toupper);

    string Name1remain = Name1upper;
    string Name2remain = Name2upper;
    for(char letter:Name1upper){
        size_t pos = Name1remain.find(letter);
         if (pos != string::npos) {
            Name2remain.erase(pos,1);
            Name1remain.erase(remove(Name1remain.begin(),Name1remain.end(),letter),Name1remain.end());
    }
}
    
// Step 3: Count remaining letters
    int lettersCount = Name1remain.length() + Name2remain.length();

// Step 4: Determine FLAMES
    string Flames = "FLAMES";
    while (Flames.length()>1){
        int remove = (lettersCount - 1) % Flames.length();
        Flames.erase(remove,1);
    }

// Step 5: Result
    char result = Flames[0];
    switch (result) {
        case 'F':
            return "Friendship";
        case 'L':
            return "Love";
        case 'A':
            return "Affection";
        case 'M':
            return "Marriage";
        case 'E':
            return "Enemy";
        case 'S':
            return "Sibling";
        default:
            return "Invalid result";
    }
}

int main() {
    string Name1, Name2;

    cout << "Enter the first name: ";
    getline(cin, Name1);

    cout << "Enter the second name: ";
    getline(cin, Name2);

    string result = DetermineFlameResult(Name1, Name2);

    cout << "The relationship between " << Name1 << " and " << Name2 << " is: " << result << endl;

    return 0;
}
