#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "myTunes.h"

void print_list(struct song_node *n) {
  char s[500] = "";
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
  printf("%s",s);
}

void print_artist(char *a) {
  int f = a[0]-65;
  char s[500] = "";
  struct song_node *x = table[f];
  if(strcmp(x->artist,a) == 0) {
      strcat(s, x->artist);
      strcat(s, ": ");
      strcat(s, x->name);
      strcat(s, " | ");
  }
  while(x->next) {
    x = x->next;
    if(strcmp(x->artist,a) == 0) {
      strcat(s, x->artist);
      strcat(s, ": ");
      strcat(s, x->name);
      strcat(s, " | ");
    }
  }
  printf("%s",s);
}

void print_all() {
  for(int i = 0; i < 27; i++) {
    if(table[i]) {
      print_list(table[i]);
    }
  }
}

void print_random(struct song_node *n) {
  char s[500] = "";
  struct song_node *x = n;
  if(rand()%2 == 1) {
      strcat(s, x->artist);
      strcat(s, ": ");
      strcat(s, x->name);
      strcat(s, " | ");
  }
  while(x->next) {
    x = x->next;
    if(rand()%2 == 1) {
      strcat(s, x->artist);
      strcat(s, ": ");
      strcat(s, x->name);
      strcat(s, " | ");
    }
  }
  printf("%s",s);
}


void shuffle() {
  for(int i = 0; i < 27; i++) {
    if(table[i]) {
      print_random(table[i]);
    }
  }
}




struct song_node * insert_front(struct song_node *n, char *na, char *a) {
  struct song_node *x = malloc(sizeof(struct song_node));
  strcpy(x->name,na);
  strcpy(x->artist,a);
  x->next = n;
  return x;
}

struct song_node * insert_ordered(struct song_node *n, char *na, char *a, int song) {
  if(song == 1) {
    struct song_node *x = malloc(sizeof(struct song_node));
    struct song_node *start = n;
    struct song_node *prev = n;
    strcpy(x->name,na);
    strcpy(x->artist,a);
    if(n->next) {
      if(strcmp(x->name,start->name) < 0) {
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
    }//notes:  Does not compile/
    else {
      if(strcmp(x->name,n->name) < 0) {
        x->next = n;
        return x;
      }
      else {
        n->next = x;
      }
    }
  }
  if(song == 0) {
    struct song_node *x = malloc(sizeof(struct song_node));
    struct song_node *start = n;
    struct song_node *prev = n;
    strcpy(x->name,na);
    strcpy(x->artist,a);
    if(n->next) {
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
    else {
      if(strcmp(x->artist,n->artist) < 0) {
        x->next = n;
        return x;
      }
      else {
        n->next = x;
        return n;
      }
    }

  }

    return NULL;
}

void clear_library() {
    for(int i = 0; i < 27; i++) {
        if(table[i]) {
            free_list(table[i]);
            table[i] = NULL;
        }
    }
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


struct song_node * remove_list(int f, struct song_node *n, char *na, char *a) {
  struct song_node *x = n;
  if(strcmp(a,n->artist) == 0 && strcmp(na,n->name) == 0) {
    if(n->next) {
        struct song_node *newStart = n->next;
        table[f] = newStart;
        free(n);
        return newStart;
    }
    else {
        free(n);
        table[f] = NULL;
    }
  }
  else {
    while(x->next) {
      struct song_node *current = x;
      x = x->next;
      if(strcmp(a,x->artist) == 0 && strcmp(na,x->name) == 0) {
        current->next = x->next;
        free(x);
        return n;
      }
    }
    return n;
  }
}

void remove_library(char *na, char *a) {
    int f = a[0]-65;
    remove_list(f,table[f],na,a);
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


struct song_node * find_library(char *na, char *a) {
    int f = a[0]-65;
    if(f<26 && f>=0) {
        return find_list(table[f],na,a);
    }
    else {
        return find_list(table[26],na,a);
    }
    return NULL;
}


struct song_node * find_artist_song(struct song_node *n, char *a) {
  if(strcmp(a,n->artist) == 0) {
    return n;
  }
  while(n->next) {
    n = n->next;
    if(strcmp(a,n->artist) == 0) {
      return n;
    }
  }
  return NULL;
}

struct song_node * find_artist(struct song_node *n, char *a) {
    int f = a[0]-65;
    if(f<26 && f>=0) {
        return find_artist_song(table[f],a);
    }
    else {
        return find_artist_song(table[26],a);
    }
    return NULL;
}

void print_artist_letter(char x) {
    int f = x-65;
    if(f<26 && f>=0) {
        return print_list(table[f]);
    }
    else {
        return print_list(table[26]);
    }

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


void add(char *na, char *a) {
  int f = a[0]-65;
  if(f<26 && f>=0) {
    if(table[f]) {
      table[f] = insert_ordered(table[f],na,a,0);
    }
    else {
      table[f] = malloc(sizeof(struct song_node));
      strcpy(table[f]->artist,a);
      strcpy(table[f]->name,na);
    }
  }
  else {
    if(table[26]) {
      table[f] = insert_ordered(table[f],na,a,0);
    }
    else {
      table[26] = malloc(sizeof(struct song_node));
      strcpy(table[f]->artist,a);
      strcpy(table[f]->name,na);
    }
  }

}
