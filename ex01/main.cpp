/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 01:18:03 by mpapin            #+#    #+#             */
/*   Updated: 2025/12/22 01:18:03 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream> 
#include <stdexcept>

int main(int argc, char **argv){
    if (argc != 2) {
        std::cerr << "Error : only 1 arg (ex: ./RNP \"1 1 +\")" << std::endl;
        return 1;
    }
    try {
        RPN rpn;
        rpn.pars_arg(argv[1]);
        std::cout << rpn.getResult() << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }
}