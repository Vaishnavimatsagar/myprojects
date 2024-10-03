#include <iostream>

using namespace std;

char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
char current_marker;
int current_player;

void drawBoard() {
    cout << "-------------\n";
    for (int i = 0; i < 3; i++) {
        cout << "| ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " | ";
        }
        cout << "\n-------------\n";
    }
}

bool placeMarker(int slot) {
    int row = (slot - 1) / 3;
    int col = (slot - 1) % 3;
    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = current_marker;
        return true;
    } else {
        return false;
    }
}

int checkWin() {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return current_player;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return current_player;
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return current_player;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return current_player;

    return 0;
}

bool checkDraw() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return false;
        }
    }
    return true;
}

void switchPlayer() {
    current_player = (current_player == 1) ? 2 : 1;
    current_marker = (current_marker == 'X') ? 'O' : 'X';
}

void game() {
    cout << "Player 1, choose your marker (X or O): ";
    char marker_p1;
    cin >> marker_p1;

    current_player = 1;
    current_marker = marker_p1;
    char marker_p2 = (marker_p1 == 'X') ? 'O' : 'X';

    drawBoard();

    int player_won;
    while (true) {
        int slot;
        cout << "Player " << current_player << "'s turn. Enter your slot: ";
        cin >> slot;

        if (slot < 1 || slot > 9) {
            cout << "Invalid slot! Please choose a slot between 1 and 9.\n";
            continue;
        }

        if (!placeMarker(slot)) {
            cout << "Slot already taken! Try again.\n";
            continue;
        }

        drawBoard();

        player_won = checkWin();
        if (player_won != 0) {
            cout << "Player " << player_won << " wins!\n";
            break;
        }

        if (checkDraw()) {
            cout << "It's a draw!\n";
            break;
        }

        switchPlayer();
    }
}

int main() {
    char playAgain;
    do {
        // Reset board
        char initialBoard[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
        copy(&initialBoard[0][0], &initialBoard[0][0] + 9, &board[0][0]);

        game();

        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
