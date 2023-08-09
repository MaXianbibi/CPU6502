/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Memory.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 15:50:46 by jmorneau          #+#    #+#             */
/*   Updated: 2023/08/09 16:22:00 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_HPP
# define MEMORY_HPP

#include "../include.hpp"



class Memory
{
public:
	static constexpr u32 MAX_MEMORY = 1024 * 64;
	
private:
	BYTE Data[MAX_MEMORY];
	
public:
	Memory();
	~Memory();

	// init Memory
	void init();


	// Read
	BYTE read(WORD addr) const;
	BYTE operator[](WORD addr) const;

};




#endif