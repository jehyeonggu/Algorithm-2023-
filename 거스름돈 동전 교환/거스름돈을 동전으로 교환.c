#include <stdio.h>

void changecoin(int coin)  // ���� ��ȯ �Լ� (changecoin)�� ����
{
	int recoin;             //�ܵ� ����    coin�� ����ص� ������ ���μ��� ���� �ʴٰ� �Ǵ� recoin�� ���
	int w500, w100, w50, w10;		//�� ������ ����

	w500 = coin / 500;		//500�� ������ ������ ���
	printf("�����¥�� ==> %d �� \n", w500);		//����� ������ ���
	recoin = coin % 500;		//�ܵ����� 500���� �������� ������ �ݾ�   

	w100 = recoin / 100;
	printf("���¥��    ==> %d �� \n", w100);
	recoin = recoin % 100;

	w50 = recoin / 50;
	printf("���ʿ�¥�� ==> %d �� \n", w50);
	recoin = recoin % 50;

	w10 = recoin / 10;
	printf("�ʿ�¥��    ==> %d �� \n", w10);
	recoin = recoin % 10;

	printf("�ٲ��� ���� �ܵ� ==> %d �� \n", recoin);		//�� ������δ� �ٲ��� ���ϴ� 1�ڸ� ���� ����
}

int main() {

	int coin;
	printf("��ȯ�� ���� ? ");
	scanf("%d", &coin);

	changecoin(coin);		//���� ��ȯ�ϴ� �Լ� ȣ��

	return 0;
}