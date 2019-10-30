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




void print_list(struct song_node *n) {
  char s[500] = "";
  char s2[100] = "";
  struct song_node *x = n;
  strcat(s, x->artist);
  strcat(s, ": ");
  strcat(s, x->name);
  strcat(s, " | ");
  while(x->next) {
    x = x->next;
    strcat(s, x->artist);
    strcat(s, ": ");
    strcat(s, x->name);
    strcat(s, " | ");
  }
  printf("%s\n",s);
}




struct song_node * insert_front(struct song_node *n, char *na, char *a) {
  printf("Inserting: %s: %s\n",a,na);
  struct song_node *x = malloc(sizeof(struct song_node));
  strcpy(x->name,na);
  strcpy(x->artist,a);
  x->next = n;
  return x;
}


struct song_node * free_list(struct song_node *n) {
    struct song_node *prev = n;
    struct song_node *x = n;
    printf("Freeing: %s: %s\n",x->artist,x->name);
    prev = x;
    free(prev);
    while(x->next) {
        x = x->next;
        prev = x;
        printf("Freeing: %s: %s\n",x->artist,x->name);
        free(prev);
    }

}

struct song_node * remove_list(struct song_node *front, char *na) {
  printf("Removing: %s: %s\n",front->artist,na);
  struct song_node *x = front;
  if(strcmp(front->name,na) == 0) {
    struct song_node *newStart = front->next;
    free(front);
    return newStart;
  }
  else {
    while(x->next) {
      struct song_node *current = x;
      x = x->next;
      if(strcmp(front->name,na) == 0) {
        current->next = x->next;
        free(x);
      }
    }
    return front;
  }
}


int main() {
  struct song_node *start = malloc(sizeof(struct song_node));
  strcpy(start->name,"song");
  strcpy(start->artist,"band");
  start = insert_front(start,"band2","song2");
  start = insert_front(start,"band3","song3");
  print_list(start);

  return 0;
}
