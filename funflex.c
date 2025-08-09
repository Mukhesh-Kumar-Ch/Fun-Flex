#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int snakes(int a)
{
    int down[][2] = {{25, 5}, {34, 1}, {47, 19}, {65, 52}, {87, 57}, {91, 61}, {99, 69}};
    for (int i = 0; i < 7; i++)
    {
        if (a == down[i][0])
        {
            printf("Oops!! You are bitten by a snake due to which you have fallen from %d to %d\n", down[i][0], down[i][1]);
            a = down[i][1];
            return a;
        }
    }
    return a;
}
int ladders(int a)
{
    int up[][2] = {{3, 51}, {6, 27}, {20, 70}, {36, 55}, {63, 95}, {68, 98}};
    for (int i = 0; i < 6; i++)
    {
        if (a == up[i][0])
        {
            printf("Congratulations!! You got a chance to climb a ladder from %d to %d\n", up[i][0], up[i][1]);
            a = up[i][1];
            return a;
        }
    }
    return a;
}
void displayHangman(int a, char clue1[])
{
    switch (a)
    {
    case 0:
        printf("  +---+\n      |\n      |\n      |\n     ===\n");
        printf("%s", clue1);
        break;
    case 1:
        printf("  +---+\n  O   |\n      |\n      |\n     ===\n");
        break;
    case 2:
        printf("  +---+\n  O   |\n  |   |\n      |\n     ===\n");
        break;
    case 3:
        printf("  +---+\n  O   |\n /|   |\n      |\n     ===\n");
        break;
    case 4:
        printf("  +---+\n  O   |\n /|\\  |\n      |\n     ===\n");
        break;
    case 5:
        printf("  +---+\n  O   |\n /|\\  |\n /    |\n     ===\n");
        break;
    case 6:
        printf("  +---+\n  O   |\n /|\\  |\n / \\  |\n     ===\n");
        break;
    }
}
int main()
{
    printf("                           ****** *      * *    *        ******* *      ****** *   *    \n");
    printf("                           *      *      * * *  *        *       *      *       * *     \n");
    printf("                           *****  *      * *  * *        *****   *      ****     *      \n");
    printf("                           *      *      * *   **        *       *      *       *  *    \n");
    printf("                           *       ******  *    *        *       ****** ****** *    *   \n");
    printf("Welcome to the ultimate hub of fun and excitement!\n");
    printf("Dive in and explore a world where you get to choose your favorite game.\n");
    printf("Your adventure starts here!\n");
    printf("Here are 4 games to play..\n");
    printf("Once a game is completed,you are directed to menu where you can choose the next plan of action..\n");
    goto menu;
menu:
    printf("Enter 1 to play Truth Or Dare...\n");
    printf("Enter 2 to play Hangman..\n");
    printf("Enter 3 to play Tic Tac Toe...\n");
    printf("Enter 4 to play Snakes and Ladders...\n");
    printf("Enter any other character to quit..\n");
    int g;
    scanf("%d", &g);
    if (g == 1)
    {
        printf("         ********   ******   ***     \n");
        printf("             *     *      *  *   *      \n");
        printf("             *     *      *  *    *    \n");
        printf("             *     *      *  *   *      \n");
        printf("             *    * ****** * ***      \n");
        printf("Persons are randomly chosen by the system..\n");
        printf("And the choice of truth or dare is also chosen by the system..\n");
        printf("The quests are to be discussed by the remaining players and should be given to the player who got the turn..\n");
    back:
        printf("Enter the number of players : \n");
        int z;
        if (z < 2)
        {
            printf("Less than 2 players cannot play this game..\n");
            printf("Enter the correct number of players..\n");
            goto back;
        }
        scanf("%d", &z);
        char name[z][100];
        for (int i = 0; i < z; i++)
        {
            printf("Enter the name of player %d:\n", i + 1);
            scanf("%s", name[i]);
        }
        int f;
        srand(time(0));
        for (int i = 0; i < 10000; i++)
        {
            f = rand() % z;
            int m = rand() % 2;
            printf("It is %s's turn:\n", name[f]);
            if (m == 0)
            {
                printf("It is a truth for you..\n");
            }
            if (m == 1)
            {
                printf("It is a dare for you..\n");
            }
            printf("Enter 1 to continue the game..\n");
            int y;
            scanf("%d", &y);
            if (y != 1)
            {
                printf("You chose to end the game..\n");
                printf("Hope you had a good time.. :)\n");
                break;
            }
        }
        goto menu;
    }
    else if (g == 2)
    {
        printf("Welcome to Hangman!\n");
        printf("                     *   *   *****  *   *  *****   *     *   *****  *   *\n");
        printf("                     *   *  *     * **  *  *       * * * *  *     * **  *\n");
        printf("                     *****  ******* * * *  *  **   *  *  *  ******* * * *\n");
        printf("                     *   *  *     * *  **  *   *   *     *  *     * *  *\n");
        printf("                     *   *  *     * *   *  *****   *     *  *     * *   *\n");
        printf("How to play:\n");
        printf("This is a group game\n");
        printf("One person in the group chooses a word and gives a clue about the word\n");
        printf("And the remaining players will try to guess the word\n");
        printf("Everybody gets their own chance to choose the word\n");
        printf("Rule:while entering the word to be guessed and letter while guessing lowerchase characters\n");
        printf("while guessing don't enter already entered letter \n");
        int ng;
        int numb;
    lab:
        printf("enter the number of people in ur group:\n");
        scanf("%d", &ng);
        int go = 1;
        if (ng <= 1)
        {
            printf("ERROR INVALID NUMBER OF PLAYERS\n");
            printf("Please enter a valid number\n");
            goto lab;
        }
        printf("Enter your names:\n");
        char names[ng][100];
        for (int i = 0; i < ng; i++)
        {
            printf("player%d:\n", i + 1);
            scanf("%s", names[i]);
        }
        while (go <= ng)
        {
            char word[50], clue1[50], let;
            printf("%s, enter a word to be guessed by your friends:\n", names[go - 1]);
            scanf("%s", word);
            printf("Enter the letter in your word that you want to display:\n");
            getchar();
            scanf("%c", &let);
            printf("Give any clue about the word to be guessed:\nclue:\n");
            getchar();
            fgets(clue1, sizeof(clue1), stdin);

            int len = strlen(word);
            char guess[len + 1];
            for (int i = 0; i < len; i++)
            {
                guess[i] = (word[i] == let) ? word[i] : '_';
            }
            guess[len] = '\0';

            int ah = 0;
            char letter;
            int coun;

            while (ah < 6)
            {
                coun = 0;
                displayHangman(ah, clue1);
                printf("Word: %s \n", guess);
                printf("Guess a letter: \n");
                scanf(" %c", &letter);

                for (int i = 0; i < len; i++)
                {
                    if (word[i] == letter && guess[i] == '_')
                    {
                        guess[i] = letter;
                        coun = 1;
                    }
                }
                if (!coun)
                {
                    ah++;
                }
                if (strcmp(word, guess) == 0)
                {
                    printf("Congratulations! You guys guessed the word: %s  \n", word);
                    break;
                }
            }

            if (ah == 6)
            {
                displayHangman(ah, clue1);
                printf("Game Over! The word was: %s \n", word);
            }
            go += 1;
        }
    }
    else if (g == 3)
    {
        printf("         *   *      *********** *********** ***********         ********                       \n");
        printf("          * *            *           *           *             *        *               \n");
        printf("           *             *           *           *             *        *               \n");
        printf("          * *            *           *           *             *        *               \n");
        printf("         *   *           *     *     *     *     *              ********                       \n  ");
        int p = 0, r, c, count;
        char a[100][100];
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                a[i][j] = '*';
            }
        }
        char p1[100], p2[100];
        printf("player 1 enter your name:\n");
        scanf("%s", p1);
        printf("player 2 enter your name:\n");
        scanf("%s", p2);
        printf("%s you got 'X'\n", p1);
        printf("%s you got 'O'\n", p2);
        while (1)
        {
            if (p == 0)
            {
                p += 1;
                printf("%s it's your chance enter the row and column you want to put 'X'\n", p1);
                scanf("%d %d", &r, &c);
                r = r - 1;
                c = c - 1;
                if (a[r][c] != 'O' && a[r][c] == '*')
                    a[r][c] = 'X';
                else
                {
                    p -= 1;
                    printf("invalid position please enter another position\n");
                    continue;
                }
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        printf("%c", a[i][j]);
                    }
                    printf("\n");
                }
                if ((a[r][c - 1] == 'X' && a[r][c + 1] == 'X') || (a[r + 1][c] == 'X' && a[r - 1][c] == 'X') || (a[r - 1][c - 1] == 'X' && a[r + 1][c + 1] == 'X') || (a[r + 1][c - 1] == 'X' && a[r - 1][c + 1] == 'X'))
                {
                    printf("%s congragulations you have won the game \n", p1);
                    break;
                }
                else if ((a[r - 1][c] == 'X' && a[r - 2][c] == 'X') || (a[r - 1][c + 1] == 'X' && a[r - 2][c + 2] == 'X') || (a[r][c + 1] == 'X' && a[r][c + 2]) || (a[r + 1][c + 1] == 'X' && a[r + 2][c + 2] == 'X') || (a[r + 1][c] == 'X' && a[r + 2][c] == 'X') || (a[r + 1][c - 1] == 'X' && a[r + 2][c - 2] == 'X') || (a[r][c - 1] == 'X' && a[r][c - 2] == 'X') || (a[r + 1][c - 1] == 'X' && a[r + 2][c - 2] == 'X'))
                {
                    printf("%s congragulations you have won the game \n", p1);
                    break;
                }
            }
            else
            {
                p -= 1;
                printf("%s it's your chance enter the row and column you want to put 'O'\n", p2);
                scanf("%d %d", &r, &c);
                r = r - 1;
                c = c - 1;
                if (a[r][c] != 'X' && a[r][c] == '*')
                    a[r][c] = 'O';
                else
                {
                    p += 1;
                    printf("invalid position please enter another position\n");
                    continue;
                }
                for (int i = 0; i < 3; i++)
                {
                    for (int j = 0; j < 3; j++)
                    {
                        printf("%c", a[i][j]);
                    }
                    printf("\n");
                }
                if ((a[r][c - 1] == 'O' && a[r][c + 1] == 'O') || (a[r + 1][c] == 'O' && a[r - 1][c] == 'O') || (a[r - 1][c - 1] == 'O' && a[r + 1][c + 1] == 'O') || (a[r + 1][c - 1] == 'O' && a[r - 1][c + 1] == 'O'))
                {
                    printf("%s congragulations you have won the game \n", p2);
                    break;
                }
                else if ((a[r - 1][c] == 'O' && a[r - 2][c] == 'O') || (a[r - 1][c + 1] == 'O' && a[r - 2][c + 2] == 'O') || (a[r][c + 1] == 'O' && a[r][c + 2]) || (a[r + 1][c + 1] == 'O' && a[r + 2][c + 2] == 'O') || (a[r + 1][c] == 'O' && a[r + 2][c] == 'O') || (a[r + 1][c - 1] == 'O' && a[r + 2][c - 2] == 'O') || (a[r][c - 1] == 'O' && a[r][c - 2] == 'O') || (a[r + 1][c - 1] == 'O' && a[r + 2][c - 2] == 'O'))
                {
                    printf("%s congragulations you have won the game  \n", p2);
                    break;
                }
            }
            count = 0;
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    if (a[i][j] == '*')
                        count++;
                }
            }
            if (count == 0)
            {
                printf("Nobody won it is a draw...\n");
                break;
            }
        }
        goto menu;
    }
    else if (g == 4)
    {
        printf("                    /--/        *****         *      *                *            \n");
        printf("                   /--/        *             * *     *                 *             \n");
        printf("                  /--/          *****       *****    *                *             \n");
        printf("                 /--/                *     *     *   *                 *             \n");
        printf("                /--/            *****   * *       ** *******          *            \n");
        printf("In this game the person who reaches 100 first,wins..\n");
        printf("If one of the players wins the game ends...\n");
        printf("The palyer gets a chance to roll the die if and only if he or she gets 6..\n");
        printf("In this game snakes decends you to lower level whereas ladder accelerates your position..\n");
        printf("Snakes are present at :\n");
        printf("25 which decends you to 5;\n");
        printf("34 which decends you to 1;\n");
        printf("47 which decends you to 19;\n");
        printf("65 which decends you to 52;\n");
        printf("87 which decends you to 57;\n");
        printf("91 which decends you to 61;\n");
        printf("99 which decends you to 69;\n");
        printf("Ladders are present at :\n");
        printf("3 which take you to 51\n");
        printf("6 which take you to 27\n");
        printf("20 which take you to 70\n");
        printf("36 which take you to 55\n");
        printf("63 which take you to 95\n");
        printf("68 which take you to 98\n");
        int q;
        printf("Enter the number of players :\n");
        scanf("%d", &q);
        char nam[q][100];
        for (int i = 0; i < q; i++)
        {
            printf("Enter the name of player %d:\n", i + 1);
            scanf("%s", nam[i]);
        }
        srand(time(0));
        int pos[q];
        for (int i = 0; i < q; i++)
        {
            pos[i] = 0;
        }
        for (int i = 0; i < q; i++)
        {
        label:
            printf("Please roll the die %s\n", nam[i]);
            printf("Enter any number to roll the die %s\n", nam[i]);
            int n;
            scanf("%d", &n);
            if (n / 1 == n)
            {
                int b = rand() % 6;
                pos[i] += b + 1;
                printf("You rolled a %d %s\n", b + 1, nam[i]);
                if (pos[i] > 100)
                {
                    pos[i] -= b + 1;
                }
                else if (pos[i] == 100)
                {
                    printf("Congratulations %s!! You are the winner of this game!!", nam[i]);
                    break;
                }
                pos[i] = snakes(pos[i]);
                pos[i] = ladders(pos[i]);
                printf("%s is now at %d\n", nam[i], pos[i]);
                if (b + 1 == 6)
                {
                    printf("Since you rolled a 6 you won another chance to roll a die %s\n", nam[i]);
                    goto label;
                }
                else
                {
                    if (pos[i] < 100 && i == q - 1)
                    {
                        i = -1;
                    }
                }
            }
            else
            {
                printf("You have entered invalid type..\n");
                printf("Hence the game is ended..\n");
                break;
            }
        }
        goto menu;
    }
    else
    {
        goto end;
    }
end:
    printf("You have chose to exit from Fun Flex..\n");
    printf("Hope you had a good time.. :)\n");
    return 0;
}