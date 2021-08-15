/* Sara Pardeshi SE-A-56 */
#include<iostream>
using namespace std;
struct node{
	int data;
	node *L;
	node *R;
};
node *root,*temp;
int count,key;
class BST{
	public:
	void create();
	void insert(node*,node*);
	void disin(node*);
	void dispre(node*);
	void dispost(node*);
	void search(node*,int);
	int height(node*);
	void mirror(node*);
	void min(node*);
BST(){
	root=NULL;
	count=0;
}
};
void BST::create()
{
	char ans;
	do{
	temp=new node;
	cout<<"\nEnter the data: "; 
	cin>>temp->data;
	temp->L=NULL;
	temp->R=NULL;
	if(root==NULL){
		root=temp;
	}
	else
		insert(root,temp);
		cout<<"\nDo you want to insert more value(y/n): "; 
		cin>>ans;
		count++;
		cout<<endl;
}
while(ans=='y');
	cout<<"\nThe total number of nodes are: "<<count; 
} 

void BST :: insert(node *root,node* temp) { 
	if(temp->data>root->data){
		if(root->R==NULL){
			root->R=temp;
		}
	else
		insert(root->R,temp);
	}
	else{
		if(root->L==NULL){
		root->L=temp;
	}
	else
		insert(root->L,temp);
	}
}

void BST::disin(node *root){
	if(root!=NULL){
		disin(root->L);
		cout<<root->data<<"\t"; 
		disin(root->R);
		count++;
	}
}
void BST::dispre(node *root){
	if(root!=NULL){
		cout<<root->data<<"\t"; 
		dispre(root->L);
		dispre(root->R);
	}
}
void BST::dispost(node *root){
	if(root!=NULL){
		dispost(root->L);
		dispost(root->R);
		cout<<root->data<<"\t";
	}
}

void BST::search(node * root,int key){
	int flag=0;
	cout<<"\n\nEnter your key: ";
	cin>>key;
	temp=root;
	while(temp!=NULL){
		if(key==temp->data){
			cout<<"\n\nKey founded!";
			flag=1;
			break;
		} 
	node *parent=temp;
	if(key>parent->data){
		temp=temp->R;
	}
	else{
		temp=temp->L;
	}
		if(flag==0){
			cout<<"\n\nKey not found!";
		} 
	}
}
	
int BST::height(node *root) { 
	int hl,hr; 
	if(root==NULL) { 
		return 0; 
	} 
	else if(root->L==NULL && root->R==NULL){
		return 0;
	}
	cout<<endl; 
	hr=height(root->R);
	hl=height(root->L);
	if(hr>hl){
		return(1+hr);
	}
	else{
		return(1+hl);
	}
}

void BST::min(node *root){
	temp=root;
	cout<<endl; 
	while(temp->L!=NULL){
		temp=temp->L;
	}
	cout<<root->data;
}

void BST::mirror(node *root){
	temp=root;
	if(root!=NULL){
		mirror(root->L);
		mirror(root->R);
		temp=root->L;
		root->L=root->R;
		root->R=temp;
	}
}

int main(){
	BST t;
	int ch;
	char ans;
	do{
		cout<<"\n ----- Main Menu ----- \t\n 1.Insert new node \n 2.Number of nodes in longest path \n 3.Minimum \n 4.Mirror \n 5.Search \n 6.Inorder \n 7.Preorder \n 8.Postorder \n\nEnter your choice: "; 
		cin>>ch;
	switch(ch)
	{
		case 1:
		t.create();
		break;
		case 2:
		cout<<"\n\nNumber of nodes in longest path: "<<(1+(t.height(root)));
		break;
		case 3:
		cout<<"\n\nThe mininum element is: ";
		t.min(root);
		break;
		case 4:
		t.mirror(root);
		cout<<"\n\nThe mirror of tree is: ";
		t.disin(root);
		break;
		case 5:
		t.search(root,key);
		break;
		case 6:
		cout<<"\n ------ Inorder ----- "<<endl;
		t.disin(root);
		break;
		case 7:
		cout<<"\n ----- Preorder ----- "<<endl;
		t.dispre(root);
		break;
		case 8:
		cout<<"\n ----- Postorder ----- "<<endl;
		t.dispost(root);
		break;
	}
cout<<"\n\nDo you want to go back to Main Menu?(y/n) :";
cin>>ans;
}
while(ans=='y');
return 0;
} 

