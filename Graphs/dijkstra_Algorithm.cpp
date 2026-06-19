//Dijkstra's Algorithm - Using Priority Queue
vector<int> dijkstraAlgorithmPQ(int v, vector<vector<int>> adj[], int s){
    priority_queue<pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    const int INF = 1e9;
    vector<int> dist(v, INF);
    dist[s] = 0;

    pq.push({0,s});
    while(!pq.empty()){
        int dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        if (dis != dist[node]) continue;
        for(auto it: adj[node]){
            int edgeWeight = it[1];
            int adjNode = it[0];

            if(dis + edgeWeight < dist[adjNode] ){
                dist[adjNode] = dis + edgeWeight;
                pq.push({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
}

//Dijkstra's Algorithm - Using Set
vector<int> dijkstraAlgorithmSET(int v, vector<vector<int>> adj[], int s){
    set<pair<int, int>> st;
    const int INF = 1e9;
    vector<int> dist(v, INF);
    dist[s] = 0;

    st.insert({0,s});
    while(!st.empty()){
        auto it = st.begin();
        int dis = it->first;
        int node = it->second;
        st.erase(it);
        if (dis != dist[node]) continue;

        for(auto &neib: adj[node]){
            int edgeWeight = neib[1];
            int adjNode = neib[0];

            if(dis + edgeWeight < dist[adjNode] ){
                if (dist[adjNode] != INF) {
                    st.erase({dist[adjNode], adjNode});
                }
                dist[adjNode] = dis + edgeWeight;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }
    return dist;
} 
