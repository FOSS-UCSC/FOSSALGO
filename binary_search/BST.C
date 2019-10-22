#include <stdio.h>
#include <stdlib.h>
 
#include "bst.h"
 
#define SIZE 9
 
int main()
{
    node* root = NULL;
    comparer int_comp = compare;
    callback f = display;
 
    /* insert data into the tree */
    int a[SIZE] = {8,3,10,1,6,14,4,7,13};
    int i;
    printf("--- C Binary Search Tree ---- \n\n");
    printf("Insert: ");
    for(i = 0; i < SIZE; i++)
    {
        printf("%d ",a[i]);
        root = insert_node(root,int_comp,a[i]);
    }
    printf(" into the tree.\n\n");
 
    /* display the tree */
    display_tree(root);
 
    /* remove element */
    int r;
    do
    {
        printf("Enter data to remove, (-1 to exit):");
        scanf("%d",&r);
        if(r == -1)
            break;
        root = delete_node(root,r,int_comp);
        /* display the tree */
        if(root != NULL)
            display_tree(root);
        else
            break;
    }
    while(root != NULL);
 
    /* search for a node */
    int key = 0;
    node *s;
    while(key != -1)
    {
        printf("Enter data to search (-1 to exit):");
        scanf("%d",&key);
 
        s = search(root,key,int_comp);
        if(s != NULL)
        {
            printf("Found it %d",s->data);
            if(s->left != NULL)
                printf("(L: %d)",s->left->data);
            if(s->right != NULL)
                printf("(R: %d)",s->right->data);
            printf("\n");
        }
        else
        {
            printf("node %d not found\n",key);
        }
    }
 
    /* remove the whole tree */
    dispose(root);
    return 0;
}
