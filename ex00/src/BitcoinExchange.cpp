/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 14:40:54 by mpapin            #+#    #+#             */
/*   Updated: 2025/12/05 16:01:09 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string file_name_args) {
	loadDatabase(file_name_args);
}

BitcoinExchange::~BitcoinExchange() {}

void	BitcoinExchange::loadDatabase(const std::string& file_name) {
	std::ifstream	db_file(file_name.c_str());
	std::string		line;

	if (!db_file.is_open()) {
		std::cout << "Error: could not open file " << file_name << std::endl;
		return;
	}
	std::getline(db_file, line);

	while (std::getline(db_file, line))
	{
		if (line.length() < 10)
			continue;

		size_t comma_pos = line.find(',');
		if (comma_pos != std::string::npos)
		{
			std::string date = line.substr(0, comma_pos);
			std::string value_str = line.substr(comma_pos + 1);
			float value = std::atof(value_str.c_str());
			database[date] = value;
		}
	}
	db_file.close();
}

float	BitcoinExchange::find_from_date(const std::string& date, bool& found)
{
	found = false;

	if (database.empty())
		return 0.0f;
	std::map<std::string, float>::iterator it = database.upper_bound(date);

	if (it == database.begin())
		return 0.0f;

	--it;
	found = true;
	return it->second;
}

bool	BitcoinExchange::isValidDate(const std::string& date)
{
	if (date.length() != 10)
		return false;

	if (date[4] != '-' || date[7] != '-')
		return false;

	for (int i = 0; i < 10; i++) {
		if (i == 4 || i == 7)
			continue;
		if (!isdigit(date[i]))
			return false;
	}

	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());

	if (month < 1 || month > 12)
		return false;

	int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	if (month == 2) {
		bool is_leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		if (is_leap)
			days_in_month[1] = 29;
	}

	if (day < 1 || day > days_in_month[month - 1])
		return false;

	return true;
}

bool	BitcoinExchange::isValidValue(const std::string& value_str, float& value)
{
	if (value_str.empty())
		return false;

	char* end;
	value = std::strtof(value_str.c_str(), &end);

	if (*end != '\0')
		return false;

	if (value < 0 || value > 1000)
		return false;

	return true;
}

bool	BitcoinExchange::validateLine(const std::string& line, std::string& error_msg)
{
	if (line.empty()) {
		error_msg = "";
		return true;
	}

	if (line == "date | value") {
		error_msg = "";
		return true;
	}

	size_t separator_pos = line.find(" | ");
	if (separator_pos == std::string::npos) {
		error_msg = "Error: bad input => " + line;
		return false;
	}

	std::string date = line.substr(0, separator_pos);
	std::string value_str = line.substr(separator_pos + 3);

	if (!isValidDate(date)) {
		error_msg = "Error: bad input => " + line;
		return false;
	}

	float value;
	if (!isValidValue(value_str, value)) {
		if (value < 0)
			error_msg = "Error: not a positive number.";
		else if (value > 1000)
			error_msg = "Error: too large a number.";
		else
			error_msg = "Error: invalid value => " + value_str;
		return false;
	}

	return true;
}

void	BitcoinExchange::find_from_file(std::string file_name)
{
	std::ifstream	input_file;
	std::string		line;

	input_file.open(file_name.c_str());
	if (!input_file.is_open()) {
		std::cout << "Error: could not open file." << std::endl;
		return ;
	}

	bool first_line = true;
	while (std::getline(input_file, line)) {
		if (first_line) {
			first_line = false;
			if (line == "date | value")
				continue;
		}

		if (line.empty())
			continue;

		std::string error_msg;
		if (!validateLine(line, error_msg)) {
			std::cout << error_msg << std::endl;
			continue;
		}

		size_t separator_pos = line.find(" | ");
		std::string date = line.substr(0, separator_pos);
		std::string value_str = line.substr(separator_pos + 3);
		float input_value = std::atof(value_str.c_str());

		bool found;
		float rate = find_from_date(date, found);
		if (!found) {
			std::cout << "Error: date not found in database => " << date << std::endl;
			continue;
		}

		float final_value = rate * input_value;
		std::cout << date << " => " << value_str << " = " << final_value << std::endl;
	}

	input_file.close();
}
