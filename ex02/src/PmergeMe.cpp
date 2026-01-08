/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:30:07 by mpapin            #+#    #+#             */
/*   Updated: 2026/01/08 14:49:43 by mpapin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

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
void fordJohnson(Container container) {
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
    container.insert(container.begin(), mins[0]);
    for (size_t j = 1; j < mins.size(); ++j) {
        typename Container::iterator pos = binaryInsert(container, mins[j], container.end());
        container.insert(pos, mins[j]);
    }
    if (hasStraggler) {
        typename Container::iterator pos = binaryInsert(container, straggler, container.end());
        container.insert(pos, straggler);
    }
}

double getTimeDifference(const timeval& start, const timeval& end) { 
    return (end.tv_sec - start.tv_sec) * 1000000.0
         + (end.tv_usec - start.tv_usec);
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
    struct timeval vec_start, vec_end;
    gettimeofday(&vec_start, NULL);
    fordJohnson(vecCopy);
    gettimeofday(&vec_end, NULL);
    double timeVec = getTimeDifference(vec_start, vec_end);

    std::deque<int> deqCopy = _deq;
    struct timeval deq_start, deq_end;
    gettimeofday(&deq_start, NULL);
    fordJohnson(deqCopy);
    gettimeofday(&deq_end, NULL);
    double timeDeq = getTimeDifference(deq_start, deq_end);

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