#include<iostream>
#include<cstdlib>   //for random number
#include<ctime>      
using namespace std;
int main(){
	srand(static_cast<unsigned int>(time(0)));
	int randomNumber=rand()%100+1;
	int userGuess=0;
	
	cout<<"Welcome To the Number Guessing Game!"<<endl;
	cout<<"I have choosen a number between 1 to 100"<<endl;
	
	while(userGuess!=randomNumber){
		cout<<"Enter Your Guess:"<<endl;
		cin>>userGuess;
		if(userGuess>randomNumber){
			cout<<"Random number is Lower than "<< userGuess<<endl;
		}else if(userGuess<randomNumber){
			cout<<"random number is Higher than "<< userGuess<<endl;
		}
		else{
			cout<<"Congratulations! You guessed the Correct Nmuber"<<endl;
		}
	}
	return 0;
}
