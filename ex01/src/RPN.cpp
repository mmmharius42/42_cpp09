/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RNP.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 12:21:51 by mpapin            #+#    #+#             */
/*   Updated: 2025/12/22 12:21:51 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void    RPN::pars_arg(const std::string& calcul) {
    std::string word;
    std::stringstream ss(calcul);

    while (ss >> word) {
        std::cout << "word :" << word << std::endl;
    }
}