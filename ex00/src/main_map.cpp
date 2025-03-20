/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:57:52 by dbonilla          #+#    #+#             */
/*   Updated: 2025/03/20 19:17:40 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <sstream>
//--------------------------------------------------------------------------------------------------------------
// Main for function easyfind_by in easyfind_map.hpp

#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include "../inc/easyfind_map.hpp" // Contains easyfind_by_value for maps
#include <stdexcept>

int main() {
    std::map<int, int> myMap;
    int numEntries;

    std::cout << "Enter number of entries: ";
    std::cin >> numEntries;
    std::cin.ignore();

    for (int i = 0; i < numEntries; i++) {
        std::string keyStr, valueStr;
        int key, value;
        
        std::cout << "Enter key (integer) for entry " << i + 1 << ": ";
        std::getline(std::cin, keyStr);
        std::cout << "Enter value (integer) for entry " << i + 1 << ": ";
        std::getline(std::cin, valueStr);

        // Convert strings to integers
        std::istringstream keyStream(keyStr);
        std::istringstream valueStream(valueStr);
        
        if (!(keyStream >> key) || !(valueStream >> value)) {
            std::cout << "Invalid input. Please enter integers only." << std::endl;
            i--;
            continue;
        }

        myMap[key] = value;
    }

    std::cout << "\nMap entries:" << std::endl;
    for (std::map<int, int>::iterator it = myMap.begin(); it != myMap.end(); ++it) {
        std::cout << "Key: " << it->first << ", Value: " << it->second << std::endl;
    }

    int searchvalue;
    std::cout << "\nEnter the value (integer) to search for: ";
    std::cin >> searchvalue;

    // int searchKey;
    // std::cout << "\nEnter the key (integer) to search for: ";
    // std::cin >> searchKey;

    try {
        // std::map<int, int>::iterator found = easyfind(myMap, searchKey);
        std::map<int, int>::iterator found = easyfind(myMap, searchvalue);
        
        std::cout << "Found key: " << found->first << " with value: " << found->second << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Value not found: " << e.what() << std::endl;
    }

    return 0;
}
