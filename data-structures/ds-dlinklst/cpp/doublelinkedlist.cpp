#include <iostream>
#include <string.h>
using namespace std;

class Node
{
public:
    int age;
    string name;
    string dept;
    string gender;
    Node *nxt;
    Node *prev;
};

Node *head = NULL;

bool repeat(string n)
{
    if (head == NULL)
        return 0;
    Node *temp = new Node;
    temp = head;
    while (temp != NULL)
    {
        if (temp->name == n)
            return 1;
        temp = temp->nxt;
    }
    return 0;
}

void insert(int age, string name, string dept, string gender)
{
    if (repeat(name))
    {
        return;
    }

    Node *temp = new Node();
    temp->age = age;
    temp->name = name;
    temp->dept = dept;
    temp->gender = gender;

    if (head == NULL || (head->name >= temp->name))
    {
        temp->nxt = head;
        temp->prev = NULL;
        head = temp;
    }

    else
    {
        Node *temp2 = head;
        while (temp2->nxt != NULL && temp2->nxt->name < temp->name)
        {
            temp2 = temp2->nxt;
        }
        temp->nxt = temp2->nxt;
        temp->prev = temp2;
        temp2->nxt = temp;
        temp2->nxt->prev = temp;
    }
}

void Delete(string name)
{
    Node *temp = head;
    Node *temp2 = NULL;

    if (temp != NULL && temp->name == name)
    {
        if (head->nxt != NULL)
        {
            head->nxt->prev = NULL;
            head = head->nxt;
            delete temp;
            return;
        }
        else
        {
            head = NULL;
        }
    }
    if (temp != NULL)
    {
        while (temp->name != name && temp != NULL)
        {
            temp2 = temp;
            temp = temp->nxt;
        }
        if (temp->nxt != NULL)
        {
            temp2->nxt = temp->nxt;
            temp->nxt->prev = temp2;
            delete temp;
            return;
        }
        else
        {
            temp2->nxt = NULL;
            delete temp;
            return;
        }
    }
}

void search(string name)
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        Node *temp = head;
        while (temp)
        {
            if (temp->name == name)
            {
                cout << "name found\n";
                cout << temp->name << " ";
                cout << temp->age << " ";
                cout << temp->gender << " ";
                cout << temp->dept << " ";
                return;
            }
            else
            {
                cout << "name not found";
            }
            temp = temp->nxt;
        }
        if (temp == NULL)
        {
            cout << " ";
        }
    }
}

void display()
{
    Node *p = head;
    if (p != NULL)
    {

        while (p != NULL)
        {
            cout << p->name << "\n";
            cout << p->age << "\n";
            cout << p->gender << "\n";
            cout << p->dept << "\n";
            p = p->nxt;
        }
    }
}

int main()
{
    int age;
    string name, dept, gender;
    char c;
    head = NULL;

    while (1)
    {
        cin >> c;

        if (c == 'A')
        {
            cin >> name;
            cin >> age;
            cin >> gender;
            cin >> dept;

            insert(age, name, dept, gender);
        }

        if (c == 'B')
        {
            cin >> name;

            search(name);
        }

        if (c == 'D')
        {
            cin >> name;

            Delete(name);
        }

        if (c == 'E')
        {

            display();
        }
    }

    return 0;
}
