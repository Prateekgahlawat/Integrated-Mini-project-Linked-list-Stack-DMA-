#include <iostream>
using namespace std;

// ---------- LINKED LIST ----------
struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void insertBegin(int x){
    Node* temp = new Node();
    temp->data = x;
    temp->next = head;
    head = temp;
}

void insertEnd(int x){
    Node* temp = new Node();
    temp->data = x;
    temp->next = NULL;

    if(head == NULL){
        head = temp;
        return;
    }

    Node* ptr = head;
    while(ptr->next != NULL){
        ptr = ptr->next;
    }
    ptr->next = temp;
}

void deleteNode(int x){
    if(head == NULL){
        cout << "List empty\n";
        return;
    }

    if(head->data == x){
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* ptr = head;
    while(ptr->next != NULL && ptr->next->data != x){
        ptr = ptr->next;
    }

    if(ptr->next == NULL)
        cout << "Value not found\n";
    else{
        Node* temp = ptr->next;
        ptr->next = temp->next;
        delete temp;
    }
}

void printList(){
    if(head == NULL){
        cout << "List empty\n";
        return;
    }

    Node* temp = head;
    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// ---------- STACK ----------
int stackArr[100];
int top = -1;

void push(int x){
    if(top == 99){
        cout << "Stack Overflow\n";
        return;
    }
    stackArr[++top] = x;
}

void pop(){
    if(top == -1){
        cout << "Stack Underflow\n";
        return;
    }
    top--;
}

void peek(){
    if(top == -1)
        cout << "Stack Empty\n";
    else
        cout << stackArr[top] << endl;
}

// ---------- MAIN ----------
int main(){
    int choice, sub, x, n;

    while(true){
        cout << "\n1.Linked List 2.Stack 3.DMA 0.Exit\n";
        cin >> choice;

        if(choice == 0){
            cout << "Exiting...\n";
            break;
        }

        switch(choice){

        case 1:
            while(true){
                cout << "1.Insert Begin 2.Insert End 3.Delete 4.Print 0.Back\n";
                cin >> sub;

                if(sub == 0) break;

                switch(sub){
                    case 1:
                        cin >> x;
                        insertBegin(x);
                        break;

                    case 2:
                        cin >> x;
                        insertEnd(x);
                        break;

                    case 3:
                        cin >> x;
                        deleteNode(x);
                        break;

                    case 4:
                        printList();
                        break;

                    default:
                        cout << "Invalid\n";
                }
            }
            break;

        case 2:
            while(true){
                cout << "1.Push 2.Pop 3.Peek 0.Back\n";
                cin >> sub;

                if(sub == 0) break;

                switch(sub){
                    case 1:
                        cin >> x;
                        push(x);
                        break;

                    case 2:
                        pop();
                        break;

                    case 3:
                        peek();
                        break;

                    default:
                        cout << "Invalid\n";
                }
            }
            break;

        case 3: {
            cout << "Enter size: ";
            cin >> n;

            int* arr = new int[n];

            cout << "Enter elements:\n";
            for(int i = 0; i < n; i++)
                cin >> arr[i];

            cout << "Array: ";
            for(int i = 0; i < n; i++)
                cout << arr[i] << " ";

            delete[] arr;
            cout << endl;
            break;
        }

        default:
            cout << "Invalid choice\n";
        }
    }

    return 0;
}