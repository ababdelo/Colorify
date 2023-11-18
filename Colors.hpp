/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ababdelo <ababdelo@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:41:24 by ababdelo          #+#    #+#             */
/*   Updated: 2023/11/18 15:32:17 by ababdelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_HPP
#define COLORS_HPP

#include <string>
#include <iostream>
#include <cstdlib>

#ifdef _WIN32
#include <windows.h>
#endif

class Colors {
public:
    void set_colors_values();
    std::string getTextStyle(std::string style) const;
    std::string getTextColor(std::string foregnd_colors) const;
    std::string getBackGroundColor(std::string backgnd_colors) const;
    std::string reset(void) const;

private:
    std::string RESET;
    std::string BOLD;
    std::string ITALIC;
    std::string UNDERLINE;
    std::string BLACK;
    std::string RED;
    std::string GREEN;
    std::string YELLOW;
    std::string BLUE;
    std::string MAGENTA;
    std::string CYAN;
    std::string WHITE;
    std::string BG_BLACK;
    std::string BG_RED;
    std::string BG_GREEN;
    std::string BG_YELLOW;
    std::string BG_BLUE;
    std::string BG_MAGENTA;
    std::string BG_CYAN;
    std::string BG_WHITE;
    std::string RESET_BG;
};

#endif