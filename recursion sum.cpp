#include<iostream>
using namespace std;
int sum(int n){
	if(n==0){
		return 0;
		
		} else
		{
			return n+sum(n-1);
		}
		 
}
int main(){
	int n;
	cout<<"enter the number";
	cin>>n;
	if(n<0){
		cout<<"inavlid input";
	}
	int result=sum(n);
	cout<<"the sum of all the integers from 1 to" " "<<n<< " " "is" " "<<result<<endl;
	return 0;
}