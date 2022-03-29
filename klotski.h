#ifndef KLOTSKI_H
#define KLOTSKI_H

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <string>

using namespace std::this_thread;
using namespace std::chrono;
using namespace std;

namespace KlotskiGame
{

    class Klotski
    {
    public:
        /* Default constructer */
        Klotski();

        /*playUser takes a string as a parameterand plays the game accordingly */
        void playUser(string move);

        /* playAuto plays the game by the computerfor one move. */
        void playAuto();

        /* prints the game on the screen starting from the top left corner of the terminal. */
        void print() const;

        /* isFinished returns true if the game is ended. */
        bool isFinished();

        /* Checking if the move input is valid or not. */
        bool check_input(string userInput);

        /* Checking if the move is valid or not. */
        bool check_move(string move);

        /* boardScore returns an int score value for the current board */
        int boardScore();

        /* initializes the board.  */
        void initialize();

    private:
        vector<vector<int>> board;
        int move_num = 0;
    };

}

#endif // KLOTSKI_H