#define N 5
Semaphore Fork[ ]={1,1,1,1,1};
void Philosopher_1(){ /* 1 番目の哲学者 */
  int i=0; /* 哲学者の番号(0<=i<5) */

  for(i = 0; i < N; i++){
    Think(); /* 考える */

    if(i == 0){ // 1番目の哲学者なら
      Take(Fork(i+1)%N);
    }else{
      Take(Fork(i));
    }

    if(i == 0){ // 1番目の哲学者なら
      Take(Fork(i));
    }else{
      Take(Fork(i+1)%N);
    }

    Eat(); /* 食べる */
    Put(Fork(i)); /* 左のフォークを戻す */
    Put(Fork((i+1)%N)); /* 右のフォークを戻す */
  }
}
