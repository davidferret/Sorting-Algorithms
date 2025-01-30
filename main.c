#include <stdio.h>
#define MAXSIZE 100

void bubbleSort(int num[], int N, int ascending);
void quickSort(int num[], int low, int high, int ascending);
int partition(int num[], int low, int high, int ascending);
void mergeSort(int num[], int left, int right, int ascending);
void merge(int num[], int left, int mid, int right, int ascending);
void printSortedArray(int num[], int N);
void saveToFile(int num[], int N, const char *filename);
void loadFromFile(int num[], int *N, const char *filename);

int main(void) {
    int i, N, number[MAXSIZE], choice, order;
    char filename[50];
    
    printf("Choose input method:\n1 - Manual Entry\n2 - Load from File\nEnter choice: ");
    scanf("%d", &choice);
    
    if (choice == 2) {
        printf("Enter filename: ");
        scanf("%s", filename);
        loadFromFile(number, &N, filename);
    } else {
        printf("How many numbers?: ");
        scanf("%d", &N);
        for (i = 0; i < N; i++) {
            printf("Enter a number (%d of %d): ", i + 1, N);
            scanf("%d", &number[i]);
        }
    }
    
    printf("Choose sorting order:\n1 - Ascending\n2 - Descending\nEnter choice: ");
    scanf("%d", &order);
    int ascending = (order == 1);
    
    printf("Choose sorting algorithm:\n1 - Bubble Sort\n2 - Quick Sort\n3 - Merge Sort\nEnter choice: ");
    scanf("%d", &choice);
    
    if (choice == 1) {
        bubbleSort(number, N, ascending);
    } else if (choice == 2) {
        quickSort(number, 0, N - 1, ascending);
    } else {
        mergeSort(number, 0, N - 1, ascending);
    }
    
    printSortedArray(number, N);
    
    printf("Enter filename to save sorted data: ");
    scanf("%s", filename);
    saveToFile(number, N, filename);
    
    return 0;
}

void bubbleSort(int num[], int N, int ascending) {
    int iter, i, temp, swapped;
    for (iter = 0; iter < N - 1; iter++) {
        swapped = 0;
        for (i = 0; i < N - 1 - iter; i++) {
            if ((ascending && num[i] > num[i + 1]) || (!ascending && num[i] < num[i + 1])) {
                temp = num[i];
                num[i] = num[i + 1];
                num[i + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) break; // Stop early if no swaps
    }
}

void quickSort(int num[], int low, int high, int ascending) {
    if (low < high) {
        int pivot = partition(num, low, high, ascending);
        quickSort(num, low, pivot - 1, ascending);
        quickSort(num, pivot + 1, high, ascending);
    }
}

int partition(int num[], int low, int high, int ascending) {
    int pivot = num[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if ((ascending && num[j] <= pivot) || (!ascending && num[j] >= pivot)) {
            i++;
            int temp = num[i];
            num[i] = num[j];
            num[j] = temp;
        }
    }
    int temp = num[i + 1];
    num[i + 1] = num[high];
    num[high] = temp;
    return (i + 1);
}

void mergeSort(int num[], int left, int right, int ascending) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(num, left, mid, ascending);
        mergeSort(num, mid + 1, right, ascending);
        merge(num, left, mid, right, ascending);
    }
}

void merge(int num[], int left, int mid, int right, int ascending) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++) L[i] = num[left + i];
    for (j = 0; j < n2; j++) R[j] = num[mid + 1 + j];
    i = 0; j = 0; k = left;
    while (i < n1 && j < n2) {
        if ((ascending && L[i] <= R[j]) || (!ascending && L[i] >= R[j]))
            num[k++] = L[i++];
        else
            num[k++] = R[j++];
    }
    while (i < n1) num[k++] = L[i++];
    while (j < n2) num[k++] = R[j++];
}

void printSortedArray(int num[], int N) {
    int i;
    printf("Sorted Numbers: ");
    for (i = 0; i < N - 1; i++) {
        printf("%d, ", num[i]);
    }
    printf("and %d\n", num[i]);
}

void saveToFile(int num[], int N, const char *filename) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        printf("Error saving file.\n");
        return;
    }
    for (int i = 0; i < N; i++) {
        fprintf(fp, "%d\n", num[i]);
    }
    fclose(fp);
    printf("Sorted data saved to %s\n", filename);
}

void loadFromFile(int num[], int *N, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error opening file.\n");
        return;
    }
    *N = 0;
    while (fscanf(fp, "%d", &num[*N]) != EOF && *N < MAXSIZE) {
        (*N)++;
    }
    fclose(fp);
    printf("Data loaded from %s\n", filename);
}
