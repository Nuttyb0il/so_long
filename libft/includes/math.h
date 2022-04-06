/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 12:12:08 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/01 15:06:33 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H

# define PI		3.14159265358979323846
# define E		2.71828182845904523536
# define PHI	1.61803398874989484820

/**
 * @brief Returns the absolute value of an integer, will overflow on INT_MIN
 * 
 * @param n The integer to get the absolute value of
 * @return int The absolute value of the integer
 */
int			ft_abs(int n);

/**
 * @brief Returns the absolute value of a long, will overflow on LONG_MIN
 * 
 * @param n The long to get the absolute value of
 * @return long The absolute value of the long
 */
long		ft_abs_l(long n);

/**
 * @brief Returns the absolute value of a long long,
 *  will overflow on LONG_LONG_MIN
 * 
 * @param n The long long to get the absolute value of
 * @return long long The absolute value of the long long
 */
long long	ft_abs_ll(long long n);

/**
 * @brief Returns the absolute value of a char, will overflow on CHAR_MIN
 * 
 * @param n The char to get the absolute value of
 * @return char The absolute value of the char
 */
char		ft_abs_c(char n);

/**
 * @brief Returns n (int) to the power of pow
 * 
 * @param n An integer
 * @param pow Power to raise n to
 * @return int n to the power of pow
 */
int			ft_pow(int n, int pow);

/**
 * @brief Returns n (long) to the power of pow
 * 
 * @param n A long
 * @param pow Power to raise n to
 * @return long n to the power of pow
 */
long		ft_pow_l(long n, int pow);

/**
 * @brief Returns n (long long) to the power of pow
 * 
 * @param n A long long
 * @param pow Power to raise n to
 * @return long long n to the power of pow
 */
long long	ft_pow_ll(long long n, int pow);

/**
 * @brief Returns the square root of n
 * 
 * @param n The number to get the square root of
 * @return int The square root of n
 */
int			ft_sqrt(int n);

/**
 * @brief Returns the square root of n (long)
 * 
 * @param n The number to get the square root of
 * @return long The square root of n
 */
long		ft_sqrt_l(long n);

/**
 * @brief Returns the square root of n (long long)
 * 
 * @param n The number to get the square root of
 * @return long long The square root of n
*/
long long	ft_sqrt_ll(long long n);

/**
 * @brief Returns n rounded to the nearest integer
 * 
 * @param n The number to round
 * @return int The rounded number
 */
int			ft_round(float n);

/**
 * @brief Returns n rounded to the integer above (can overflow)
 * 
 * @param n The number to round
 * @return int The rounded number
 */
int			ft_round_up(float n);

/**
 * @brief Returns n rounded to the integer below (can underflow)
 * 
 * @param n The number to round
 * @return int The rounded number
 */
int			ft_round_down(float n);

// -- factorial --
/**
 * @brief Returns the factorial of n
 * 
 * @param n The number to get the factorial of
 * @return int The factorial of n
 */
int			ft_factorial(int n);

/**
 * @brief Returns the factorial of n (long)
 * 
 * @param n The number to get the factorial of
 * @return long The factorial of n
 */
long		ft_factorial_l(long n);

/**
 * @brief Returns the factorial of n (long long)
 * 
 * @param n The number to get the factorial of
 * @return long long The factorial of n
 */
long long	ft_factorial_ll(long long n);

/**
 * @brief Return fibonacci number at index n (exhaustive search)
 * 
 * @param n The index of the fibonacci number to get
 * @return int The fibonacci number at index n
 */
int			ft_fibonacci(int n);

/**
 * @brief Return fibonacci number at index n (exhaustive search) (long)
 * 
 * @param n The index of the fibonacci number to get
 * @return long The fibonacci number at index n
 */
long		ft_fibonacci_l(long n);

/**
 * @brief Return fibonacci number at index n (exhaustive search) (long long)
 * 
 * @param n The index of the fibonacci number to get
 * @return long long The fibonacci number at index n
 */
long long	ft_fibonacci_ll(long long n);

/**
 * @brief Returns a boolean (0 -- 1) if n is prime (exhaustive search)
 * 
 * @param n The number to check if prime
 * @return int 1 if n is prime, 0 if not
 */
int			ft_is_prime(int n);

/**
 * @brief Returns a boolean (0 -- 1) if n is prime (exhaustive search) (long)
 * 
 * @param n The number to check if prime
 * @return long 1 if n is prime, 0 if not
 */
long		ft_is_prime_l(long n);

/**
 * @brief Returns a boolean (0 -- 1) if
 *  n is prime (exhaustive search) (long long)
 * 
 * @param n The number to check if prime
 * @return long long 1 if n is prime, 0 if not
 */
long long	ft_is_prime_ll(long long n);

#endif