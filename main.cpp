#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

struct peg{
	int id;
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

peg::peg(int x, bool y, int z){
		pos = x;
		on = y;
		id = z;
}

void printBoard(vector<peg> v){
	for(int i = 0; i<v.size(); i++){
		if(v[i].on){
			printf("%d, \n", v[i].id);
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
				if(v[i].pos == 1){
					if((v[2].on) && !(v[4].on)){
						v[i].pos = v[4].pos;
						v[2].on = false;	
						sort(v);
					}
					if(v[3].on && !(v[6].on)){
						v[i].pos = v[6].pos
						v[3].on = false;
						sort(v);
					}
				}
				if(v[i].pos == 2){
					if(v[4].on && !(v[7].on)){
						v[i].pos = v[7].pos//will this mess things up?
						v[4].on = false;
						sort(v);
					}
					if(v[5].on && !(v[9].on)){
						v[i].pos = v[9].pos
						v[5].on = false;
						sort(v);
					}
				}
				if(v[i].pos == 3){
					if(v[5].on && !(v[8].on)){
						v[i].pos = v[8].pos
						v[5].on = false;
						sort(v);
					}
					if(v[6].on && !(v[10].on)){
						v[i].pos = v[10].pos;
						v[6].on = false;
						sort(v);
					}
				}
				if(v[i].pos == 4){
					if(v[2].on && !(v[1].on)){
						v[i].pos = v[1].pos;
						v[2].on = false;
						sort(v):
					}
					if(v[5].on && !(v[6].on)){
						v[i].pos = v[6].pos;
						v[5].on = false;
						sort(v):
					}
					if(v[8].on && !(v[13].on)){
						v[i].pos = v[13].pos;
						v[8].on = false;
						sort(v);
					}
					if(v[7].on && !(v[11].on)){
						v[i].pos = v[11].pos;
						v[7].on = false;
						sort(v);
					}
				}
				if

			}
		}
	}
}



int main(int argc, char* argv[]){
	peg one(1, 1, 1);
	peg two(2, 1, 2);
	peg three(3, 1, 3);
	peg four(4, 1, 4);
	peg five(5, 1, 5);
	peg six(6, 1, 6);
	peg seven(7, 1, 7);
	peg eight(8, 1, 8);
	peg nine(9, 1, 9);
	peg ten(10, 1, 10);
	peg eleven(11, 1, 11);
	peg twelve(12, 1, 12);
	peg thirt(13, 1, 13);
	peg fourt(14, 1, 14);
	peg fift(15, 1, 15);

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
