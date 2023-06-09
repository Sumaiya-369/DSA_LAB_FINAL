#include<stdio.h>
#include<string.h>

#define n 100
int color[n]; // 0 for WHITE, 1 for GREY, 2 for BLACK
int time;
int prev[n];
int d[n];
int f[n];
int graph[n][n];
int stack[n];
int top = -1;

void push(int v) {
    stack[++top] = v;
}

void dfs_visit(int u, int nv) {
    color[u]= 1;
    time++;
    d[u] = time;
    for(int i=0; i<nv; i++) {
        if(graph[u][i] && !color[i]) {
            prev[i] = u;
            dfs_visit(i, nv);
        }
    }  
    color[u] = 2;
    time++;
    f[u] = time;

    push(u);

}

void dfs(int nv) {
    for(int i=0; i<nv; i++) {
        color[i] = 0;
        prev[i] = -1;
        f[i] = d[i] = -1;
    }
    time =0;
    for(int i=0; i<nv; i++) {
        if(!color[i]) {
            dfs_visit(i, nv);
        }
    }
}

void topological_sort(int nv) {
    dfs(nv);

    printf("Topological sort: ");
    while(top>=0) {
        printf("%d ", stack[top--]);
    }
}

int main() {
    int nv, ne;

    printf("Enter the number of verteces: ");
    scanf("%d", &nv);
    printf("Enter the number of edges: ");
    scanf("%d", &ne);

    for(int i=0; i<ne; i++) {
        int v1, v2;
        scanf("%d %d", &v1, &v2);
        graph[v1][v2]=1;

    }

    topological_sort(nv);


}