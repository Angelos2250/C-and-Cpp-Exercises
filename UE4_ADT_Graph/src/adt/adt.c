#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "graph.h"

int main(){
   graph_t graph;
   graph_init(&graph);
   printf("TEST Appending/printing nodes\n");
   graph_append_node(&graph, "a");
   graph_append_node(&graph, "b");
   graph_append_node(&graph, "c");
   graph_append_node(&graph, "d");
   graph_append_node(&graph, "e");
   print_graph(&graph);

   printf("TEST Adding Edges/Printing with edges\n");
   graph_add_edge(&graph,"a","b");
   graph_add_edge(&graph,"a","c");
   graph_add_edge(&graph,"a","d");
   graph_add_edge(&graph,"a","e");
   graph_add_edge(&graph,"b","d");
   graph_add_edge(&graph,"c","b");
   graph_add_edge(&graph,"c","e");
   print_graph(&graph);

   printf("TEST Remove Node(and also nodes that point to target node)\n");
   graph_delete_node(&graph,"b");
   print_graph(&graph);

   printf("TEST Remove Edge\n");
   graph_delete_edge(&graph,"a","e");
   print_graph(&graph);

   printf("TEST Adding Node that already exists\n");
   graph_append_node(&graph,"a");

   printf("TEST Adding Edge that point to self\n");
   graph_add_edge(&graph,"a","a");
   print_graph(&graph);

   // printf("TEST Adding Edge with node_ptr that doesnt exist\n");
   // graph_add_edge(&graph,"a","p");

   printf("TEST Destroy graph\n");
   destroy_graph(&graph);
   print_graph(&graph);
}