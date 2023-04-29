#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char board[3][3]; // Игровое поле

// Функция для отображения игрового поля
void display_board()
{
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("\n");
}

// Функция для проверки выигрыша
char check_win()
{
    int i;
    // Проверка строк
    for (i = 0; i < 3; i++)
    {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
        {
            return board[i][0];
        }
    }
    // Проверка столбцов
    for (i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
        {
            return board[0][i];
        }
    }
    // Проверка диагоналей
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
    {
        return board[0][2];
    }
    return ' ';
}

// Функция для хода игрока
void player_move(char symbol)
{
    int row, col;
    printf("Print the number of column and line ");
    scanf("%d%d", &row, &col);
    row--;
    col--;
    if (board[row][col] == ' ')
    {
        board[row][col] = symbol;
    }
    else
    {
        printf("Invalid move. Try again.\n");
        player_move(symbol);
    }
}


// Функция для хода компьютера
void computer_move(char symbol)
{
    int row, col;
    srand(time(NULL));
    do
    {
        row = rand() % 3;
        col = rand() % 3;
    } while (board[row][col] != ' ');
    board[row][col] = symbol;
}

// Основная функция игры
void play_game_vs_computer()
{
    char symbol = 'X';
    int turn;
    for (turn = 0; turn < 9 && check_win() == ' '; turn++)
    {
        if (turn % 2 == 0)
        {
            player_move(symbol);
        }
        else
        {
            computer_move(symbol);
        }
        display_board();
        symbol = symbol == 'X' ? 'O' : 'X';
    }
    char winner = check_win();
    if (winner == ' ')
    {
        printf("A draw!\n");
    }
    else
    {
        printf("%c won!\n", winner);
    }
} 

void play_game_vs_player()
{
    char symbol = 'X';
    int turn;
    for (turn = 0; turn < 9 && check_win() == ' '; turn++)
    {
        if (turn % 2 == 0)
        {
            printf("Player 1's turn.\n");
            player_move(symbol);
        }
        else
        {
            printf("Player 2's turn.\n");
            player_move(symbol);
        }
        display_board();
        symbol = symbol == 'X' ? 'O' : 'X';
    }
    char winner = check_win();
    if (winner == ' ')
    {
        printf("A draw!\n");
    }
    else
    {
        printf("%c won!\n", winner);
    }
}


// Главная функция
int main()
{
    int i, j;
    int mode = 0; // initialize mode to an invalid value

    // Инициализация игрового поля
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            board[i][j] = ' ';
        }
    }

    while (mode != 1 && mode != 2)
    {
        printf("Select the game mode: \n");
        printf("1. Play against the computer\n");
        printf("2. Play against another player\n");
        scanf("%d", &mode);

        if (mode != 1 && mode != 2)
        {
            printf("Wrong choice. Please choose 1 or 2.\n");
        }
    }

    if (mode == 1)
    {
        // Режим игры против компьютера
        display_board();
        play_game_vs_computer();
    }
    else if (mode == 2)
    {
        // Режим игры против другого игрока
        display_board();
        play_game_vs_player();
    }

    return 0;
}
