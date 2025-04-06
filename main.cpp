#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/bc_clustering.hpp>
#include <boost/graph/connected_components.hpp>
#include <boost/graph/graph_utility.hpp>
#include <boost/property_map/property_map.hpp>
#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace boost;

typedef adjacency_list<vecS, vecS, undirectedS,
                       property<vertex_index_t, int>,
                       property<edge_index_t, int>> Graph;

typedef graph_traits<Graph>::vertex_descriptor Vertex;
typedef graph_traits<Graph>::edge_descriptor Edge;

struct Done {
    int count = 0;
    int max_removals;

    Done(int max_removals) : max_removals(max_removals) {}

    bool operator()(double max_centrality, Edge e, const Graph &g) {
        std::cout << "Removed edge with centrality = " << max_centrality << "\n";
        return (++count >= max_removals);
    }
};

void print_clusters(const Graph& g) {
    std::vector<int> component(num_vertices(g));
    int num = connected_components(g, &component[0]);
    std::cout << "Number of clusters: " << num << "\n";
    for (size_t i = 0; i < component.size(); ++i)
        std::cout << "Vertex " << i << " in cluster " << component[i] << "\n";
}

void run_clustering(Graph& g, const std::string& name, int max_removals) {
    std::cout << "\n========== " << name << " ==========\n";

    std::cout << "Initial Edges:\n";
    print_edges(g, get(vertex_index, g));

    std::cout << "\nInitial Clusters:\n";
    print_clusters(g);

    std::map<Edge, double> edge_centrality_map;
    associative_property_map<std::map<Edge, double>> centrality_prop_map(edge_centrality_map);

    betweenness_centrality_clustering(g, Done(max_removals), centrality_prop_map);

    std::cout << "\nEdges After Clustering:\n";
    print_edges(g, get(vertex_index, g));

    std::cout << "\nClusters After Clustering:\n";
    print_clusters(g);
}

Graph make_complete_graph(int n) {
    Graph g(n);
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            add_edge(i, j, g);
    return g;
}

Graph make_clustered_graph() {
    Graph g(9);

    add_edge(0, 1, g); add_edge(1, 2, g); add_edge(0, 2, g);
    add_edge(3, 4, g); add_edge(4, 5, g); add_edge(3, 5, g);
    add_edge(6, 7, g); add_edge(7, 8, g); add_edge(6, 8, g);

    add_edge(2, 3, g);
    add_edge(5, 6, g);

    return g;
}

// Single-Cluster Graph: Grid or Path (weak structure)
Graph make_single_cluster_graph() {
    Graph g(9);
    // Make a 3x3 grid manually
    std::vector<std::pair<int, int>> edges = {
        {0,1},{1,2},{3,4},{4,5},{6,7},{7,8},
        {0,3},{3,6},{1,4},{4,7},{2,5},{5,8}
    };
    for (auto& e : edges) add_edge(e.first, e.second, g);
    return g;
}

int main() {
    Graph complete = make_complete_graph(5);
    Graph clustered = make_clustered_graph();
    Graph single = make_single_cluster_graph();

    run_clustering(complete, "Complete Graph (K5)", 5);
    run_clustering(clustered, "3-Cluster Graph", 3);  // stop after 2 bridges are removed
    run_clustering(single, "Single-Cluster Grid Graph", 5);

    return 0;
}
