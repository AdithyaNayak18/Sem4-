/* my code
  int mySqrt(int x) {
    int n;
    int i=1;
    while(x%i == 0)
    {
        if(x/i == i)
            return i;
        i++;
    }
    i=1;
        while(i*i <= x)
              i++;
    return i-1;
           
}*/
// Actual soln :
int mySqrt(int x) {
    int n;
    int i=1;
    while(x%i == 0)
    {
        if(x/i == i)
            return i;
        i++;
    }
    i=1;
        while(i*i <= x)
              i++;
    return i-1;
        
    
}
