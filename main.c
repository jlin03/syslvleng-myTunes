#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "myTunes.h"

int main() {
  srand(time(NULL));


  printf("Adding: The Rolling Stones | Miss You\n");
  add("Miss You","The Rolling Stones");
  printf("Adding: Bruce Springsteen | The Rising\n");
  add("The Rising","Bruce Springsteen");
  printf("Adding: Jackson Browne | Running on Empty\n");
  add("Running on Empty","Jackson Browne");
  printf("Adding: The Rolling Stones | Brown Sugar\n");
  add("Brown Sugar","The Rolling Stones");
  printf("Adding: Coldplay | Clocks");
  add("Clocks","Coldplay");
  printf("Adding: Justin Timberlake | Cry Me a River\n");
  add("Cry Me a River","Justin Timberlake");
  printf("Adding: Jefferson Airplane | White Rabbit\n");
  add("White Rabbit","Jefferson Airplane");
  printf("Adding: Rick James | Super Freak\n");
  add("Super Freak","Rick James");
  printf("Adding: The Beatles | Rain\n\n");
  add("Rain","The Beatles");

  print_all();

  struct song_node *r = malloc(sizeof(struct song_node));
  r = find_library("Rain","The Beatles");
  printf("\n\n%s | %s is located on: %p\n\n",r->artist,r->name,r);

  printf("\nShuffling songs:\n");
  shuffle();

  printf("\n\nRemoving: The Beatles | Rain\n");
  remove_library("Rain","The Beatles");
  print_all();

  printf("\n\nClearing Library...\n");
  clear_library();
  print_all();

  return 0;
}
