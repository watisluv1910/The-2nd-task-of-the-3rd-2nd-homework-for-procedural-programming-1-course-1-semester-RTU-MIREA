#include <iostream>
#include <string>
#include <math.h>
#include <iomanip>
#include <stdio.h> // for printf

using namespace std;

// Tasks:
// ����������� �������� � �������������� ���������� * done
// �������� �������� ������ ����� while
// ���������� r ��������� ��������
// ���������� step ��������� ��������

void f2rew() { 
	double Sum, years, fractional_percent, monthly_payment, error = 0.1, monthly_payment_guess, step;
	cout << "������� �������� ����� Sum:\n";
	cin >> Sum;
	cout << "������� �������� �������� ������ m:\n";
	cin >> monthly_payment;
	cout << "������� ���������� ��� n:\n";
	cin >> years;
	int x = monthly_payment, deg_of_err = -8;
	while (x > 0)
	{
		deg_of_err += 1; // degree of e in error
		x /= 10;
	}
	error = pow(10, (deg_of_err)); // margin of error (depends on number of digits of m)
	if (monthly_payment > Sum) // checking the availability to pay arrears before interest will be accrued
	{
		cout << "������ �������� ������ �������� (�.�. �������� ����������� ����� 1�� ������, � m > Sum).\n���������� �������, ��� ������� ����� ������, ����������.\n";
	}
	else if (Sum / (years * 12) == monthly_payment) // condition for percentage == 0
	{
		cout << "������ ����� ��� ������� �������.\n";
	}
	else if (Sum / (years * 12) > monthly_payment) // condition for percentage < 0
	{
		int iteration = 0;
		double fractional_percent = (monthly_payment * years * 12 - Sum) / Sum;
		printf("\n������������� ���������: C���� ��������� %.2lf, ������� ������� ��������� ��������� ��������� %.2lf � ������� %.2lf ���, ������ ��� ������� %lf.\n\n", Sum, monthly_payment, years, fractional_percent * 100);
	}
	else // condition for percentage > 0
	{
		int iter = 0;
		step = 1;
		fractional_percent = 1;
		monthly_payment_guess = Sum * fractional_percent * pow((1 + fractional_percent), years) / (12 * (pow((1 + fractional_percent), years) - 1));
		while (fabs(monthly_payment_guess - monthly_payment) >= error)
		{
			iter += 1;
			printf("m_guess = %lf\t\t r = %lf\t\t iter = %d\t\t\n", monthly_payment_guess, fractional_percent, iter);
			if (monthly_payment_guess > monthly_payment)
			{
				fractional_percent -= step;
				step /= 2;
			}
			if (2 * monthly_payment_guess < monthly_payment)
			{
				step *= 2;
			}
			fractional_percent += step;
			monthly_payment_guess = Sum * fractional_percent * pow((1 + fractional_percent), years) / (12 * (pow((1 + fractional_percent), years) - 1));
		}
		printf("\nm_guess = %lf\t\t r = %lf\t\t iter = %d\t\t\n", monthly_payment_guess, fractional_percent, iter);
		printf("\n������������� ���������: C���� ��������� %.2lf, ������� ������� ��������� ��������� ��������� %.2lf � ������� %.2lf ���, ������ ��� ������� %lf (� ������������ +- %lf).\n\n", Sum, monthly_payment, years, fractional_percent * 100, error);
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