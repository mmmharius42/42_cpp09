/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpapin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 14:30:07 by mpapin            #+#    #+#             */
/*   Updated: 2025/12/22 16:13:03 by mpapin           ###   ########.fr       */
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

void PmergeMe::validateInput(int value) const {
    if (value < 0)
        throw std::runtime_error("Error: negative number detected");
}

void PmergeMe::parseArgs(int argc, char **argv) {
    for (int i = 1; i < argc; ++i) {
        std::stringstream ss(argv[i]);
        int valeur;
        if (ss >> valeur || ss.eof()) {
            validateInput(valeur);
            _vec.push_back(valeur);
            _deq.push_back(valeur);
        }
        else
            throw std::runtime_error("Error: invalid argument");
    }
}

void PmergeMe::insertionSortVector(std::vector<int>& vec) {
    for (size_t i = 1; i < vec.size(); ++i) {
        int key = vec[i];
        size_t j = i;
        while (j > 0 && vec[j - 1] > key) {
            vec[j] = vec[j - 1];
            --j;
        }
        vec[j] = key;
    }
}

void PmergeMe::insertionSortDeque(std::deque<int>& deq) {
    for (size_t i = 1; i < deq.size(); ++i) {
        int key = deq[i];
        size_t j = i;
        while (j > 0 && deq[j - 1] > key) {
            deq[j] = deq[j - 1];
            --j;
        }
        deq[j] = key;
    }
}

double getTimeDifference(const timeval& start, const timeval& end) { 
    return (end.tv_usec - start.tv_usec);
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
    insertionSortVector(vecCopy);
    gettimeofday(&vec_end, NULL);
    double timeVec = getTimeDifference(vec_start, vec_end);

    std::deque<int> deqCopy = _deq;
    struct timeval deq_start, deq_end;
    gettimeofday(&deq_start, NULL);
    insertionSortDeque(deqCopy);
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