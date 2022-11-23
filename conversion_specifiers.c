#include "main.h"

/**
 * format_specifier_element_num - returns the position of a conversio
n speciefer, which is also the number of character that make up a given format specifier.
 * @p: string representing our format specifier
 * @i: index of that string, @p
 * Return: an non-zero integer representing the position of conversio
n
 *      specifier in a formart specifier, otherwise a zero value
 */

int format_specifier_elements_number(const char* const p, int i)
{
        int format_specifier_element_num = 0;
        while (!is_conversion_specifier(p[i]))
        {
                format_specifier_element_num += 1;
                i += 1;
        }
        return (format_specifier_element_num);
}

/**
 * is_conversion_specifier - checks if a character is a conversion sp
ectfier
 * @c: character to be checekd
 * Return: 1 if @c is a conversion specifier, otherwise 0
 */
int is_conversion_specifier(char c)
{
        const int conversion_specifier_size = 11;
        char conversion_specifier[] = {'c', 's', 'd', 'i', 'b', 'u',
'o', 'x', 'X', 'S', 'p'};
        int conversion_specifier_index = 0;
        while (conversion_specifier[conversion_specifier_index] != c
&& conversion_specifier_index < conversion_specifier_size)
                conversion_specifier_index += 1;;
        if (conversion_specifier_index < conversion_specifier_size)
                return(1);
        return (0);
}

/**
 * get_conversion_type - checks the data type of a given conversion specifier
 * @c: character to be checekd
 * Description: returrn value eqaul to minus one shows that @c has an unkhonwn type. return value less than nine means that @c has is of type 'char' or 'int'. return value less than eleven means that @c has type 'string'
 * Return: appropeiate intger value corresponding to the type of @c
 */
int get_conversion_type(char c)
{
        const int conversion_specifier_size = 11;
        char conversion_specifier[] = {'c', 'd', 'i', 'b', 'u',
'o', 'x', 'X', 'p', 's', 'S'};
        int conversion_specifier_index = 0;
        while (conversion_specifier[conversion_specifier_index] != c
&& conversion_specifier_index < conversion_specifier_size)
                conversion_specifier_index += 1;;
        if (conversion_specifier_index < conversion_specifier_size)
                return(conversion_specifier_index);
        return (-1);
}
