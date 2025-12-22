/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RNP.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 01:19:38 by mpapin            #+#    #+#             */
/*   Updated: 2025/12/22 01:19:38 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP
#include <sstream>
#include <stack>
#include <string>
#include <iostream> 


class RPN {
    private :
        std::stack<int> rpn;
    public :
        void    pars_arg(const std::string& calcul);
};

#endif