/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <ababdelo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:42:43 by ababdelo          #+#    #+#             */
/*   Updated: 2023/11/18 14:37:58 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colors.hpp"

void Colors::set_colors_values() {
    // Define the color codes
    RESET = "\033[0m";
    BOLD = "\033[1m";
    ITALIC = "\033[3m";
    UNDERLINE = "\033[4m";
    BLACK = "\033[30m";
    RED = "\033[31m";
    GREEN = "\033[32m";
    YELLOW = "\033[33m";
    BLUE = "\033[34m";
    MAGENTA = "\033[35m";
    CYAN = "\033[36m";
    WHITE = "\033[37m";
    BG_BLACK = "\033[40m";
    BG_RED = "\033[41m";
    BG_GREEN = "\033[42m";
    BG_YELLOW = "\033[43m";
    BG_BLUE = "\033[44m";
    BG_MAGENTA = "\033[45m";
    BG_CYAN = "\033[46m";
    BG_WHITE = "\033[47m";
}

std::string Colors::getTextStyle(std::string style) const {
    if (style == "Bold")
        return BOLD;
    else if (style == "Italic")
        return ITALIC;
    else if (style == "Normal")
        return "";
    else if (style == "Underline")
        return UNDERLINE;
    else if (style == "Bold/Italic")
        return BOLD + ITALIC;
    else 
        return "";
}

std::string Colors::getTextColor(std::string foregnd_colors) const{
    if (foregnd_colors == "Black")
        return BLACK;
    else if (foregnd_colors == "Red")
        return RED;
    else if (foregnd_colors == "Green")
        return GREEN;
    else if (foregnd_colors == "Yellow")
        return YELLOW;
    else if (foregnd_colors == "Blue")
        return BLUE;
    else if (foregnd_colors == "Magenta")
        return MAGENTA;
    else if (foregnd_colors == "Cyan")
        return CYAN;
    else if (foregnd_colors == "White")
        return WHITE;
    else
        return "";
}

std::string Colors::reset(void) const{
     return RESET;
}

std::string Colors::getBackGroundColor(std::string backgnd_colors) const{
    if (backgnd_colors == "Black")
        return BG_BLACK;
    else if (backgnd_colors == "Red")
        return BG_RED;
    else if (backgnd_colors == "Green")
        return BG_GREEN;
    else if (backgnd_colors == "Yellow")
        return BG_YELLOW;
    else if (backgnd_colors == "Blue")
        return BG_BLUE;
    else if (backgnd_colors == "Magenta")
        return BG_MAGENTA;
    else if (backgnd_colors == "Cyan")
        return BG_CYAN;
    else if (backgnd_colors == "White")
        return BG_WHITE;
    else
        return "";
}
