/* Sara Pardeshi SE-A-56 */
#include<iostream>
using namespace std;
class graph{
	int ver,edge;
	int a[10][10];
	int visit[10];
	public:
		graph(int v,int e)
		{
			int i,j;
			ver=v;
			edge=e;
			for(i=0;i<v;i++)
			for(j=0;j<e;j++)
			{
				a[i][j]=0;
			}
			for(i=0;i<v;i++){
				visit[i]=0;
			}
		}
		void create(){
			cout<<"\n Enter Matrix: ";
			for(int i=0;i<ver;i++){
				for(int j=0;j<ver;j++){
					cin>>a[i][j];
				}
			}
		}
		void traverse(int node){
			visit[node]=1;
			int i;
			cout<<node+1<<" ";
			for(i=0;i<ver;i++){
				if(a[node][i] && !visit[i]){
					traverse(i);
				}
			}
		}
};
int main(){
	graph gh(4,4);
	cout<<"\n Creating the graph...\n";
	gh.create();
	cout<<"\n The DFS Traversal is: ";
	gh.traverse(0);
	return 0;	
}


