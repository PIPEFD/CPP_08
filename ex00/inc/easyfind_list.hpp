/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind_list.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:25:41 by dbonilla          #+#    #+#             */
/*   Updated: 2025/03/20 13:21:34 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_LIST_HPP
#define EASYFIND_LIST_HPP

#include <algorithm>
#include <list>

template<typename K>
typename std::list<K>::iterator easyfind_by(std::list<K> &container, int value)
{
    typename std::list<K>::iterator it = std::find(container.begin(), container.end(), value);
    
    if (it == container.end())
        throw std::runtime_error("Value not found");
    
    return (it);
}

#endif