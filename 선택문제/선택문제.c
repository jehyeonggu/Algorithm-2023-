#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int* a, int* b)   // �Ǻ��� �迭�� ���Ҹ� ��ȯ�ϴ� �Լ�
{
    int temp = *a;
    *a = *b;
    *b = temp;
}


int partition(int arr[], int left, int right)   // �� ������ �����ϰ� �Ǻ��� �ε����� ��ȯ�ϴ� �Լ�
{
   
    srand(time(NULL));  // �Ǻ��� �����ϰ� ����

    int pivotindex = left + rand() % (right - left + 1);
    int pivot = arr[pivotindex];

    // �Ǻ��� A[left]�� ��ġ�� �ٲ�
    swap(&arr[left], &arr[pivotindex]); 

    int i = left + 1;
    int j = right;

    while (1) 
    {
        while (i <= j && arr[i] < pivot)
            i++;

        while (i <= j && arr[j] > pivot)
            j--;

        if (i > j)
            break;

        swap(&arr[i], &arr[j]);
        i++;
        j--;
    }

    
    swap(&arr[left], &arr[j]);  // �Ǻ��� �˸��� ���� ��ġ�� ��ġ

    return j;
}

// Selection �˰���
int Selection(int arr[], int left, int right, int k) 
{
    if (left == right)
        return arr[left];

    int pivotIndex = partition(arr, left, right);
    int smallG = pivotIndex - left;

    if (k <= smallG)
        return Selection(arr, left, pivotIndex - 1, k);
    else if (k == smallG + 1)
        return arr[pivotIndex];
    else
        return Selection(arr, pivotIndex + 1, right, k - smallG - 1);
}

int main() 
{
   
    FILE* inFile = fopen("data.txt", "r");  // ���� �б�

    if (inFile == NULL) 
    {
        printf("Failed to open the input file.\n");
        return 1;
    }

    // ���Ͽ��� �������� �о� �迭�� ����

    int maxElements = 1000; // �迭�� �ִ� ũ��
    int* arr = malloc(maxElements * sizeof(int));

    if (arr == NULL) 
    {
        printf("Memory allocation failed.\n");
        fclose(inFile);
        return 1;
    }

    int i = 0;

    while (fscanf(inFile, "%d", &arr[i]) != EOF) //EOF�� "End of File"�� ���ڷ�, ������ ���� ��Ÿ���� ���
    {
        i++;
        if (i >= maxElements)
            break;
    }

    int n = i; // �迭�� ���� ũ��

    fclose(inFile);

    // Selection �˰��� ����
    int k = 5;
    int result = Selection(arr, 0, n - 1, k);

    // ��� ���Ͽ� ����
    FILE* OutFile = fopen("result.txt", "w");

    if (OutFile == NULL)
    {
        printf("Failed to open the output file.\n");
        free(arr);
        return 1;
    }
    else
    {
        printf("result�� ����Ǿ����ϴ�.\nresult�� Ȯ�� ���ּ���!!!\n");
    }

    fprintf(OutFile, "%d��°�� ���� ����: %d\n", k, result);

    fclose(OutFile);

    free(arr);

    return 0;
}