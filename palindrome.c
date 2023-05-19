bool isPalindrome(int x){
    int n=x;
    long long r=0;
    if (x<0)
    {
        return 0;
    }
    else
    {
        
        while(0 != x)
        {
            r= (x%10) + (r*10);
            x/=10;
        }
    }
    return r == n;
}