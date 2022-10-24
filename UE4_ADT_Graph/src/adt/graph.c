#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "graph.h"

static node_ptr new_node(char *payload){
   node_ptr n = (node_ptr)malloc(sizeof(struct node));
   if (n == NULL)
   {
      printf("ERROR: out of memory");
      exit(-1);
   }
   n->payload = payload;
   n->next = NULL;
   return n;
}

void graph_init(graph_t *graph){
   graph->head = NULL;
}

void graph_append_node(graph_t *graph,char *val){
   node_ptr n = new_node(val);
   if (graph->head != NULL)
   {
      node_ptr current_node = graph->head;
      node_ptr last_node = current_node;
      while (current_node->next != NULL)
      {
         if (strcmp(current_node->payload,val)==0)
         {
            printf("node already exists\n");
            return;
         }
         current_node = current_node->next;
         last_node = current_node;
      }
      last_node->next = n;
   }
   else
   {
      graph->head = n;
   }
   char *new_pl = malloc((strlen(val)+1)*sizeof(char));
   strcpy(new_pl, val);
   n->payload = new_pl;
   n->next = NULL;
   n->edge_next = NULL;
}

static node_ptr find_node(graph_t *graph, char *dest){
   for (node_ptr n = graph->head; n != NULL; n = n->next)
   {
      
      if (strcmp(n->payload,dest)==0)
      {
         return n;
      }
   }
   printf("node does not exist\n");
   exit(-1);
}

void graph_add_edge(graph_t *graph,char *node,char *dest){
   //first find start node with char(node) and save it to a new node_ptr
   node_ptr start = find_node(graph,node);
   //second find destination of edge with char(dest and save it to new node_ptr)
   node_ptr dest_node = find_node(graph,dest);

   edge_ptr n_e = (edge_ptr)malloc(sizeof(struct edge_node));
   if (start->edge_next == NULL)
   {
      start->edge_next = n_e;
   }
   else
   {
      //Go to the last edge of start node
      edge_ptr last_edge = start->edge_next;
      for (edge_ptr e = start->edge_next; e != NULL; e = e->next)
      {
         last_edge = e;
      }
      last_edge->next = n_e;
   }
   //Create new Edge with next = NULL and dest = dest(node_ptr)(second step)
   n_e->next = NULL;
   n_e->dest = dest_node;
}


void print_graph(graph_t *graph){
   node_ptr n = graph->head;
   while (n != NULL)
   {
      printf("%s :",n->payload);
      if (n->edge_next != NULL)
      {
         for (edge_ptr e = n->edge_next; e!= NULL; e=e->next)
         {
            printf("%s, ",e->dest->payload);
         }  
      }
      printf("\n");
      n = n->next;
   }
}

void graph_delete_edge(graph_t *graph,char *node,char *dest){
   //first find start node with char(node) and save it to a new node_ptr
   node_ptr start = find_node(graph,node);
   //second find destination of edge with char(dest) and save it to new node_ptr
   node_ptr dest_node = find_node(graph,dest);
   if (start->edge_next == NULL)
   {
      printf("Edge does not exist");
      return;
   }
   edge_ptr last_edge = start->edge_next;
   if (strcmp(last_edge->dest->payload,dest_node->payload)==0)//delete if first edge
   {
      start->edge_next = last_edge->next;
      free(last_edge);
      return;
   }
   for (edge_ptr e = start->edge_next; e != NULL; e = e->next)
   {
      if (strcmp(e->dest->payload,dest_node->payload)==0)
      {
         last_edge->next = e->next;
         free(e);
         return;
      }
      last_edge = e;
   }
}

void graph_delete_node(graph_t *graph,char *val){
   node_ptr last_node = graph->head;
   //first delete all edges of target node
   for (node_ptr n = graph->head; n != NULL; n = n->next)   {
      if (strcmp(n->payload,val)==0)
      {
         edge_ptr e = n->edge_next;
         while (e != NULL)
         {
            edge_ptr last_edge = e;
            e = e->next;
            free(last_edge);
         }
         n->edge_next = NULL;
         break;
      }
   }
   //second delete all edges from rest of nodes that point to target node
   for (node_ptr n = graph->head; n != NULL; n = n->next)
   {
      edge_ptr last_edge = NULL;
      for (edge_ptr e = n->edge_next; e != NULL ; e=e->next)
      {
         if (strcmp(e->dest->payload,val)==0)
         {
            if (last_edge == NULL)
            {
               last_edge = n->edge_next;
               n->edge_next = last_edge->next;
               free(last_edge);
               break;
            }
            else
            {
               last_edge->next=e->next;
               free(e);
               break;
            }
         }
         last_edge = e;
      }
   }
   //last delete target node
   node_ptr n = graph->head;
   while ( n != NULL)   {
      n = n->next;
      if (strcmp(last_node->payload,val)==0)
      {
         graph->head = last_node->next;
         free(last_node);
         return;
      }
      else if (strcmp(n->payload,val)==0)
      {
         last_node->next=n->next;
         free(n);
         return;
      }
      last_node = n;
   }
}

void destroy_graph(graph_t *graph){
   node_ptr n = graph->head;
   while (n != NULL)
   {
      edge_ptr e = n->edge_next;
      while (e != NULL)
      {
         edge_ptr last_edge = e;
         e = e->next;
         free(last_edge);
      }
      node_ptr last_node = n;
      n = n->next;
      free(last_node);
   }
   free(graph);
}

