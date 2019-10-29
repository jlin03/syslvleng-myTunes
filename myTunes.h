#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};


void print_list(struct song_node *n);
struct song_node * insert_front(struct song_node *n, char *na, char *a);
struct song_node * free_list(struct song_node *n);
struct song_node * remove_list(struct song_node *front, char *na);
