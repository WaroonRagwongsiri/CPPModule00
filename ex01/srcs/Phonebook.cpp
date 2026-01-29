/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:07:27 by waroonwork@       #+#    #+#             */
/*   Updated: 2026/01/29 21:01:11 by waroonwork@      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook()
{
	this->contact_count = 0;
}

Phonebook::~Phonebook()
{
}

static void is_valid(std::string input, std::string err_msg)
{
	if (input.empty() == true)
		throw std::invalid_argument(err_msg);
}

static void is_valid(std::string input, std::string err_msg, int phone_len)
{
	int	i;

	if (input.empty() == true)
		throw std::invalid_argument(err_msg);
	if ((int) input.length() != phone_len)
		throw std::invalid_argument(err_msg);
	i = 0;
	while (input[i])
	{
		if (input[i] < '0' || input[i] > '9')
			throw std::invalid_argument(err_msg);
		++i;
	}
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
		is_valid(first_name, "Empty First Name");
		std::cout << "Last Name: ";
		std::cin >> last_name;
		is_valid(last_name, "Empty Last Name");
		std::cout << "Nickname: ";
		std::cin >> nickname;
		is_valid(nickname, "Empty Ncikname");
		std::cout << "Phone Number: ";
		std::cin >> phone_number;
		is_valid(phone_number, "Empty Phone Number or Phone length != 10 or Phone Number must be number", PHONE_LEN);
		std::cout << "Darkest Secret: ";
		std::cin >> darkest_secret;
		is_valid(darkest_secret, "Empty Darkest Secret");
		if (this->contact_count < MAX_CONTACT)
		{
			this->all_contact[contact_count] = Contact(first_name, last_name, nickname, phone_number, darkest_secret);
			this->contact_count++;
			return ;
		}
		this->shift_down();
		this->all_contact[MAX_CONTACT - 1] = Contact(first_name, last_name, nickname, phone_number, darkest_secret);
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

	i = 0;
	while (i < MAX_CONTACT - 1)
	{
		this->all_contact[i] = this->all_contact[i + 1];
		i++;
	}
}

void Phonebook::search()
{
	std::string	search_index;
	int			i;
	int			index;

	std::cout << std::right << std::setfill(' ') << std::setw(10) << "index";
	std::cout << "|";
	std::cout << std::right << std::setfill(' ') << std::setw(10) << "firstname";
	std::cout << "|";
	std::cout << std::right << std::setfill(' ') << std::setw(10) << "lastname";
	std::cout << "|";
	std::cout << std::right << std::setfill(' ') << std::setw(10) << "nickname";
	std::cout << "\n";
	i = 0;
	while (i < this->contact_count)
	{
		std::cout << std::right << std::setfill(' ') << std::setw(10) << i;
		std::cout << "|";
		this->all_contact[i].brief_info();
		i++;
	}
	try
	{
		std::cout << "search index: ";
		std::cin >> search_index;
		is_valid(search_index, "Empty Search Index");
		i = 0;
		while (search_index[i])
		{
			if (search_index[i] < '0' || search_index[i] > '9')
				throw std::invalid_argument("Index must be nunmber");
			++i;
		}
		index = std::atoi(search_index.c_str());
		if (index >= this->contact_count || index < 0)
			throw std::out_of_range("Out of range index");
		std::cout << std::right << std::setfill(' ') << std::setw(10) << "index";
		std::cout << "|";
		std::cout << std::right << std::setfill(' ') << std::setw(10) << "firstname";
		std::cout << "|";
		std::cout << std::right << std::setfill(' ') << std::setw(10) << "lastname";
		std::cout << "|";
		std::cout << std::right << std::setfill(' ') << std::setw(10) << "nickname";
		std::cout << "|";
		std::cout << std::right << std::setfill(' ') << std::setw(10) << "phoneno";
		std::cout << "|";
		std::cout << std::right << std::setfill(' ') << std::setw(10) << "dark_sec";
		std::cout << "\n";
		std::cout << std::right << std::setfill(' ') << std::setw(10) << index;
		std::cout << "|";
		this->all_contact[index].info();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return ;
	}
}

void Phonebook::logs()
{
	int	i;

	std::cout << std::right << std::setfill(' ') << std::setw(10) << "index";
	std::cout << "|";
	std::cout << std::right << std::setfill(' ') << std::setw(10) << "firstname";
	std::cout << "|";
	std::cout << std::right << std::setfill(' ') << std::setw(10) << "lastname";
	std::cout << "|";
	std::cout << std::right << std::setfill(' ') << std::setw(10) << "nickname";
	std::cout << "|";
	std::cout << std::right << std::setfill(' ') << std::setw(10) << "phoneno";
	std::cout << "|";
	std::cout << std::right << std::setfill(' ') << std::setw(10) << "dark_sec";
	std::cout << "\n";
	i = 0;
	while (i < this->contact_count)
	{
		std::cout << std::right << std::setfill(' ') << std::setw(10) << i;
		std::cout << "|";
		this->all_contact[i].info();
		i++;
	}
}
