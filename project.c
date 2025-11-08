#include <stdio.h>

// Function declarations
void drawBoard(char board[3][3]);
int checkWinner(char board[3][3]);
int isFull(char board[3][3]);

int main() {
    char board[3][3] = { {'1','2','3'},
                         {'4','5','6'},
                         {'7','8','9'} };
    int choice, row, col, turn = 0, winner = 0;
    char mark;

    printf("=== TIC TAC TOE ===\n");
    printf("Player 1: X | Player 2: O\n");

    while (!winner && !isFull(board)) {
        drawBoard(board);
        mark = (turn % 2 == 0) ? 'X' : 'O';
        printf("Player %d (%c), enter your move (1-9): ", (turn % 2) + 1, mark);
        scanf("%d", &choice);

        // Convert choice to row & column
        row = (choice - 1) / 3;
        col = (choice - 1) % 3;

        // Check if move is valid
        if (choice < 1 || choice > 9 || board[row][col] == 'X' || board[row][col] == 'O') {
            printf("❌ Invalid move! Try again.\n");
        } else {
            board[row][col] = mark;
            winner = checkWinner(board);
            turn++;
        }
    }

    drawBoard(board);

    if (winner == 1)
        printf("🎉 Player %d (%c) WINS!\n", (turn % 2 == 0) ? 2 : 1, (turn % 2 == 0) ? 'O' : 'X');
    else
        printf("😐 It's a DRAW!\n");

    return 0;
}

// Draw the game board
void drawBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < 2)
            printf("---|---|---\n");
    }
    printf("\n");
}

// Check for a winner
int checkWinner(char board[3][3]) {
    // Rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
            return 1;
    }
    // Diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;

    return 0;
}

// Check if board is full (draw)
int isFull(char board[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O')
                return 0;
    return 1;
}