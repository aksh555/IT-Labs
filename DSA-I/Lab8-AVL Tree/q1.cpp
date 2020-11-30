//avl

#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;

struct tree{
	int key;
	struct tree* left;
	struct tree* right;
	int h;

};

struct tree* create(int x)
{
	struct tree* nn = (struct tree*)malloc(sizeof(struct tree));
	nn->left=NULL;
	nn->right=NULL;
	nn->key=x;
	nn->h=1;
	return nn;
}
int geth(struct tree* n)
{
	if(n) return n->h;
	return 0;
}

struct tree* rr(struct tree* n)
{
	struct tree* t = n->left;
	struct tree* u = t->right;
	t->right = n;
	n->left = u;

	t->h=max(geth(t->left),geth(t->right))+1;
	n->h=max(geth(n->left),geth(n->right))+1;
	return t;
}

struct tree* ll(struct tree* n)
{
	struct tree* t = n->right;
	struct tree* u = t->left;
	t->left = n;
	n->right = u;

	t->h=max(geth(t->left),geth(t->right))+1;
	n->h=max(geth(n->left),geth(n->right))+1;
	return t;

}

struct tree* minkey(struct tree* root)
{
	while(root!=NULL && root->left !=NULL)

		root=root->left;
	return root;
}

int getbf(struct tree* n)
{
	return geth(n->left)-geth(n->right);
}

struct tree* insert(struct tree* root,int x)
{
	if(root==NULL) return create(x);
	if(x<root->key) root->left=insert(root->left,x);
	else if(x>root->key) root->right=insert(root->right,x);
	else return root;
	//cout<<"h";
	root->h=max(geth(root->left),geth(root->right))+1;

	int b=getbf(root);
	//cout<<"bf"<<b;
	if(b>1 && x<(root->left->key)) return rr(root);
	if(b>1 && x>root->left->key) {root->left = ll(root->left); return rr(root);}
	if(b<-1 && x>root->right->key) return ll(root);
	if(b<-1 && x<root->right->key) {root->right=rr(root->right); return ll(root);}

	return root;

}

struct tree* del(struct tree* root, int x)
{
	if(root==NULL) return root;
	else if(x<root->key) root->left = del(root->left,x);
	else if(x>root->key) root->right = del(root->right,x);
	else
	{
		if( (root->left == NULL) || (root->right == NULL) )
        {
            struct tree *temp = root->left ? root->left : root->right;
            if (temp == NULL)
            {
                temp = root;
                root = NULL;
            }
            else
             *root = *temp;
            free(temp);
        }
        else
        {
            struct tree* temp = minkey(root->right);
            root->key = temp->key;
            root->right = del(root->right, temp->key);
        }
    }
    if (root == NULL)
      return root;
		   root->h = 1 + max(geth(root->left),
                           geth(root->right));
    int bf = getbf(root);
    if (bf > 1 && getbf(root->left) >= 0)
        return rr(root);

    if (bf > 1 && getbf(root->left) < 0)
    {
        root->left =  ll(root->left);
        return rr(root);
    }

    if (bf < -1 && getbf(root->right) <= 0)
        return ll(root);

    if (bf < -1 && getbf(root->right) > 0)
    {
        root->right = rr(root->right);
        return ll(root);
    }

    return root;
}

void inorder(struct tree* root)
{
	if(root!=NULL)
	{
		cout<<root->key<<" ";
		inorder(root->left);
		inorder(root->right);
	}
}

struct tree* search(struct tree* root, int x)
{
	if(root == NULL || root->key==x) {return root;}
	if(x<root->key) return search(root->left,x);
	else if(x>root->key) return search(root->right,x);
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
			if(roo->key>root->key)
			{
				temp=root;
				root=root->right;
			}
			else if(roo->key<root->key)
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
		return minkey(roo->right);
	else{
		struct tree* temp=NULL;
		while(root!=NULL)
		{
			if(roo->key<root->key)
			{

				temp=root;
				root=root->left;
			}
			else if(roo->key>root->key)
				root=root->right;
			else break;
		}
		return temp;

}
}

int main()
{
	struct tree *root = NULL;
	int n,x,c;
	char ch='y';
	char cho='y';
	while(cho=='y'){
	cout<<"Enter choice: 1 to build tree, 2 to insert keyues, 3 to search, 4 to delete, 5 to find min, 6 to find max,7 to find successor, 8 to find predecessor, 9 for inorder traverse "<<endl;
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
				cin>>x; struct tree* t=search(root,x); if(t) cout<<t->key<<" found"; else cout<<"Not found"; cout<<endl; break;}

		case 4:{
				cout<<"Enter number to delete ";
				cin>>x; root=del(root,x);
			break;

		}
		case 5:{
			struct tree* t=minkey(root); if(t) cout<<"Min: "<<t->key; else cout<<"None"; cout<<endl;  break;}

		case 6:{
			struct tree* t=max(root); if(t) cout<<"Max: "<<t->key; else cout<<"None"; cout<<endl;  break;}

		case 7:{
			cout<<"Enter number to find succeessor ";
				cin>>x;
			struct tree* t=succ(root,x); if(t) cout<<"successor: "<<t->key; else cout<<"None"; cout<<endl;  break;}

		case 8:{
			cout<<"Enter number to find predessor ";
				cin>>x;
			struct tree* t=pred(root,x); if(t) cout<<"predecessor: "<<t->key; else cout<<"None"; cout<<endl;  break;}

		case 9:{inorder(root); break;}


	}
	cout<<"u want to continue? ";
	cin>>cho;
}
}
