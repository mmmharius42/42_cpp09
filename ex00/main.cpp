/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:41:54 by mpapin            #+#    #+#             */
/*   Updated: 2025/12/22 01:02:23 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cout << "Error: you need to provide a file" << std::endl;
        return 1;
    }
    BitcoinExchange	db_btc("files/data.csv");
	db_btc.find_from_file(argv[1]);
}