#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //freopen("11240.in", "r", stdin);
    //freopen("out.txt", "w", stdout);

    int n;
    scanf("%d", &n);

    int arr[30000+5];
    while(n--)
    {
        int k;
        scanf("%d", &k);

        for(int i = 0; i < k; i++){
            scanf("%d", &arr[i]);
        }

        int cnt = 0, r = 1;
        for(int i = 0; i < k-1; i++){
            if(arr[i] > arr[i+1] && r == 1){
                cnt++;
                r = -1;
            }
            else if(arr[i] < arr[i+1] && r == -1){
                cnt++;
                r = 1;
            }
        }
        printf("%d\n", cnt+1);




    }

    return 0;
}
