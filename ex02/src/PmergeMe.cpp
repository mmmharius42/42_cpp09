/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:30:07 by mpapin            #+#    #+#             */
/*   Updated: 2026/01/26 16:44:30 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "time.h"
#include <stdio.h>
PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other) : _vec(other._vec), _deq(other._deq) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _vec = other._vec;
        _deq = other._deq;
    }
    return *this;
}

PmergeMe::~PmergeMe() {}

void PmergeMe::parseArgs(int argc, char **argv) {
    for (int i = 1; i < argc; ++i) {
        std::stringstream ss(argv[i]);
        int valeur;
        if (ss >> valeur && ss.eof()) {
            if (valeur < 0)
                throw std::runtime_error(std::string("Error: negative number detected => ") + argv[i]);
            _vec.push_back(valeur);
            _deq.push_back(valeur);
        }
        else
            throw std::runtime_error(std::string("Error: invalid argument => ") + argv[i]);
    }
}

template <typename Container>
typename Container::iterator binaryInsert(Container& c, int value, typename Container::iterator end)
{
    typename Container::iterator left = c.begin();
    typename Container::iterator right = end;

    while (left < right) {
        typename Container::iterator mid = left + (right - left) / 2;
        if (*mid < value)
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

template <typename Container>
void fordJohnson(Container& container) {
    if (container.size() <= 1)
        return;

    Container mins;
    Container maxs;

    size_t i = 0;
    for (; i + 1 < container.size(); i += 2) {
        if (container[i] < container[i + 1]) {
            mins.push_back(container[i]);
            maxs.push_back(container[i + 1]);
        } else {
            mins.push_back(container[i + 1]);
            maxs.push_back(container[i]);
        }
    }
    bool hasStraggler = (i < container.size());
    int straggler = hasStraggler ? container[i] : 0;
    fordJohnson(maxs);
    container = maxs;
    if (mins.size() > 1)
    {
        std::vector<size_t> jacobIndices;
        jacobIndices.push_back(0);
        size_t a = 0, b = 1;
        while (b < mins.size())
        {
            jacobIndices.push_back(b);
            size_t tmp = b;
            b = b + 2 * a;
            a = tmp;
        }
        std::vector<size_t> uniqueJacob;
        for (size_t i = 0; i < jacobIndices.size(); ++i) {
            size_t idx = jacobIndices[i];
            if (idx < mins.size() && std::find(uniqueJacob.begin(), uniqueJacob.end(), idx) == uniqueJacob.end())
                uniqueJacob.push_back(idx);
        }
        for (size_t k = 0; k < uniqueJacob.size(); ++k) {
            size_t idx = uniqueJacob[k];
            typename Container::iterator pos = binaryInsert(container, mins[idx], container.end());
            container.insert(pos, mins[idx]);
        }
        for (size_t j = 0; j < mins.size(); ++j) {
            if (std::find(uniqueJacob.begin(), uniqueJacob.end(), j) == uniqueJacob.end()) {
                typename Container::iterator pos = binaryInsert(container, mins[j], container.end());
                container.insert(pos, mins[j]);
            }
        }
    }
    if (hasStraggler) {
        typename Container::iterator pos = binaryInsert(container, straggler, container.end());
        container.insert(pos, straggler);
    }
}


void PmergeMe::sortAndDisplay() {
    std::cout << "Before: ";
    if (_vec.size() > 5) {
        for (size_t i = 0; i < 4; ++i)
            std::cout << _vec[i] << " ";
        std::cout << "[...]" << std::endl;
    } else {
        for (size_t i = 0; i < _vec.size(); ++i)
            std::cout << _vec[i] << " ";
        std::cout << std::endl;
    }

    std::vector<int> vecCopy = _vec;
    clock_t vecStart = clock();
    fordJohnson(vecCopy);
    clock_t vecEnd = clock();
    double timeVec = (double)(vecEnd - vecStart) * 1e6 / CLOCKS_PER_SEC;

    std::deque<int> deqCopy = _deq;
    clock_t deqStart = clock();
    fordJohnson(deqCopy);
    clock_t deqEnd = clock();
    double timeDeq = (double)(deqEnd - deqStart) * 1e6 / CLOCKS_PER_SEC;
    
    std::cout << "After: ";
    if (vecCopy.size() > 5) {
        for (size_t i = 0; i < 4; ++i)
            std::cout << vecCopy[i] << " ";
        std::cout << "[...]" << std::endl;
    } else {
        for (size_t i = 0; i < vecCopy.size(); ++i)
            std::cout << vecCopy[i] << " ";
        std::cout << std::endl;
    }

    std::cout << "Time to process a range of " << vecCopy.size() 
              << " elements with std::vector : " << std::fixed << std::setprecision(5)
              << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << deqCopy.size() 
              << " elements with std::deque : " << std::fixed << std::setprecision(5)
              << timeDeq << " us" << std::endl;
}
