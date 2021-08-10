#include <iostream>
using namespace std;

int main() {
	int T;
	    cin >> T;
	while(T--){
	    int N,D,i ;
	    cin >> N >> D;
	    int arr[N];
        for(int i=0;i<N;i++){
	    cin >> arr[i];
	    }
	    int temp[D];
	    for(int i=0;i<D;i++){//to store first d elements in array
	    temp[i] = arr[i];
	    }
	    
	    int x=0 ;//to shift the remaining elements
	    for(int j=D;j<N;j++){
	        arr[x]= arr[j];
	        x++;
	    }
	    x=0;
	    for(int k=N-D;k<N;k++){//to restore the elements back into array
	        arr[k]= temp[x];
	        x++;

	    }
    for(i =0; i< N; i++){
     cout << arr[i] << " ";
    }
    cout << "\n";
	}
	    
	return 0;
}
