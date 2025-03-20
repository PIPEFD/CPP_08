/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:57:52 by dbonilla          #+#    #+#             */
/*   Updated: 2025/03/20 16:13:04 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


//--------------------------------------------------------------------------------------------------------------
//Main for function easyfind_by in easyfind_vector.hpp

#include <iostream>
#include <vector>
#include <exception>
#include <cstdlib>
#include "../inc/easyfind_vector.hpp"

int main() {
    std::vector<int> v;
    int numEntries;

    std::cout << "Enter the number of integers: ";
    std::cin >> numEntries;
    
    for (int i = 0; i < numEntries; i++) {
        int value;
        std::cout << "Enter integer " << (i + 1) << ": ";
        std::cin >> value;
        v.push_back(value);
    }

    std::cout << "\nVector contents:" << std::endl;
    for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    int searchValue;
    std::cout << "Enter an integer to search for: ";
    std::cin >> searchValue;

    try {
        std::vector<int>::iterator found = easyfind(v, searchValue);
        std::cout << "Value found: " << *found << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Value not found: " << e.what() << std::endl;
    }

    return 0;
}

//--------------------------------------------------------------------------------------------------------------
 
// Main for function easyfind_by in easyfind_list.hpp
