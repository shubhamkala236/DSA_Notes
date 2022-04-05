bool findPair(int arr[], int size, int n){
    //code
     sort (arr, arr+size);
    
       for(int i=0; i< size-1; i++){
           
          for (int j= i+1; j< size; j++){
              
               if (arr[j]-arr[i] == n)
                   return true;         
          }   
        
      }
      
      return false;
    
    
}