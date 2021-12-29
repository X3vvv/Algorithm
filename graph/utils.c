#include "utils.h"

int get_num_of_digits(int x) {
    x = x < 0 ? -x : x;
    int cnt = 0;
    while (x > 0) {
        x /= 10;
        ++cnt;
    }
    return cnt;
}

void print_adj_matrix(int num_of_nodes, int **adjacency_matrix) {
    int max_width_of_node_id = get_num_of_digits(num_of_nodes);
    printf("\n-------- adjacency matrix of the graph --------\n");
    printf("%*c   ", max_width_of_node_id,
           ' '); // whitespace before the IDs for columns
    // ID for columns
    for (int i = 0; i < num_of_nodes; ++i) {
        printf("%*d ", max_width_of_node_id, i + 1);
    }
    printf("\n");
    printf("%*c___", max_width_of_node_id, '_');
    for (int i = 0; i < num_of_nodes; ++i) {
        printf("%*c_", max_width_of_node_id, '_');
    }
    printf("\n");
    for (int i = 0; i < num_of_nodes; ++i) {
        printf("%*d | ", max_width_of_node_id, i + 1); // ID for the row
        for (int j = 0; j < num_of_nodes; ++j) {
            printf("%*d ", max_width_of_node_id, adjacency_matrix[i][j]);
        }
        printf("\n");
    }
}

void print_adj_list(int num_of_nodes, node_t *adjacency_list) {
    int max_width_of_node_id = get_num_of_digits(num_of_nodes);
    printf("\n-------- adjacency list of the graph --------\n");
    for (int i = 0; i < num_of_nodes; ++i) {
        printf("[node %*d]: ", max_width_of_node_id, i + 1);
        node_t *ptr_curr_node = &(adjacency_list[i]);
        while (1) {
            if (ptr_curr_node == NULL) {
                printf("x\n");
                break;
            }
            printf("%*d -> ", max_width_of_node_id, ptr_curr_node->id);
            ptr_curr_node = ptr_curr_node->next;
        }
    }
    printf("");
}

int **read_as_adj_matrix(int num_of_nodes) {
    // dynamically create a two dimentional array as adjacency matrix
    int **adjacency_matrix = (int **)calloc(num_of_nodes, sizeof(int *));
    for (int i = 0; i < num_of_nodes; ++i)
        adjacency_matrix[i] = (int *)calloc(num_of_nodes, sizeof(int));

    int max_width_of_node_id = get_num_of_digits(num_of_nodes);
    printf("Input the IDs of all adjacent node to the following nodes "
           "(seperated with space).\n");
    for (int i = 0; i < num_of_nodes; ++i) {
        printf("[node %*d]: ", max_width_of_node_id, i + 1);

        // read in a line of numbers seperated by space
        // e.g. "2 3 7\n"
        // reference: https://blog.csdn.net/BUPTSCSLJ/article/details/51023494
        int adj_node_id;
        while (1) {
            scanf("%d", &adj_node_id);
            // validate the inputted node ID (from 1~n and not equal to itself)
            if (adj_node_id < 1 || adj_node_id > num_of_nodes ||
                adj_node_id == i + 1) {
                printf("Illegal node ID\n");
                getchar();
                getchar();
                exit(-1);
            }
            adjacency_matrix[i][adj_node_id - 1] =
                adjacency_matrix[adj_node_id - 1][i] = 1;
            if (getchar() == '\n')
                break;
        }
    }

    return adjacency_matrix;
}

node_t *read_as_adj_lists(int num_of_nodes) {
    // index of adj_list = node ID - 1
    node_t *adj_list = calloc(
        num_of_nodes + 1,
        sizeof(node_t)); // initialize an extra position to detect list end

    int max_width_of_node_id = get_num_of_digits(num_of_nodes);
    printf("Input the IDs of all adjacent node to the following nodes "
           "(seperated with space).\n");
    for (int i = 0; i < num_of_nodes; ++i) {
        printf("[node %*d]: ", max_width_of_node_id, i + 1);

        // read in a line of adjacency node IDs seperated by space
        // e.g. "2 3 7\n"
        // reference: https://blog.csdn.net/BUPTSCSLJ/article/details/51023494
        int adj_node_id;
        node_t *ptr_curr_node = &(adj_list[i]);
        ptr_curr_node->id = i + 1;
        while (1) {
            scanf("%d", &adj_node_id);
            // validate the inputted node ID (from 1~n and not equal to itself)
            if (adj_node_id < 1 || adj_node_id > num_of_nodes ||
                adj_node_id == i + 1) {
                printf("Illegal node ID\n");
                system("pause");
                exit(-1);
            }

            // temporary variables in loop normally have fixed address, so
            // we need to dynamycally allocate memory
            node_t *next_node = (node_t *)malloc(sizeof(node_t));
            next_node->id = adj_node_id;
            next_node->next = NULL;
            ptr_curr_node->next = next_node;
            ptr_curr_node = ptr_curr_node->next;

            if (getchar() == '\n') // read in whiltespace or newline
                break;
        }
    }

    return adj_list;
}

int get_arr_len(int *arr) {
    int cnt = 0;
    while (arr != NULL) {
        ++arr;
        ++cnt;
    }
    return cnt;
}

void BFS(int root_id, node_t *adj_list, int **adj_matrix) {
    if (adj_list == NULL && adj_matrix == NULL) {
        printf("ERROR: Illegal argument.\n");
        return;
    }
    // adjacency list implementation
    if (adj_list != NULL) {
        node_t root = adj_list[root_id - 1];

        // create a list for adj nodes
        int search_node_id_list[MAX_BFS_LIST_LEN] = {
            0};                                // id-s of nodes to be searched
        int traversed[MAX_BFS_LIST_LEN] = {0}; // traversed node id-s
        int len = 0, traversed_idx = 0;

        // BFS the tree
        printf("\nBFS path:\n");
        search_node_id_list[len++] = root_id;
        while (1) {
            if (len <= 0)
                break;

            // fetch a node from the list (and re-order the list)
            int curr_node_id = search_node_id_list[0];
            node_t curr_node = adj_list[curr_node_id - 1];
            for (int i = 0; i < len; ++i)
                search_node_id_list[i] = search_node_id_list[i + 1];
            --len;
            traversed[traversed_idx++] = curr_node_id;

            // print out the node
            printf("%d -> ", curr_node.id);

            // add all sons of current node to the end of the list
            node_t *p_next_node = curr_node.next;
            while (1) {
                // check if reach end
                if (p_next_node == NULL)
                    break;
                // check if the node is traversed, prevent recursive search
                int is_traversed = 0;
                for (int i = 0; i < traversed_idx; ++i)
                    if (p_next_node->id == traversed[i]) {
                        is_traversed = 1;
                        break;
                    }
                if (is_traversed) {
                    p_next_node = p_next_node->next;
                    continue;
                }

                search_node_id_list[len++] = p_next_node->id;
                p_next_node = p_next_node->next;
            }
        }
        printf("x\n");
    }
    // adjacency matrix implementation
    else {
    }
}