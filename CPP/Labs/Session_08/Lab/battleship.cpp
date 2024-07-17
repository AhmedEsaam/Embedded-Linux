#include <iostream>
#include <cstdlib>
#include <time.h>
#include <vector>

class Battleship
{
public:
    Battleship(int maxGuesses) : m_maxGuesses(maxGuesses), m_guesses(0)
    {
        srand(time(0));

        for (int i = 0; i < 5; ++i)
        {
            for (int j = 0; j < 5; ++j)
            {
                m_board[i][j] = false;
            }
        }

        m_locationX = rand() % 5;
        m_locationY = rand() % 5;

        m_board[m_locationX][m_locationY] = true;

        std::cout << m_locationX << " " << m_locationY << std::endl;
    }

    bool guess(int x, int y)
    {
        if (x == m_locationX && y == m_locationY)
        {
            m_guesses++;
            std::cout << "You hit the battleship!" << std::endl;
            std::cout << "You won in " << m_guesses << " guesses!" << std::endl;
            return true;
        }
        else if (x == m_locationX)
        {
            m_guesses++;
            std::cout << "You missed! ... You have " << m_maxGuesses - m_guesses << " guesses left." << std::endl;
            std::cout << "You are in the same row as the battleship." << std::endl;
        }
        else if (y == m_locationY)
        {
            m_guesses++;
            std::cout << "You missed! ... You have " << m_maxGuesses - m_guesses << " guesses left." << std::endl;
            std::cout << "You are in the same column as the battleship." << std::endl;
        }
        else
        {
            std::cout << "Your guess is out of bounds." << std::endl;
        }

        return false;
    }

    bool gameOver() const
    {
        if (m_guesses >= m_maxGuesses)
        {
            std::cout << "Game Over! ... You have no guesses left." << std::endl;
        }

        return (m_guesses >= m_maxGuesses);
    }

    int getGuesses() const
    {
        return m_guesses;
    }

private:
    bool m_board[5][5];
    int m_guesses;
    int m_maxGuesses;
    int m_locationX;
    int m_locationY;
};

int main()
{
    int max_guesses = 5, guessed_x, guessed_y;

    Battleship game(max_guesses);

    while (!game.gameOver())
    {
        std::cout << std::endl
                  << "Please Enter your guess (row and column): ";

        std::cin >> guessed_x >> guessed_y;

        if (game.guess(guessed_x, guessed_y))
            break;
    }

    return 0;
}