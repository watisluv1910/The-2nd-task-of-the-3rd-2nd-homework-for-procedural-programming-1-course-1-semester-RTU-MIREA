#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <stdio.h>

using namespace std;

void f2rew() { // ������� �������� ����� ����� printf
	double S, n, r, m, k = 0.1, m_guess, shag, count = 0; // ����������� � ������������ k �� m

	cout << "������� S:\n";
	cin >> S;
	cout << "������� m:\n";
	cin >> m;
	cout << "������� n:\n";
	cin >> n;
	/*float x = m;
	while (x > 0)
	{
		count += 1;
		x /= 10;
	}
	k = pow(10, (count - 5));*/
	if (S / (n * 12) == m)
	{
		cout << "������ ����� ��� ������� �������.\n";
	}
	else if (S / (n * 12) > m)
	{
		int iter = 0;
		shag = 1; // ���������� ��� ��������� ��������
		r = 1; // ���������� r ��������� ��������
		m_guess = S * r * pow((1 + r), n) / (12 * (pow((1 + r), n) - 1));
		while (fabs(m_guess - m) >= k)
		{
			iter += 1;
			cout << "m_guess = " << m_guess << " r =" << r << " iter = " << iter << endl;
			if (m_guess > m)
			{
				r -= shag;
				shag /= 2;
			}
			if (2 * m_guess < m)
			{
				shag *= 2;
			}
			r += shag;
			m_guess = S * r * pow((1 + r), n) / (12 * (pow((1 + r), n) - 1));
		}
		//cout << "������������� ���������: C���� ��������� " << S << ", ������� ������� ��������� ��������� ��������� " << m << " � ������� " << n << " ���, ������ ��� ������� " << r * 100 << " (� ��������� ��" << k << ").\n" << endl;
		printf("\nm_guess = %lf\t r = %lf\t iter = %d\t\n", m_guess, r, iter);
		printf("\n������������� ���������: C���� ��������� %.2lf, ������� ������� ��������� ��������� ��������� %.2lf � ������� %.2lf ���, ������ ��� ������� %.5lf (� ������������ +- %.2lf).\n\n", S, m, n, r * 100, k);
	}
	else
	{
		int iter = 0;
		shag = 1;
		r = 1;
		m_guess = S * r * pow((1 + r), n) / (12 * (pow((1 + r), n) - 1));
		while (fabs(m_guess - m) >= k)
		{
			iter += 1;
			printf("m_guess = %lf\t r = %lf\t iter = %d\t\n", m_guess, r, iter);
			//cout << "m_guess = " << setw(8) << m_guess << setw(10) << " r = " << setw(15) << r << setw(10) << " iter = " << setw(5) << iter << setw(10) << endl;
			if (m_guess > m)
			{
				r -= shag;
				shag /= 2;
			}
			if (2 * m_guess < m)
			{
				shag *= 2;
			}
			r += shag;
			m_guess = S * r * pow((1 + r), n) / (12 * (pow((1 + r), n) - 1));
		}

		//cout << "m_guess = " << m_guess << setw(10) << " r = " << r << setw(10) << " iter = " << iter << setw(10) << endl << endl;
		//cout << "������������� ���������: C���� ��������� "<< S << ", ������� ������� ��������� ��������� ��������� " << m << " � ������� " << n  << " ���, ������ ��� ������� " << r * 100 << " (� ������������ +- " << k << ").\n" << endl;
		printf("\nm_guess = %lf\t r = %lf\t iter = %d\t\n", m_guess, r, iter);
		printf("\n������������� ���������: C���� ��������� %.2lf, ������� ������� ��������� ��������� ��������� %.2lf � ������� %.2lf ���, ������ ��� ������� %.5lf (� ������������ +- %.2lf).\n\n", S, m, n, r * 100, k);
	}
}

int main() {
	int counter;
	setlocale(LC_ALL, "Russian");
	cout << "����� ������ �� ��������� 5.\n" << "����� ��������� ������, ������� 0.\n";
	cout << "������� ����� ������: \n";
	cin >> counter;
	while (counter > 0)
	{
		switch (counter)
		{
		case 1:
			//f1();
			break;
		case 2:
			f2rew();
			break;
		case 3:
			//f3();
			break;
		case 4:
			//f4();
			break;
		case 5:
			//f5();
			break;
		default:
			cout << "����� ������ �� ��������� 5.\n" << "����� ��������� ������, ������� 0.\n";
			break;
		}
		cout << "������� ����� ��������� ������: \n";
		cin >> counter;
	}
}