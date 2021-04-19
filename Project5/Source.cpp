#include<iostream>
#include<fstream>
#include<string>
using namespace std; 
int main(void)
{
	setlocale(LC_ALL, "ru");
	int i=0;
		system("md C:\\Program\\prob");
		ifstream appf("C:/Program/prob/Средняя_погода_В_Дурке.txt");
		double mass[9], summ = 0;
		for (int i = 0; i < 9; i++)
		{
			appf >> mass[i];
			summ += mass[i];
		}
		if (!appf.eof())
		{
			runtime_error("hui");
		}
		appf.close();
		summ = summ / 9;
		int y = 0;
		for (int i = 0; i < 9; i++)
			if (mass[i] < summ)
				y++;
		cout << y;	
}	
