#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	string kat_name("C:/Program/prob/tabl.txt");
	system("md C:\\Program\\prob");

	ifstream file(kat_name);
	if (file.is_open())
	{
		string line;
		while (getline(file, line))
			cout << line << endl;
		if (!file.eof())
			runtime_error("Некорректные данные в файле test.txt");
	}
	else
	{
		file.close();
		ofstream outfile(kat_name);
		cout << "Создание файла и его заполнение";
		for (int i = 2; i < 10; i++)
		{
			for (int j = 2; j < 10; j++)
			{
				outfile << to_string(j) << " * " << to_string(i) << " = " << to_string(i * j) << "\t";
			}
			outfile << '\n';
		}
		outfile.close();
	}
}
