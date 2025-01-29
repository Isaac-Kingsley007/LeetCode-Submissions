class Solution {

    private int findParent(int n, int[] parent){
        if(n != parent[n]) parent[n] = findParent(parent[n], parent);
        return parent[n];
    }

    public int[] findRedundantConnection(int[][] edges) {
        int n = edges.length + 1, pa, pb;
        int[] parent = new int[n];
        for(int i = 0; i<n; i++) parent[i] = i;

        for(int[] edge: edges){
            pa = findParent(edge[0], parent);
            pb = findParent(edge[1], parent);

            if(pa == pb) return edge;

            if(pa < pb) parent[pb] = pa;
            else parent[pa] = pb;
        }

        return edges[0];
    }
}