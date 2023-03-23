/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etattevi <etattevi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 15:48:00 by hunam             #+#    #+#             */
/*   Updated: 2023/02/21 16:49:44 by etattevi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODE_H
# define KEYCODE_H

# ifdef __APPLE__

#  define ESC 53

#  define ARROW_LEFT 123
#  define ARROW_RIGHT 124
#  define ARROW_UP 126
#  define ARROW_DOWN 125

#  define A 0
#  define Z 6
#  define Q 12
#  define S 1
#  define D 2
#  define W 13
#  define K 40
#  define C 8
#  define M 46
#  define P 35
#  define R 15
#  define T 17

# else

#  define ESC 65307

#  define ARROW_LEFT 65361
#  define ARROW_RIGHT 65363
#  define ARROW_UP 65362
#  define ARROW_DOWN 65364

#  define A 97
#  define Z 122
#  define Q 113
#  define S 115
#  define D 100
#  define W 119
#  define K 107
#  define C 99
#  define M 109
#  define P 112
#  define R 114
#  define T 116

# endif

# define SCROLL_UP 5
# define SCROLL_DOWN 4

#endif