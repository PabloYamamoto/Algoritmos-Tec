#include <iostream> 
#include <utility> 
#include <limits.h>
#include <vector>
#include <list>
#include <queue>
#include <stack>

template <class T>
class GraphVertexWeighted
{
private:
    T val;
    std::vector<std::pair<int, float> > adj;
public: 
    ~GraphVertexWeighted() {};
    GraphVertexWeighted() {};
    GraphVertexWeighted(T _val) {val = _val;};

    T get_val() {return val;};
    void set_val(T _val) {val = _val;};

    std::vector<std::pair<int, float> > get_adj() {return adj;};
    void add_to_adj(int idx, float weight) {adj.push_back(std::make_pair(idx, weight));};
};


template <class T>
class GraphWeighted
{
private:
    std::vector<GraphVertexWeighted<T> > nodes;
    bool is_directed;

public:
    ~GraphWeighted() {};
    GraphWeighted() {is_directed=false;};

    void add_node(T val)
    {
        GraphVertexWeighted<T> node(val);
        nodes.push_back(node);
    };

    void add_edge(int src, int dst, float weight)
    {
        nodes[src].add_to_adj(dst, weight);
        if (!is_directed)
            nodes[dst].add_to_adj(src, weight);
    };

    T get_node_val(int i)
    {
        return nodes[i].get_val();
    };

    std::vector<float> shortest_path(int s)
    {
        std::vector<bool> status(nodes.size(), true);
        std::vector<float> distance(nodes.size(), INT_MAX);
        distance[s] = 0;

        for(int j = 0; j<distance.size(); j++)
        {
            int node = 0;
            for(int i  = 1; i < distance.size(); i++)
            {
                if((status[i] && distance[i] < distance[node]) || !status[node])
                {
                    node = i;
                }
    
            }
            status[node] = false;
            for(int i = 0; i < nodes[node].get_adj().size(); i++)
            {
                std::pair<int, float> node_to_calculate = nodes[node].get_adj()[i];
                int node_to_calculate_index = node_to_calculate.first;
                float node_to_calculate_distance = node_to_calculate.second;
                
                if(status[node_to_calculate_index] && distance[node_to_calculate_index] > node_to_calculate_distance + distance[node])
                    distance[node_to_calculate_index] = node_to_calculate_distance + distance[node];
            }
        }
        
        return distance;     
    };
};


