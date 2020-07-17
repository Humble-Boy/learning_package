#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define  MaxSize 50
#define  InitSize 100

typedef  int  ElementType;
//静态数组
typedef struct  {
    ElementType  data[ MaxSize ];
    int length , maxsize ;
} sqList;


//动态数组
typedef  struct  {
    ElementType  *data;
    int  max_size,length;
}dyna_sqlist;
// 静态表初始化
void  InitStaticSeqlist (sqList *list ) {
    memset(list->data, 0, sizeof( list->data ));
    list->length = MaxSize;
}
// length ：位序
//静态顺序插入
bool staticListInsert( sqList *L , int i , ElementType data ) {
    if ( i<1 || i>L->length +1  ) {
        return false;
    }
    //其实这里都是一样
    for (int j = L->length; j < i;j--  ) {
        L->data[j] = L->data[j-1];
    }
    //只是这里把位置的号码变化了
    L->data[i-1] = data;
    L->length++;
    return true;
}
// 按值查询
int staticLocateElem ( sqList *list ,ElementType e   ) {
    int i ;
    for (  int  i =0 ; i< list->length ;i++ ) {
        if ( list->data[i] == e ) {
            return  i+1;
        }
    }
    return  0 ;
}
//静态顺序表删除
bool staticListDlete( sqList *list  , int i , ElementType  *beDeleteElem ) {
    if (  i<1 || i> list->length +1  ) {
        return  false;
    }
    printf( " 被删除的值是: %d  " , list->data[ i-1 ] );
    *beDeleteElem = list->data[ i-1 ];
    printf( " 被删除的值是: %d  " , *beDeleteElem );
    for (int j = i; j <  list->length ; ++j) {
        list->data[j-1] = list->data[j];
    }
    return  true;
//    list->length--;
}
// 循环左移 N个单位
bool circleLeftMove(sqList *list , int  leftMoveUnit  ) {
    if ( list->length == 0 ) {
        return  false;
    }
    int  index = 0;
    sqList  copyList =  *list;
    for (int i = 0; i < list->length  ; ++i) {
        if (  (i- leftMoveUnit) % list->length  <= -1   ) {
            index =  list->length +  ((i- leftMoveUnit) % list->length);
        } else{
            index = (i- leftMoveUnit) % list->length;
        }
        list->data[index] =  copyList.data[ i ];
    }
    return true;
}
// 等长的 升序 数组
int findmid3(int A[], int B[], int n)
{
    int start1 = 0, end1 = n - 1, m1, start2 = 0, end2 = n - 1, m2;
    //分别表示序列A和B的首位数、末位数和中位数

    while (start1 != end1 || start2 != end2)
    {
        m1 = (start1 + end1) / 2;
        m2 = (start2 + end2) / 2;
        if (A[m1] == B[m2])
            return A[m1];   //满足条件 1)

        if (A[m1] < B[m2]) // 满足条件 2)
        {
            if ((start1 + end1) % 2 == 0)  //若元素个数为奇数
            {
                start1 = m1;  //舍弃A中间点以前的部分且保留中间点
                end2 = m2;  //舍弃B中间点以后的部分且保留中间点
            }
            else				//元素个数为偶数
            {
                start1 = m1 + 1;  //舍弃A中间点及中间点以前部分
                end2 = m2;  //舍弃B中间点以后部分且保留中间点
            }
        }
        else
        {  //满足条件3)
            if ((start2 + end2) % 2 == 0)   //若元素个数为奇数
            {
                end1 = m1;    //舍弃A中间点以后的部分且保留中间点
                start2 = m2;    //舍弃B中间点以前的部分且保留中间点
            }
            else     //元素个数为偶数
            {
                end1 = m1;    //舍弃A中间点以后部分且保留中间点
                start2 = m2 + 1;    //舍弃B中间点及中间点以前部分
            }
        }
    }
    return  A[start1] < B[start2] ? A[start1] : B[start2];
}


//动态顺序表初始化
void InitSeqList(dyna_sqlist* pSeq)
{
    pSeq->data = ( ElementType * ) malloc( sizeof( ElementType ) * InitSize   );
    if ( pSeq->data ==NULL ) {
        exit(-1);
    }
    pSeq->max_size = MaxSize;
    pSeq->length = 0;
}


int main() {
    sqList list;
    ElementType elem ;
    // 静态表初始化
    InitStaticSeqlist( &list );
    for (int i = 0; i < list.length ; ++i) {
        list.data[i] =  i;
    }
    circleLeftMove( &list , 10 );
//    for (int j = 0; j < list.length; ++j) {
//        printf("%d\n" ,list.data[j]  );
//    }
    int   testNum =  4.5;
    printf(" %d "  , testNum  );
    return 0;
}
