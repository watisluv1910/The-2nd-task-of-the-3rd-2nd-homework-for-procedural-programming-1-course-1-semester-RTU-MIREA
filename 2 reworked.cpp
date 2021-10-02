#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <stdio.h> // for printf

using namespace std;

// Tasks:
// ����������� �������� � �������������� ���������� 
// �������� �������� ������ ����� while

void f2rew() { 
	double S, n, r, m, error = 0.1, m_guess, step;
	cout << "������� �������� ����� S:\n";
	cin >> S;
	cout << "������� �������� �������� ������ m:\n";
	cin >> m;
	cout << "������� ���������� ��� n:\n";
	cin >> n;
	int x = m, deg_of_err = -8;
	while (x > 0)
	{
		deg_of_err += 1; // degree of e in error
		x /= 10;
	}
	error = pow(10, (deg_of_err)); // margin of error (depends on number of digits of m)
	if (m > S) // checking the availability to pay arrears before interest will be accrued
	{
		cout << "������ �������� ������ �������� (�.�. �������� ����������� ����� 1�� ������, � m > S).\n���������� �������, ��� ������� ������ �����, ����������.\n";
	}
	else if (S / (n * 12) == m) // condition for percentage == 0
	{
		cout << "������ ����� ��� ������� �������.\n";
	}
	else if (S / (n * 12) > m) // condition for percentage < 0
	{
		int iter = 0;
		step = 1; // ���������� ��� ��������� ��������
		r = 1; // ���������� r ��������� ��������
		m_guess = S * r * pow((1 + r), n) / (12 * (pow((1 + r), n) - 1));
		while (fabs(m_guess - m) >= error)
		{
			iter += 1;
			printf("m_guess = %lf\t\t r = %lf\t\t iter = %d\t\t\n", m_guess, r, iter);
			if (m_guess > m)
			{
				r-= step;
				step /= 2;
			}
			if (2 * m_guess < m)
			{
				step *= 2;
			}
			r += step;
			m_guess = S * r * pow((1 + r), n) / (12 * (pow((1 + r), n) - 1));
		}
		//cout << "������������� ���������: C���� ��������� " << S << ", ������� ������� ��������� ��������� ��������� " << m << " � ������� " << n << " ���, ������ ��� ������� " << r * 100 << " (� ��������� ��" << error << ").\n" << endl;
		printf("\nm_guess = %lf\t\t r = %lf\t\t iter = %d\t\t\n", m_guess, r, iter);
		printf("\n������������� ���������: C���� ��������� %.2lf, ������� ������� ��������� ��������� ��������� %.2lf � ������� %.2lf ���, ������ ��� ������� %lf (� ������������ +- %lf).\n\n", S, m, n, r * 100, error);
	}
	else // condition for percentage > 0
	{
		int iter = 0;
		step = 1;
		r = 1;
		m_guess = S * r * pow((1 + r), n) / (12 * (pow((1 + r), n) - 1));
		while (fabs(m_guess - m) >= error)
		{
			iter += 1;
			printf("m_guess = %lf\t\t r = %lf\t\t iter = %d\t\t\n", m_guess, r, iter);
			//cout << "m_guess = " << setw(8) << m_guess << setw(10) << " r = " << setw(15) << r << setw(10) << " iter = " << setw(5) << iter << setw(10) << endl;
			if (m_guess > m)
			{
				r -= step;
				step /= 2;
			}
			if (2 * m_guess < m)
			{
				step *= 2;
			}
			r += step;
			m_guess = S * r * pow((1 + r), n) / (12 * (pow((1 + r), n) - 1));
		}
		//cout << "\nm_guess = " << m_guess << "\t\t" << " r = " << r << "\t\t" << " iter = " << iter << "\t\t" << endl << endl;
		//cout << "������������� ���������: C���� ��������� "<< S << ", ������� ������� ��������� ��������� ��������� " << m << " � ������� " << n  << " ���, ������ ��� ������� " << r * 100 << " (� ������������ +- " << error << ").\n" << endl;
		printf("\nm_guess = %lf\t\t r = %lf\t\t iter = %d\t\t\n", m_guess, r, iter);
		printf("\n������������� ���������: C���� ��������� %.2lf, ������� ������� ��������� ��������� ��������� %.2lf � ������� %.2lf ���, ������ ��� ������� %lf (� ������������ +- %lf).\n\n", S, m, n, r * 100, error);
	}
}

int main() {
	int counter;
	setlocale(LC_ALL, "Russian");
	cout << "����� ������ �� ��������� 2.\n" << "����� ��������� ������, ������� 0.\n";
	cout << "������� ����� ������: \n";
	cin >> counter;
	while (counter > 0)
	{
		switch (counter)
		{
		case 1:
			cout << "��� ��������� 1� � ����������� ����� �� �� �3 �������� �� ����:\nD:/Microsoft VS source/C++/Home Tasks/1 ����/�� �4 �� 5� ������/4.\n";
			break;
		case 2:
			f2rew();
			break;
		default:
			cout << "����� ������ �� ��������� 2.\n" << "����� ��������� ������, ������� 0.\n";
			break;
		}
		cout << "������� ����� ��������� ������: \n";
		cin >> counter;
	}
}