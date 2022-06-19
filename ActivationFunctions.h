#pragma once
double Sigmoid(double Stratum)
{
	return 1 / (1 + exp(-Stratum));
}

double DerivativeSigmoid(double x)
{
	return Sigmoid(x)*(1 - Sigmoid(x));
}

bool Check(vector<double> &a, vector<double> &b,double e)
{
	double max = 0;
	if (a.size() != b.size())
		return true;
	for (int i = 0; i < a.size(); i++)
	{
		if (max < abs(a.at(i) - b.at(i)))
		{
			max = abs(a.at(i) - b.at(i));
		}
	}
	cout << "Nev:" << max << endl;
	if (max > e)
		return false;
	else
		return true;
}

double Nev(vector<double> &a, vector<double> &b)
{
	double s = 0;

	for (int i = 0; i < a.size(); i++)
	{
		s += abs(a.at(i) - b.at(i));
	}
	return s / a.size();
}