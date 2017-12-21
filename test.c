#include <stdio.h>
#define N 10000  //����������󳤶�

int count = 0;  //���ڼ�¼quick_sort�ĵ��ô���

//����������������
void swap(int *a, int *b){
  if(a != b){
    (*a) = (*a) + (*b);
    (*b) = (*a) - (*b);
    (*a) = (*a) - (*b);
  }
}

//���ź�����quick_sort()��helper function
int patition(int *A, int p, int r){
  int i, j = p - 1; //i��ѭ������, j��¼��i֮ǰ��xС�����һ�������±�
  int x = A[r];
  
  //��������, ����xС�ķ���ǰ�桢��x������ں���
  for(i = p; i < r; i++){
    if(A[i] < x){
      swap(&A[++j], &A[i]);
    }
  }

  //����x�嵽�м�, ���������ڵ�λ��(��ʱ����������xΪ�ֽ��, ��xǰ��ı�xС, ��x����Ĳ�С��x, ���ǿ�������ĺ���)
  swap(&A[++j], &A[r]);
  return j;
}

//����������
void quick_sort(int *A, int p, int r){
  int q; //��¼�ֽ��±�
  count++; //���üƴ�

  //��������
  if(p < r){
    q = patition(A, p, r); //���Ų���÷ֽ��±�
    quick_sort(A, p, q - 1); //�ݹ��ǰ�������������
    quick_sort(A, q + 1, r); //�ݹ�Ժ�������������
  }
}

//������
int main(){
  int A[N], n, i;
  scanf("%d", &n); //����Ҫ��������г���

  //��������
  for(i = 0; i < n; i++){
    scanf("%d", &A[i]);
  }

  //���ÿ���������
  quick_sort(A, 0, n - 1);

  //�������
  for(i = 0; i < n; i++){
    printf("%d ", A[i]);
  }

  //���quick_sort()���ܵ��ô���
  printf("\ntotal count: %d\n", count);
  return 0;
}
