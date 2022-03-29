#include "klotski.h"

namespace KlotskiGame
{ /* Klotski MEMBER FUNCTIONS */
    Klotski::Klotski()
    {
        initialize(); // initialzing the board
    }

    /**
     * This function takes in a string of the form "number direction" and moves the number in the direction
     * specified
     *
     * @param move the move that the user wants to make
     *
     * @return Nothing is being returned.
     */
    void Klotski::playUser(string move)
    {

        /* The above code is checking if the input is valid or not. */
        if (check_input(move))
        {
            cout << "\n\nINVALID INPUT!!\n";
            return;
        }

        /* The above code is checking if the move is valid or not. */
        if (check_move(move))
        {
            cout << "\n\nINVALID MOVE!!\n";
            return;
        }

        int number = move[0] - '0';
        int i, k, temp;

        /* This code is moving the number in the board to the left or up. */
        for (i = 1; i < 6; i++)
        { // until row
            for (k = 1; k < 5; k++)
            { // until column
                if (board[i][k] == number)
                {
                    if (move[1] == 'L' || move[1] == 'l')
                    { // if left
                        temp = board[i][k - 1];
                        board[i][k - 1] = board[i][k];
                        board[i][k] = temp;
                    }
                    else if (move[1] == 'U' || move[1] == 'u')
                    { // if up
                        temp = board[i - 1][k];
                        board[i - 1][k] = board[i][k];
                        board[i][k] = temp;
                    }
                }
            }
        }

        /* This code is moving the number in the board to the right or down. */
        for (i = 5; i >= 1; i--)
        { // until row
            for (k = 4; k >= 1; k--)
            { // until column
                if (board[i][k] == number)
                {
                    if (move[1] == 'R' || move[1] == 'r')
                    { // if right
                        temp = board[i][k + 1];
                        board[i][k + 1] = board[i][k];
                        board[i][k] = temp;
                    }

                    else if (move[1] == 'D' || move[1] == 'd')
                    { // if down
                        temp = board[i + 1][k];
                        board[i + 1][k] = board[i][k];
                        board[i][k] = temp;
                    }
                }
            }
        }
        move_num++;
    }

    /**
     * The function plays a random move on the board.
     */
    void Klotski::playAuto()
    {

        string directions = "LlRrUuDd";
        string nums = "0123456789";

        bool legal_move = true;
        char direction, numLet;
        string autoMove;
        int i, k, number, temp;

        /* The above code is generating a random move and checking if it is legal or not. */
        while (legal_move)
        { // checking if move is legal or not
            autoMove = "";
            numLet = nums[rand() % 10];         // random number
            direction = directions[rand() % 8]; // rand direction
            autoMove += numLet;
            autoMove += direction;
            legal_move = check_move(autoMove);
        }

        // making the move
        playUser(autoMove);
    }

    /**
     * Prints the board
     */
    void Klotski::print() const
    {
        int i, k;

        sleep_until(system_clock::now() + nanoseconds(5));

        // printing the board

        cout << "-----------\n";
        for (i = 1; i < 6; i++)
        {
            for (k = 1; k < 5; k++)
            {

                if (k != 4)
                {
                    if (board[i][k] != -5)
                    {
                        cout << board[i][k] << "  ";
                    }
                    else
                    {
                        cout << "   ";
                    }
                }
                else
                {
                    if (board[i][k] != -5)
                    {
                        cout << board[i][k];
                    }
                    else
                    {
                        cout << " ";
                    }
                }
            }
            cout << "\n\n";
        }
        cout << "---     ----\n";
    }

    /**
     * If the user input is not a valid move, return true
     *
     * @param userInput the user's input
     *
     * @return Nothing.
     */
    bool Klotski::check_input(string userInput)
    {
        string directions = "LlRrUuDd";

        /* This is checking if the input is valid or not. */
        if (userInput.size() == 2)
        { // check input size
            if ((userInput[0] >= '0' && userInput[0] <= '9'))
            { // check input
                for (int i = 0; i < directions.size(); i++)
                {
                    if (userInput[1] == directions[i])
                        return false;
                }
            }
        }

        return true;
    }

    /**
     * If the move is valid, return true. Otherwise, return false
     *
     * @param move a string that represents the move to be made.
     *
     * @return A boolean value.
     */
    bool Klotski::check_move(string move)
    {

        int number = move[0] - '0';
        int i, k;
        bool check = false;

        for (i = 1; i < 6; i++)
        {
            for (k = 1; k < 5; k++)
            {
                if (board[i][k] == number)
                {
                    if (move[1] == 'L' || move[1] == 'l')
                    { // if left
                        if (board[i][k - 1] != number && board[i][k - 1] != -5)
                        {
                            check = true;
                        }
                    }
                    else if (move[1] == 'R' || move[1] == 'r')
                    { // if right
                        if (board[i][k + 1] != number && board[i][k + 1] != -5)
                        {
                            check = true;
                        }
                    }
                    else if (move[1] == 'U' || move[1] == 'u')
                    { // if up
                        if (board[i - 1][k] != number && board[i - 1][k] != -5)
                        {
                            check = true;
                        }
                    }
                    else if (move[1] == 'D' || move[1] == 'd')
                    { // if down
                        if (board[i + 1][k] != number && board[i + 1][k] != -5)
                        {
                            check = true;
                        }
                    }
                }
            }
        }

        return check;
    }

    /**
     *check if the game is finished or not
     *
     * @return a boolean value.
     */
    bool Klotski::isFinished()
    {

        // check if the game has finished
        if (board[4][2] == 1 && board[4][3] == 1)
        {
            if (board[5][2] == 1 && board[5][3] == 1)
            {
                return false;
            }
        }
        return true;
    }

    /**
     * The function returns the number of moves made by the player
     *
     * @return The number of moves made by the player.
     */
    int Klotski::boardScore()
    {
        return move_num;
    }

    /* Initializing the board. */
    void Klotski::initialize()
    {

        // initialazing the board

        int i, k;
        board.resize(7, vector<int>(6, -1));
        for (i = 1; i < 6; i++)
        {

            for (k = 1; k < 5; k++)
            {
                switch (i)
                {

                case 1:
                    switch (k)
                    { // for first row
                    case 1:
                        board[i][k] = 0;
                        break;
                    case 2:
                        board[i][k] = 1;
                        break;
                    case 3:
                        board[i][k] = 1;
                        break;
                    case 4:
                        board[i][k] = 2;
                        break;
                    }
                    break;
                case 2:
                    switch (k)
                    { // for second row
                    case 1:
                        board[i][k] = 0;
                        break;
                    case 2:
                        board[i][k] = 1;
                        break;
                    case 3:
                        board[i][k] = 1;
                        break;
                    case 4:
                        board[i][k] = 2;
                        break;
                    }
                    break;
                case 3: // for third row
                    switch (k)
                    {
                    case 1:
                        board[i][k] = 3;
                        break;
                    case 2:
                        board[i][k] = 4;
                        break;
                    case 3:
                        board[i][k] = 4;
                        break;
                    case 4:
                        board[i][k] = 5;
                        break;
                    }
                    break;
                case 4: // for fourth row
                    switch (k)
                    {
                    case 1:
                        board[i][k] = 3;
                        break;
                    case 2:
                        board[i][k] = 6;
                        break;
                    case 3:
                        board[i][k] = 7;
                        break;
                    case 4:
                        board[i][k] = 5;
                        break;
                    }
                    break;
                case 5: // for fifth row
                    switch (k)
                    {
                    case 1:
                        board[i][k] = 8;
                        break;
                    case 2:
                        board[i][k] = -5;
                        break;
                    case 3:
                        board[i][k] = -5;
                        break;
                    case 4:
                        board[i][k] = 9;
                        break;
                    }
                    break;
                }
            }
        }
    }
}