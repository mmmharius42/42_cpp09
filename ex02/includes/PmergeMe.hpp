/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:32:03 by mpapin            #+#    #+#             */
/*   Updated: 2025/12/22 15:59:49 by mpapin           ###   ########.fr       */
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

    void validateInput(int value) const;
    void insertionSortVector(std::vector<int>& vec);
    void insertionSortDeque(std::deque<int>& deq);

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    ~PmergeMe();

    void parseArgs(int argc, char **argv);
    void sortAndDisplay();
};


#endif