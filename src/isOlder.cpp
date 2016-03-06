/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int valid(char *dob1, char *dob2);
int num(char *a, int i);
int corr(int oneday, int onemon, int oneyar);
int young(int a, int b, int c, int d, int e, int f);
int isOlder(char *dob1, char *dob2) {

	if (dob1[2] == '-'&&dob2[2] == '-')
	{
		int	i = valid(dob1, dob2);
		return i;
	}
	else
		return -1;
}
int valid(char *dob1, char *dob2)
{
	int i = 0, l = 0, m = 0, oneday = 0, secday = 0, onemon = 0, secmon = 0, oneyar = 0, secyar = 0;
	oneday = num(dob1, 0);
	secday = num(dob2, 0);
	onemon = num(dob1, 3);
	secmon = num(dob2, 3);
	oneyar = num(dob1, 6);
	secyar = num(dob2, 6);
	l = corr(oneday, onemon, oneyar);
	m = corr(secday, secmon, secyar);
	i = young(oneyar, secyar, onemon, secmon, oneday, secday);

	if ((oneyar == secyar) && (onemon == secmon) && (oneday == secday))
		return 0;

	else if (onemon > 12 || onemon == 0 || secmon > 12 || secmon == 0)
		return -1;
	else if (l == 1 && m == 1)
		return i;
	else
		return -1;


}
int young(int a, int b, int c, int d, int e, int f)
{
	if (a > b)
		return 2;
	else if (a < b)
		return 1;
	else if (c > d)
		return 2;
	else if (c < d)
		return 1;
	else if (e > f)
		return 2;
	else
		return 1;
}
int num(char *a, int i)
{
	int  k = 0;
	while (a[i] != '-' && a[i] != '\0')
	{
		if (a[i] >= 48 || a[i] > 58)

			k = k * 10 + (a[i] - '0');
		else
		{
			return -1;
			break;
		}


		i++;
	}
	return k;
}

int corr(int oneday, int onemon, int oneyar)
{
	switch (onemon)
	{
	case 01:if (oneday > 31 || oneday <= 0)
		return -1;
			else
				return 1;
		break;

	case 02:if (oneyar % 4 == 0 && (oneyar % 100 != 0 || oneyar % 400 == 0))
	{
		if (oneday > 29 || oneday <= 0)
			return -1;
	}

			else
			{
				if (oneday > 28 || oneday <= 0) return -1;
			}

			return 1;
			break;
	case 03: if (oneday > 31 || oneday <= 0)  return -1;
			 else
				 return 1;
		break;
	case 04: if (oneday > 30 || oneday <= 0)  return -1;
			 else
				 return 1;
		break;
	case 05: if (oneday > 31 || oneday <= 0)  return -1;
			 else
				 return 1;
		break;
	case 06: if (oneday > 30 || oneday <= 0)  return -1;
			 else
				 return 1;
		break;
	case 07: if (oneday > 31 || oneday<0)  return -1;
			 else
				 return 1;
		break;
	case 8:
		if (oneday > 31 || oneday <= 0)  return -1;
		else
			return 1;
		break;
	case 9: if (oneday > 30 || oneday <= 0)  return -1;
			else
				return 1;
		break;
	case 10: if (oneday > 31 || oneday <= 0)  return -1;
			 else
				 return 1;
		break;
	case 11: if (oneday > 30 || oneday <= 0)  return -1;
			 else
				 return 1;
		break;
	case 12: if (oneday > 31 || oneday <= 0)  return -1;
			 else
				 return 1;
		break;
	default:return -1;
		break;

	}
}