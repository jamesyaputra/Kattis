#include <iostream>

int main()
{
    int n;
    scanf("%d",&n);
    int a[6] = {0};
    int index[6] = {0};
    for (int i = 0; i < n; i++) {
        int k;
        scanf("%d",&k);
        a[k-1]++;
        index[k-1] = i + 1;
    }

    if (a[5] == 1) printf("%d\n", index[5]);
    else if (a[4] == 1) printf("%d\n", index[4]);
    else if (a[3] == 1) printf("%d\n", index[3]);
    else if (a[2] == 1) printf("%d\n", index[2]);
    else if (a[1] == 1) printf("%d\n", index[1]);
    else if (a[0] == 1) printf("%d\n", index[0]);
    else printf("none\n");
    return 0;
}