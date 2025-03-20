/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind_vector.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbonilla <dbonilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 15:25:41 by dbonilla          #+#    #+#             */
/*   Updated: 2025/03/20 12:56:40 by dbonilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_VECTOR_HPP
#define EASYFIND_VECTOR_HPP
#include <algorithm>
#include <vector>

template <typename T>
typename T::iterator easyfind(T &container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) 
    {
        throw std::runtime_error("Valor no encontrado");
    }
    return it;
}
#endif

