

const int N = 1e6 + 5;
bool prime[N+1] ;
 
void seive()
{
    for(int i=0; i<=N; i++) prime[i] = 1;
    prime[0] = 0;
    prime[1] = 0;
    for (int p = 2; p * p <= N; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= N; i += p)
                prime[i] = false;
        }
    }
}
