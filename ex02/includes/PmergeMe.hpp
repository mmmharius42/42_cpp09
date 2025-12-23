/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:32:03 by mpapin            #+#    #+#             */
/*   Updated: 2025/12/23 16:17:47 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PmergeMe_HPP
#define PmergeMe_HPP

#include <sys/time.h>
#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <ctime>
#include <iomanip>
#include <cstdlib>

class PmergeMe {
    private:
        std::vector<int> _vec;
        std::deque<int> _deq;

    public:
        PmergeMe();
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        void parseArgs(int argc, char **argv);
        void sortAndDisplay();
};

template <typename Container>
typename Container::iterator binaryInsert(Container& c, int value, typename Container::iterator end);

template <typename Container>
void fordJohnson(Container container);

#endif