#include <iostream>
using namespace std;

int problem1();
int problem2();
int problem3();
int problem4();
int biDir(int, int);
int disj(int, int);
int nDisjN(int, int);
int ifThen(int, int);
int conj(int, int);
int nConj(int, int);



int main() 
{
	/*
	int a1 = problem1(p, q);
	int a2 = problem2(p, q);
	int a3 = problem3(p, q);
	int a4 = problem4(p, q, r);
	r = 0;
	int b4 = problem4(p, q, r);
	r = 1;
	q = 0;
	int b1 = problem1(p, q);
	int b2 = problem2(p, q);
	int b3 = problem3(p, q);
	int c4 = problem4(p, q, r);
	r = 0;
	int d4 = problem4(p, q, r);
	p = 0;
	int d1 = problem1(p, q);
	int d2 = problem2(p, q);
	int d3 = problem3(p, q);
	int h4 = problem4(p, q, r);
	r = 1;
	int g4 = problem4(p, q, r);
	q = 1;
	int c1 = problem1(p, q);
	int c2 = problem2(p, q);
	int c3 = problem3(p, q);
	int e4 = problem4(p, q, r);
	r = 0;
	int f4 = problem4(p, q, r);
	*/
	int a = ifThen(1, 0);
	cout << a << endl;
}

int problem1() {
	int p = 1;
	int q = 1;
	int equality;



	return 1;
}
int problem2() {
	int p = 1;
	int q = 1;
	int equality;

	return 1;
}
int problem3() {
	int p = 1;
	int q = 1;
	int equality;

	return 1;
}
int problem4() {
	int p = 1;
	int q = 1;
	int r = 1;
	int equality;

	return 1;
}
// subroutines
int biDir(int p, int q){
	if(p == q) return 1;
	else return 0;
}
int disj(int p, int q) {
	if(p || q) return 1;
	else return 0;
}
int nDisjN(int p, int q) {
	if(p == 0) p = 1;
	else if(p == 1) p = 0;
	if(q == 0) q = 1;
	else if(q == 1) q = 0;
	return disj(p, q);
}
int ifThen(int p, int q) {
	if(p && !q) return 0;
	else return 1;
}
int conj(int p, int q) {
	if(p && q) return 1;
	else return 0;
}
int nConj(int p, int q) {
	if(p && q) return 0;
	else return 1;
}