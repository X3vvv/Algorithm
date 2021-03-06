#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int id;            // id of this node
    struct node *next; // pointer to the next node
};
typedef struct node node_t; // struct of node in linked list

/**
 * @brief Get the num of digits of a number.
 *
 * @param x the number
 * @return int number of digits of param x
 */
int get_num_of_digits(int x);
/**
 * @brief print the adjacency matrix for the graph.
 *
 * @param num_of_nodes number of nodes in the graph
 * @param adjacency_matrix the adjacency matrix of the graph
 */
void print_adj_matrix(int num_of_nodes, int **adjacency_matrix);

/**
 * @brief print the adjacency list for the graph.
 *
 * @param num_of_nodes number of nodes in the graph
 * @param adjacency_list the adjacency list of the graph
 */
void print_adj_list(int num_of_nodes, node_t *adjacency_list);

/**
 * @brief Read a graph from user input and store as an adjacency matrix. The
 * pointer of the adjacency matrix is calloc-ed inside the function.
 *
 * @param num_of_nodes number of the nodes in the graph
 * @return int** the pointer of the adjacency matrix
 */
int **read_as_adj_matrix(int num_of_nodes);

/**
 * @brief Read a graph from user input and store as an adjacency list. The
 * pointer of the adjacency list is calloc-ed inside the function.
 *
 * @param num_of_nodes number of the nodes in the graph
 * @return node_t* pointer of the adjacency list
 */
node_t *read_as_adj_lists(int num_of_nodes);

/**
 * @brief Find out how many values there are in the array before meet a NULL.
 *
 * @param arr the array to get the length of
 * @return int the length of the array
 */
int get_arr_len(int *arr);

#define MAX_BFS_LIST_LEN 100
/**
 * @brief BFS traverse the graph and print visited nodes' IDs.
 * TODO: Implement the adjacent matrix version.
 *
 * @param root_id id of the root node. node-index = id - 1
 * @param adj_list pointer to adjacency list
 * @param adj_matrix pointer to adjacency matrix
 */
void BFS(int root_id, node_t *adj_list, int **adj_matrix);

#endif