#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void gameIntro() {
    cout << "Let's play a Rock Paper Scissor game!\n";
    cout << "Choose your weapon! Type: r for Rock; p for Paper; s for Scissor....\n";
    cout << "Press 'q' to quit the game\n";
}

int main() {
    const char r = 'r';
    const char s = 's';
    const char p = 'p';
    const char q = 'q';
    char PlayerMove;
    char BotMove;
    string PlayerInput;
    
    int PlayerScore = 0;  // Initialize scores to 0
    int BotScore = 0;
    bool playAgain = true;  // Control game loop
    
    // Call the intro function
    gameIntro();
    
    // Main game loop
    while (playAgain) {
        // Get player's move
        cout << "\nCurrent Score - You: " << PlayerScore << " Bot: " << BotScore << endl;
        cout << "Enter your move: ";
        cin >> PlayerInput;
        
        // Check if player wants to quit
        if (PlayerInput.length() == 1 && tolower(PlayerInput[0]) == q) {
            playAgain = false;
            continue;
        }
        
        // Input validation loop
        while (PlayerInput.length() != 1 || 
               (PlayerInput[0] != r && PlayerInput[0] != p && PlayerInput[0] != s)) {
            cout << "Please enter r for Rock or p for Paper or s for Scissor" << endl;
            cin >> PlayerInput;
            
            // Check for quit during validation
            if (PlayerInput.length() == 1 && tolower(PlayerInput[0]) == q) {
                playAgain = false;
                break;
            }
        }
        
        // If player chose to quit during validation
        if (!playAgain) {
            continue;
        }
        
        PlayerMove = tolower(PlayerInput[0]);
        
        // Generate bot's move
        srand(time(NULL));
        int num = rand() % 3 + 1;
        
        if (num == 1) {
            BotMove = 'r';
        } else if (num == 2) {
            BotMove = 's';
        } else {
            BotMove = 'p';
        }
        
        // Display moves
        cout << "Your move: " << PlayerMove << endl;
        cout << "Bot's move: " << BotMove << endl;
        
        // Determine winner
        if (PlayerMove == r && BotMove == p) {
            cout << "You lose!" << endl;
            ++BotScore;
        } else if (PlayerMove == r && BotMove == s) {
            cout << "You win!" << endl;
            ++PlayerScore;
        } else if (PlayerMove == p && BotMove == s) {
            cout << "You lose!" << endl;
            ++BotScore;
        } else if (PlayerMove == p && BotMove == r) {
            cout << "You win!" << endl;
            ++PlayerScore;
        } else if (PlayerMove == s && BotMove == r) {
            cout << "You lose!" << endl;
            ++BotScore;
        } else if (PlayerMove == s && BotMove == p) {
            cout << "You win!" << endl;
            ++PlayerScore;
        } else {
            cout << "It's a tie!" << endl;
        }
    }
    
    // Display final score when game ends
    cout << "\nFinal Score:" << endl;
    cout << "You: " << PlayerScore << endl;
    cout << "Bot: " << BotScore << endl;
    if (PlayerScore > BotScore) {
        cout << "Congratulations! You won the game!" << endl;
    } else if (BotScore > PlayerScore) {
        cout << "Better luck next time! Bot wins!" << endl;
    } else {
        cout << "It's a tie game!" << endl;
    }
    
    return 0;
}
