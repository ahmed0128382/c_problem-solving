#include "stdio.h"
#include "stdlib.h"
#include "math.h"
 struct node {
   int data;
   struct node *leftChild;
   struct node *rightChild;
};
struct node *root = NULL;
void insert(int data){
   struct node *tempNode = (struct node*) malloc(sizeof(struct node));
   struct node *current;
   struct node *parent;
   tempNode->data = data;
   tempNode->leftChild = NULL;
   tempNode->rightChild = NULL;

   //if tree is empty
   if(root == NULL) {
      root = tempNode;
   } else {
      current = root;
      parent = NULL;
      while(1) {
         parent = current;

         //go to left of the tree
         if(data < parent->data) {
            current = current->leftChild;

            //insert to the left
            if(current == NULL) {
               parent->leftChild = tempNode;
               return;
            }
         }//go to right of the tree
         else {
            current = current->rightChild;

            //insert to the right
            if(current == NULL) {
               parent->rightChild = tempNode;
               return;
            }
         }
      }
   }
}
void inorder_traversal(struct node* root){
   if(root != NULL) {
      inorder_traversal(root->leftChild);
      printf("%d ",root->data);
      inorder_traversal(root->rightChild);
   }
}
int maxDepth(struct node* root){
    if(root == NULL) return 0;
    return fmax(maxDepth(root->leftChild), maxDepth(root->rightChild)) + 1;

}
char isBalanced(struct node* root){
    if(root == NULL){
        return 1;
    }
    int lefth = maxDepth(root->leftChild);
    int righth = maxDepth(root->rightChild);
    if(abs(lefth - righth) <= 1 && isBalanced(root->leftChild) && isBalanced(root->rightChild)){
        return 1;
    } 
    return 0;
}

int main()
{
	int i;
    int array[7] = { 1,10,13,11,15,22 };
    for(i = 0; i < 7; i++)
       insert(array[i]);
    printf("\nInorder traversal: ");
    inorder_traversal(root);
	int x=isBalanced(root);
	if (x)
	{
		printf("balanced\n");
		printf("%d\n",root->data);
	}	
	else
		printf("unbalanced\n");
    return 0;
}