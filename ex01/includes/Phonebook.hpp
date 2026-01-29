/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 15:13:51 by waroonwork@       #+#    #+#             */
/*   Updated: 2026/01/29 21:13:57 by waroonwork@      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "mandatory.hpp"
#include "Contact.hpp"

# define MAX_CONTACT 8
# define PHONE_LEN 10

class Phonebook
{
	private:
		Contact	all_contact[MAX_CONTACT];
		int		contact_count;
		void	shift_down();
	public:
		Phonebook();
		~Phonebook();
		void add();
		void search();
		void logs();
};

#endif