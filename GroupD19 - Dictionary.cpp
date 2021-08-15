/* Sara Pardeshi SE-A-56 */
#include<iostream>
#include<string>
using namespace std;
class Tree;
class avlnode
{
	string keyword;
	string meaning;
	avlnode *left,*right;
	int bf;
	public:
	avlnode(){
		keyword='\0';
		meaning='\0';
		left=right=NULL;
		bf=0;
	}
	avlnode(string k,string m){
		keyword=k;
		meaning=m;
		left=right=NULL;
		bf=0;
	}
friend class Tree;
};
class Tree
{
	avlnode *par,*loc;
	public:
	avlnode *root;
	Tree(){	
		root=NULL;
		par=loc=NULL;
	}
	void accept();
	void insert(string key,string mean);
	void LLrotation(avlnode*,avlnode*);
	void RRrotation(avlnode*,avlnode*);
	void ascend(avlnode *root);
	void descend(avlnode *);
};
void Tree::descend(avlnode *root){
	if(root){
		descend(root->right);
		cout<<root->keyword<<" "<<root->meaning<<endl;
		descend(root->left);
	}
}
void Tree::accept(){
	string key,mean;
	cout<<"Enter keyword: ";
	cin>>key;
	cout<<"Enter meaning: ";
	cin>>mean;
	insert(key,mean);
}

void Tree::LLrotation(avlnode *a,avlnode *b){	
	a->left=b->right;
	b->right=a;
	a->bf=b->bf=0;
}

void Tree::RRrotation(avlnode *a,avlnode *b){	
	a->right=b->left;
	b->left=a;
	a->bf=b->bf=0;
}

void Tree::insert(string key,string mean){
	if(!root){
		root=new avlnode(key,mean);
		cout<<"Key inserted! \n";
		return;
	}
	avlnode *a,*pa,*p,*pp;
		pa=NULL;
		p=a=root;
		pp=NULL;
		while(p){
			if(p->bf){
			a=p;
			pa=pp;
			}
			if(key<p->keyword){pp=p;p=p->left;
			}  
			else if(key>p->keyword){pp=p;p=p->right;
			} 
			else{
				cout<<"Already exist \n";
				return;
			}
		}
		avlnode *y=new avlnode(key,mean);		
		if(key<pp->keyword){
			pp->left=y;
		}
		else
			pp->right=y;
		cout<<"Key inserted! \n";
		int d;
		avlnode *b,*c;
		b=c=NULL;
		if(key>a->keyword){
			b=p=a->right;
			d=-1;
		}
		else{

			b=p=a->left;
			d=1;
		}
		while(p!=y){
			if(key>p->keyword){
				p->bf=-1;
				p=p->right;
			}
			else{
				p->bf=1;
				p=p->left;
			}		
		}
		if(!(a->bf)||!(a->bf+d)){
			a->bf+=d;
			return;
		}
		if(d==1){
			if(b->bf==1)
			{
				LLrotation(a,b);
			}
			else{						
				c=b->right;
				b->right=c->left;
				a->left=c->right;
				c->left=b;
				c->right=a;
				switch(c->bf){
					case 1:
					{
						a->bf=-1;
						b->bf=0;
						break;
					}
					case -1:
					{
						a->bf=0;
						b->bf=1;
						break;
					}
					case 0:
					{
						a->bf=0;
						b->bf=0;
						break;
					}		
				}
				c->bf=0;
				b=c;  				
			}
		}	
		if(d==-1){
			if(b->bf==-1)	{
				RRrotation(a,b);
			}
			else{
				c=b->left;		
				a->right=c->left;
				b->left=c->right;
				c->left=a;
				c->right=b;
				switch(c->bf){
					case 1:
					{
						a->bf=0;
						b->bf=-1;
						break;
					}
					case -1:
					{
						a->bf=1;
						b->bf=0;
						break;
					}
					case 0:
					{
						a->bf=0;
						b->bf=0;
						break;
					}		
				}
				c->bf=0;
				b=c;  				
			}
		}
		if(!pa)
			root=b;
		else if(a==pa->left)
			pa->left=b;
		else
			pa->right=b;
}
//void Tree::search(string key){
//	cout<<"ENTER SEARCH \n";
//	loc=NULL;
//	par=NULL;
//	if(root==NULL){
//		cout<<"Tree not created  "<<endl;
//		loc=NULL;
//		par=NULL;
//	}
//	avlnode *ptr;
//	ptr=root;
//	while(ptr!=NULL){
//		if(ptr->keyword==key){
//			loc=ptr;
//			break;                             
//		}
//		else if(key<ptr->keyword){
//			par=ptr;
//			ptr=ptr->left;
//		}
//		else{
//			par=ptr;                         
//			ptr=ptr->right;			
//		}
//	}	
//	if(loc==NULL){
//		cout<<"Not found "<<endl;
//	}	
//}
//
//void Tree::update(string oldkey,string newmean){
//	search(oldkey);
//	loc->meaning=newmean;
//	cout<<"UPDATE SUCCESSFUL \n";
//}
//
//void Tree::deletekey(string key){	
//}
void Tree::ascend(avlnode *root){
	if(root){
		ascend(root->left);
		cout<<root->keyword<<" "<<root->meaning<<endl;
		ascend(root->right);
	}
}

int main(){
	string k,m;
	Tree d;
	int ch;
	string key,mean;	
	do{
	cout<<"\n -----MENU----- \n1.Insert \n2.Display ascending \n3.Display descending \n4.Quit \nEnter your choice: ";
	cin>>ch;
	switch(ch){
		case 1:
		{
			d.accept();
			break;
		}
//		case 2:
//		{
//			cout<<"Enter key whose meaning to update \n";
//			cin>>key;
//			cout<<"Enter new meaning\n";
//			cin>>mean;
//			d.update(key,mean);
//			break;
//		}
//		case 3:
//			d.inorder(d.root);
//			break;
//		
		case 2:
			cout<<"\n Ascending order- \n";
			d.ascend(d.root);
			break;
		case 3:
			cout<<"\n Descending order- \n";
			d.descend(d.root);
			break;
		default:
			break;
	}	
	}while(ch!=4);	
return 0;
}





