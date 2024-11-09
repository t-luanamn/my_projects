/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tluanamn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 20:09:45 by tluanamn          #+#    #+#             */
/*   Updated: 2024/09/03 20:09:50 by tluanamn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _Brain_HPP_
# define _Brain_HPP_

# include <iostream>

class	Brain
{
  public:
    Brain(void);
    Brain(const Brain &cpy);
    ~Brain(void);
    Brain &operator=(const Brain &cpy);

  private:
    std::string _ideas[100];
};

#endif
