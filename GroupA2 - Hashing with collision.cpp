/* Sara Pardeshi SE-A-56 */
#include <iostream>
using namespace std;
class HashFunct
{
    typedef struct hash
    {
        int key;
        int value;
    }hash;
    hash h[10];
    public:
        HashFunct()
        {
            int i;
            for( i= 0; i < 10; i++)
            {
                h[i].key = -1;
                h[i].value = -1;
            }
        }
        void insert()
        {
            char choice;
            int k, v, hash_index, flag = 0, count = 0, i;
            do
            {
                if(count >= 10)
                {
                    cout << "\n Hash Table FULL!" << endl;
                    break;
                }
                cout << "\nEnter Key: ";
                cin >> k;
                cout << "\nEnter Value: ";
                cin >> v;
                hash_index = k % 10;
                if(h[hash_index].key == -1)
                {
                    h[hash_index].key = k;
                    h[hash_index].value = v;
                }
                else
                {
                    for(i = hash_index + 1; i < 10; i++)
                    {
                        if(h[i].key == -1)
                        {
                            h[i].key = k;
                            h[i].value = v;
                            flag = 1;
                            break;
                        }
                    }
                    for(i = 0; i < hash_index && flag == 0; i++)
                    {
                        if(h[i].key == -1)
                        {
                            h[i].key = k;
                            h[i].value = v;
                            break;
                        }
                    }
                }
                flag = 0;
                count++;
                cout << "\nDo you want to insert another key?(y/n) ";
                cin >> choice;
            }while(choice == 'y');
        }
        void display()
        {
            int i;
            cout << "\n\t\tKey \t\t Value" << endl;
            for(i = 0; i < 10; i++)
            {
            	cout<<"\n\th["<<i<<"]\t"<<h[i].key<<"\t\t"<<h[i].value;
            }
        }
        void search()
        {
        	int i;
 			cout<<"\n Enter key: ";
 			cin>>i;
 			for(i=0;i<10;i++){
  			cout << h[i].key <<"\t"<< h[i].value << endl;
   		}
   		
		}
		void Delete()
		{
			int k;
			if(k==-1){
				cout<<"\n Key not found!";
			}
			else{
				cout<<"\n Enter key to be deleted: ";
				cin>>k;
				cout<<"\n Key is deleted!";
			}
			
		}
};
int main()
{
    int choice;
    HashFunct hf;
    do
    {
        cout << "\n \n------- MENU -------" << endl;
        cout << "\n1.Insert Key and Value \n2.Display \n3.Search \n4.Delete \n5.Exit \nEnter Choice: ";
        cin >> choice;
        switch(choice)
        { 
            case 1:
                hf.insert();
                break;
            
            case 2:
                hf.display();
                break;

            case 3:
                hf.search();
                break;
                
			case 4:
                hf.Delete();
            	break;
            	
            case 5:
                cout << "\n Thank you"<< endl;
                break;
             
        }
    }while(choice != 4);
    return 0;
}
