/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span_map.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 01:40:19 by dbonilla          #+#    #+#             */
/*   Updated: 2025/03/21 12:07:02 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_MAP_HPP

#define SPAN_MAP_HPP

#include <iostream>
#include <algorithm>
#include <map>
#include <exception>
#include <limits>

class Span
{
    private:
        unsigned int    _maxSize;
        std::map<int, int> _numbers;
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