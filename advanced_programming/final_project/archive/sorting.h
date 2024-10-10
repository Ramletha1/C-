void display(int [],int );
void swap(int &,int &);
void bubbleSorting(int a[],int N);
void selectionSorting(int a[], int N);
void insertionSorting(int a[], int &N);

void display(int *a,int N){
        for(int i=0;i<N;i++){
                cout<<a[i]<<" ";
        }
        cout<<endl;
}

void swap(int &a,int &b){
    int temp;
    temp = a;
    a = b;
    b = temp;
}


void bubbleSorting(int *a, int N){
    int i,j,sorted;
    for (i=N-1; i>0 ;i--){
        sorted = 0;
        for(j=0; j<i ;j++){
            if (a[j]>a[j+1]){
                swap(a[j],a[j+1]);
                sorted = 1;
            }
            display(a,N);
        }
        if (sorted == 0) break;
    }
}

void selectionSorting(int *a, int N){
    int mini;

    for (int i=0; i<N-1; i++){
        mini = i;
        for(int j=i+1; j<N; j++){
            if(a[mini]>a[j]) mini = j;
        }
        swap(a[mini],a[i]);
        display(a,N);
    }
}

void insertionSorting(int *a, int &N){
    int i,j,value;
    
    for (i=1;i<N;i++){
        value = a[i];
        for(j = i-1; j>=0; j--){
            if (value<a[j]) a[j+1]=a[j];
            else break;
        }
        a[j+1]=value;
        display(a,N);
    }

}


