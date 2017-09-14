//AUTHOR1: Ami Vyas amivyas@bu.edu
#include <iostream>
using namespace std;
int main() {
	int temp, i = 0,original_num = 0,k = 0;
	int linecount = 0; 
	int count = 0;
	int sum;
	
	while (count < 100000){	
		i++;	
		original_num = i;		
		while (k != 1 && k != 4){
			sum = 0;
			while(i > 0){
				sum += (i % 10)*(i % 10);
				i /= 10;
			}
			k = sum;
			temp = k;
			i = sum;
		}
		k = 0;
		if (temp == 1){		
			cout << original_num << " ";
			count++;			
			linecount++;
			if (linecount == 10){
				cout << endl;
				linecount = 0;
			}
		}
		i  = original_num;	
	}
	return 0;
}
