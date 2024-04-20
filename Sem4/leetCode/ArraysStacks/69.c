//Testing for 2 cases
// If divsible by the number ie perfect square
int mySqrt(int x) {
    int n;
    int i=1;
    while(x%i == 0)
    {
        if(x/i == i)
            return i;
        i++;
    }
  //If not perfect square :
    i=1;
        while(i*i <= x)
              i++;
    return i-1;
        
    
}
