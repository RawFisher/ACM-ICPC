#include <bits/stdc++.h>
#define IPV4 4
using namespace std;

const int maxn = 1000 + 10;
const int mask[] = {254, 252, 248, 240, 224, 192, 128};

typedef struct address {
    int a[IPV4];
    bool operator<(const address &nip) const {
        if (a[0]==nip.a[0] && a[1]==nip.a[1] && a[2]==nip.a[2])
            return a[3] < nip.a[3];
        else if (a[0]==nip.a[0] && a[1]==nip.a[1])
            return a[2] < nip.a[2];
        else if (a[0]==nip.a[0])
            return a[1] < nip.a[1];
        else
            return a[0] < nip.a[0];
    }
}addr;
  
addr A[maxn];
int m[4], ip[4];

int main() {
    int m;
    while (scanf("%d", &m) != EOF) {
        for (int i = 0; i < m; i++)
        { scanf("%d.%d.%d.%d", &A[i].a[0], &A[i].a[1], &A[i].a[2], &A[i].a[3]); }
        sort(A, A + m);
        int ind;
        for (ind = 0; ind < IPV4; ind++) {
            if (A[0].a[ind] != A[m-1].a[ind]) break;
        }
        int m_ind;
        for (m_ind = 0; m_ind < 7; m_ind++) {
            if ((A[0].a[ind] & mask[m_ind]) == (A[m-1].a[ind] & mask[m_ind])) break;
        }
        int m_ip[IPV4];
        for (int i = 0; i < ind; i++) m_ip[i] = 255;
        m_ip[ind] = mask[m_ind];
        for (int i = ind+1; i < IPV4; i++) m_ip[i] = 0;
        for (int i = 0; i < IPV4; i++) {
            printf(i==IPV4-1?"%d\n":"%d.", A[0].a[i]&m_ip[i]);
        }
        for (int i=0; i<IPV4; i++) {
            printf(i==IPV4-1?"%d\n":"%d.", m_ip[i]);
        }
    }
    return 0;
}

    
