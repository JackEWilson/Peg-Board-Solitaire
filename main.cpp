#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

struct peg{
	int pos;
	bool on;

	peg(int x, bool y);
//	bool complete(vector<peg> v);
//	void hop(peg x, peg y);
};

bool complete(vector<peg> v){
	int count = 0;
	for(int i = 0; i<v.size(); i++){
		if(v[i].pos > 0){
			count++;
		}
	}	
	if(count == 1){
		return true;
	}
	else{
		return false;
	}
}
/*
void peg::hop(peg x, peg y){
	x.pos = y.pos;
	y.pos = 0;
	y.on = 0;
}*/

peg::peg(int x, bool y){
		pos = x;
		on = y;
}

void printBoard(vector<peg> v){
	for(int i = 0; i<v.size(); i++){
		if(v[i].on){
			printf("%d, \n", v[i].pos);
		}
	}
}

void sort(vector<peg> v){
	if(complete(v)){
		printBoard(v);
	}
	else{
		for(int i=0; i<v.size(); i++){
			if(v[i].on){
				if(v[i].pos = 1){
					if((v[2].on) && !(v[4].on)){
						v[i].on = false;
						v[4].on = true;
						v[2].on = false;	
					} 
				}	




			}
		}
	}
}



int main(int argc, char* argv[]){
	peg one(1, 1);
	peg two(2, 1);
	peg three(3, 1);
	peg four(4, 1);
	peg five(5, 1);
	peg six(6, 1);
	peg seven(7, 1);
	peg eight(8, 1);
	peg nine(9, 1);
	peg ten(10, 1);
	peg eleven(11, 1);
	peg twelve(12, 1);
	peg thirt(13, 1);
	peg fourt(14, 1);
	peg fift(15, 1);

	vector<peg> v;
	v.push_back(one);
	v.push_back(two);
	v.push_back(three);
/*	v.push_back(four);
	v.push_back(five);
	v.push_back(six);
	v.push_back(seven);
	v.push_back(eight);
	v.push_back(nine);
	v.push_back(ten);
	v.push_back(eleven);
	v.push_back(twelve);
	v.push_back(thirt);
	v.push_back(fourt);
	v.push_back(fift);
*/
	printBoard(v);
	sort(v);
	return 0;
}
