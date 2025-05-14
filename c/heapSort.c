#include <stdio.h>

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        int swap = arr[i];
        arr[i] = arr[largest];
        arr[largest] = swap;

        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    int i;

    for (i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (i = n - 1; i >= 0; i--) {
        int swap = arr[0];
        arr[0] = arr[i];
        arr[i] = swap;

        heapify(arr, i, 0);
    }
}

int main() {
    int arr[50], len;
	printf("Enter length: ");
	scanf("%d", &len);
	printf("Enter elements:\n");
	for (int i = 0; i < len; i++) {
		scanf("%d", &arr[i]);
	}
    heapSort(arr, len);
    printf("Sorted array is \n");
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}