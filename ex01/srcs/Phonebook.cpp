/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:07:27 by waroonwork@       #+#    #+#             */
/*   Updated: 2026/01/25 17:51:59 by waroonwork@      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook()
{
	int	i;

	this->contact_count = 0;
	i = 0;
	while (i < MAX_CONTACT)
	{
		this->all_contact[i] = NULL;
		i++;
	}
}

Phonebook::~Phonebook()
{
	int	i;

	i = 0;
	while (i < MAX_CONTACT)
	{
		if (this->all_contact[i])
			delete this->all_contact[i];
		i++;
	}
}

static void is_valid(std::string input, std::string err_msg)
{
	if (input.empty() == true)
		throw std::invalid_argument(err_msg);
}

static void is_valid(std::string input, std::string err_msg, int phone_len)
{
	if (input.empty() == true)
		throw std::invalid_argument(err_msg);
	if ((int) input.length() != phone_len)
		throw std::invalid_argument(err_msg);
}

void Phonebook::add()
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_number;
	std::string darkest_secret;

	try
	{
		std::cout << "First Name: ";
		std::cin >> first_name;
		is_valid(first_name, "Invalid First Name");
		std::cout << "Last Name: ";
		std::cin >> last_name;
		is_valid(last_name, "Invalid Last Name");
		std::cout << "Nickname: ";
		std::cin >> nickname;
		is_valid(nickname, "Invalid Ncikname");
		std::cout << "Phone Number: ";
		std::cin >> phone_number;
		is_valid(phone_number, "Invalid Phone Number", 10);
		std::cout << "Darkest Secret: ";
		std::cin >> darkest_secret;
		is_valid(darkest_secret, "Invalid Darkest Secret");
		if (this->contact_count < MAX_CONTACT)
		{
			this->all_contact[contact_count] = new Contact(first_name, last_name, nickname, phone_number, darkest_secret);
			this->contact_count++;
			return ;
		}
		this->shift_down();
		this->all_contact[MAX_CONTACT - 1] = new Contact(first_name, last_name, nickname, phone_number, darkest_secret);
		return ;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return ;
	}
}

void Phonebook::shift_down()
{
	int		i;
	Contact	*temp;

	if (this->all_contact[0])
	{
		delete this->all_contact[0];
		this->all_contact[0] = NULL;
	}
	i = 0;
	while (i < MAX_CONTACT - 1)
	{
		temp = this->all_contact[i];
		this->all_contact[i] = this->all_contact[i + 1];
		this->all_contact[i + 1] = temp;
		i++;
	}
}

void Phonebook::search()
{
	std::string	search_index;
	int			i;

	i = 0;
	while (i < this->contact_count)
	{
		std::cout << std::right << std::setfill(' ') << std::setw(10) << i;
		std::cout << "|";
		this->all_contact[i]->brief_info();
		i++;
	}
}

void Phonebook::logs()
{
	int	i;

	i = 0;
	while (i < this->contact_count)
	{
		this->all_contact[i]->info();
		i++;
	}
}
