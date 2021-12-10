#include "utils.h"

/**
 * @brief BFS traverse the graph and print visited nodes' IDs
 *
 * @param adj_list pointer to adjacency list
 * @param adj_matrix pointer to adjacency matrix
 */
void BFS(int root_id, node_t *adj_list, int **adj_matrix) {
    if (adj_list == NULL && adj_matrix == NULL) {
        printf("ERROR: Illegal argument.\n");
        return;
    }
    // adjacency list implementation
    if (adj_list != NULL) {
        node_t root = adj_list[root_id - 1];

        // get the max number of adjacent nodes
        int max_num_of_adj_nodes = 0;
        int adj_list_idx = 0;
        while (1) {
            // reach the list end
            if (adj_list[adj_list_idx].id == 0 &&
                adj_list[adj_list_idx].next == 0)
                break;
            node_t *ptr_node = &adj_list[adj_list_idx++];
            int num_of_adj_nodes = 0;
            while (1) {
                ++num_of_adj_nodes;
                if (ptr_node->next == NULL)
                    break;
                ptr_node = ptr_node->next;
            }
            if (num_of_adj_nodes > max_num_of_adj_nodes)
                max_num_of_adj_nodes = num_of_adj_nodes;

            // for debugging:
            printf("this adj node num = %d\n"
                   "max adj node num = %d\n"
                   "this node id = %d\n"
                   "\n",
                   num_of_adj_nodes, max_num_of_adj_nodes, adj_list_idx);
        }
        // create a list for adj nodes
        node_t *node_list_for_search =
            malloc(sizeof(node_t) * max_num_of_adj_nodes);
        int idx = 0;

    }
    // adjacency matrix implementation
    else {
    }
}

int main(void) {
    // assume the IDs of nodes in the graph start from 1 and are successive
    int num_of_nodes;
    printf("Input the number of nodes in graph: ");
    scanf("%d", &num_of_nodes);

    node_t *adj_list = read_as_adj_lists(num_of_nodes);
    print_adj_list(num_of_nodes, adj_list);

    // int **adj_matric = read_as_adj_matrix(num_of_nodes);
    // print_adj_matrix(num_of_nodes, adj_matric);

    BFS(1, adj_list, NULL);
    system("pause");
    return 0;
}