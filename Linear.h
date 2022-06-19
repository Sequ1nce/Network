#pragma once
vector<double> MultiplyMatrixOnVector(const vector<vector<double>> &matrix, const vector<double> &myvector)
{
	if (myvector.size() != matrix.at(0).size())
	{
		throw "error of multiplying";
	}
	vector<double> answer;
	answer.resize(matrix.size());

	for (int i = 0; i < matrix.size(); i++)
	{
		double s = 0;
		for (int j = 0; j < matrix.at(0).size(); j++)
		{
			s += matrix.at(i).at(j)*myvector.at(j);
		}
		answer.at(i) = s;
	}
	return answer;
}

vector<double> SumVector(const vector<double> &v1, const vector<double> &v2)
{
	if (v1.size() != v2.size())
	{
		throw "error of summary";
	}
	vector<double> answer = v1;
	for (int i = 0; i < v1.size(); i++)
	{
		answer.at(i) += v2.at(i);
	}
	return answer;
}

vector<vector<double>> GenerateMatrix(int a, int b)
{
	vector<vector<double>> answer;
	answer.resize(a);
	for (int i = 0; i < a; i++)
	{
		answer.at(i).resize(b);
	}
	srand(time(NULL));

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < b; j++)
		{
			answer.at(i).at(j) = rand() %100;
			answer.at(i).at(j) /= 5;
		}
	}
	return answer;
}

vector<vector<double>> Transpose(const vector<vector<double>> &matrix)
{
	vector<vector<double>> answer;
	answer.resize(matrix.at(0).size());

	for (int i = 0; i < answer.size(); i++)
	{
		answer.at(i).resize(matrix.size());
	}


	for (int i = 0; i < answer.size(); i++)
	{
		for (int j = 0; j < answer.at(0).size(); j++)
		{
			answer.at(i).at(j) = matrix.at(j).at(i);
		}
	}

	return answer;
}