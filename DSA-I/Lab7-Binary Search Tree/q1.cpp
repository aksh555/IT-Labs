// BST-operations
#include<iostream>
#include<stdlib.h>
using namespace std;

struct tree{
	int val;
	struct tree* left;
	struct tree* right;
};
struct node
{
	int key;
	struct node* prev;
	struct node* next;
};
struct node* head;

struct node* CreateNode(int x)
{
	struct node* NewNode = new node;
	NewNode->key = x;
	NewNode->prev = NULL;
	NewNode->next = NULL;
  return NewNode;
}

struct tree* createnode(int val)
{
	struct tree* nn = (struct tree*)malloc(sizeof(struct tree));
	nn->left=NULL;
	nn->right=NULL;
	nn->val=val;
	return nn;
}
struct tree* insert(struct tree* root,int x)
{
	if(root == NULL) return createnode(x);
	if(x<root->val) root->left = insert(root->left,x);
	if(x>root->val) root->right =insert(root->right,x);
	return root;
}

struct tree* search(struct tree* root, int x)
{
	if(root == NULL || root->val==x) {return root;}
	if(x<root->val) return search(root->left,x);
	else if(x>root->val) return search(root->right,x);
}

struct tree* min(struct tree* root)
{
	while(root!=NULL && root->left !=NULL)

		root=root->left;
	return root;
}

struct tree* max(struct tree* root)
{
	while(root!=NULL && root->right !=NULL)
		root=root->right;
	return root;
}

struct tree* pred(struct tree* root,int x)
{
	struct tree* roo=NULL;

	roo=search(root,x);
	if(roo==NULL) return roo;
	if(roo->left !=NULL)
		return max(roo->left);
	else{
		struct tree* temp=NULL;
		while(root!=NULL)
		{
			if(roo->val>root->val)
			{
				temp=root;
				root=root->right;
			}
			else if(roo->val<root->val)
				root=root->left;
			else break;
		}
		return temp;

}
}

struct tree* succ(struct tree* root,int x)
{
	struct tree* roo=NULL;
	roo=search(root,x);
	if(roo==NULL) return roo;
	if(roo->right !=NULL)
		return min(roo->right);
	else{
		struct tree* temp=NULL;
		while(root!=NULL)
		{
			if(roo->val<root->val)
			{

				temp=root;
				root=root->left;
			}
			else if(roo->val>root->val)
				root=root->right;
			else break;
		}
		return temp;

}
}

struct tree* del(struct tree* root,int x)
{


	if(root==NULL) return root;
	if(x>root->val) root->right=del(root->right,x);
	else if(x<root->val) root->left=del(root->left,x);
	else{
	if(root->left ==NULL && root->right==NULL)
	{
		free(root);
		root=NULL;
	}
	else if (root->left == NULL)
	{
		struct tree* temp = root;
		root=root->right;
		free(temp);
	}
	else if(root->right == NULL)
	{
		struct tree* temp = root;
		root=root->left;
		free(temp);
	}
	else
	{
		struct tree* temp = min(root->right);
		root->val=temp->val;
		root->right=del(root->right,temp->val);

	}
	return root;
}
}

void inorder(struct tree* root)
{
	if(root==NULL) return;
	inorder(root->left);
	cout<<root->val<<" ";
	inorder(root->right);

}
void ConvertToLL(int value)
{
	if(head == NULL)
   {
      head = CreateNode(value);
		 head->next = head;
	}
	else
   {
	struct node* curr = head;
	struct node* temp = CreateNode(value);
	while(curr->next != head)
	{
	   curr = curr->next;
	}
	curr->next = temp;
	temp->prev = curr;
	temp->next = head;
   }
}

void pri()
{
	cout<<"mm";
	struct node* c = head;
	while(c->next!=head)
	{
		cout<<c->key<<" ";
		c=c->next;
	}
}

void inorder1(struct tree* root)
{
	if(root == NULL)
		return;
	inorder1(root->left);
	ConvertToLL(root->val);
	inorder1(root->right);
}




int main()
{
	struct tree* root=NULL;
	int n,x,c;
	char ch='y';
	char cho='y';
	while(cho=='y'){
	cout<<"Enter choice: 1 to build tree, 2 to insert values, 3 to search, 4 to delete, 5 to find min, 6 to find max,7 to find successor, 8 to find predecessor, 9 for inorder traverse, 10 for convert "<<endl;
	cin>>c;

	switch(c)
	{
		case 1:{while(true)
			{
				cout<<"Enter number ";
				cin>>x;
				root = insert(root,x);
				cout<<"You want to add more?(y) ";
				cin>>ch;
				if(ch!='y') break;
			} break;}
		case 2:{cout<<"Enter number to be inserted";
				cin>>x;
				root = insert(root,x);
				break;

		}
		case 3:{cout<<"Enter search number ";
				cin>>x; struct tree* t=search(root,x); if(t) cout<<t->val<<" found"; else cout<<"Not found"; cout<<endl; break;}

		case 4:{
				cout<<"Enter number to delete ";
				cin>>x; root=del(root,x);
			break;

		}
		case 5:{
			struct tree* t=min(root); if(t) cout<<"Min: "<<t->val; else cout<<"None"; cout<<endl;  break;}



		case 6:{
			struct tree* t=max(root); if(t) cout<<"Max: "<<t->val; else cout<<"None"; cout<<endl;  break;}



		case 7:{
			cout<<"Enter number to find succeessor ";
				cin>>x;
			struct tree* t=succ(root,x); if(t) cout<<"successor: "<<t->val; else cout<<"None"; cout<<endl;  break;}

		case 8:{
			cout<<"Enter number to find predessor ";
				cin>>x;
			struct tree* t=pred(root,x); if(t) cout<<"predecessor: "<<t->val; else cout<<"None"; cout<<endl;  break;}

		case 9:{inorder(root); break;}
		case 10:{inorder1(root); pri(); break;}


	}
	cout<<"u want to continue? ";
	cin>>cho;
}
}