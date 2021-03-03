#include "menger.h"

/**
 * menger - a function that draws a 2D Menger Sponge
 * @level: is the level of the Menger Sponge to draw
 */

void menger(int level)
{
    /*
     * @i: index
     * @c: column
     * @s: space
     * @r: rows
     */
	long int i, c, s, r;

	if (level < 0)
		return;
	if (level == 0)
	{
		printf("#\n");
		return;
	}
	for (i = 1; level > 0; level--)
		i *= 3;
	for (r = 1; r <= i; r++)
	{
		for (c = 1; c <= i; c++)
		{
			for (s = 1; s <= i; s *= 3)
			{
				if (r % s * 3 <= s * 2 &&
					r % s * 3 >= s + 1 &&
					c % s * 3 <= s * 2 &&
					c % s * 3 >= s + 1)
				{
					printf(" ");
					break;
				}
			}
			if (s > i)
				printf("#");
		}
		printf("\n");
	}
}
