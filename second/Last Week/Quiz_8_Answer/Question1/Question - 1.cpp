#include <stdio.h>
#include "circular_queue.h"
#define NOOFCUSTOMER 19

int main()
{
	queue_t desk1, desk2, desk3;
	initialize_q(&desk1); initialize_q(&desk2); initialize_q(&desk3);

	int cash_desk1 = 0, cash_desk2 = 0, cash_desk3 = 0;
	double payment;
	int cash = 0, visa = 0;

	QType qtype_customer;

	FILE* customer;
	customer = fopen("customers.bin", "rb");

	for (int i = 0; i < NOOFCUSTOMER; i++)
	{
		fread(&qtype_customer, sizeof(payment_t), 1, customer);
		if (qtype_customer.code != 'P')
		{
			if (cash_desk1 <= cash_desk2 && cash_desk1 <= cash_desk3)
			{
				insert(&desk1, qtype_customer);
				cash_desk1++;
			}
			else if (cash_desk2 <= cash_desk1 && cash_desk2 <= cash_desk3)
			{
				insert(&desk2, qtype_customer);
				cash_desk2++;
			}
			else if (cash_desk3 <= cash_desk1 && cash_desk3 <= cash_desk2)
			{
				insert(&desk3, qtype_customer);
				cash_desk3++;
			}
		}
		else
		{
			if (qtype_customer.amount == 1)
			{
				qtype_customer = remove(&desk1);
				cash_desk1--;
				payment += qtype_customer.amount;
			}
			else if (qtype_customer.amount == 2)
			{
				qtype_customer = remove(&desk2);
				cash_desk2--;
				payment += qtype_customer.amount;
			}
			else if (qtype_customer.amount == 3)
			{
				qtype_customer = remove(&desk3);
				cash_desk3--;
				payment += qtype_customer.amount;
			}

			if (qtype_customer.code == 'C')
			{
				cash++;
			}
			else
			{
				visa++;
			}
		}
	}

	if (!is_empty_q(&desk1) && !is_empty_q(&desk2) && !is_empty_q(&desk3))
	{
		payment_t temp1, temp2, temp3;

		int count1 = desk1.counter;
		int count2 = desk2.counter;
		int count3 = desk3.counter;

		temp1 = remove(&desk1);
		temp2 = remove(&desk2);
		temp3 = remove(&desk3);

		printf("Cash Desk 1\n");

		for (int i = 0; i < count1; i++)
		{
			printf("%c %.2lf\n", temp1.code, temp1.amount);
			temp1 = remove(&desk1);
		}

		printf("Cash Desk 2\n");

		for (int i = 0; i < count2; i++)
		{
			printf("%c %.2lf\n", temp2.code, temp2.amount);
			temp2 = remove(&desk2);
		}

		printf("Cash Desk 3\n");

		for (int i = 0; i < count3; i++)
		{
			printf("%c %.2lf\n", temp3.code, temp3.amount);
			temp3 = remove(&desk3);
		}

		printf("Cash: %d\nVisa: %d\nTotal Payment:%.2lf", cash, visa, payment);
	}

	return 0;
}
