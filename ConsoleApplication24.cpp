// ConsoleApplication24.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include<vector>
#include<ctime>
#include<cmath>
#include<string>
#include<fstream>
#include<cstdio>
#include<ctime>
using namespace std;
#include"Linear.h"
#include"ActivationFunctions.h"
#include "Perceptron.h"
#include "FileProcessing.h"

int main()
{
	//Network P;
	////P.InitData("Picture.txt", 28, 5);
	////GenerateRandomWeights("11.txt", "22.txt", "33.txt", "44.txt");
	//ifstream in("DataSet.txt");
	//ReadData(in, 28, 5, P);	
	//InitWeigthsFunc("W11.txt", "W22.txt", "W33.txt", "W44.txt",P);

	//P.GenerateOutput();
	//for (int i = 0; i < 15000; i++)
	//{
	//	P.Reset();
	//	ReadData(in, 28, 5, P);
	//}
	//

	//for (int count = 0; count <5000; count++)
	//{
	//	//ReadData(in, 28, 5, P);
	//	P.GenerateOutput();
	//	//int G = 0;
	//	double LR = 0.05;
	//    if(!Check(P.output, P.ideal_output, 0.1))
	//	{
	//		P.ChangeWeights(LR);
	//		//P.GenerateOutput();
	//		//cout << P.output.at(1) << endl;
	//		//G++;
	//		//LR = LR*pow(2,G/15);
	//	}
	//	cout << "-------------------------------" <<count<< endl;
	//	P.Reset();
	//	ReadData(in, 28, 5, P);
	//}

	////ReadData(in, 28, 5, P);
	//P.GenerateOutput();

	//cout << endl;
	//int k = 0;
	//for (int i = 0; i < 5; i++)
	//{
	//	for (int j = 0; j < 5; j++)
	//	{
	//		cout << P.output.at(k)<<" ";
	//		k++;
	//	}
	//	cout << endl;
	//}

	//cout << endl << endl;
	//int c = 0;
	//for (int i = 0; i < 5; i++)
	//{
	//	for (int j = 0; j < 5; j++)
	//	{
	//		cout << P.ideal_output.at(c) << " ";
	//		c++;
	//	}
	//	cout << endl;
	//}

	//OutWeightsToFiles("W111.txt", "W222.txt", "W333.txt", "W444.txt", P);

	//in.close();

	setlocale(LC_ALL, "Russian");
	//Network P;
	////GenerateRandomWeights("R1.txt", "R2.txt", "R3.txt", "R4.txt");
	//ifstream in("DataSet.txt");
	//ReadData(in, 28, 5, P);
	//InitWeigthsFunc("11.txt", "22.txt", "33.txt", "44.txt", P);
	//
	//P.GenerateOutput();
	//for (int i = 0; i < 15000; i++)
	//{
	//	P.Reset();
	//	ReadData(in, 28, 5, P);
	//}
	//

	//double s = 0;
	//for (int i = 0; i < 1000; i++)
	//{
	//	P.GenerateOutput();
	//	s += Nev(P.output, P.ideal_output);
	//	P.Reset();
	//	ReadData(in, 28, 5, P);
	//}

	//cout <<"Средняя невязка одного пикселя для случайных весов:"<< s / 1000<<endl;
	//in.close();

	Network Q;
	//GenerateRandomWeights("R1.txt", "R2.txt", "R3.txt", "R4.txt");
	ifstream in2("DataSet.txt");
	ReadData(in2, 28, 5, Q);
	InitWeigthsFunc("W111.txt", "W222.txt", "W333.txt", "W444.txt", Q);
	Q.GenerateOutput();
	/*
	double sum = 0;
	for (int i = 0; i < 1000; i++)
	{

		Q.GenerateOutput();
		sum += Nev(Q.output, Q.ideal_output);

		if (!Check(Q.output, Q.ideal_output, 0.1)) {
			int k = 0;
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					cout << Q.output.at(k) << " ";
					k++;
				}
				cout << endl;
			}

			cout << endl << endl;

			int c = 0;
			for (int i = 0; i < 5; i++)
			{
				for (int j = 0; j < 5; j++)
				{
					cout << Q.ideal_output.at(c) << " ";
					c++;
				}
				cout << endl;
			}
		}

		Q.Reset();
		ReadData(in2, 28, 5, Q);

		cout << endl;

		
	}*/

	ofstream out("outpicture.txt");
	for (int i = 0; i < 10; i++)
	{
		OutPicture(out, Q);
		Q.Reset();
		ReadData(in2, 28, 5, Q);
		Q.GenerateOutput();
	}
	out.close();
	//cout << "Средняя невязка одного пикселя для весов, полученных путем обучения:" << sum / 1000<<endl;
	in2.close();
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
