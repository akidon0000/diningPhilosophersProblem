#include <stdio.h>
// #include <stdlib.h>

// struct node{
//   int data;
//   struct node *next;
// };

// struct node *head, *tail, *p;
// int x = 1;


// //関数のプロトタイプ宣言
// void Add(int);
// void Del();
// void Display();
// void Release();
// struct node list;

// int main(){
//   list.next=&list;
//   // p=(struct node*)malloc(sizeof(struct node));
//   // p->data=x;
//   // p->next=&list;
//   // tail=&list;
//   // // for(head=list.next;head!=&list;head=head->next){
//   // //   tail=head;
//   // // }
//   // tail->next=p;
//   Add(5);
//   Add(6);
//   Add(4);
//   Add(2);
//   Display();
//   // Del();
//   head=&list;
//   // p=list.next;
//   // head->next=p->next;
//   p=head;
//   head=head->next;
//   free(p);

//   Display();
//   return 0;
// }


// void Add(int x){
//   // struct node list;
//   //新しいリストの領域を確保
//   p=(struct node*)malloc(sizeof(struct node));

//   p->data=x;
//   //次の要素は先頭要素のポインタ
//   p->next=&list;
//   //最初は先頭が末尾直前のポインタになる
//   tail=&list;
//   //末尾のポインタまで移動
//   for(head=list.next;head!=&list;head=head->next){
//     tail=head;
//   }
//   //リストを連結する。
//   tail->next=p;
//   puts("追加しました");
// }

// void Del(){
//   struct node* prev;
//   head=&list;
//   p=list.next;
//   head->next=p->next;
//   free(p);
//   // if(p->data==5){
//   //   prev->next=p->next;
//   //   free(p);
//   //   puts("aa");
//   // }

// 	//リストを末尾(先頭要素のポインタ)までループ
// 	// for(struct node *p=list.next;p!=&list;p=p->next){
// 	// 	//その値があれば
// 	// 	if(p->data==7){
// 	// 		//削除要素の前のリストにつなげる
// 	// 		//その前に次の要素が末尾ならつなげる必要ないのでチェック
// 	// 		if(p->next!=&list){
// 	// 			//削除直前の要素につなげる
// 	// 			prev->next=p->next;
// 	// 			//削除対象要素の解放
// 	// 			free(p);
// 	// 			return;
// 	// 		}
// 	// 		//末尾要素に先頭要素のポインタを保存
// 	// 		prev->next=&list;
// 	// 		//削除対象要素の解放
// 	// 		free(p);
// 	// 		puts("削除しました");
// 	// 		return;
// 	// 	}
// 	// 	prev=p;
// 	// }
//   return;
// }


// void Display(){
// 	if(list.next==&list){
// 		puts("まだ何もありません");
// 		return;
// 	}

// 	//末尾まで全部表示
// 	for(struct node  *p=list.next;p!=&list;p=p->next){

// 		printf("%d,",p->data);
// 	}

// 	puts("");

// }

// void Release(){

// 	//次のリストのポインタ
// 	struct node *next;
// 	//削除対象のポインタ
// 	struct node *del;

// 	next=list.next;

// 	//末尾までループ
// 	while(next!=&list){
// 		//削除対象のポインタを保存
// 		del=next;
// 		//次のリストのポインタを取得しとく
// 		next=next->next;

// 		free(del);
// 	}
// }

// #define int b[10]
int b[10];
int counter = 0;

// void part_of_sort( int x[ ], int start, int end )
// {
//   int mid, i, j, k;
//   mid = (start + end) / 2;
//   i = start;
//   j = mid + 1;
//   for(k = start; k <= end; k++){
//     if(x[i] > x[j] && j <= end || i > mid){
//       b[k] = x[j];
//       j ++;
//     }
//     else{
//       b[k] = x[i];
//       i ++;
//     }
//   }

//   for(k = start; k <= end; k++) x[k] = b[k];

//   // counter++;
//   // printf("\n\n\n%d\n",counter);
//   // for(int i=0; i < 10; i++){
//   //   printf("%d",x[i]);
//   // }
// }

// void sort1(int x[], int start, int end)
// {
//   int mid;
//   if(start >= end) return;
//   mid = (start + end) / 2;
//   sort1(x, start, mid);
//   sort1(x, mid+1, end);
//   part_of_sort( x, start, end );
// }
// void sort2(int x[], int n)
// {
//   int i, j, t;
//   for(i = 0; i < n -1; i++){
//     for( j = n -1 ; j > i ; j --){
//       if(x[ j ] >x[ j -1 ] ){
//         t = x[ j ];
//         x[ j ] = x[ j -1 ];
//         x[ j -1 ] = t;
//       }
//     }
//     counter++;
//     printf("\n\n\n%d\n",counter);
//     for(int i=0; i < 10; i++){
//       printf("%d",x[i]);
//     }
//   }
// }
// void sort3(int x[], int n)
// {
//   int i, j, t;
//   for( i = 1 ; i < n ; i++ ){
//     for( j = i ; j > 0 ; j--){
//       if( x[ j ] < x[ j -1 ] ){
//         t = x[ j ];
//         x[ j ] = x[ j -1 ];
//         x[ j -1 ] = t;
//       }
//         else
//         break;
//     }
//       counter++;
//       printf("\n\n\n%d\n",counter);
//       for(int i=0; i < 10; i++){
//         printf("%d",x[i]);
//       }
//   }
// }


int part_of_sort(int a[], int start, int end)
{
  int i, j, t;
  i = start; j = end -1;
  while(1){
    while(a[i] < a[end]) i++;
    while(a[j] > a[end] && j > i) j--;
    if(i >= j)break;
    t = a[i]; a[i] = a[j]; a[j] = t;
    i++; j--;
  }
  t = a[i]; a[i] = a[end]; a[end] = t;
  return i;
}

void sort4(int x[], int start, int end)
{
  int s;
  if(start >= end)return;
  s = part_of_sort(x, start, end);

  counter++;
  printf("\n\n\n%d\n",counter);
  for(int i=0; i < 10; i++){
    printf("%d",x[i]);
  }

  sort4(x, start, s-1);
  sort4(x, s+1, end);
}

int main() {
  int x[10] = {6,1,1,8,2,1,0,0,6,6};
  // sort1(x,0,9);
  // sort2(x,10);
  // sort3(x,10);
  sort4(x,0,9);
  printf("\nHello,world!\n");
}
