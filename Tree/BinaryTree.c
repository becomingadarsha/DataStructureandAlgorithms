/*

	@About
		This program creates a simple Binary tree. 
		
	@Simple
	There is a basic Binary tree 
	
	      (60)					<====== This line is tree root
             /    \
            /      \
        (50)        (80)			<====== This are tree's branchs
        /   \       /   \
      (40) (55)   (75)  (90)			
      / \   /\    /\	  /\
    (0)(0) /  \	 (0)(0) (0)(0)		
         (52)(57) 					<====== This are tree's leaves
	      
		
		
*/

#include <stdio.h>
#include <stdlib.h>

/*
 * This structure represents a single node in a BST.
 */
struct Tree
{
    int info;

    struct Tree *left;
    struct Tree *right;
};

typedef struct Tree Tree;

Tree *createNode(Tree *root, int item)
{
    if (root == NULL)
    {
        root = (Tree *)malloc(sizeof(Tree));

        root->info = item;
        root->left = root->right = NULL;
        return (root);
    }

    else if (root->info > item)
    {
        root->left = createNode(root->left, item);
        return root;
    }

    else
    {
        root->right = createNode(root->right, item);
        return root;
    }
}

void PreorderTraversal(Tree *root)
{

    if (root != NULL)
    {
        printf("%d\t", root->info);
        PreorderTraversal(root->left);
        PreorderTraversal(root->right);
    }

    return;
}

void InorderTraversal(Tree *root)
{
    if (root != NULL)
    {
        InorderTraversal(root->left);
        printf("%d\t", root->info);
        InorderTraversal(root->right);
    }
    return;
}

void PostorderTraversal(Tree *root)
{

    if (root != NULL)
    {
        PostorderTraversal(root->left);
        PostorderTraversal(root->right);
        printf("%d\t", root->info);
    }

    return;
}

/*

Delete 10 in below tree
       10
     /    \         
    20     30
Output :    
       30
     /             
    20     


Delete 20 in below tree
       10
     /    \         
    20     30
            \
            40
Output :    
       10
     /   \             
    40    30  


*/

Tree *Delete(Tree *node, int data)
{
    Tree *p1, *p2;
    if (node == NULL)
    {
        printf("Element Not Found");
        return node;
    }

    else if (data < node->info)
    {
        node->left = Delete(node->left, data);
        return node;
    }

    else if (data > node->info)
    {
        node->right = Delete(node->right, data);
        return node;
    }

    else
    {

        if (node->info == data)
        {
            if (node->right == node->left)
            {
                /* LEAF NODE */
                free(node);
                return NULL;
            }

            else if (node->left == NULL)
            { //right subtree
                p1 = node->right;
                free(node);
                return p1;
            }

            else if (node->right == NULL) //left subtree
            {
                p1 = node->left;
                free(node);
                return p1;
            }

            else
            {
                p1 = node->right;
                p2 = node->left;
                if (node->left != NULL)
                {
                    p1 = p1->right;
                }
                p1->left = node->left;
                free(node);
                return p2;
            }
        }
    }
    return node;
}

Tree *search(Tree *root)
{
    int key, i;

    Tree *ptr;
    ptr = root;

    printf("Enter element to be searched : ");
    scanf("%d", &key);

    while (ptr)
    {
        if (key > ptr->info)
        {
            ptr = ptr->right;
        }

        else if (key < ptr->info)
        {
            ptr = ptr->left;
        }

        else
        {
            break;
        }
    }

    if (ptr)
    {
        printf("Element %d is found which is %d\n", key, ptr->info);
    }

    else
    {
        printf("\nElement doesn't exits\n");
    }
}

int TreeDeep(Tree *root)
{
    int deep = 0;
    if (root != NULL)
    {
        int leftdeep = TreeDeep(root->left);
        int rightdeep = TreeDeep(root->right);
        deep = leftdeep >= rightdeep ? leftdeep + 1 : rightdeep + 1;
    }

    return deep;
}

int main(int argc, char const *argv[])
{
    struct Tree *root;

    int ch, item, item_no, depth;

    root = NULL;

    printf("1. Enter in Binary Tree \n");
    printf("2. Delete Binary Tree \n");
    printf("3. Inorder Traversal in Binary Tree \n");
    printf("4. Postorder Traversal in Binary Tree \n");
    printf("5. Preorder Traversal in Binary Tree \n");
    printf("6. Search and Replace \n");
    printf("7. Depth of Tree \n");
    printf("8. Exit \n");

    while (1)
    {
        printf("\nEnter your choice : ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("\nEnter new element : ");
            scanf("%d", &item);
            root = createNode(root, item);
            printf("\nRoot item : %d", root->info);
            printf("\nInorder traversal of binary tree is : ");
            InorderTraversal(root);
            break;

        case 2:
            printf("Enter item to be deleted : ");
            scanf("%d", &item_no);
            root = Delete(root, item);
            printf("\nDeleted item is %d", root->info);
            printf("\nInorder traversal of binary tree is :");
            InorderTraversal(root);
            break;

        case 3:
            printf("\nInorder traversal of binary tree is : \n");
            InorderTraversal(root);
            break;

        case 4:
            printf("\nPostorder traversal of binary tree is : \n");
            PostorderTraversal(root);
            break;

        case 5:
            printf("\nPreorder traversal of binary tree is : \n");
            PreorderTraversal(root);
            break;

        case 6:
            printf("\nSearch in binary tree : \n");
            root = search(root);
            break;
        case 7:
            depth = TreeDeep(root);
            printf("Depth of binary tree is : %d\n", depth);
            break;

        case 8:
            exit(1);

        default:
            break;
        }
    }

    return 0;
}
