#include <iostream>
#include <conio.h>

using namespace std;

class selectionSort{
	private:
		int *arr;
		int length;
	public:
		selectionSort(int arr[],int length){
			this->arr=arr;
			this->length=length;
		}
		void sort(){
			for(int i=0; i<length; i++)
    		{
		        int min=arr[i],posmin=i;
		        for(int j=i+1; j<length; j++)
		        {
		            if(arr[j]<min)	//Change to < to make ascending order
		            {
		                min=arr[j];
		                posmin=j;
		            }
		            
		        }
		        int temp=arr[i];
		        arr[i]=min;
		        arr[posmin]=temp;
	   		}
		}
		void display(){
			cout<<"Sorted array selection \n";
			for(int i=0;i<length;i++){
				cout<<arr[i]<<endl;
			}
		}
		
};

class bubbleSort{
	private:
		int *arr;
		int length,internal_length;
	public:
		bubbleSort(int arr[],int length){
			this->arr=arr;
			this->length=length;
			this->internal_length=length;
		}
		void sort(){
			for(int i=0; i<length; i++)	//Kitni bar kam karna hai
    		{
		        for(int j=0; j<internal_length-1; j++)  //Internal array mai kitni bar last mai rakhna hai
		        {
		            if(arr[j]>arr[j+1])
		            {
		            
		                //Interchanging values
		                int temp=arr[j];
		                arr[j]=arr[j+1];
		                arr[j+1]=temp;
		            }
		        }
		        internal_length--;
    		}
    		
		}
		void display(){
			cout<<"Sorted array bubble \n";
			for(int i=0;i<length;i++){
				cout<<arr[i]<<endl;
			}
		}
	
};

class mergeSort{
	private:
		int *arr;
		int start,end;
	
	public:
		mergeSort(int arr[],int length){
			this->arr=arr;
			this->end=length-1;
			this->start=0;
		}
	void sort(){
		Mergesort(arr,start,end);
	}
	void display(){
		cout<<"Elements merge:"<<endl;
	
		for(int x=0;x<=end;x++){
			cout<<arr[x]<<endl;
		}
	}
	void Mergesort(int arr[],int start,int end){
		if(start>=end){
			return;
		}
		//1.Divide
		int mid=(start+end)/2;
		
		//Now sort it
		Mergesort(arr,start,mid);
		Mergesort(arr,mid+1,end);
		
		merge(arr,start,end);
		
	}
	void merge(int arr[],int start,int end){
		int mid=(start+end)/2;
		
		int i=start;
		int j=mid+1;
		int k=start;
		
		int temp[end+1];
		
		while(i<=mid && j<=end){
			if(arr[i]<arr[j])
				temp[k++]=arr[i++];
			else
				temp[k++]=arr[j++];
		}
		
		while(i<=mid){
			temp[k++]=arr[i++];
			
		}
		
		while(j<=end){
			temp[k++]=arr[j++];
			
		}
		
		//Now copy all elements from temp to original array
            for(int x = start; x <=end; x++)
            {
            	arr[x]=temp[x];
            }
		
	}
	
};


int main(){
	/*int arr[]= {65,98,12,55,5,89,24};
    int length=7;
	*/
	char decision;
	int length,choice;
	cout<<"Enter number of elements you want to sort "<<endl;
	cin>>length;
	int arr[length];
	
	for(int i=0;i<length;i++){
		cout<<"Enter "<<i+1<<" element: ";
		cin>>arr[i];
	}
	
	cout<<"Which sort would you like to use \n1.Selection sort\n2.Bubble sort\n3.Merge sort"<<endl;
	cin>>choice;
	
	do{
		switch(choice){
		case 1:
			{
				selectionSort s(arr,length);
				s.sort();
				s.display(); 
				cout<<"Do you want to try again?"<<endl;
				cin>>decision;
				if(decision=='y' || decision=='Y'){
				cout<<"Which sort would you like to use \n1.Selection sort\n2.Bubble sort\n3.Merge sort"<<endl;
				cout<<"Enter your choice"<<endl;
				cin>>choice;
				}	
			}
			break;
		case 2:
			{
				bubbleSort b(arr,length);
				b.sort();
				b.display();
				cout<<"Do you want to try again?"<<endl;
				cin>>decision;
				if(decision=='y' || decision=='Y'){
				cout<<"Which sort would you like to use \n1.Selection sort\n2.Bubble sort\n3.Merge sort"<<endl;	
				cout<<"Enter your choice"<<endl;
				cin>>choice;
				}
			}
			break;
		case 3:
			{
				mergeSort m(arr,length);
				m.sort();
				m.display();
				cout<<"Do you want to try again?"<<endl;
				cin>>decision;
				if(decision=='y' || decision=='Y'){
				cout<<"Which sort would you like to use \n1.Selection sort\n2.Bubble sort\n3.Merge sort"<<endl;
				cout<<"Enter your choice"<<endl;
				cin>>choice;
				}		
			}
			break;
		default:
			cout<<"Wrong choice entered \nDo you want to try again?"<<endl;
			cin>>decision;
			if(decision=='y' || decision=='Y'){
				cout<<"Which sort would you like to use \n1.Selection sort\n2.Bubble sort\n3.Merge sort"<<endl;
				cout<<"Enter your choice"<<endl;
				cin>>choice;
			}
				
		}	
		
	}while(decision=='y' || decision=='Y');
	
	
	
	
	/*selectionSort s(arr,length);
	s.sort();
	s.display(); 
	*/
	/*bubbleSort b(arr,length);
	b.sort();
	b.display();
	*/
	
/*	mergeSort m(arr,length);
	m.sort();
	m.display();*/
	
	
	return 0;
}
