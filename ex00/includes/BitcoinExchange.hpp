/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:40:47 by mpapin            #+#    #+#             */
/*   Updated: 2025/12/05 16:01:03 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <map>
#include <string>

class BitcoinExchange
{
	private:
		std::map<std::string, float>	database;

		bool	isValidDate(const std::string& date);
		bool	isValidValue(const std::string& value_str, float& value);
		void	loadDatabase(const std::string& file_name);
        
	public:
		BitcoinExchange(std::string	file_name_arg);
		~BitcoinExchange();

		float	find_from_date(const std::string& date, bool& found);
		void	find_from_file(std::string file_name);
		bool	validateLine(const std::string& line, std::string& error_msg);
};

#endif
