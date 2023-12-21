/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aconti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:20:23 by aconti            #+#    #+#             */
/*   Updated: 2023/10/20 17:21:29 by aconti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
//#include <stdio.h>

int	count_words(const char *s, char c)
{
	int	count;
	int	word;

	count = 0;
	word = 0;
	while (*s)
	{
		if (*s == c)
		{
			word = 0;
		}
		else
		{
			if (word == 0)
			{
				count++;
				word = 1;
			}
		}
		s++;
	}
	return (count);
}

char	*copy_word(const char *s, char c)
{
	int		l;
	char	*word;
	int		i;

	l = 0;
	i = 0;
	while (s[l] && s[l] != c)
		l++;
	word = (char *)malloc(l + 1);
	if (!word)
		return (NULL);
	while (i < l)
	{
		word[i] = s[i];
		i++;
	}
	word[l] = '\0';
	return (word);
}

char	**scorp(char **result, char const *s, char c, int i)
{
	int	j;

	j = 0;
	while (*s)
	{
		if (*s != c)
		{
			result[i] = copy_word(s, c);
			if (!result[i])
			{
				j = 0;
				while (j++ < i)
					free (result[j]);
				free (result);
				return (NULL);
			}
			i++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	result[i] = 0;
	return (result);
}

char	**ft_split(char const *s, char c)
{
	int		n;
	char	**result;
	int		i;

	if (!s)
		return (NULL);
	n = count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (n + 1));
	if (!result)
		return (NULL);
	i = 0;
	result = scorp(result, s, c, i);
	return (result);
}

/*int main() {
    char const *input_string = "  il comunismo  .  fa   cagare  ";
    char separator = ' ';

    char **result = ft_split(input_string, separator);

    if (result) {
        for (int i = 0; result[i] != NULL; i++) {
            printf("%s\n", result[i]);
        }

        // Liberare la memoria allocata
        for (int i = 0; result[i] != NULL; i++) {
            free(result[i]);
        }
        free(result);
    } else {
        printf("Errore durante la divisione della stringa.\n");
    }

    return 0;
}*/
