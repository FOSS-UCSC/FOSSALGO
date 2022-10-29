#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    int age;
    int c; // 1-red, 0-black
    struct node *parent;
    struct node *rchild;
    struct node *lchild;
};

struct node *root = NULL;

struct node *bst(struct node *trav, struct node *temp)
{

    if (trav == NULL)
        return temp;

    if (temp->age < trav->age)
    {
        trav->lchild = bst(trav->lchild, temp);
        trav->lchild->parent = trav;
    }
    else if (temp->age > trav->age)
    {
        trav->rchild = bst(trav->rchild, temp);
        trav->rchild->parent = trav;
    }

    return trav;
}

void rightrotate(struct node *temp)
{
    struct node *left = temp->lchild;
    temp->lchild = left->rchild;
    if (temp->lchild)
        temp->lchild->parent = temp;
    left->parent = temp->parent;
    if (!temp->parent)
        root = left;
    else if (temp == temp->parent->lchild)
        temp->parent->lchild = left;
    else
        temp->parent->rchild = left;
    left->rchild = temp;
    temp->parent = left;
}

void leftrotate(struct node *temp)
{
    struct node *right = temp->rchild;
    temp->rchild = right->lchild;
    if (temp->rchild)
        temp->rchild->parent = temp;
    right->parent = temp->parent;
    if (!temp->parent)
        root = right;
    else if (temp == temp->parent->lchild)
        temp->parent->lchild = right;
    else
        temp->parent->rchild = right;
    right->lchild = temp;
    temp->parent = right;
}

void fixup(struct node *root, struct node *pt)
{
    struct node *parentpt = NULL;
    struct node *grandparent = NULL;

    while ((pt != root) && (pt->c != 0) && (pt->parent->c == 1))
    {
        parentpt = pt->parent;
        grandparent = pt->parent->parent;

        if (parentpt == grandparent->lchild)
        {

            struct node *uncle = grandparent->rchild;

            if (uncle != NULL && uncle->c == 1) // recolouring required
            {
                grandparent->c = 1;
                parentpt->c = 0;
                uncle->c = 0;
                pt = grandparent;
            }

            else
            {

                if (pt == parentpt->rchild) // left rotation required
                {
                    leftrotate(parentpt);
                    pt = parentpt;
                    parentpt = pt->parent;
                }

                rightrotate(grandparent); // right rotation required
                int t = parentpt->c;
                parentpt->c = grandparent->c;
                grandparent->c = t;
                pt = parentpt;
            }
        }

        else
        {
            struct node *uncle = grandparent->lchild;

            if ((uncle != NULL) && (uncle->c == 1)) // recolouring required
            {
                grandparent->c = 1;
                parentpt->c = 0;
                uncle->c = 0;
                pt = grandparent;
            }
            else
            {
                if (pt == parentpt->lchild) // right rotation required
                {
                    rightrotate(parentpt);
                    pt = parentpt;
                    parentpt = pt->parent;
                }

                leftrotate(grandparent); // left rotation required
                int t = parentpt->c;
                parentpt->c = grandparent->c;
                grandparent->c = t;
                pt = parentpt;
            }
        }
    }

    root->c = 0;
}

void inorder(struct node *trav)
{
    if (trav == NULL)
        return;
    inorder(trav->lchild);
    cout<<trav->age<<"("<<trav->c<<") ";
    inorder(trav->rchild);
}

node *search(struct node *root, int data)
{
    if (root == NULL)
    {
        cout << "age not found\n";
        return NULL;
    }
    if (root->age == data)
    {
        cout << "age found\n";
    }
    else
    {
        if (data > root->age)
        {
            return search(root->rchild, data);
        }
        else
        {
            return search(root->lchild, data);
        }
    }
    return root;
}

int main()
{
    int age;
    char c;
    while (1)
    {
        cin >> c;

        if (c == 'i')
        {
            cin >> age;
            struct node *temp = (struct node *)malloc(sizeof(struct node));
            temp->rchild = NULL;
            temp->lchild = NULL;
            temp->parent = NULL;
            temp->age = age;
            temp->c = 1;

            root = bst(root, temp);

            fixup(root, temp);
        }

        if (c == 's')
        {
            cin >> age;

            search(root, age);
        }

        if (c == 't')
        {
            cout<<"Inoder Traversal"<<"\n";
            inorder(root);
        }
    }
    return 0;
}
