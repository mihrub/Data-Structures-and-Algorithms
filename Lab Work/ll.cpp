#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class List {
public:
    Node* head;
    Node* tail;

    List() {
        head = NULL;
        tail = NULL;
    }

    void push_front(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_back() {
        if (head == NULL) {
            cout << "List is empty, nothing to remove.\n\n";
            return;
        }
        if (head == tail) {
            cout << "Removing last node: " << tail->data << endl;
            delete head;
            head = tail = NULL;
            return;
        }

        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        cout << "Removing last node: " << tail->data << endl;
        delete tail;
        temp->next = NULL;
        tail = temp;
        cout << "Successfully removed!\n\n";
    }

    void pop_front() {
        if (head == NULL) {
            cout << "List is empty, nothing to remove.\n\n";
            return;
        }

        cout << "Removing front node: " << head->data << endl;
        Node* temp = head;
        head = head->next;
        delete temp;

        if (head == NULL) {
            tail = NULL;
        }
        cout << "Successfully removed!\n\n";
    }

    void print() {
        if (head == NULL) {
            cout << "List is empty!\n\n";
            return;
        }

        cout << "Current List: ";
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl << endl;
    }

    void insert(int position, int value) {
        cout << "Inserting value " << value << " at position " << position << ".\n";
        if (position == 0) {
            push_front(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* temp = head;

        int index = 0;
        while (temp != NULL && index < position - 1) {
            temp = temp->next;
            index++;
        }

        if (temp == NULL) {
            cout << "Invalid position! No insertion performed.\n\n";
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        if (newNode->next == NULL) {
            tail = newNode;
        }

        cout << "Successfully inserted!\n\n";
    }

    void erase(int position) {
        if (head == NULL) {
            cout << "List is empty, nothing to erase.\n\n";
            return;
        }

        cout << "Attempting to erase node at position " << position << ".\n";

        if (position == 0) {
            pop_front();
            return;
        }

        Node* temp = head;
        int index = 0;

        while (temp->next != NULL && index < position - 1) {
            temp = temp->next;
            index++;
        }

        if (temp->next == NULL) {
            cout << "Invalid position! No deletion performed.\n\n";
            return;
        }

        cout << "Removing node with value: " << temp->next->data << endl;
        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;

        if (temp->next == NULL) {
            tail = temp;
        }

        cout << "Successfully removed!\n\n";
    }
};

void menu() {
    cout << "1. Print List\n";
    cout << "2. Push Back -> LL\n";
    cout << "3. Pop Back -> LL\n";
    cout << "4. Insert -> LL\n";
    cout << "5. Erase -> LL\n";
    cout << "6. Push Front -> LL\n";
    cout << "7. Pop Front -> LL\n";
    cout << "8. Exit\n";
}

int main() {
    List ll;

    int n;
    cout << "Enter the size of the linked list: ";
    cin >> n;

    cout << "Enter " << n << " values:\n";
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        ll.push_front(a);
    }

    while (true) {
        int choice;
        menu();
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            ll.print();
        } else if (choice == 2) {
            int val;
            cout << "Enter value to push back: ";
            cin >> val;
            ll.push_back(val);
        } else if (choice == 3) {
            ll.pop_back();
        } else if (choice == 4) {
            int position, value;
            cout << "Enter position: ";
            cin >> position;
            cout << "Enter value: ";
            cin >> value;
            ll.insert(position, value);
        } else if (choice == 5) {
            int position;
            cout << "Enter position to erase: ";
            cin >> position;
            ll.erase(position);
        } else if (choice == 6) {
            int val;
            cout << "Enter value to push front: ";
            cin >> val;
            ll.push_front(val);
        } else if (choice == 7) {
            ll.pop_front();
        } else if (choice == 8) {
            cout << "Exiting program.\n";
            break;
        }
    }

    return 0;
}