#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
    ~Node()
    {
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
    }
};

class List
{
public:
    Node *head;
    Node *tail;

    List()
    {
        head = NULL;
        tail = NULL;
    }
    ~List()
    {
        if (head != NULL)
        {
            delete head;
            head = NULL;
        }
    }

    void push_front(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
    }

    void push_back(int val)
    {
        Node *newNode = new Node(val);

        if (head == NULL)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front()
    {
        if (head == NULL)
        {
            return;
        }

        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    void pop_back()
    {
        if (head == NULL)
        {
            return;
        }

        Node *temp = head;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

    void print()
    {
        Node *temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void search(int value)
    {
        Node *temp = head;
        bool check = false;

        while (temp != NULL)
        {
            if (value == temp->data)
            {
                check = true;
            }
            temp = temp->next;
        }
        if (check)
        {
            cout << "Found" << endl;
        }
        else
        {
            cout << "Not Found" << endl;
        }
    }

    void insert(int position, int value)
    {
        Node *temp = head;

        for (int i = 0; i < position - 1; i++)
        {
            temp = temp->next;
        }

        Node *newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void erase(int position)
    {
        Node *temp = head;
        for (int i = 0; i < position - 1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
    }

    void total_elements()
    {
        Node *temp = head;
        int count = 0;

        while (temp != NULL)
        {
            temp = temp->next;
            count++;
        }
        cout << count << endl;
    }

    void recursive_search(Node *temp, int key)
    {
        if (temp == NULL)
        {
            cout << "Not Found" << endl;
            return;
        }
        if (temp->data == key)
        {
            cout << "Found" << endl;
            return;
        }
        recursive_search(temp->next, key);
    }
};

int main()
{

    List ll;

    ll.push_front(4);
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);

    ll.push_back(5);
    ll.push_back(6);

    ll.pop_back();
    ll.pop_front();

    ll.insert(2, 10);
    ll.erase(2);

    ll.print();

    ll.search(5);
    ll.recursive_search(ll.head, 5);

    return 0;
}
