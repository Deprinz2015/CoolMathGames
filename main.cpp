#include <iostream>
#include <random>
#include "headers/MathHelpers.h"

int main()
{
    int lives = 3;
    int questionCount = 0;
    int a, b;
    int result;
    int userResult;
    char calcSymbol;
    char symbols[] = {'+', '-', '*', '/'}; 

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrNumbers(-100, 100);
    std::uniform_int_distribution<> distrSymbol(0, 3);

    std::cout << "Welcome to your new Mathtrainer! Press Enter to start with the first question!" << std::endl;
    std::cout << "(Remember, all numbers are rounded to have no decimals!)" << std::endl;
    std::cin.get();

    while(lives > 0)
    {
        a = distrNumbers(gen);
        b = distrNumbers(gen);
        calcSymbol = symbols[distrSymbol(gen)];
        result = calc(calcSymbol, a, b);

        std::cout << "Question nr. " << questionCount << ":" << std::endl;
        std::cout << "You have " << lives << " left." << std::endl;
        std::cout << a << " " << calcSymbol << " " << b << " = ";
        std::cin >> userResult;

        if(userResult == result)
        {
            std::cout << "Congratulations! Your answer is correct!" << std::endl;
        }
        else
        {
            lives--;
            std::cout << "Wrong! The correct anser would be: " << result << "!" << std::endl;
            std::cout << "You lost a live..." << std::endl;
        }
        std::cout << "------------------------------------------------------" << std::endl;
        questionCount++;
    }

    std::cout << "You lost all your lives! If you want to try again, you need to restart the program." << std::endl;
}
