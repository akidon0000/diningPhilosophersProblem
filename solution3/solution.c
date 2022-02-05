#define N 5
Semaphore Fork[ ]={1,1,1,1,1};
void Philosopher_1(){    /* 1番目の哲学者 */
  int i=0;                 /* 哲学者の番号(0<=i<5) */
  for(i = 0; i < N; i++){
    Think();               /* 考える */
    Take(Fork(i));        /* 左のフォークを取る */
    Take(Fork((i+1)%N)); /* 右のフォークを取る */
    Eat();                  /* 食べる */
    Put(Fork(i));         /* 左のフォークを戻す */
    Put(Fork((i+1)%N));  /* 右のフォークを戻す */
  }
}
