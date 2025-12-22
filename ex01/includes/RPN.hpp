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
#include <stack>
#include <string>


class RPN {
    private :
        std::stack<int> _rpn;
    public :
        RPN();
        RPN(const RPN& other);
        RPN& operator=(const RPN& other);
        ~RPN();
        
        void    pars_arg(const std::string& calcul);
        void    calcul_stack(int a, int b, const std::string& op);
        int     getResult() const;
};

#endif