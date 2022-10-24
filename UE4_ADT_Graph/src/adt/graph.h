#ifndef GRAPH_H
#define GRAPH_H

typedef struct node *node_ptr;
typedef struct edge_node *edge_ptr;

struct edge_node
{
   edge_ptr next;
   node_ptr dest;
};// Content of edge_node

struct node
{
   char *payload;
   edge_ptr edge_next;
   node_ptr next;
};// Content of graph_node

typedef struct 
{
   node_ptr head;
}graph_t;//Head of graph

extern void graph_init(graph_t *graph);
extern void graph_append_node(graph_t *graph,char *val);
extern void graph_add_edge(graph_t *graph,char *node,char *dest);
extern void graph_delete_node(graph_t *graph,char *val);
extern void graph_delete_edge(graph_t *graph,char *node,char *dest);
extern void print_graph(graph_t *graph);
extern void destroy_graph(graph_t *graph);

#endif