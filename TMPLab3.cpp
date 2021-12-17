#include <iostream>
#include <vector>
#include <algorithm>
#include "Tree.h"

bool sortbysec(const std::pair<int, int>& a,const std::pair<int, int>& b)
{
	return (a.second < b.second);
}

int main() {
	setlocale(LC_ALL, "Russian");
	std::vector<std::pair<int,float>> a;
	std::vector<std::pair<int,float>> b;

	Tree A;
	int sizeA;
	std::cout << "Введите размер дерева A > ";
	std::cin >> sizeA;	
	int k;
	for (int i = 0; i < sizeA; i++) {
		std::cout << "Введите значение " << i+1 << " > ";
		std::cin >> k;
		a.push_back(std::make_pair(k, k % 10));
	}
	std::sort(a.begin(),a.end(),sortbysec);
	std::reverse(a.begin(), a.end());
	for (int i = 0; i < sizeA; i++) {
		A.push(a[i].first);
	}
	std::cout << "Дерево A в обратном порядке: ";
	A.print_back();
	std::cout << std::endl;

	Tree B;
	int sizeB;
	std::cout << "Введите размер дерева B > ";
	std::cin >> sizeB;
	for (int i = 0; i < sizeB; i++) {
		std::cout << "Введите значение " << i+1 << " > ";
		std::cin >> k;
		b.push_back(std::make_pair(k, k % 10));
	}
	std::sort(b.begin(), b.end(), sortbysec);
	std::reverse(b.begin(), b.end());
	for (int i = 0; i < sizeB; i++) {
		B.push(b[i].first);
	}
	std::cout << "Дерево B в симметричном порядке: ";
	B.print_sym();
	std::cout << std::endl;

	Tree C;
	C.merge(&A, &B); 

	std::cout << "Дерево C в прямом порядке: ";
	C.print_direct();
	std::cout << std::endl;	

	std::cout << "Дерево C в обратном порядке: ";
	C.print_back();
	std::cout << std::endl;

	std::cout << "Дерево C в симметричном порядке: ";
	C.print_back();
	std::cout << std::endl;
	return 0;
}