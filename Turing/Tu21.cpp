#include "Tu21.h"
#include <iostream>

std::string Tu21::Machine()
{
	//String Name is str
	//put your code here
	int a = 0, b = 0, counter = 0, num = 0;
	bool passed = true, queue = false;
	while (counter < str.length())
	{
		q = 0;
		switch (str[counter])
		{
		case '*':
			queue = false;
			break;
		default:
			if (!queue && (str[counter] == '0' || str[counter] == '1'))
			{
				queue = true;
				num++;
			}
			if (num == 1 && (str[counter] == '0' || str[counter] == '1'))
			{
				a++;
			}
			else if (str[counter] == '0' || str[counter] == '1')
			{
				b++;
			}
			else
				passed = false;
			break;
		}
		counter++;
	}

	if (a != b || !passed || num > 2)
	{
		std::cerr << "Input is wrong!" << std::endl;
		return "";
	}

	while (q != -1)
	{
		switch (q)
		{
		case 0:
			q = 5;
			position--;
			break;
		case 1:
			switch (str[position])
			{
			case '*':
				q = 2;
				position--;
				break;
			default:
				position--;
				break;
			}
			break;
		case 2:
			switch (str[position])
			{
			case '0':
				q = 3;
				str[position] = 'x';
				position++;
				break;
			case '1':
				q = 4;
				str[position] = 'x';
				position++;
				break;
			default:
				position--;
				break;
			}
			break;
		case 3:
			switch (str[position])
			{
			case 'c':
				str[position] = 'l';
				position--;
				q = 5;
				break;
			case 'd':
				str[position] = 'l';
				position--;
				q = 5;
				break;
			default:
				position++;
				break;
			}
			break;
		case 4:
			switch (str[position])
			{
			case 'c':
				str[position] = 'a';
				q = 5;
				position--;
				break;
			case 'd':
				str[position] = 'b';
				q = 5;
				position--;
				break;
			default:
				position++;
				break;
			}
			break;
		case 5:
			switch (str[position])
			{
			case '*':
				position++;
				q = 6;
				break;
			case '0':
				str[position] = 'c';
				position--;
				q = 1;
				break;
			case '1':
				str[position] = 'd';
				position--;
				q = 1;
				break;
			}
			break;
		case 6:
			switch (str[position])
			{
			case '*':
				q = 7;
				position--;
				break;
			default:
				position++;
				break;
			}
			break;
		case 7:
			switch (str[position])
			{
			case 'a':
				q = 12;
				position--;
				break; 
			case 'b':
				q = 12;
				position--;
				break;
			case '*':
				position--;
				q = -1;
				break;
			case 'l':
				q = 13;
				position--;
				break;
			}
			break;
		case 8:
			switch (str[position])
			{
			case 'l':
				position++;
				break;
			default:
				q = 10;
				position--;
				break;
			}
			break;
		case 9:
			switch (str[position])
			{
			case 'l':
				position++;
				break;
			default:
				q = 11;
				position--;
				break;
			}
			break;
		case 10:
			str[position] = 'a';
			position--;
			q = 7;
			break;
		case 11:
			str[position] = 'b';
			position--;
			q = 7;
			break;
		case 12:
			switch (str[position])
			{
			case 'l':
				q = 13;
				position--;
				break;
			case '*':
				position--;
				q = 14;
				break;
			default:
				position--;
				break;
			}
			break;
		case 13:
			switch (str[position])
			{
			case 'a':
				q = 8;
				str[position] = 'l';
				position++;
				break;
			case 'b':
				q = 9;
				str[position] = 'l';
				position++;
				break;
			case '*':
				position--;
				q = 14;
				break;
			default:
				position--;
				break;
			}
			break;
		case 14:
			switch (str[position])
			{
			case '*':
				q = 15;
				position++;
				break;
			default:
				position--;
				break;
			}
			break;
		case 15:
			switch (str[position])
			{
			case 'a':
				str[position] = '*';
				position++;
				q = 17;
				break;
			case 'b':
				str[position] = '1';
				q = 16;
				position++;
				break;
			case 'l':
				str[position] = '*';
				position++;
				q = 19;
				break;
			default:
				str[position] = '*';
				position++;
				break;
			}
			break;
		case 16:
			switch (str[position])
			{
			case 'a':
				str[position] = '0';
				position++;
				break;
			case 'b':
				str[position] = '1';
				position++;
				break;
			case '*':
				q = -1;
				break;
			}
			break;
		case 17:
			switch (str[position])
			{
			case 'a':
				str[position] = '*';
				position++;
				break;
			case 'b':
				str[position] = '1';
				q = 18;
				position++;
				break;
			case '*':
				q = -1;
				break;
			case 'l':
				str[position] = '*';
				position++;
				break;
			}
			break;
		case 18:
			switch (str[position])
			{
			case 'a':
				str[position] = '0';
				position++;
				break;
			case 'b':
				str[position] = '1';
				position++;
				break;
			case '*':
				q = -1;
				break;
			}
			break;
		case 19:
			switch (str[position])
			{
			case 'a':
				str[position] = '*';
				q = 18;
				position++;
				break;
			case 'b':
				str[position] = '1';
				q = 18;
				position++;
				break;
			case '*':
				q = -1;
				break;
			case 'l':
				str[position] = '*';
				position++;
				break;
			}
			break;
		}
	}


	return GetString();
}