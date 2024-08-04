#include <iostream>

#define STD 6

#if STD == 1
// 포인터
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
// 참조자 (래퍼런스)
int main() {
	int a = 3;
	int& another_a = a;		// another_a = a 의 참조자
							// 래퍼런스는 메모리 상에 존재하지 않을 수 있다!

	another_a = 5;
	std::cout << "a : " << a << std::endl;
	std::cout << "another_a : " << another_a << std::endl;

	return 0;
}

#elif STD == 3
// 함수 인자로 레퍼런스 받기
int change_val(int& p) {	// 인자 int& p == number 가 되는 것.
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
// 여러가지 참조자 예시들
int main() {
	int x;
	int& y = x;		
	int& z = y;		// y, z 모두 x의 참조자이다.

	x = 1;
	std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;

	y = 2;
	std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;

	z = 3;
	std::cout << "x : " << x << " y : " << y << " z : " << z << std::endl;
}

#elif STD == 5
// 외부 변수의 레퍼런스를 리턴
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
// 참조자가 아닌 값을 리턴하는 함수를 참조자로 받기
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