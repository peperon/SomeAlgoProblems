#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

int main()
{
	//ifstream file("test.txt");
	int N;
	cin>>N;
	//file>>N;
	vector<int> memo(N);
	for(int i = 0;i<N;++i)
	{
		cin>>memo[i];
		//file>>memo[i];
	}

	int lastSum = 0, sum = 0;
	for(int i = 0;i<N;++i)
	{
		if(memo[i]<0&&lastSum==0)
			continue;
		if(lastSum+memo[i]>=0)
		{
			sum = (sum<lastSum)?lastSum:sum;
			lastSum+=memo[i];
		}
		else 
		{		
			sum = (sum<lastSum)?lastSum:sum;
			lastSum = 0;
		}
	}
	sum = (sum<lastSum)?lastSum:sum;
	cout<<sum<<endl;
	return 0;
}