/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 00:02:29 by dbonilla          #+#    #+#             */
/*   Updated: 2025/03/21 12:06:40 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP


#include <iostream>
#include <algorithm>
#include <vector>
#include <exception>
#include <limits>
#include <string>


class Span
{
    private:
        unsigned int _maxSize;
        std::vector<int> _numbers;

    public:
        Span();
        Span(unsigned int n);
        Span(const Span &other);
        Span &operator=(const Span &rhs);
        ~Span();
        class ExceptionSpan: public std::exception
        {
            public:
                virtual const char* what() const throw();
            
        };

        class ExceptionEnoughNumbers: public std::exception
        {
            public:
                virtual const char* what() const throw();
            
        };

        void addNumber(int number);
        int shortestSpan()  const;
        int longestSpan()   const;
        
};


#endif