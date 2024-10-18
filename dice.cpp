#include <iostream>
#include <cstdlib> 
#include <ctime>   
using namespace std;

int rollDice() {
    return (rand() % 6) + 1;
}

int main() {
    srand(time(0)); 
    int player1_dice1, player1_dice2;
    int player2_dice1, player2_dice2;
    char playAgain = 'y';

    while (playAgain == 'y' || playAgain == 'Y') {
        player1_dice1 = rollDice();
        player1_dice2 = rollDice();
        int player1_sum = player1_dice1 + player1_dice2;
        cout << "Player 1 rolled: " << player1_dice1 << " and " << player1_dice2 << " (Sum = " << player1_sum << ")" << endl;

        player2_dice1 = rollDice();
        player2_dice2 = rollDice();
        int player2_sum = player2_dice1 + player2_dice2;
        cout << "Player 2 rolled: " << player2_dice1 << " and " << player2_dice2 << " (Sum = " << player2_sum << ")" << endl;
      
        if (player1_sum > player2_sum) {
            cout << "Player 1 wins!" << endl;
        } else if (player1_sum < player2_sum) {
            cout << "Player 2 wins!" << endl;
        } else {
            cout << "It's a draw!" << endl;
        }
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    }

    cout << "Thanks for playing!" << endl;

    return 0;
}
