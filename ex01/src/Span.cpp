/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 00:06:09 by dbonilla          #+#    #+#             */
/*   Updated: 2025/03/21 02:31:33 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span.hpp"


Span::Span(unsigned int n) : _maxSize(n)
{
    std::cout << "Constructor to Default" << std::endl;
}

Span::Span(const Span &other) : _maxSize(other._maxSize), _numbers(other._numbers)
{
    
}

Span &Span::operator=(const Span &rhs)
{
    if (this != &rhs)
    {
        _maxSize = rhs._maxSize;
        _numbers = rhs._numbers;
    }
    return (*this);
}

Span::~Span()
{
    std::cout << "Destroyer" << std::endl;
}

const char *Span::ExceptionSpan::what() const throw()
{
	return ("Span is Full");
}

const char *Span::ExceptionEnoughNumbers::what() const throw()
{
	return ("Span is Full");
}

void Span::addNumber(int num)
{
    if (_numbers.size() >=  _maxSize)
        throw ExceptionSpan();
    _numbers.push_back(num);

        
}
int Span::shortestSpan()  const
{
    if (_numbers.size() <= 1)
        throw ExceptionEnoughNumbers();
    std::vector<int> tmp = _numbers;
    std::sort(tmp.begin(), tmp.end());
    
    int minSpan = std::numeric_limits<int>::max();
    for (unsigned int i = 1; i < tmp.size(); i++)
    {
        int span = tmp[i] - tmp[i - 1];
        // std::cout << span << std::endl;
        if (span < minSpan)
            minSpan = span;
    }
    // std::cout << minSpan << std::endl;

    return (minSpan);
    
}


int Span::longestSpan()   const
{
    if (_numbers.size() <=  1)
        throw ExceptionEnoughNumbers();
    int minVal = *std::min_element(_numbers.begin(), _numbers.end());
    int maxVal = *std::max_element(_numbers.begin(), _numbers.end());
    // std::cout << minVal << std::endl;
    // std::cout << maxVal << std::endl;

    return (maxVal - minVal);
    
}



// // #include <iostream>
// // #include <map>
// // #include <stdexcept>
// // #include <limits>
// // #include <algorithm>

// // class Span {
// // public:
// //     // Constructor that sets the maximum number of elements.
// //     Span(unsigned int n) : maxSize(n) {}

// //     // Orthodox Canonical Form: copy constructor, assignment operator, and destructor.
// //     Span(const Span &other)
// //         : maxSize(other.maxSize), numbers(other.numbers) {}

// //     Span &operator=(const Span &other) {
// //         if (this != &other) {
// //             maxSize = other.maxSize;
// //             numbers = other.numbers;
// //         }
// //         return *this;
// //     }

// //     ~Span() {}

// //     // Add a single number to the Span.
// //     // In a multimap, duplicates are allowed and the container remains sorted.
// //     void addNumber(int num) {
// //         if (numbers.size() >= maxSize)
// //             throw std::runtime_error("Span is full");
// //         numbers.insert(std::make_pair(num, num)); // key and value are both 'num'
// //     }

// //     // Template method to add multiple numbers from a range of iterators.
// //     template <typename Iterator>
// //     void addNumbers(Iterator begin, Iterator end) {
// //         for (; begin != end; ++begin)
// //             addNumber(*begin);
// //     }

// //     // Calculate the shortest span (minimum difference between adjacent elements).
// //     int shortestSpan() const {
// //         if (numbers.size() <= 1)
// //             throw std::runtime_error("Not enough numbers to compute a span");

// //         int minSpan = std::numeric_limits<int>::max();

// //         // Use two iterators to traverse adjacent elements in the sorted multimap.
// //         for (std::multimap<int, int>::const_iterator it = numbers.begin(),
// //              next_it = ++numbers.begin();
// //              next_it != numbers.end();
// //              ++it, ++next_it)
// //         {
// //             int diff = next_it->first - it->first;
// //             if (diff < minSpan)
// //                 minSpan = diff;
// //         }
// //         return minSpan;
// //     }

// //     // Calculate the longest span (difference between the smallest and largest element).
// //     int longestSpan() const {
// //         if (numbers.size() <= 1)
// //             throw std::runtime_error("Not enough numbers to compute a span");

// //         int minVal = numbers.begin()->first;
// //         int maxVal = numbers.rbegin()->first; // last element (largest key)
// //         return maxVal - minVal;
// //     }

// // private:
// //     unsigned int maxSize;           // Maximum capacity.
// //     std::multimap<int, int> numbers; // Container to store the numbers.
// // };

// // int main() {
// //     try {
// //         Span sp(5);
// //         sp.addNumber(6);
// //         sp.addNumber(3);
// //         sp.addNumber(17);
// //         sp.addNumber(9);
// //         sp.addNumber(11);

// //         std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
// //         std::cout << "Longest span: " << sp.longestSpan() << std::endl;
// //     }
// //     catch (const std::exception &e) {
// //         std::cerr << "Error: " << e.what() << std::endl;
// //     }
// //     return 0;
// // }