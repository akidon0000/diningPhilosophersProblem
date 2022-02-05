#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

// 哲学者の人数
#define N 5

typedef struct Philosophyer{
	int id;                    // 哲学者を識別する番号
	int forkleft;              // 左手でフォークを取ろうとする時にtrue
	int forkright;             // 右手でフォークを取ろうとする時にtrue
	pthread_t phil_thread;     // 自身の処理を行うスレッド
	struct Philosophyer *prev; // 右側の哲学者を指すポインタ
	struct Philosophyer *next; // 左側の哲学者を指すポインタ
}Philosophyer;

void *Phil(Philosophyer* me);
int Diningtime();

Philosophyer header;
sem_t Forks_sem;
sem_t Spaces_sem;

int main(){
  int res0,res1;
  int i=0;
  void *thread_result;
  Philosophyer *pointer,*prev;

  header.prev = NULL;
  header.id = 0;

  for(i=0,prev=&header;i<N;i++){
    //create a philosophyer
    if(( prev->next=malloc(sizeof(Philosophyer)) )==NULL){
      exit(1);
    }
    //initialize a philosophyer
    pointer=prev->next;
    pointer->id = i+1;
    pointer->forkleft=0;
    pointer->forkright=0;
    pointer->prev = prev;
    pointer->next = header.next;

    header.next->prev = pointer;
    prev = pointer;
  }

  res0 = sem_init(&Forks_sem,0,N-1);
  res0 = sem_init(&Spaces_sem,0,0);

  //create phil_thread s
  for(i=0,pointer=header.next; i<N; i++){
    res1 = pthread_create(&(pointer->phil_thread),NULL,Phil,pointer);

    pointer=pointer->next;
  }

  printf("Waiting for phil_thread to finish...\n");

  //join phil_thread s
  for(i=0,pointer=header.next; pointer!=NULL; i++){
    res1 = pthread_join(pointer->phil_thread,&thread_result);

    pointer=pointer->next;
  }

  sem_destroy(&Forks_sem);
  sem_destroy(&Spaces_sem);
  exit(EXIT_SUCCESS);
}

void *Phil(Philosophyer* me){
  int diningtime;

  while(1){

    while(1){
      me->forkleft=1;

      while(me->next->forkleft==1){}

      sem_wait(&Forks_sem);
      sem_post(&Spaces_sem);

      me->forkright=1;
      if(me->prev->forkleft!=1){
        sem_wait(&Forks_sem);
        sem_post(&Spaces_sem);
        break;
      }

      me->forkleft=0;
      sem_post(&Forks_sem);
      sem_wait(&Spaces_sem);
      me->forkright=0;

      sleep(1);
    }

    //食事をする
    printf("哲学者%d:食事をする\n",me->id);
    diningtime=Diningtime();
    printf(">>>哲学者%d:食事中(時間=%d秒)\n",me->id,diningtime);
    sleep(diningtime);
    printf("---哲学者%d:完食\n",me->id);

    //左手のフォークを戻す
    sem_wait(&Spaces_sem);
    sem_post(&Forks_sem);
    me->forkleft=0;
    //右手のフォークを戻す
    sem_wait(&Spaces_sem);
    sem_post(&Forks_sem);
    me->forkright=0;

    sleep(1);
  }
}

int Diningtime(){
  return 1+(int)(9.0*rand()/RAND_MAX+1.0);
}
