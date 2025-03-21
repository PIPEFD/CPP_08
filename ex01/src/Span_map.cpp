/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 01:48:29 by dbonilla          #+#    #+#             */
/*   Updated: 2025/03/21 13:57:41 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Span_map.hpp"

Span::Span(unsigned int n) : _maxSize(n)
{
	std::cout << "Constructor to default" << std::endl;
}

Span::Span(const Span &other) : _maxSize(other._maxSize),
	_numbers(other._numbers)
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
	if (_numbers.size() >= _maxSize)
		throw ExceptionSpan();
	_numbers.insert(std::make_pair(num, num));
}
int Span::shortestSpan() const
{
	if (_numbers.size() <= 1)
		throw std::runtime_error("Not enough _numbers to compute a span");

	int minSpan = std::numeric_limits<int>::max();
	std::map<int, int>::const_iterator it = _numbers.begin();
	std::map<int, int>::const_iterator next = it;

	next++;

	for (; next != _numbers.end();)
	{
		std::cout << "IT FIRST  " << it->first << std::endl;
		int diff = next->first - it->first;
		if (diff < minSpan)
			minSpan = diff;
		it++;
		next++;
	}
	return (minSpan);
}

int Span::longestSpan() const
{
	if (_numbers.size() <= 1)
		throw ExceptionEnoughNumbers();
	int minVal = _numbers.begin()->first;
	int maxVal = _numbers.rbegin()->first;
	return (maxVal - minVal);
}
