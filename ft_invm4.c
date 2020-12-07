/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_invm4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsandsla <jsandsla@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 14:25:34 by jsandsla          #+#    #+#             */
/*   Updated: 2020/12/07 17:27:35 by jsandsla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define A mat[0][0]
#define B mat[0][1]
#define C mat[0][2]
#define D mat[0][3]

#define E mat[1][0]
#define F mat[1][1]
#define G mat[1][2]
#define H mat[1][3]

#define I mat[2][0]
#define J mat[2][1]
#define K mat[2][2]
#define L mat[2][3]

#define M mat[3][0]
#define N mat[3][1]
#define O mat[3][2]
#define P mat[3][3]

static	void	calc_t1(float t[6], t_m4 mat)
{
	t[0] = K * P - O * L;
	t[1] = J * P - N * L;
	t[2] = J * O - N * K;
	t[3] = I * P - M * L;
	t[4] = I * O - M * K;
	t[5] = I * N - M * J;
}

static	void	calc_t2(float t[6], t_m4 mat)
{
	t[0] = G * P - O * H;
	t[1] = F * P - N * H;
	t[2] = F * O - N * G;
	t[3] = E * P - M * H;
	t[4] = E * O - M * G;
	t[5] = E * N - M * F;
}

static	void	calc_t3(float t[6], t_m4 mat)
{
	t[0] = G * L - K * H;
	t[1] = F * L - J * H;
	t[2] = F * K - J * G;
	t[3] = E * L - I * H;
	t[4] = E * K - I * G;
	t[5] = E * J - I * F;
}

void			ft_inv_m4_to(t_m4 mat, t_m4 out)
{
	float	t[6];
	float	det;

	calc_t1(t, mat);
	out[0][0] = F * t[0] - G * t[1] + H * t[2];
	out[1][0] = -(E * t[0] - G * t[3] + H * t[4]);
	out[2][0] = E * t[1] - F * t[3] + H * t[5];
	out[3][0] = -(E * t[2] - F * t[4] + G * t[5]);
	out[0][1] = -(B * t[0] - C * t[1] + D * t[2]);
	out[1][1] = A * t[0] - C * t[3] + D * t[4];
	out[2][1] = -(A * t[1] - B * t[3] + D * t[5]);
	out[3][1] = A * t[2] - B * t[4] + C * t[5];
	calc_t2(t, mat);
	out[0][2] = B * t[0] - C * t[1] + D * t[2];
	out[1][2] = -(A * t[0] - C * t[3] + D * t[4]);
	out[2][2] = A * t[1] - B * t[3] + D * t[5];
	out[3][2] = -(A * t[2] - B * t[4] + C * t[5]);
	calc_t3(t, mat);
	out[0][3] = -(B * t[0] - C * t[1] + D * t[2]);
	out[1][3] = A * t[0] - C * t[3] + D * t[4];
	out[2][3] = -(A * t[1] - B * t[3] + D * t[5]);
	out[3][3] = A * t[2] - B * t[4] + C * t[5];
	det = 1 / (A * out[0][0] + B * out[1][0] + C * out[2][0] + D * out[3][0]);
	ft_scale_m4(mat, det);
}

void			ft_inv_m4(t_m4 mat)
{
	t_m4	ma;

	ft_inv_m4_to(mat, ma);
	ft_copy_m4(ma, mat);
}
