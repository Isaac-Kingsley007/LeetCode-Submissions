/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int findParent(int n, int* parent){
    if(n != parent[n]) parent[n] = findParent(parent[n], parent);
    return parent[n];
}

int* findRedundantConnection(int** edges, int n, int* edgesColSize, int* returnSize) {
    int pa,pb;
    n++;
    *returnSize = 2;
    int parent[n];
    for(int i = 0; i<n; i++) parent[i] = i;

    for(int i = 0; i<n; i++){
        pa = findParent(edges[i][0], parent);
        pb = findParent(edges[i][1], parent);

        if (pa == pb) return edges[i];

        if(pa < pb) parent[pb] = pa;
        else parent[pa] = pb;
    }

    return edges[0];
}