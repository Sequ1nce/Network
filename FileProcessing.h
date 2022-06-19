#pragma once
void OutWeightsToFiles(string filename1, string filename2, string filename3, string filename4,Network &P)
{
	remove(filename1.c_str());
	remove(filename2.c_str());
	remove(filename3.c_str());
	remove(filename4.c_str());

	ofstream out1(filename1);
	ofstream out2(filename2);
	ofstream out3(filename3);
	ofstream out4(filename4);

	for (int i = 0; i < P.weight_for_first.size(); i++)
	{
		for (int j = 0; j < P.weight_for_first.at(0).size(); j++)
		{
			out1 << P.weight_for_first.at(i).at(j) << " ";
		}
		out1 << endl;
	}

	for (int i = 0; i < P.weight_Bias_for_first.size(); i++)
	{
		out2 << P.weight_Bias_for_first.at(i) << " ";
	}

	for (int i = 0; i < P.weight_for_second.size(); i++)
	{
		for (int j = 0; j < P.weight_for_second.at(0).size(); j++)
		{
			out3 << P.weight_for_second.at(i).at(j) << " ";
		}
		out3 << endl;
	}

	for (int i = 0; i < P.weight_Bias_for_second.size(); i++)
	{
		out4 << P.weight_Bias_for_second.at(i) << " ";
	}

	out1.close();
	out2.close();
	out3.close();
	out4.close();
}

void InitWeigthsFunc(string filename1, string filename2, string filename3, string filename4,Network &P) {

	if (P.input_for_first.size() == 0)
		throw "need init data";

	ifstream in1(filename1);

	P.weight_for_first.resize(P.size_of_second_stratum);
	for (int i = 0; i < P.weight_for_first.size(); i++)
	{
		P.weight_for_first.at(i).resize(P.input_for_first.size());
	}

	for (int i = 0; i < P.weight_for_first.size(); i++)
	{
		for (int j = 0; j < P.weight_for_first.at(0).size(); j++)
		{
			double a;
			in1 >> a;
			P.weight_for_first.at(i).at(j) = a;
			//cout << a << " ";
		}
		//cout << endl;
	}

	P.weight_Bias_for_first.resize(P.size_of_second_stratum);

	ifstream in2(filename2);

	for (int i = 0; i < P.weight_Bias_for_first.size(); i++)
	{
		double a;
		in2 >> a;
		P.weight_Bias_for_first.at(i) = a;
	}

	ifstream in3(filename3);
	P.weight_for_second.resize(P.ideal_output.size());
	for (int i = 0; i < P.weight_for_second.size(); i++)
	{
		P.weight_for_second.at(i).resize(P.size_of_second_stratum);
	}

	for (int i = 0; i < P.weight_for_second.size(); i++)
	{
		for (int j = 0; j < P.weight_for_second.at(0).size(); j++)
		{
			double a;
			in3 >> a;
			P.weight_for_second.at(i).at(j) = a;
		}
	}

	ifstream in4(filename4);
	P.weight_Bias_for_second.resize(P.ideal_output.size());
	for (int i = 0; i <P.weight_Bias_for_second.size(); i++)
	{
		double a;
		in4 >> a;
		P.weight_Bias_for_second.at(i) = a;
	}

	in1.close();
	in2.close();
	in3.close();
	in4.close();
}

void GenerateRandomWeights(string filename1, string filename2, string filename3, string filename4)
{

	ofstream out1(filename1);
	ofstream out2(filename2);
	ofstream out3(filename3);
	ofstream out4(filename4);
	srand(time(NULL));
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 28 * 28; j++)
		{		
			double a = (double)(rand() % 9 + 1) / 1000;
			out1<<" " << a;
		}
		out1 << endl;
	}

	for (int i = 0; i < 100; i++)
	{
		double a = (double)(rand() % 9 + 1) / 1000;
		out2<<" "<< a;
	}

	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			double a = (double)(rand() % 9 + 1) / 1000;
			out3 << " " << a;
		}
	}

	for (int i = 0; i < 25; i++)
	{
		double a = (double)(rand() % 9 + 1) / 1000;
		out4 << " " << a;
	}
	out1.close();
	out2.close();
	out3.close();
	out4.close();
}

void ReadData(ifstream &in, int SizePicture, int size_of_lost, Network &P)
{
	int b;
	in >> b;
	
	P.size_of_lose = size_of_lost;
	P.size_of_picture = SizePicture;
	for (int i = 0; i < P.size_of_picture; i++)
	{
		for (int j = 0; j < P.size_of_picture; j++)
		{
			if (i >= (P.size_of_picture - P.size_of_lose) / 2
				&& i <= ((P.size_of_picture - P.size_of_lose) / 2 + P.size_of_lose - 1)
				&& j >= (P.size_of_picture - P.size_of_lose) / 2
				&& j <= ((P.size_of_picture - P.size_of_lose) / 2 + P.size_of_lose - 1))
			{
				double a;
				in >> a;
				P.ideal_output.push_back(a);
			}
			else
			{
				double a;
				in >> a;
				P.input_for_first.push_back(a);
			}
		}
	}
	//in.close();
	if (P.ideal_output.size() != P.size_of_lose * P.size_of_lose
		|| P.input_for_first.size() != P.size_of_picture * P.size_of_picture - P.ideal_output.size())
		throw "error of generate data";
}

void OutPicture(ofstream &out, Network P)
{
	int k = 0;
	int z = 0;
	for (int i = 0; i <28; i++)
	{
		for (int j = 0; j <28; j++)
		{
			if (i >= (P.size_of_picture - P.size_of_lose) / 2
				&& i <= ((P.size_of_picture - P.size_of_lose) / 2 + P.size_of_lose - 1)
				&& j >= (P.size_of_picture - P.size_of_lose) / 2
				&& j <= ((P.size_of_picture - P.size_of_lose) / 2 + P.size_of_lose - 1))
			{
				out << P.output.at(k) << ",";
				k++;
			}
			else
			{
				if (i != 27 || j != 27)
					out << P.input_for_first.at(z) << ",";
				else
					out << P.input_for_first.at(z);
				z++;
			}
		}
	}
	out << endl<<endl;

	int a = 0;
	for (int i = 0; i < 28; i++)
	{
		for (int j = 0; j < 28; j++)
		{
			if (i >= (P.size_of_picture - P.size_of_lose) / 2
				&& i <= ((P.size_of_picture - P.size_of_lose) / 2 + P.size_of_lose - 1)
				&& j >= (P.size_of_picture - P.size_of_lose) / 2
				&& j <= ((P.size_of_picture - P.size_of_lose) / 2 + P.size_of_lose - 1))
			{
				out <<0<< ",";
				
			}
			else
			{
				if (i != 27 || j != 27)
					out << P.input_for_first.at(a) << ",";
				else
					out << P.input_for_first.at(a);
				a++;
			}
		}
	}
	out << endl << endl;
}