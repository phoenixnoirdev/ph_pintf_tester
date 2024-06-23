/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fic.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phkevin <phkevin@42luxembourg.lu>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 19:44:41 by phkevin           #+#    #+#             */
/*   Updated: 2024/06/23 19:46:50 by phkevin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintftest.h"

int sortfic1(void)
{
    FILE *tmp1 = freopen("tmp1.txt", "w+", stdout);
    if (tmp1 == NULL) {
		perror("freopen");
		return 1;
    }
    return 0;
}

int sortfic2(void)
{
    FILE *tmp2 = freopen("tmp2.txt", "w+", stdout);
    if (tmp2 == NULL) {
		perror("freopen");
		return 1;
    }
    return 0;
}

int comptfic(void)
{
    FILE *fp1 = fopen("tmp1.txt", "r");
    FILE *fp2 = fopen("tmp2.txt", "r");
    
    if (fp1 == NULL || fp2 == NULL)
        exit(EXIT_FAILURE);
     
    char line1[LINE_LENGTH];
    char line2[LINE_LENGTH];
    int line_number = 1;
    int differences = 0;

    while (fgets(line1, LINE_LENGTH, fp1) != NULL && fgets(line2, LINE_LENGTH, fp2) != NULL)
    {
        if (strcmp(line1, line2) != 0)
            differences++;
        line_number++;
    }

    // Check for extra lines in file1
    while (fgets(line1, LINE_LENGTH, fp1) != NULL)
    {
        differences++;
        line_number++;
    }

    // Check for extra lines in file2
    while (fgets(line2, LINE_LENGTH, fp2) != NULL)
    {
        differences++;
        line_number++;
    }

    fclose(fp1);
    fclose(fp2);
    
    if (differences == 0)
        return 0;
    return 1;
}