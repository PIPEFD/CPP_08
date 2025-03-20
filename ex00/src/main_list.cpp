/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_list.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:57:52 by dbonilla          #+#    #+#             */
/*   Updated: 2025/03/20 16:16:47 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <exception>
#include <list>
#include "../inc/easyfind_list.hpp" // Header for the easyfind function specialized for lists

int main() {
    std::list<int> myList;
    int numEntries;
    
    std::cout << "Enter the number of integers: ";
    std::cin >> numEntries;
    
    for (int i = 0; i < numEntries; i++) {
        int value;
        std::cout << "Enter integer " << (i + 1) << ": ";
        std::cin >> value;
        myList.push_back(value);
    }
    
    std::cout << "\nList contents:" << std::endl;
    for (std::list<int>::iterator it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    int searchValue;
    std::cout << "Enter an integer to search for: ";
    std::cin >> searchValue;
    
    try {
        std::list<int>::iterator found = easyfind_by(myList, searchValue);
        std::cout << "Value found: " << *found << std::endl;
    }
    catch (const std::exception &e) {
        std::cout << "Value not found: " << e.what() << std::endl;
    }
    
    return 0;
}
