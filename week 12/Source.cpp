#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int str(char* arr)
{
	int i = 0;
	while (arr[i] != '\0')
	{
		if (arr[i] >= 'a' && arr[i] <= 'z' || arr[i] == ' ')
		{
			i++;
		}
		else return -1;
		
	}
	return i;
}
int main()
{
	char arr[10000];
	scanf("%[^\n]", &arr);
	char ch[100];
	int num = 0;
	int check = 0;
	int max = 0;
	if (str(arr) == -1) { printf("error"); return 0; }
	for (int i = 0; i < str(arr); i++)
	{
		if (arr[i] == ' ') break;
		for (int j = 0; j < str(arr); j++)
		{
			for (int k = 0; k <= num;k++)
			{
				if (arr[i] == ch[k])
				{
					check = 0;
					break;
				}
			}
			if (arr[i] == arr[j])
			{
				check++;
			}
		}
		if (check > max)
		{
			ch[num] = arr[i];
			max = check;
			check = 0;
		}
		else if (check == max)
		{
			num++;
			ch[num] = arr[i];
			check = 0;
		}
		else
		{
			check = 0;
		}
	}
	for (int i = 0; i <= num; i++)
	{
		printf("%c ", ch[i]);
	}
	printf("\n%d", max);
	return 0;
}