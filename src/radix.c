/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpoussie <mpoussie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:50:27 by mpoussie          #+#    #+#             */
/*   Updated: 2023/07/26 20:39:40 by mpoussie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../push_swap.h"

void radix_sort(int arr[], int n)
{
    int *bucket;
    int count[10] = {0};
    int i, j, m, exp;

    m = arr[0];
    exp = 1;
    bucket = (int *)malloc(sizeof(int) * n);

    // Trouver la valeur maximale dans le tableau
    i = 1;
    while (i < n)
    {
        if (arr[i] > m)
            m = arr[i];
        i++;
    }

    // Effectuer le tri par les chiffres les moins significatifs aux plus significatifs
    while (m / exp > 0)
    {
        // Réinitialiser le tableau de compteurs
        i = 0;
        while (i < 10)
        {
            count[i] = 0;
            i++;
        }

        // Compter le nombre d'éléments à chaque position
        i = 0;
        while (i < n)
        {
            count[(arr[i] / exp) % 10]++;
            i++;
        }

        // Calculer les positions finales de chaque élément
        i = 1;
        while (i < 10)
        {
            count[i] += count[i - 1];
            i++;
        }

        // Placer les éléments dans le seau
        i = n - 1;
        while (i >= 0)
        {
            j = (arr[i] / exp) % 10;
            bucket[count[j] - 1] = arr[i];
            count[j]--;
            i--;
        }

        // Copier les éléments du seau vers le tableau d'origine
        i = 0;
        while (i < n)
        {
            arr[i] = bucket[i];
            i++;
        }

        exp *= 10;
    }

    free(bucket);
}
