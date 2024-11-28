#include <stdio.h>
#include <stdlib.h>

// Define the structure for a doubly linked list node
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Function prototypes
Node* createNode(int data);
void insertAtFront(Node** head, int data);
void insertAtEnd(Node** head, int data);
void insertAtAny(Node** head, int data, int position);
void deleteAtFront(Node** head);
void deleteAtEnd(Node** head);
void deleteAtAny(Node** head, int position);
Node* search(Node* head, int key);
void display(Node* head);

// Main function
int main() {
    Node* head = NULL;
    int choice, data, position, key;
    Node* result;

    do {
        printf("\nDoubly Linked List Operations:\n");
        printf("1. Insert At Front\n2. Insert At End\n3. Insert At Any Position\n");
        printf("4. Delete At Front\n5. Delete At End\n6. Delete At Any Position\n");
        printf("7. Search\n8. Display\n9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at front: ");
                scanf("%d", &data);
                insertAtFront(&head, data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                insertAtAny(&head, data, position);
                break;
            case 4:
                deleteAtFront(&head);
                break;
            case 5:
                deleteAtEnd(&head);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtAny(&head, position);
                break;
            case 7:
                printf("Enter key to search: ");
                scanf("%d", &key);
                result = search(head, key);
                if (result)
                    printf("Key %d found in the list.\n", key);
                else
                    printf("Key %d not found in the list.\n", key);
                break;
            case 8:
                display(head);
                break;
            case 9:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 9);

    return 0;
}

// Create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->prev = newNode->next = NULL;
    return newNode;
}

// Insert at the front
void insertAtFront(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    if (*head != NULL)
        (*head)->prev = newNode;
    *head = newNode;
}

// Insert at the end
void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

// Insert at any position
void insertAtAny(Node** head, int data, int position) {
    if (position == 1) {
        insertAtFront(head, data);
        return;
    }

    Node* newNode = createNode(data);
    Node* temp = *head;

    for (int i = 1; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }

    newNode->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = newNode;
    temp->next = newNode;
    newNode->prev = temp;
}

// Delete at the front
void deleteAtFront(Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node* temp = *head;
    *head = (*head)->next;

    if (*head != NULL)
        (*head)->prev = NULL;

    free(temp);
    printf("Node deleted from front.\n");
}

// Delete at the end
void deleteAtEnd(Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node* temp = *head;

    while (temp->next != NULL)
        temp = temp->next;

    if (temp->prev != NULL)
        temp->prev->next = NULL;
    else
        *head = NULL;

    free(temp);
    printf("Node deleted from end.\n");
}

// Delete at any position
void deleteAtAny(Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    if (position == 1) {
        deleteAtFront(head);
        return;
    }

    Node* temp = *head;

    for (int i = 1; i < position && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position!\n");
        return;
    }

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    free(temp);
    printf("Node deleted at position %d.\n", position);
}

// Search for a key
Node* search(Node* head, int key) {
    Node* temp = head;

    while (temp != NULL) {
        if (temp->data == key)
            return temp;
        temp = temp->next;
    }

    return NULL;
}

// Display the list
void display(Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }

    Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
