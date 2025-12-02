#include <stdbool.h>

bool kLengthApart(int* nums, int numsSize, int k) {
    int i = 0;
	int j;
	int count;

	while (i < numsSize && nums[i] != 1)
		i++;
	i = i + 1;
    while (i < numsSize)
	{
		if (nums[i] == 1)
		{
			if (j < k)
				return (false);
			j = 0;
		}
		else
			j++;
		i++;
	}
	return (true);
}