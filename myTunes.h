#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>


struct song_node * table[27];

struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};


void print_list(struct song_node *n);
void print_artist(char *a);
void print_all();
void print_random(struct song_node *n);
void shuffle();
struct song_node * insert_front(struct song_node *n, char *na, char *a);
struct song_node * insert_ordered(struct song_node *n, char *na, char *a, int song);
void clear_library();
struct song_node * free_list(struct song_node *n);
struct song_node * remove_list(int f, struct song_node *n, char *na, char *a);
void remove_library(char *na, char *a);
struct song_node * find_list(struct song_node *n,char *na, char *a);
struct song_node * find_library(char *na, char *a);
struct song_node * find_artist_song(struct song_node *n, char *a);
struct song_node * find_artist(struct song_node *n, char *a);
void print_artist_letter(char x);
struct song_node * random_list(struct song_node *n);
void add(char *na, char *a);
