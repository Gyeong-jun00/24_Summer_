#include <iostream>

#define STD 5

#if STD == 1
// ������ ����
int main() {
	int arr[10];
	int* parr = arr;

	int i;
	int* pi = &i;		// �迭�̳� ������ ���Ǵ� C�� ����

	return 0;
}

#elif STD == 2
// �ݺ���
int main() {
	int i;

	for (i = 0; i < 10; i++) {
		std::cout << i << std::endl;
	}
	return 0;
}

#elif STD == 3
// 1 ���� 10 ���� ��
int main() {
	int i, k = 1, sum1 = 0, sum2 = 0;

	for (i = 1; i <= 10; i++) {		// C���� ����
		sum1 += i;
	}

	while (k <= 10) {				// C���� ����
		sum2 += k;
		i++;
	}

	std::cout << "���� : " << sum1 << std::endl;
	return 0;

	std::cout << "���� : " << sum2 << std::endl;
	return 0;
}

#elif STD == 4
// ����� ���� ���߱� (���ǹ� if)
int main() {
	int lucky_number = 3;
	std::cout << "�� ��� ���� ���߾� ������~" << std::endl;

	int user_input;  // ����� �Է�

	while (1) {
		std::cout << "�Է� : ";
		std::cin >> user_input;		// std::cin  �Է�
		if (lucky_number == user_input) {
			std::cout << "���߼̽��ϴ�~~" << std::endl;
			break;
		}
		else {
			std::cout << "�ٽ� �����غ�����~" << std::endl;
		}
	}
	return 0;
}

#elif STD == 5
// ���ǹ� switch
using std::cout;
using std::endl;
using std::cin;

int main() {
	int user_input;
	cout << "���� ������ ǥ�����ݴϴ�" << endl;
	cout << "1. �̸� " << endl;
	cout << "2. ���� " << endl;
	cout << "3. ���� " << endl;
	cin >> user_input;

	switch (user_input) {
	case 1:
		cout << "Psi ! " << endl;
		break;

	case 2:
		cout << "99 ��" << endl;
		break;

	case 3:
		cout << "����" << endl;
		break;

	default:
		cout << "�ñ��Ѱ� ������~" << endl;
		break;
	}
	return 0;
}

#endif