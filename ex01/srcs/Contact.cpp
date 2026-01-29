/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 17:10:03 by waroonwork@       #+#    #+#             */
/*   Updated: 2026/01/29 21:04:53 by waroonwork@      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	this->first_name = DEFAULT_MSG;
	this->last_name = DEFAULT_MSG;
	this->nickname = DEFAULT_MSG;
	this->phone_number = DEFAULT_MSG;
	this->darkest_secret = DEFAULT_MSG;
}

Contact::Contact(std::string first_name, std::string last_name, \
		std::string nickname, std::string phone_number, \
		std::string darkest_secret)
{
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
}

Contact &Contact::operator=(const Contact &other)
{
	if (this == &other)
		return (*this);
	this->first_name = other.first_name;
	this->last_name = other.last_name;
	this->nickname = other.nickname;
	this->phone_number = other.phone_number;
	this->darkest_secret = other.darkest_secret;
	return (*this);
}

Contact::~Contact()
{
}

static std::string format_field(const std::string &s)
{
	if (s.length() > 10)
		return (s.substr(0, 9) + ".");
	return (s);
}

void Contact::info()
{
	std::cout << std::right << std::setfill(' ') << std::setw(10) << format_field(this->first_name);
	std::cout << "|";
	std::cout << std::right << std::setfill(' ') << std::setw(10) << format_field(this->last_name);
	std::cout << "|";
	std::cout << std::right << std::setfill(' ') << std::setw(10) << format_field(this->nickname);
	std::cout << "|";
	std::cout << std::right << std::setfill(' ') << std::setw(10) << format_field(this->phone_number);
	std::cout << "|";
	std::cout << std::right << std::setfill(' ') << std::setw(10) << format_field(this->darkest_secret);
	std::cout << "\n";
}

void Contact::brief_info()
{
	std::cout << std::right << std::setfill(' ') << std::setw(10) << format_field(this->first_name);
	std::cout << "|";
	std::cout << std::right << std::setfill(' ') << std::setw(10) << format_field(this->last_name);
	std::cout << "|";
	std::cout << std::right << std::setfill(' ') << std::setw(10) << format_field(this->nickname);
	std::cout << "\n";
}
