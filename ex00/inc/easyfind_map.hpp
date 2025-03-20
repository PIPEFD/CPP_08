/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind_map.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:25:41 by dbonilla          #+#    #+#             */
/*   Updated: 2025/03/20 19:16:07 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_MAP_HPP
#define EASYFIND_MAP_HPP

#include <map>
#include <stdexcept>

// Search by key (direct map access)
template<typename K, typename V>
typename std::map<K, V>::iterator easyfind_by_key(std::map<K, V>& container, const K& key)
{
    typename std::map<K, V>::iterator it = container.find(key);
    if (it == container.end())
        throw std::runtime_error("Key not found");
    return it;
}
// Search by value (iterative search)


template<typename K, typename V>
typename std::map<K, V>::iterator easyfind(std::map<K, V>& container, const V& value)
{
    typename std::map<K, V>::iterator it;
    for (it = container.begin(); it != container.end(); ++it) {
        if (it->second == value)
            return it;
    }
    throw std::runtime_error("Value not found");
}

#endif