#include <iostream>

#define STD 6

#if STD == 1
// ������
int change_val(int* p) {
	*p = 3;

	return 0;
}
int main() {
	int number = 5;

	std::cout << number << std::endl;
	change_val(&number);
	std::cout << number << std::endl;
}

#elif STD == 2
// ������ (���۷���)
int main() {
	int a = 3;
	int& another_a = a;		// another_a = a �� ������
							// ���۷����� �޸� �� �������� ���� �� �ִ�!

	another_a = 5;
	std::cout << "a : " << a << std::endl;
	std::cout << "another_a : " << another_a << std::endl;

	return 0;
}

#elif STD == 3
// �Լ� ���ڷ� ���۷��� �ޱ�
int change_val(int& p) {	// ���� int& p == number �� �Ǵ� ��.
	p = 3;

	return 0;
}
int main() {
	int number = 5;

	std::cout << number << std::endl;
	change_val(number);
	std::cout << number << std::endl;
}

#elif STD == 4
// �������� ������ ���õ�
int main() {
	int x;
	int& y = x;		
	int& z = y;		// y, z ��� x�� �������̴�.

	x = 1;
	std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;

	y = 2;
	std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;

	z = 3;
	std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;
}

#elif STD == 5
// �ܺ� ������ ���۷����� ����
int& function(int& a) {
	a = 5;
	return a;
}

int main() {
	int b = 2;
	int c = function(b);
	return 0;
}

#elif STD == 6
// �����ڰ� �ƴ� ���� �����ϴ� �Լ��� �����ڷ� �ޱ�
int function() {
	int a = 5;
	return a;
}

int main() {
	const int& c = function();
	std::cout << "c : " << c << std::endl;
	return 0;
}

#endif