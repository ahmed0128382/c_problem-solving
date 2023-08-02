#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "limits.h"
/********************variables*******************/
int max=INT_MIN;
int res=0;
/***********************************************/
 struct node {
   int data;
   struct node *leftChild;
   struct node *rightChild;
};

/*****************the root of the tree************************/
struct node *root = NULL;
/*******************************/

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
int maxVal(struct node* root , int maxValue){
    if(root == NULL) return 0;
	
    return ((root->data >= maxValue) + maxVal(root->leftChild , fmax(root->data,maxValue)) + maxVal(root->rightChild , fmax(root->data,maxValue)));

}
int goodNodes(struct node* root){
	if (!root) return 0;

	return maxVal(root,INT_MIN);;
	
}

int main()
{
	int i;
    int array[7] = {1};
    for(i = 0; i < 1; i++)
       insert(array[i]);
    int x=goodNodes(root);
	printf("\ngood no count is: %d\n",x);
    //printf("\nInorder traversal: ");
    //inorder_traversal(root);
	//int x=isBalanced(root);
	//if (x)
	//{
	//	printf("balanced\n");
	//	printf("%d\n",root->leftChild->leftChild->data);
	//}	
	//else
	//	{
	//	printf("unbalanced\n");
	//	printf("%d\n",root->leftChild->rightChild->data);
	//}	
    return 0;
}