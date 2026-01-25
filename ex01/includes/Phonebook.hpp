/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: waroonwork@gmail.com <WaroonRagwongsiri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/25 15:13:51 by waroonwork@       #+#    #+#             */
/*   Updated: 2026/01/25 17:46:49 by waroonwork@      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "mandatory.h"
#include "Contact.hpp"

# define MAX_CONTACT 8

class Phonebook
{
	private:
		Contact	*all_contact[MAX_CONTACT];
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