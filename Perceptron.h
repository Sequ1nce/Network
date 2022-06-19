#pragma once
class Network {
public:
	const int Bias = 1;
	const int size_of_second_stratum = 100;

	int size_of_lose;
	int size_of_picture;
	vector<double> input_for_first;
	vector<vector<double>> weight_for_first;
	vector<double> weight_Bias_for_first;
	vector<double> input_for_second;
	vector<vector<double>> weight_for_second;
	vector<double> weight_Bias_for_second;
	vector<double> output;
	vector<double> ideal_output;

	void InitData(string filename, int SizePicture, int size_of_lost)
	{
		ifstream in(filename);
		size_of_lose = size_of_lost;
		size_of_picture = SizePicture;
		for (int i = 0; i < size_of_picture; i++)
		{
			for (int j = 0; j < size_of_picture; j++)
			{
				if (i >=(size_of_picture - size_of_lose) / 2
					&& i<=((size_of_picture - size_of_lose) / 2 + size_of_lose-1)
					&& j>=(size_of_picture - size_of_lose) / 2
					&& j <= ((size_of_picture - size_of_lose) / 2 + size_of_lose-1))
				{
					double a;
					in >> a;
					ideal_output.push_back(a);
				}
				else
				{
					double a;
					in >> a;
					input_for_first.push_back(a);
				}
			}
		}
		in.close();
		if (ideal_output.size() != size_of_lose * size_of_lose 
			|| input_for_first.size() != size_of_picture * size_of_picture - ideal_output.size())
			throw "error of generate data";
	}

	void GenerateOutput()
	{
		input_for_second = SumVector(MultiplyMatrixOnVector(weight_for_first, input_for_first), weight_Bias_for_first);
		for (int i = 0; i < input_for_second.size(); i++)
		{
			input_for_second.at(i) = Sigmoid(input_for_second.at(i));
		}
		output = SumVector(MultiplyMatrixOnVector(weight_for_second, input_for_second), weight_Bias_for_second);
		for (int i = 0; i < output.size(); i++)
		{
			output.at(i) = Sigmoid(output.at(i));
		}
	}

	void ChangeWeights(double alpha)
	{
		vector<double> wSum = MultiplyMatrixOnVector(weight_for_second, input_for_second);
		for (int i = 0; i < weight_for_second.size(); i++)
		{
			for (int j = 0; j < weight_for_second.at(0).size(); j++)
			{
				double grad =(ideal_output.at(i) - output.at(i))*DerivativeSigmoid(wSum.at(i))*input_for_second.at(j);
				weight_for_second.at(i).at(j) = weight_for_second.at(i).at(j) + alpha * grad;
			}
		}

		for (int i = 0; i < weight_Bias_for_second.size(); i++)
		{
			weight_Bias_for_second.at(i) = weight_Bias_for_second.at(i) 
				+ alpha *(ideal_output.at(i) - output.at(i))*DerivativeSigmoid(wSum.at(i));
		}
		//=======================================

		vector<double> wSumFirst = MultiplyMatrixOnVector(weight_for_first, input_for_first);
		for (int i = 0; i < weight_for_first.size(); i++)
		{
		
			for (int j = 0; j < weight_for_first.at(0).size(); j++)
			{
				double sum = 0;
				for (int k = 0; k < weight_for_second.size(); k++)
				{
					sum += (ideal_output.at(k) - output.at(k))*DerivativeSigmoid(wSum.at(k))*weight_for_second.at(k).at(i);//abs??
				}
				double grad1 = sum * DerivativeSigmoid(wSumFirst.at(i))*input_for_first.at(j);
				weight_for_first.at(i).at(j)=weight_for_first.at(i).at(j)+alpha*grad1;
				//cout << grad1 << endl;
			}
		}

		for (int i = 0; i < weight_Bias_for_first.size(); i++)
		{
			double sum = 0;
			for (int k = 0; k < weight_for_second.size(); k++)
			{
				sum += (ideal_output.at(k) - output.at(k))*DerivativeSigmoid(wSum.at(k))*weight_for_second.at(k).at(i);
			}
			double grad_b1 = sum * DerivativeSigmoid(wSumFirst.at(i));
			weight_Bias_for_first.at(i) += grad_b1 * alpha;
		}

	}

	void Reset()
	{
		int R1 = input_for_first.size();
		int R2 = ideal_output.size();
		for (int i = 0; i < R1; i++)
		{
			input_for_first.pop_back();
		}

		for (int i = 0; i < R2; i++)
		{
			ideal_output.pop_back();
		}
	}


};