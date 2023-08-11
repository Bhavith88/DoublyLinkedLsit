#include <stdio.h>

#include <stdlib.h>



struct Node {

    int data;

    struct Node *prev;

    struct Node *next;

};



typedef struct Node Node;



// Function to create a new node

Node* createNode(int data) {

    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->data = data;

    newNode->prev = NULL;

    newNode->next = NULL;

    return newNode;

}



// Function to append a node to the end of the linked list

void append(Node **head, int data) {

    Node *newNode = createNode(data);

    

    if (*head == NULL) {

        *head = newNode;

    } else {

        Node *current = *head;

        while (current->next != NULL) {

            current = current->next;

        }

        current->next = newNode;

        newNode->prev = current;

    }

}



// Function to find an element in the linked list

int findElement(Node *head, int target) {

    Node *current = head;

    while (current != NULL) {

        if (current->data == target) {

            return 1;

        }

        current = current->next;

    }

    return 0;

}



// Function to persist elements to a text file

void persistToTextFile(Node *head) {

    FILE *file = fopen("doubly_linked_list.txt", "w");

    if (file == NULL) {

        perror("Error opening file");

        return;

    }



    Node *current = head;

    while (current != NULL) {

        fprintf(file, "%d\n", current->data);

        current = current->next;

    }



    fclose(file);

}



// Function to persist elements to a binary file

void persistToBinaryFile(Node *head) {

    FILE *file = fopen("doubly_linked_list.bin", "wb");

    if (file == NULL) {

        perror("Error opening file");

        return;

    }



    fwrite(&head, sizeof(Node*), 1, file);



    fclose(file);

}



int main() {

    Node *head = NULL;

    int elements[10], i,n;

    printf("Enter the number of elements to be in the list:");

    scanf("%d",&n);

    for (i=0;i<n;i++) {

        scanf("%d",&elements[i]);

    }

  

    int numElements = sizeof(elements) / sizeof(elements[0]);

    

    for (int i = 0; i < numElements; ++i) {

        append(&head, elements[i]);

    }

    

    int targetElement;

    printf("Enyter the target element:");

    scanf("%d",&targetElement);

    int found = findElement(head, targetElement);

    printf("Element %d found: %s\n", targetElement, found ? "Yes" : "No");



    persistToTextFile(head);

    persistToBinaryFile(head);



    return 0;

}

