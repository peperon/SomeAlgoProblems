#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

int main()
{
	//ifstream file("Test.txt");
	int N;
	cin>>N;
	//file>>N;
	vector<vector<int> > matrix(N, vector<int>(N));
	for(int i = 0;i<N;++i)
	{
		for(int j = 0;j<N;++j)
		{
			cin>>matrix[i][j];
			//file>>matrix[i][j];
		}
	}


	int maxSum = -101;
	for(int l = 0;l<N;++l)
	{
		vector<int> subArr(N);

		for(int j = l;j<N;++j)
		{
			for(int k = 0;k<N;++k)
				subArr[k]+=matrix[j][k];

			int lastSum = 0, sum = -101, maxVal = -101;
			for(int i = 0;i<N;++i)
			{
				maxVal = (maxVal<subArr[i])?subArr[i]:maxVal;
				if(subArr[i]<0&&lastSum==0)
					continue;
				if(lastSum+subArr[i]>=0)
				{
					sum = (sum<lastSum)?lastSum:sum;
					lastSum+=subArr[i];
				}
				else 
				{		
					sum = (sum<lastSum)?lastSum:sum;
					lastSum = 0;
				}
			}
			sum = (sum<lastSum)?lastSum:sum;
			if(sum==0&&maxVal<0)
				sum = maxVal;
			maxSum = (maxSum<sum)?sum:maxSum;
		}
	}
	cout<<maxSum<<endl;
	return 0;
}