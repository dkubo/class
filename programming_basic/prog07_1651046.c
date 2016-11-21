#include <stdio.h>
void sort(int *num);

main()
{
	int arr[10]={67,25,14,43,20,7,92,58,36,83};
	sort(&arr[0]);
}
void sort(int *num){
	int i,j,tmp,sortarr[10];
 for (i=0;i<10;++i){
    for (j=i+1;j<10;++j) {
      if (*(num+i)<*(num+j)) {
        tmp=*(num+i);
        *(num+i)=*(num+j);
        *(num+j)=tmp;
      }
    }
  }
	for (i=0;i<10;++i){
		sortarr[i]=*(num+i);
	}
	for (i=0;i<10;++i){
		printf("%d\n",sortarr[i]);
/*		printf("%d\n",*(num+i));*/
	}
}

