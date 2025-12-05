/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:41:54 by mpapin            #+#    #+#             */
/*   Updated: 2025/12/05 15:57:45 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cout << "Error: could not open file." << std::endl;
        return 1;
    }
    BitcoinExchange	db_btc("files/data.csv");
	db_btc.find_from_file(argv[1]);
}