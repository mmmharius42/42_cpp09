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

int main(int argc, char **argv){
    if (argc != 2) {
        std::cout << "Error : You need to provide calcul" << std::endl;
        return 1;
    }
    RPN rpn;
    rpn.pars_arg(argv[1]); 
}