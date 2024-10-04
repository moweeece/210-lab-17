// COMSC-210 | Lab 17 | Mauricio Espinosa
// IDE Used: Visual Studios Code & Github

#include <iostream>
using namespace std;

const int SIZE = 7;  

struct Node {
    float value;
    Node *next;
};

// function prototypes
void output(Node *);
Node* addNodeFront(Node*, float);
Node* addNodeTail(Node*, float);
Node* deleteNode(Node*, int);
Node* insertNode(Node*, int);
Node* deleteList(Node*);


int main() {
    Node *head = nullptr;
    float frontVal, backVal = 0.0;

    // create a linked list of size SIZE with random numbers 0-99
    for (int i = 0; i < SIZE; i++) {
        int tmp_val = rand() % 100;
        Node *newVal = new Node;
        
        // adds node at head
        if (!head) { // if this is the first node, it's the new head
            head = newVal;
            newVal->next = nullptr;
            newVal->value = tmp_val;
        }
        else { // its a second or subsequent node; place at the head
            newVal->next = head;
            newVal->value = tmp_val;
            head = newVal;
        }
    }
    output(head);

    // adding a node to the front using a function and user input
    cout << "What value to add to the front of the list? " << endl;
    cin >> frontVal;
    head = addNodeFront(head, frontVal);
    output(head);


    // adding a node to the back using a function and user input
    cout << "What value to add to the back of the list? " << endl;
    cin >> backVal;
    head = addNodeTail(head, backVal);
    output(head);


    // deleting a node
    cout << "Which node to delete? " << endl;
    output(head);
    int entry;
    cout << "Choice --> ";
    cin >> entry;
    head = deleteNode(head, entry);
    output(head);


    // insert a node
    Node *current = head;
    cout << "After which node to insert 10000? " << endl;
    int count = 1;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << "Choice --> ";
    cin >> entry;
    head = insertNode(head, entry);
    output(head);

    
    // deleting the linked list
    head = deleteList(head);
    output(head);    

    return 0;
}


// function definitions

// function for ouputting the list
void output(Node * hd) {
    if (!hd) {
        cout << "Empty list.\n";
        return;
    }
    int count = 1;
    Node * current = hd;
    while (current) {
        cout << "[" << count++ << "] " << current->value << endl;
        current = current->next;
    }
    cout << endl;
}

// function for adding a node to the front
Node* addNodeFront(Node* head, float frontValue)
{
    // create a new memory allocation for the new node
    Node *newNode = new Node;
    newNode->next = nullptr;

    // initialize the new nodes value and next pointer
    newNode->value = frontValue;
    newNode->next = head;

    // have head now point to the new node
    head = newNode;

    return head;
}

 
// function for adding a node to the back
Node* addNodeTail(Node* head, float backValue)
{
    Node *newNode = new Node;
    newNode->value = backValue;
    newNode->next = nullptr;
    
    if (!head)
    {
        return newNode;
    }

    Node *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }
    current->next = newNode;
    
    return head;
}

// function for deleting a node
Node* deleteNode(Node* head, int userEntry)
{
    if (!head) return nullptr;

    Node *current = head;
    Node *prev = nullptr;

    // for deleting the first node
    if (userEntry == 1)
    {
        head = current->next;
        delete current;
        return head;
    }

    // traverse that many times and delete that node
    for (int i = 1; i < userEntry; i++)
    {
        prev = current;
        current = current->next;
        if (!current) return head;
    }
        
    // at this point, delete current and reroute pointers
    if (current) {  // checks for current to be valid before deleting the node
        prev->next = current->next;
        delete current;
    }

    return head;
}

// function for inserting a node
Node* insertNode(Node* head, int userEntry)
{
    Node *current = head;
    Node *prev = head;

    for (int i = 0; i < (userEntry); i++)
        if (i == 0)
            current = current->next;
        else {
            current = current->next;
            prev = prev->next;
        }
        
    //at this point, insert a node between prev and current
    Node * newnode = new Node;
    newnode->value = 10000;
    newnode->next = current;
    prev->next = newnode;


    return head;
}


// function for deleting the list
Node* deleteList(Node* head)
{
    Node *current = head;

    // original while loop
    while (current) {
        Node *nextNode = current->next;  // creates a new node and stores next ndoe
        delete current;                  // delete current
        current = nextNode;              // advance to next node
    }

    return nullptr;
}

