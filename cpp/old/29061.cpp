#include<iostream>
using namespace std;
int main(){
  int days, sum=0, coins=1;
  cin>>days;
  while(days>0){
  	for(int i=0; i<coins&&days>0; i++){
  		sum+=coins;
  		days--;
	}
	coins++;
  }
  cout<<sum;
}
/*1 1
2 2
3 2
4 3
5 3
6 3
7 4
8 4
9 4
10 4
*/
