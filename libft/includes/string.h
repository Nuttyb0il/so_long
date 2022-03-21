/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jallerha <jallerha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:34:07 by jallerha          #+#    #+#             */
/*   Updated: 2022/03/21 11:36:33 by jallerha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

# include <stdlib.h>
# include <unistd.h>
# include "../includes/lists.h"

/**
 * @brief Returns the first occurrence of the character c in the string s
 * 
 * @param s The string
 * @param c The character to find
 * @return char* The pointer to the 
 * first occurrence of the character c in the string s
 */
char		*ft_strchr(char *s, int c);

/**
 * @brief Copy src to dest, and append null-byte
 * 
 * @param dest The destination string
 * @param src The source string
 * @return char* The pointer to the destination string
 */
char		*ft_strcpy(char *dest, char *src);

/**
 * @brief Creates a free-able copy of s
 * 
 * @param s The string to copy
 * @return char* The pointer to the copy of s
 */
char		*ft_strdup(char *s);

/**
 * @brief Concatenates n bytes from src to dest
 * 
 * @param dest The destination string
 * @param src The source string
 * @param n The number of bytes to concatenate
 * @return char* The pointer to the destination string
 */
char		*ft_strncat(char *dest, char *src, size_t n);

/**
 * @brief Copy n bytes from src to dest
 * 
 * @param dest The destination string
 * @param src The source string
 * @param n The number of bytes to copy
 * @return char* The pointer to the destination string
 */
char		*ft_strncpy(char *dest, char *src, size_t n);

/**
 * @brief Append and prepend padding spaces to the string s
 * 
 * @param s The string to pad
 * @param padding The number of spaces to pad 
 * (if odd, the right side will be padded more)
 * @return char* The pointer to a copy the padded string
 */
char		*ft_center(char *s, int padding);

/**
 * @brief Replace all occurrences of old with new in str
 * 
 * @param str The string to modify
 * @param old The string to replace
 * @param new The string to replace old with
 * @return char* The pointer to a copy of the modified string
 */
char		*ft_replace(char *str, char *old, char *new);

/**
 * @brief Join all strings in the list with the separator,
 * separator won't be added at both ends of the joined string
 * 
 * @param separator The separator to join the strings with
 * @param iterable The list of strings to join
 * @return char* The pointer to a copy of the joined list
 */
char		*ft_strjoin(char *separator, t_chain_lst *iterable);

/**
 * @brief Set first n bytes of target to c
 * 
 * @param target The target string
 * @param c The character to set
 * @param n The number of bytes to set
 * @return char* The pointer to the target string
 */
char		*ft_strnset(char *target, char c, size_t n);

/**
 * @brief Search for the last occurrence of
 *  the character c in the string s
 * 
 * @param s The string
 * @param c The character to find
 * @return char* The pointer to the last
 *  occurrence of the character c in the string s
 */
char		*ft_strrchr(char *s, int c);

/**
 * @brief Search for the last occurrence of the string 
 * needle in the string haystack
 * 
 * @param needle The string to find
 * @param haystack The string to search in
 * @return char* The pointer to the last occurrence of 
 * the string needle in the string haystack
 */
char		*ft_strrstr(char *needle, char *haystack);

/**
 * @brief Set every char of target to c
 * 
 * @param target The target string
 * @param c The character to set
 * @return char* The pointer to the target string
 */
char		*ft_strset(char *target, char c);

/**
 * @brief Search for the first occurrence of string needle in haystack
 * 
 * @param needle The string to find
 * @param haystack  The string to search in
 * @return char* The pointer to the first occurrence
 *  of the string needle in the string haystack
 */
char		*ft_strstr(char *needle, char *haystack);

/**
 * @brief Return the substring of s starting at index 
 * start and ending at index end
 * 
 * @param s The string to cut
 * @param start The index of the first character to cut
 * @param len The length of the substring
 * @return char* The pointer to a copy of the substring
 */
char		*ft_strsub(char const *s, unsigned int start, size_t len);

/**
 * @brief Set a fixed length string to a variable length string,
 * will prepend missing characters with '0'
 * @param s The string to fill with '0'
 * @param n The wanted length of the string
 * @return char* The pointer to a copy the fixed-length string
 */
char		*ft_zfill(char *s, int n);

/**
 * @brief Count occurrences of the char c in string s
 * 
 * @param s The string
 * @param c The character to count
 * @return int The number of occurrences of the character c in the string s
 */
int			ft_ccnt(char *s, char c);

/**
 * @brief Count occurrences of needle in haystack
 * 
 * @param haystack The string to search in
 * @param needle The string to find
 * @return int The number of occurrences of the string
 *  needle in the string haystack
 */
int			ft_count_words(char *haystack, char *needle);

/**
 * @brief Checks if s endswith suffix
 * 
 * @param s The string to check
 * @param suffix The suffix to check
 * @return int 1 if s ends with suffix, 0 otherwise
 */
int			ft_endswith(char *s, char *suffix);

/**
 * @brief Return the index of first occurrence of needle in haystack
 * 
 * @param haystack The string to search in
 * @param needle The string to find
 * @return int The index of the first occurrence of the 
 * string needle in the string haystack
 */
int			ft_index(char *haystack, char *needle);

/**
 * @brief Checks if s startswith prefix
 * 
 * @param s The string to check
 * @param prefix The prefix to check
 * @return int 1 if s starts with prefix, 0 otherwise
 */
int			ft_startswith(char *s, char *prefix);

/**
 * @brief Returns the difference (case-sensitive) between s1 and s2
 * 
 * @param s1 The first string
 * @param s2 The second string
 * @return int The difference between s1 and s2
 */
int			ft_strcmp(char *s1, char *s2);

/**
 * @brief Returns the difference (case-insensitive) between s1 and s2
 * 
 * @param s1 The first string
 * @param s2 The second string
 * @return int The difference between s1 and s2
 */
int			ft_strcmpi(char *s1, char *s2);

/**
 * @brief Returns the number of chars between str and first occurrence of charset
 * 
 * @param str The string to search in
 * @param charset The string to search for
 * @return int The number of chars between str and first occurrence of charset
 */
int			ft_strcspn(char *str, char *charset);

/**
 * @brief Count how many chars are in str (excluding '\0')
 * 
 * @param str The string to count
 * @return int The number of chars in str
 */
int			ft_strlen(char *str);

/**
 * @brief The difference in n first bytes between s1 and s2 (case-sensitive)
 *  
 * @param s1 The first string
 * @param s2 The second string
 * @param n The number of bytes to compare
 * @return int The difference in n first bytes between s1 and s2
 */
int			ft_strncmp(char *s1, char *s2, size_t n);

/**
 * @brief Split lines in str (\\r\\n or \\n, not both at the same time)
 * 
 * @param str The string to split
 * @return t_chain_lst* The list of lines
 */
t_chain_lst	*ft_split_lines(char *str);

/**
 * @brief Returns a chained list of strings split by the given separator
 * 
 * @param str The string to split
 * @param word The separator
 * @return t_chain_lst* The list of strings
 */
t_chain_lst	*ft_split(char *str, char *word);

/**
 * @brief Capitalize every first letter of every word in str
 * 
 * @param str The string to capitalize
 */
void		ft_capitalize(char *str);

/**
 * @brief Remove every blanks at the start of str
 * 
 * @param s The string to trim
 */
void		ft_lstrip(char *s);

/**
 * @brief Remove every blanks at the end of s
 * 
 * @param s The string to trim
 */
void		ft_rstrip(char *s);

/**
 * @brief Concatenate src to dest
 * 
 * @param dest The destination string
 * @param src The source string
 */
void		ft_strcat(char *dest, char *src);

/**
 * @brief Remove every blanks at end and start of str
 * 
 * @param s The string to trim
 */
void		ft_strip(char *s);

/**
 * @brief Transform every char of str to lowercase
 * 
 * @param s The string to transform
 */
void		ft_strlwr(char *s);

/**
 * @brief Reverse passed string
 * 
 * @param s The string to reverse
 */
void		ft_strrev(char *s);

/**
 * @brief Transform every char of str to uppercase
 * 
 * @param s The string to transform
 */
void		ft_strupr(char *s);

/**
 * @brief Reverse case of every char of str (upper to lower, lower to upper)
 * 
 * @param str The string to reverse case
 */
void		ft_swapcase(char *str);

/**
 * @brief Compare n-bytes of two memory blocks
 * 
 * @param s1 The first memory block
 * @param s2 The second memory block
 * @param n The number of bytes to compare
 * @return int The difference between s1 and s2
 */
int			ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief Returns the first occurrence of byte c in memory block s
 * 
 * @param s The memory block
 * @param c The byte to find
 * @param n The number of bytes to search
 * @return void* The pointer to the first occurrence of byte c in memory block s
 */
void		*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief Copy n bytes from memory block src to memory block dest
 * 
 * @param dest The destination memory block
 * @param src The source memory block
 * @param n The number of bytes to copy
 * @return void* The pointer to the destination memory block
 */
void		*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief Move n bytes from memory block src to memory block dest
 * 
 * @param dest The destination memory block
 * @param src The source memory block
 * @param n The number of bytes to move
 * @return void* The pointer to the destination memory block
 */
void		*ft_memmove(void *dest, const void *src, size_t n);

/**
 * @brief Returns the last occurrence of byte c in memory block s
 * 
 * @param s The memory block
 * @param c The byte to find
 * @param n The number of bytes to search
 * @return void* The pointer to the last occurrence of byte c in memory block s
 */
void		*ft_memrchr(const void *s, int c, size_t n);

/**
 * @brief Set len-bytes of memory block s to byte c
 * 
 * @param b The memory block
 * @param c The byte to set
 * @param len The number of bytes to set
 * @return void* The pointer to the memory block
 */
void		*ft_memset(void *b, int c, size_t len);

/**
 * @brief Set n bytes of memory block s to 0x00
 * 
 * @param s The memory block
 * @param n The number of bytes to set
 */
void		ft_bzero(void *s, size_t n);

/**
 * @brief Returns a new malloc'd concatenated string of s1 and s2
 * 
 * @param s1 The first string
 * @param s2 The second string
 */
char		*ft_strsjoin(char *s1, char *s2);
#endif