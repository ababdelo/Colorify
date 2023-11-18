/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <ababdelo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 15:16:46 by ababdelo          #+#    #+#             */
/*   Updated: 2023/11/18 16:20:34 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"

#ifdef _WIN32
void clearConsole() {
    system("cls");
}
#else
void clearConsole() {
    system("clear");
}
#endif

void    ask4clear(){
    std::string userInput;
    std::cout << "\nType 'clear' And To Clear The Console Or Type Anything To Skip: ";
    std::getline(std::cin, userInput);

    if (userInput == "clear" || userInput == "CLEAR") {
        clearConsole();
    }
    else
        return;
}

int main() {
    Colors colors;
    colors.set_colors_values();
    clearConsole();

    const std::string foregroundColorOptions[] = {
        "Black", "Red", "Green", "Yellow", "Blue", "Magenta", "Cyan", "White"
    };

    const std::string backgroundColorOptions[] = {
        "Black", "Red", "Green", "Yellow", "Blue", "Magenta", "Cyan", "White"
    };

    const std::string textStyleOptions[] = {
        "Normal", "Bold", "Italic", "Underline", "Bold/Italic"
    };

    while (true) {
        std::cout << "\n\t\tColorful Phrase Customization Program\n" << std::endl;
        std::cout << "+-----------------------+-----------------------+----------------+" << std::endl;
        std::cout << "| Background Colors:\t| Foreground Colors:\t| Text Styles:   |" << std::endl;
        std::cout << "+-----------------------+-----------------------+----------------+" << std::endl;

        for (size_t i = 0; i < 8; ++i) {
            std::cout << "| " << i + 1 << ". " << colors.getBackGroundColor(backgroundColorOptions[i]) << "   " << colors.reset() << " " 
                    << backgroundColorOptions[i] << colors.reset();
            if (i == 5)
                std::cout << "\t| ";
            else
                std::cout << "\t\t| ";
            std::cout << i + 1 << ". " << colors.getTextColor(foregroundColorOptions[i]) << foregroundColorOptions[i] << colors.reset();
            std::cout << "\t\t| ";
            if (i < 5) 
                std::cout << i + 1 << ". " << colors.getTextStyle(textStyleOptions[i]) << textStyleOptions[i] << colors.reset();
            if (i < 4) 
                std::cout << " \t |\n";
            else if (i == 4)
                std::cout << " |\n";
            else
                std::cout << "\t\t |\n";
            std::cout << "+-----------------------+-----------------------+----------------+" << std::endl; 
        }
        std::cout << "| 9.     Transparent\t|\t\t\t|\t\t |" << std::endl;
        std::cout << "+-----------------------+-----------------------+----------------+" << std::endl;
        std::cout << "\n </> Choose Your Preferred Colors And Style To Customize Your Phrase Or Type 'exit' To End The Program: ";
  
        std::string userInput;
        std::getline(std::cin, userInput);

        if (userInput == "exit" || userInput == "EXIT") {
            break;
        }

        // Use substr to split the input string
        size_t pos1 = userInput.find(' ');
        size_t pos2 = userInput.find(' ', pos1 + 1);
        size_t pos3 = userInput.find(' ', pos2 + 1);

        if (pos1 == std::string::npos || pos2 == std::string::npos || pos3 != std::string::npos) {
            std::cerr << "\n---> ERROR: " << colors.getTextColor("Red") << "Invalid input. Please enter exactly three numbers." << colors.reset() << std::endl;
            ask4clear();
            continue;
        }

        std::string strChoice1 = userInput.substr(0, pos1);
        std::string strChoice2 = userInput.substr(pos1 + 1, pos2 - pos1 - 1);
        std::string strChoice3 = userInput.substr(pos2 + 1);

        size_t choice1 = std::atoi(strChoice1.c_str());
        size_t choice2 = std::atoi(strChoice2.c_str());
        size_t choice3 = std::atoi(strChoice3.c_str());

        if (choice1 <= 0 || choice1 > 9 || choice2 <= 0 || choice2 > 8 || choice3 <= 0 || choice3 > 5) {
            std::cerr << "\n---> ERROR: " << colors.getTextColor("Red") << "Invalid choices. Please enter three valid numbers." << colors.reset() << std::endl;
            ask4clear();
            continue;
        }

        std::string userString;

        std::cout << "---> Enter a string to Customize: " << colors.reset();
        std::getline(std::cin, userString);

        std::cout << "\n---> OUTPUT: ";

        std::cout << colors.getBackGroundColor(backgroundColorOptions[choice1 - 1])
                << colors.getTextStyle(textStyleOptions[choice3 - 1])
                << colors.getTextColor(foregroundColorOptions[choice2 - 1])
                << userString
                << colors.reset() << std::endl;
        ask4clear();
    }

    return 0;
}
