#include <iostream>

#define STD 5

#if STD == 1
// 변수의 정의
int main() {
	int arr[10];
	int* parr = arr;

	int i;
	int* pi = &i;		// 배열이나 포인터 정의는 C와 동일

	return 0;
}

#elif STD == 2
// 반복문
int main() {
	int i;

	for (i = 0; i < 10; i++) {
		std::cout << i << std::endl;
	}
	return 0;
}

#elif STD == 3
// 1 부터 10 까지 합
int main() {
	int i, k = 1, sum1 = 0, sum2 = 0;

	for (i = 1; i <= 10; i++) {		// C언어와 동일
		sum1 += i;
	}

	while (k <= 10) {				// C언어와 동일
		sum2 += k;
		i++;
	}

	std::cout << "합은 : " << sum1 << std::endl;
	return 0;

	std::cout << "합은 : " << sum2 << std::endl;
	return 0;
}

#elif STD == 4
// 행운의 숫자 맞추기 (조건문 if)
int main() {
	int lucky_number = 3;
	std::cout << "내 비밀 수를 맞추어 보세요~" << std::endl;

	int user_input;  // 사용자 입력

	while (1) {
		std::cout << "입력 : ";
		std::cin >> user_input;		// std::cin  입력
		if (lucky_number == user_input) {
			std::cout << "맞추셨습니다~~" << std::endl;
			break;
		}
		else {
			std::cout << "다시 생각해보세요~" << std::endl;
		}
	}
	return 0;
}

#elif STD == 5
// 조건문 switch
using std::cout;
using std::endl;
using std::cin;

int main() {
	int user_input;
	cout << "저의 정보를 표시해줍니다" << endl;
	cout << "1. 이름 " << endl;
	cout << "2. 나이 " << endl;
	cout << "3. 성별 " << endl;
	cin >> user_input;

	switch (user_input) {
	case 1:
		cout << "Psi ! " << endl;
		break;

	case 2:
		cout << "99 살" << endl;
		break;

	case 3:
		cout << "남자" << endl;
		break;

	default:
		cout << "궁금한게 없군요~" << endl;
		break;
	}
	return 0;
}

#endif