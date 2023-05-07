#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void quicksort(int arr[], int left, int right) {
    int pivot, i, j, temp;

    // �迭�� ũ�Ⱑ 1 ���ϸ� ������ �ʿ䰡 ����
    if (left >= right) {
        return;
    }

    // �ǹ��� ��� ���ҷ� �����Ѵ�
    pivot = arr[(left + right) / 2];

    // �ǹ��� �������� ���� ���� ��������, ū ���� ���������� �ű��
    i = left;
    j = right;
    while (i <= j) {
        while (arr[i] < pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i <= j) {
            // i�� j�� ���Ҹ� ��ȯ�Ѵ�
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }

    // ���ҵ� �� �κ� �迭�� ���� ��������� �������� �����Ѵ�
    if (left < j) {
        quicksort(arr, left, j);
    }
    if (i < right) {
        quicksort(arr, i, right);
    }
}

int main() {
    FILE* inFile = fopen("data.txt", "r");

    if (inFile == NULL) {
        printf("�Է� ������ ���µ� �����Ͽ����ϴ�.\n");
        return 1;
    }

    int maxElements = 1000;
    int* arr = malloc(maxElements * sizeof(int));

    if (arr == NULL) {
        printf("�޸� �Ҵ翡 �����Ͽ����ϴ�.\n");
        fclose(inFile);
        return 1;
    }

    int i = 0;

    while (fscanf(inFile, "%d", &arr[i]) != EOF) {
        i++;
        if (i >= maxElements)
            break;
    }

    int n = i;

    fclose(inFile);

    quicksort(arr, 0, n - 1);

    FILE* outFile = fopen("result.txt", "w");

    if (outFile == NULL) {
        printf("��� ������ ���� ���߽��ϴ�.\n");
        free(arr);
        return 1;
    }
    else {
        printf("result�� ����Ǿ����ϴ�.\nresult�� Ȯ�����ּ���!!!\n");
    }

    fprintf(outFile, "������ ������ �迭: ");
    for (int i = 0; i < n; i++)
        fprintf(outFile, "%d ", arr[i]);
    fprintf(outFile, "\n");

    fclose(outFile);

    free(arr);

    return 0;
}