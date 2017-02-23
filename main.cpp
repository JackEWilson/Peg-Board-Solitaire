#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <cstdlib>
#include <string.h>

int count1; //counting number of sort calls
int count2; //counting number of function interations
bool board = true;

using namespace std;

struct peg{
	int id;
	int on;

	vector<int> jump;
	vector<int> land;
	vector<int> moves;
	
	peg(int z);
};

vector<peg> start();

bool complete(vector<peg> v){
	int count = 0;
	for(int i = 0; i<v.size(); i++){
		if(v[i].on == 0){
			count++;
		}
	}	
	if(count == 14){
		return true;
	}
	else{
		return false;
	}
}

peg::peg(int z){
		on = 1;
		id = z;
}

void printBoard(vector<peg> v){
	printf("         %d\n", v[0].on);
	printf("        %d %d\n", v[1].on, v[2].on);
	printf("       %d %d %d\n", v[3].on, v[4].on, v[5].on);
	printf("      %d %d %d %d\n", v[6].on, v[7].on, v[8].on, v[9].on);
	printf("     %d %d %d %d %d\n", v[10].on, v[11].on, v[12].on, v[13].on, v[14].on);
}

void printMoves(vector<peg> v){
	vector<peg> x = start();
	for(int i = 0; i<v[0].moves.size();){
		printf("%d -> %d\n", v[0].moves[i],/* v[0].moves[i+1],*/ v[0].moves[i+2]);
		if(board){
			x[v[0].moves[i]-1].on = 0;
			x[v[0].moves[i+1]-1].on = 0;
			x[v[0].moves[i+2]-1].on = 1;
			if(i == 0){
				x[v[0].moves[i]-1].on = 0;
			}
			printBoard(x);
		}
		i+=3;
	}
}

void sort(vector<peg> v){
	count1++;
	if(complete(v)){
		printBoard(v);
		printf("number of sorts %d\n", count1);
		printf("number of iterations %d\n", count2);
		printMoves(v);
		exit(1);
	}

	for(int i = 0; i<v.size(); i++){
		if(v[i].on == 1){
			for(int x = 0; x<v[i].jump.size(); x++){
				if(v[v[i].jump[x]-1].on == 1 && v[v[i].land[x]-1].on == 0){
					v[i].on = 0;
					v[v[i].jump[x]-1].on = 0;
					v[v[i].land[x]-1].on = 1;
					
					v[0].moves.push_back(v[i].id);
					v[0].moves.push_back(v[v[i].jump[x]-1].id);
					v[0].moves.push_back(v[v[i].land[x]-1].id);

					sort(v);

					v[0].moves.pop_back();
					v[0].moves.pop_back();
					v[0].moves.pop_back();

					v[i].on = 1;
					v[v[i].jump[x]-1].on = 1;
					v[v[i].land[x]-1].on = 0;
				}
				count2++;
			}
		}
	}
}



vector<peg> start(){
	peg one(1);
	one.jump.push_back(2);
	one.jump.push_back(3);
	one.land.push_back(4);
	one.land.push_back(6);
	peg two(2);
	two.jump.push_back(4);
	two.jump.push_back(5);
	two.land.push_back(7);
	two.land.push_back(9);
	peg three(3);
	three.jump.push_back(5);
	three.jump.push_back(6);
	three.land.push_back(8);
	three.land.push_back(10);
	peg four(4);
	four.jump.push_back(2);
	four.jump.push_back(5);
	four.jump.push_back(7);
	four.jump.push_back(8);
	four.land.push_back(1);
	four.land.push_back(6);
	four.land.push_back(11);
	four.land.push_back(13);
	peg five(5);
	five.jump.push_back(8);
	five.jump.push_back(9);
	five.land.push_back(12);
	five.land.push_back(14);
	peg six(6);
	six.jump.push_back(3);
	six.jump.push_back(5);
	six.jump.push_back(9);
	six.jump.push_back(10);
	six.land.push_back(1);
	six.land.push_back(4);
	six.land.push_back(13);
	six.land.push_back(15);
	peg seven(7);
	seven.jump.push_back(4);
	seven.jump.push_back(8);
	seven.land.push_back(2);
	seven.land.push_back(9);
	peg eight(8);
	eight.jump.push_back(5);
	eight.jump.push_back(9);
	eight.land.push_back(3);
	eight.land.push_back(10);
	peg nine(9);
	nine.jump.push_back(5);
	nine.jump.push_back(8);
	nine.land.push_back(2);
	nine.land.push_back(7);
	peg ten(10);
	ten.jump.push_back(6);
	ten.jump.push_back(9);
	ten.land.push_back(3);
	ten.land.push_back(8);
	peg eleven(11);
	eleven.jump.push_back(7);
	eleven.jump.push_back(12);
	eleven.land.push_back(4);
	eleven.land.push_back(13);
	peg twelve(12);
	twelve.jump.push_back(8);
	twelve.jump.push_back(13);
	twelve.land.push_back(5);
	twelve.land.push_back(14);
	peg thirt(13);
	thirt.jump.push_back(8);
	thirt.jump.push_back(9);
	thirt.jump.push_back(12);
	thirt.jump.push_back(14);
	thirt.land.push_back(4);
	thirt.land.push_back(6);
	thirt.land.push_back(11);
	thirt.land.push_back(15);
	peg fourt(14);
	fourt.jump.push_back(9);
	fourt.jump.push_back(13);
	fourt.land.push_back(5);
	fourt.land.push_back(12);
	peg fift(15);
	fift.jump.push_back(10);
	fift.jump.push_back(14);
	fift.land.push_back(6);
	fift.land.push_back(13);

	vector<peg> v;	

	v.push_back(one);
	v.push_back(two);
	v.push_back(three);
	v.push_back(four);
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

	return v;
}
	
int main(int argc, char* argv[]){
	vector<peg> v = start();
	int x;
	if(argc == 3){
		x = atoi(argv[1]);
		if(x > 0 && x < 16){
			v[x-1].on = 0;
		}
		else{
			fprintf(stderr, "Correct usage: a.out 4 false\n");
			fprintf(stderr, "Number must be 1 - 15\n");
		}
		if(strcmp(argv[2], "true") == 1){
//			board = true;	
		}
		else{
//			board = false;
		}
	}
	else{
		fprintf(stderr, "argv not provided\n");
		v[0].on = 0;
		x = 1;
	}	
	v[0].moves.push_back(x);	
	v[0].moves.push_back(x);	
	v[0].moves.push_back(x);	
	
	printBoard(v);
	sort(v);

	return 0;
}
