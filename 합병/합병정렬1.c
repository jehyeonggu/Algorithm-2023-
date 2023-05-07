#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h> // malloc, free �Լ� ����� ���� �ʿ�

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // �ӽ� �迭�� �������� �Ҵ�
    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    // �ӽ� �迭�� ���� ����
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // �ӽ� �迭 L�� R�� �պ��Ͽ� arr�� ���ĵ� ���� ����
    i = 0; // L �迭�� �ε���
    j = 0; // R �迭�� �ε���
    k = left; // arr �迭�� �ε���
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // L �迭�� ���� ���� �ִٸ� arr�� ����
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // R �迭�� ���� ���� �ִٸ� arr�� ����
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // �������� �Ҵ��� �޸𸮸� ����
    free(L);
    free(R);
}

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // ���� �κ� �迭�� ����
        merge_sort(arr, left, mid);

        // ������ �κ� �迭�� ����
        merge_sort(arr, mid + 1, right);

        // �� �κ� �迭�� �պ�
        merge(arr, left, mid, right);
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

    merge_sort(arr, 0, n - 1);

    FILE* OutFile = fopen("result.txt", "w");

    if (OutFile == NULL) {
        printf("��� ������ ���� ���߽��ϴ�.\n");
        free(arr);
        return 1;
    }
    else {
        printf("result�� ����Ǿ����ϴ�.\nresult�� Ȯ�� ���ּ���!!!\n");
    }

    fprintf(OutFile, "�պ����� ������ �迭: ");
    for (int i = 0; i < n; i++)
        fprintf(OutFile, "%d ", arr[i]);
    fprintf(OutFile, "\n");

    fclose(OutFile);

    free(arr);

    return 0;
}