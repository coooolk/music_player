#include<iostream>
using namespace std;

class Student
{
	string name;
	long int telno;
	
	public:
		Student()
		{
			name=" ";
			telno=0;
		}
		
		void getdata()
		{
			cout<<"Enter name of the student"<<endl;
			cin>>name;
			
			cout<<"Enter telephone number"<<endl;
			cin>>telno;
		}
		
		void display()
		{
			cout<<"Name: "<<name<<"\nTelephone no.: "<<telno<<endl;			
		}
		
		long int return_telno()
		{
			return telno;
		}
		
		bool operator ==(int a)
		{
			if(this->telno==a)
			return true;
			else
			return false;
		}
		
};

void linear_probing(Student S[],Student hashtable[],long int tel[],int n)
{
	int index;
	for(int i=0;i<n;i++)
	{
		index=tel[i]%10;
		if(hashtable[index]==0)
		{
			hashtable[index]=S[i];
		}
		else
		{
			for(int j=index;j<10;j++)
			{
				if(hashtable[index]==0)
				{
					hashtable[index]=S[i];
					break;
				}	
				else
				{
					index=index+1;
					if(index>9)
					{
						for (int k=0;k<10;k++)
						{
							if(hashtable[k]==0)
							{
								hashtable[k]=S[i];
								break;
							}
						}
					}
				}
			}	
		}
	}
	cout<<"*******************************************"<<endl;
	for(int i=0;i<10;i++)
	{
		hashtable[i].display();
	}
}

void quadratic_probing(Student S[],Student hashtable[],long int tel[],int n)
{
	int index;
	for(int i=0;i<n;i++)
	{
		index=tel[i]%10;
		if(hashtable[index]==0)
		{
			hashtable[index]=S[i];
		}
		else{
			for(long int j=0;j<10;j++)
			{
				if(hashtable[index]==0)
				{
					hashtable[index]=S[i];
					break;
				}
				else{
					index=(tel[i]+(j*j))%10;
				}	
			}	
		}
	}
	cout<<"*******************************************"<<endl;
	for(int i=0;i<10;i++)
	{
		hashtable[i].display();
	}
}

void search(Student hashtable[],long int key)
{
	int index=key%10;
	int n=0;
	bool flag=false;
	for(int i=0;i<10;i++)
	{
		n+=1;
		if(hashtable[index].return_telno()==key)
		{
			flag=true;
			break;	
		}
		else{
			index=index+1;
			if(index==10)
			index=0;
		}
	}
	if(flag==true)
	{
		cout<<"Record found at index: "<<index<<endl;
		cout<<"The record is: "<<endl;
		hashtable[index].display();
		cout<<n;
	}
}

void quad_search(Student hashtable[],long int key,long int tel[])
{
	int index=key%10;
	int n=0;
	bool flag=false;
	if(hashtable[index].return_telno()==key)
	{
		flag=true;
		n+=1;	
	}
	else{
		for(int i=0;i<10;i++)
		{
			index=(tel[index]+(i*i))%10;
			n+=1;
			if(hashtable[index].return_telno()==key)
			{
				flag=true;
				break;
			}
		}	
	}
	if(flag==true)
	{
		cout<<"Record found at index: "<<index<<endl;
		cout<<"Number of comparisons: "<<n<<endl;
		cout<<"The record is: "<<endl;
		hashtable[index].display();
	}
}

int main()
{
	int n,op;
	Student S[10];
	Student hashtable[10];
	long int tel[10];
	
	cout<<"Enter the number of students"<<endl;
	cin>>n;
	
	for(int i=0;i<n;i++)
	{
		S[i].getdata();
	}
	
	for(int i=0;i<n;i++)
	{
		tel[i]=S[i].return_telno();
	}
	
	do{
		cout<<"Enter \n1.Linear Probing \n2.Quadratic probing \n3.Search a record \n4.Exit"<<endl;
		cin>>op;
		if(op==1)
		linear_probing(S,hashtable,tel,n);
		else if(op==2)
		quadratic_probing(S,hashtable,tel,n);
		else if(op==3)
		{
			long int key;
			cout<<"Enter telephone number to be searched"<<endl;
			cin>>key;
			search(hashtable,key);
		}
		else if(op==4)
		{
			cout<<"Exit"<<endl;
			break;
		}
		else
		cout<<"Wrong choice"<<endl;	
	}while(op!=3);
}