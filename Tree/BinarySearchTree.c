#include <stdio.h>
#include <stdlib.h>


struct BST
{
    int data;
    // struct BST *root;
    struct BST *lchild;
    struct BST *rchild;
};

typedef struct BST Node;

Node *get_node() //get new node
{
    Node *temp;
    temp = (Node *) malloc(sizeof(Node));
    temp->lchild = NULL;
    temp->rchild = NULL;
    return temp;
}

//This function is for creating a binary search tree

void Insert(Node *root, Node *new_node)
{
    if (new_node->data < root->data)
    {

        if (root->lchild == NULL)
            root->lchild = new_node;

        else
        {
            Insert(root->lchild, new_node);
        }
    }

    if (new_node->data > root->data)
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

Node *Search(Node *root, int key, Node **parent)
{
    Node *temp;
    temp = root;

    while (temp != NULL)
    {
        if (temp->data == key)
        {
            printf("\n The %d Element is present\n", temp->data);
            return temp;
        }

        *parent = temp;

        if (temp->data > key)
            temp = temp->lchild;

        else
        {
            temp = temp->rchild;
        }
    }

    return NULL;
}

void Inorder(Node *temp)
{

    if (temp != NULL)
    {
        Inorder(temp->lchild);
        printf("%d ", temp->data);
        Inorder(temp->rchild);
    }
}

void Preorder(Node *temp)
{

    if (temp != NULL)
    {
        printf("%d ", temp->data);
        Preorder(temp->lchild);
        Preorder(temp->rchild);
    }
}

void Postorder(Node *temp)
{

    if (temp != NULL)
    {
        Postorder(temp->lchild);
        Postorder(temp->rchild);
        printf("%d ", temp->data);
    }
}

Node *FindMin(Node *root)
{
    while (root->lchild != NULL)
        root = root->lchild;

    return root;
}

Node *deleteNode(Node *root, int data)
{

    if (root == NULL)
    { //if tree is empty
        return root;
    }

    else if (data < root->data) //
    {
        root->lchild = deleteNode(root->lchild, data);
    }

    else if (data > root->data)
    {
        root->rchild = deleteNode(root->rchild, data);
    }

    else
    {
        // case 1. no child
        if ((root->lchild == NULL) && (root->rchild == NULL))
        {
            free(root);
            root = NULL;
            return root;
        }

        //case 2. one child

        else if (root->lchild == NULL)
        {
            Node *temp = root;
            root = root->rchild;
            free(temp);
            return root;
        }

        else if (root->rchild == NULL)
        {
            Node *temp = root;
            root = root->lchild;
            free(temp);
            return root;
        }

        //case 3: two child

        else
        {
            Node *temp;
            temp = FindMin(root->rchild); //Function that finds the min value of right subtree
            root->data = temp->data;
            root->rchild = deleteNode(root->rchild, temp->data);
            return root;
        }
    }
}

int main(int argc, char const *argv[])
{
    int choice;
    int key, data;
    int x;
    Node *new_node, *temp, *root, *parent;
    printf("\n1. Create Binary Search Tree\n");

    printf("\n2. Search Item in Tree\n");

    printf("\n3. Recursive Traversal\n");

    printf("\n4. Delete Node in BST\n");

    printf("\n5. Exit\n");

    while (1)
    {
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            new_node = get_node();

            printf("Enter item to be inserted : ");
            scanf("%d", &new_node->data);

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
            printf("\nEnter element to be searched : ");
            scanf("%d", &key);

            temp = Search(root, key, &parent);
            printf("\nParent of node %d is %d\n", temp->data, parent->data);
            break;

        case 3:
            if (root == NULL)
            {
                printf("\nTree is not created!\n");
            }

            else
            {
                printf("\nInorder Traversal :\n");
                Inorder(root);

                printf("\nPreorder Traversal :\n");
                Preorder(root);

                printf("\nPostorder Traversal :\n");
                Postorder(root);
            }

            break;

        case 4:
            printf("Enter item to be deleted :");
            scanf("%d", &data);
            deleteNode(root, data);
            //printf("THe deleted item is %d",x );
            break;

        case 5:
            exit(1);

        default:
            break;
        }
    }

    return 0;
}
