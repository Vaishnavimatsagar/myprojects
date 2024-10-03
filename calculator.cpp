#include<iostream>
using namespace std;

int main(){
	char oper;
	double num1,num2,result;
	
	cout<<"Enter First Number:"<<endl;
	cin>>num1;
	
	cout<<"Enter Operator: "<<endl;
	cin>>oper;
	
	cout<<"Enter Second Number:"<<endl;
	cin>>num2;
	
	if(oper=='+'){
		result=num1+num2;
		cout<<"Result = "<<result<<endl;
	}
	else if(oper=='-'){
		result=num1-num2;
		cout<<"Result = "<<result<<endl;
	}
	else if(oper=='*'){
		result=num1*num2;
		cout<<"Result = "<<result<<endl;
	}
	else if(oper=='/'){
		if(num2!=0){
			result=num1/num2;
			cout<<"Result = "<<result<<endl;
		}else{
			cout<<"Error: Division by zero!"<<endl;
		}
		
	}
	else{
		cout<<"Invalid Operator!!";
	}
	return 0;
}
