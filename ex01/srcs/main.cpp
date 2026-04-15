/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 14:49:35 by waroonwork@       #+#    #+#             */
/*   Updated: 2026/04/15 16:38:16 by waroonwork@      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "Phonebook.hpp"

#ifndef DEBUG
# define DEBUG false
#endif

int main(void)
{
	Phonebook	phonebook;
	std::string	prompt;

	while (true)
	{
		std::cout << "prompt: ";
		if (!std::getline(std::cin, prompt))
		{
			std::cerr << "EOL" << std::endl;
			return (1);
		}
		if (prompt.compare("ADD") == 0)
			phonebook.add();
		else if (prompt.compare("SEARCH") == 0)
			phonebook.search();
		else if (prompt.compare("EXIT") == 0)
			return (0);
		if (DEBUG)
		{
			if (prompt.compare("LOG") == 0)
				phonebook.logs();
		}
	}
	return (0);
}
