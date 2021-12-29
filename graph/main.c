#include "utils.h"


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