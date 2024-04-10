/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pvass <pvass@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 13:51:31 by pvass             #+#    #+#             */
/*   Updated: 2024/04/09 19:54:04 by pvass            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	size_t	i;
	char	*ptr;

	i = 0;
	if (nitems == 0 || size == 0)
		return (NULL);
	ptr = (char *) malloc (nitems * size);
	if (ptr == NULL)
		return (NULL);
	while (i < nitems * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}

/*
#include <stdio.h>

int main()
{

	// This pointer will hold the
	// base address of the block created
	int* ptr;
	int n, i;

	// Get the number of elements for the array
	n = 5;
	printf("Enter number of elements: %d\n", n);

	// Dynamically allocate memory using calloc()
	ptr = (int*)ft_calloc(n, sizeof(int));

	// Check if the memory has been successfully
	// allocated by calloc or not
	if (ptr == NULL) {
		printf("Memory not allocated.\n");
		exit(0);
	}
	else {

		// Memory has been successfully allocated
		printf("Memory successfully allocated using calloc.\n");


		// Print the elements of the array
		printf("The elements of the array before fill are: ");
		for (i = 0; i < n; ++i) {
			printf("%d, ", ptr[i]);
		}
		
		// Get the elements of the array
		for (i = 0; i < n; ++i) {
			ptr[i] = i + 1;
		}

		// Print the elements of the array
		printf("The elements of the array are: ");
		for (i = 0; i < n; ++i) {
			printf("%d, ", ptr[i]);
		}
	}

	return 0;
}
*/