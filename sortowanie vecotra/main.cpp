#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;
void wypisz(int l)
{
	cout<<l<<" ";
}
class User
{
  int id;
  string name;
  string surname;
  int data;

};
int main()
{

	vector<User> users;




//	for(int i=0;i<users.size();i++)
//		cin>>tab[i];

	sort(users.begin(), users.end(),users.data());


	for_each(users.begin(),users.end(),wypisz);

	return 0;
}
