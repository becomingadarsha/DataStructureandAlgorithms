#include <stdio.h>
#include <stdlib.h>

struct BST
{
    int info;
    // struct BST *root;
    struct BST *lchild;
    struct BST *rchild;
};

typedef struct BST Node;

Node *get_node() //get new node
{
    Node *temp;
    temp = (Node *)malloc(sizeof(Node));
    temp->lchild = NULL;
    temp->rchild = NULL;
    return temp;
}

//This function is for creating a binary search tree

void Insert(Node *root, Node *new_node)
{
    if (new_node->info < root->info)
    {

        if (root->lchild == NULL)
            root->lchild = new_node;

        else
        {
            Insert(root->lchild, new_node);
        }
    }

    if (new_node->info > root->info)
    {
        if (root->rchild == NULL)
        {
            root->rchild = new_node;
        }

        else
        {
            Insert(root->rchild, new_node);
        }
    }
}

int main(int argc, char const *argv[])
{
    int choice;
    int key;
    Node *new_node, *temp, *root, *parent;
    printf("\n1. Create Binary Search Tree\n");

    printf("\n2. Search Item in Tree\n");

    printf("\n3. Recursive Traversal\n");

    printf("\n4. Exit\n");

    while (1)
    {
        printf("Enter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            new_node = get_node();

            printf("Enter item to be inserted : ");
            scanf("%d", &new_node->info);

            if (root == NULL)
            {
                root = new_node;
            }

            else
            {
                Insert(root, new_node);
            }
            break;

        case 2:
            printf("Enter element to be searched : ");
            scanf("%d", &key);

            temp = Search(root, key, &parent);
            printf("Parent of node %d is %d", temp -> data, parent -> data);
            break;

        case 3:
            /* code */
            break;

        case 4:
            exit(1);

        default:
            break;
        }
    }

    return 0;
}
