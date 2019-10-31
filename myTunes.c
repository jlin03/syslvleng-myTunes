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

struct song_node * insert_ordered(struct song_node *n, char *na, char *a, int song) {
  if(song == 1) {
    printf("Inserting: %s: %s\n",a,na);
    struct song_node *x = malloc(sizeof(struct song_node));
    struct song_node *start = n;
    struct song_node *prev = n;
    strcpy(x->name,na);
    strcpy(x->artist,a);
    if(strcmp(x->name,start->next->name) < 0) {
      x->next = n;
      return x;
    }
    else {
      print_list(n);
      while(start->next && strcmp(x->name,start->name) > 0) {
        prev = start;
        start = start->next;
      }
      if(strcmp(x->name,start->name) < 0) {
        prev->next = x;
        x->next = start;
        return n;
      }
      else {
        x->next = start->next;
        start->next = x;
        return n;
      }

    }
  }
  if(song == 0) {
    printf("Inserting: %s: %s\n",a,na);
    struct song_node *x = malloc(sizeof(struct song_node));
    struct song_node *start = n;
    struct song_node *prev = n;
    strcpy(x->name,na);
    strcpy(x->artist,a);
    if(strcmp(x->artist,start->next->artist) < 0) {
      x->next = n;
      return x;
    }
    else {
      print_list(n);
      while(start->next && strcmp(x->artist,start->artist) > 0) {
        prev = start;
        start = start->next;
      }
      if(strcmp(x->artist,start->artist) < 0) {
        prev->next = x;
        x->next = start;
        return n;
      }
      else {
        x->next = start->next;
        start->next = x;
        return n;
      }
    }

  }

    return NULL;
}


struct song_node * free_list(struct song_node *n) {
    struct song_node *prev = n;
    struct song_node *x = n;
    printf("Freeing: %s: %s\n",x->artist,x->name);
    prev = x;
    free(prev);
    while(x->next) {
        x = x->next;      print_list(n);
        prev = x;
        printf("Freeing: %s: %s\n",x->artist,x->name);
        free(prev);
    }

}

struct song_node * find_list(struct song_node *n,char *na, char *a) {
  if(strcmp(a,n->artist) == 0 && strcmp(na,n->name) == 0) {
    return n;
  }
  while(n->next) {
    n = n->next;
    if(strcmp(a,n->artist) == 0 && strcmp(na,n->name) == 0) {
      return n;
    }
  }
  return NULL;
}



struct song_node * random_list(struct song_node *n) {
  while(n->next) {
    if(rand() % 10 < 4) {
      return n;
    }
    else {
      n = n->next;
    }
  }
  return n;
}



int main() {
  srand(time(NULL));
  struct song_node *start = malloc(sizeof(struct song_node));
  strcpy(start->name,"song4");
  strcpy(start->artist,"band4");
  start = insert_front(start,"song3","band3");
  start = insert_front(start,"song2","band2");
  start = insert_ordered(start,"song1","band5",0);
  print_list(start);
  struct song_node *r = random_list(start);
  printf("%s %s",r->artist,r->name);

  return 0;
}
