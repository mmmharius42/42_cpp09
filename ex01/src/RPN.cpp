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
#include <sstream>
#include <iostream> 
#include <cctype> 
#include <stdexcept>

RPN::RPN() {}

RPN::RPN(const RPN& other) : _rpn(other._rpn) {}

RPN& RPN::operator=(const RPN& other)
{
    if (this != &other)
        _rpn = other._rpn;
    return *this;
}

RPN::~RPN() {}

void     RPN::calcul_stack(int a, int b, const std::string& op) {
    if (op == "+")
        _rpn.push (a + b);
    else if (op == "-")
        _rpn.push (a - b);
    else if (op == "*")
        _rpn.push(a * b);
    else if (op == "/")
    {
        if (b == 0)
            throw std::runtime_error("Error can't divide by 0");
        _rpn.push(a / b);
    }
}

void    RPN::pars_arg(const std::string& calcul) {
    std::string word;
    std::stringstream ss(calcul);

    while (ss >> word) {
        if (std::isdigit(word[0]) || 
            (word.size() > 1 && word[0] == '-' && std::isdigit(word[1])))
        {
            int value = std::stoi(word);
            _rpn.push(value);
        }
        else if (word == "+" || word == "-" || word == "*" || word == "/")
        {
            if (_rpn.size() < 2) 
                throw std::runtime_error("Error : operator with no number");
            int b = _rpn.top();
            _rpn.pop();
            int a = _rpn.top();
            _rpn.pop(); 
            RPN::calcul_stack(a, b, word);
        }
        else
            throw std::runtime_error("Error : only operator and number are authorized");
    }
    if (_rpn.size() != 1)
        throw std::runtime_error("Error : more than 1 number at the end...");
}

int     RPN::getResult() const {
    if (_rpn.empty())
        throw std::runtime_error("Error : stack empty");
    return _rpn.top();
}