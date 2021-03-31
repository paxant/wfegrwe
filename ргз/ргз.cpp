#include<iostream>  
#include <cmath>
#define _USE_MATH_DEFINES 
#include <ATLComTime.h>
#include<vector>
#include <iomanip>
#include<fstream>
#include<string>
using namespace std; 
typedef long double D; 
long kf = 0; 
D fun(D h) 
{
	kf++; 
	return sin(h) / (1 - sin(h));
}
D PF(D x) 
{
	return -x + tan((M_PI / 4) + x / 2); 
}
D NK_4(D a, D b, D esp) 
{
	D k = 1.;
	vector<D>INTEG; 
	D n = 4.; 
	D N = 90.; 
	D summ;
	vector<D>H{ 32.0 / N,12.0 / N,32.0 / N,14.0 / N }; 
	do 
	{
		do 
		{
			D H_0 = 7 / 90; 
			D l = (b - a) / k;
			summ = 0; 
			vector<D>X{ a };
			D h = (b - a) / (n * k);
			int j;
			for (int i = 1; i <= n * k - 1; i++) 
				X.push_back(X[0] + i * h);
			for (int i = 1; i <= n * k - 1; i++) 
			{
				j = (i - 1) % (int)n;
				summ += H[j] * fun(X[i]);
			}
			k *= 2;
			INTEG.push_back(l * ((fun(a) + (fun(b))) * H_0 + summ)); 
		} while (INTEG.size() < 2);
	} while (abs(INTEG[INTEG.size() - 2] - INTEG[INTEG.size() - 1]) > esp);
	return INTEG[INTEG.size() - 1]; 
}
D Gaus_2(D a, D b, D esp)
{
	D k = 1.;
	D n = 2.;
	vector<D>X_i{ 0.2113249, 0.7886751 };
	D A_i = 0.5;                          
	D summ = NULL;   
	D summ_1 = NULL;
	vector<D>INTEG; 
	do 
	{
		do 
		{
			D h = (b - a) / k;                   
			summ = NULL;   
			summ_1 = NULL;
			vector<D>X_j{ a };
			vector<vector<D>>X_i_j; 
			for (int j = 1; j <= k; j++) 
			{
				X_j.push_back(X_j[j - 1] + h);  
				vector<D>H;
				for (int i = 0; i < n; i++)
				{
					H.push_back(X_j[j - 1] + X_i[i] * h);
				}
				X_i_j.push_back(H); 
				summ_1 = NULL;
				for (int i = 0; i < n; i++) 
				{
					summ_1 += A_i * fun(X_i_j[j - 1][i]);
				}
				summ += summ_1;
			}
			INTEG.push_back(h * summ); 
			k *= 2;						
		} while (INTEG.size() <= 2);
	} while (abs(INTEG[INTEG.size() - 2] - INTEG[INTEG.size() - 1]) > esp);
	return INTEG[INTEG.size() - 1];		
}
void print(D vf, D esp, D gf, long kg_1, D nf)  
{
	system("md C:\\Program\\prob");  
	ofstream appf("C:/Program/prob/Fail.txt", ios::app);
	appf << "Точное значение интеграла: " << vf << '\n';       
	appf << "Требуемая точность вычисления интеграла = " << esp << '\n';
	appf << "Гаус для n = 2. Интеграл = " << gf << '\n';
	appf << "К-во обращений: " << kg_1 << '\n';
	appf << "Ньютон–Котес для n = 4. Интеграл = " << nf << "\n";
	appf << "К-во обращений: " << kf << "\n \n";
	appf.close(); 
}
int main(void) 
{
	setlocale(LC_ALL, "ru"); 
	D a = -1., b = 1.5, gh, esp; 
	while (true) 
	{
		cout << setprecision(16) << "Введите количество знаков после запятой" << '\n'; 
		cin >> gh; 
		esp = pow(10, -gh); 
		D vf = PF(b) - PF(a); 
		cout << "Точное значение интеграла: " << vf << '\n';
		cout << "Требуемая точность вычисления интеграла = " << esp << '\n';
		kf = 0; 
		D gf = Gaus_2(a, b, esp); 
		cout << "Гаус для n = 2. Интеграл = " << gf << '\n';
		long kg_1 = kf;
		cout << "К-во обращений: " << kg_1 << '\n';
		kf = 0;
		D nf = NK_4(a, b, esp); 
		cout << "Ньютон–Котес для n = 4. Интеграл = " << nf << "\n";
		cout << "К-во обращений: " << kf << "\n\n";
		print(vf, esp, gf, kg_1, nf); 
	}
}