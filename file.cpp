#include<stdio.h>

int main()
{
	char s[10] ;
	FILE *fin = fopen("input_01.txt","r");
	FILE *fout = fopen("ouput_01.txt","w");

	while(fscanf(fin, "%s", s)==1)
	{
		if((s[0] >=65 && s[0] <= 90) || (s[0] >= 97 && s[0] <= 122))
			fprintf(fout, "%s = string.\n", s);

		else if(s[0] >= 48 && s[0] <= 57)
			fprintf(fout, "%s = Number.\n", s);

		else if(s[0] >= 37 && s[0] <= 47)
		{
			if(s[0] == '-' && ((s[1] >=65 && s[1] <= 90) || (s[1] >= 97 && s[1] <= 122)))
				fprintf(fout, "%s = String cann't be negative.\n", s);
			else if(s[0] == '-' && (s[1] >= 48 && s[1] <= 57))
				fprintf(fout, "%s = negative value.\n", s);
			else
				fprintf(fout, "%s = Operator.\n", s);
		}
	}
	

	fclose(fin);
	fclose(fout);

	return 0;
}