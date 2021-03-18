#include <stdio.h>
#include <stdlib.h>

typedef struct iskambil_destesi{
  char sayi;
  char renk;
  struct iskambil_destesi *next;
  struct iskambil_destesi *prev;
} iskambil_destesi;


iskambil_destesi* yeni_deste_olustur(){
  iskambil_destesi *head = NULL;
  iskambil_destesi *current = NULL;
  char s[13]={'A','2','3','4','5','6','7','8','9','0','J','Q','K'};
  char r[4]={'S','K','M','C'};
  int i,j;
  for (i=0;i<4;i++){
    for (j=0;j<13;j++){
      if (i==0 && j==0){
        current = (iskambil_destesi*)malloc(sizeof(iskambil_destesi));
        current->renk = r[i];
        current->sayi = s[j];
        current->next = NULL;
        current->prev = NULL;
        head = current;
      }
      else {
        current->next = (iskambil_destesi*)malloc(sizeof(iskambil_destesi));
        current->next->renk = r[i];
        current->next->sayi = s[j];
        current->next->next = NULL;
        current->next->prev = current;
        current=current->next;
      }
    }
  }
  return head;
}


void karistir(iskambil_destesi *head){
  iskambil_destesi *current = head;
  iskambil_destesi *temp = head;
  char s,r;
  int i,j;
  while(current->next!=NULL)
    current=current->next;
  for (i=51;i>0;i--){
    j=(rand()%i);
    while(j>0){
      temp=temp->next;
      j--;
    }
    r= current->renk;
    s= current->sayi;
    current->renk=temp->renk;
    current->sayi=temp->sayi;
    temp->sayi=s;
    temp->renk=r;
    temp=head;
    current=current->prev;
  }
}


void desteyi_goster(iskambil_destesi *head){
  iskambil_destesi *current = head;
  if(current == NULL){
  printf("Kart yok.\n");
  }
  else{
    while(current!=NULL){
      printf("%c%c\n",current->renk,current->sayi);
      current=current->next;
    }
  }
}


int main() {
  int i;
  iskambil_destesi *yeni_deste = yeni_deste_olustur();
  karistir(yeni_deste);
  desteyi_goster(yeni_deste);
  return 0;
}
