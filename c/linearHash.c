// Linear Probing Hashing where if supposed to fill index is filled go to index + 1

#include<stdio.h>
#include<stdlib.h>

int array[50] = {0}, max = 10;

void hashing(int data) {
	for (int i = 0; i < max; i++) {
		if (!array[(data + i) % max]) {
			array[(data + i) % max] = data;
			return;
		}
	}
	printf("Hash table is full\n");
}

void display() {
	for (int i = 0; i < max; i++) {
		printf("%d. %d\n", i, array[i]);
	}
}

int main() {
	char choice;
	int data;
	while (1) {
		printf("h: hash, l: length, d: display, e: exit\nEnter choice: ");
		scanf("%s", &choice);

		switch (choice) {
		case 'h':
			scanf("%d", &data);
			hashing(data);
			break;

		case 'l':
			scanf("%d", &max);
			break;

		case 'd':
			display();
			break;

		case 'e':
			exit(0);
		
		default:
			printf("Invalid\n");
		}
	}
	

	hashing(12);
	display();
}

