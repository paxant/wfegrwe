#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream input("C:/Program/prob/�������_������_�_�����.txt");
    float ch;
    int Count = 0;
    while (input >> ch)
        Count++;
    cout << "����� � ����� : " << Count << endl;
    input.close();

    float* mass = new float[Count];
    ifstream file("C:/Program/prob/�������_������_�_�����.txt");
    for (int i = 0; i < Count; i++) {
        file >> mass[i];
        cout << mass[i] << endl;
    }

    delete[]  mass;
    system("pause");
    return 0;
}