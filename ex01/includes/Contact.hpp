/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 15:13:01 by waroonwork@       #+#    #+#             */
/*   Updated: 2026/01/29 21:03:21 by waroonwork@      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H
# define CONTACT_H

# define DEFAULT_MSG "Default"

#include "mandatory.hpp"

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
	public:
		Contact();
		Contact(std::string first_name, std::string last_name, \
			std::string nickname, std::string phone_number, \
			std::string darkest_secret);
		Contact &operator=(const Contact &other);
		~Contact();
		void info();
		void brief_info();
};

#endif