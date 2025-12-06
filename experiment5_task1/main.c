#include <stdio.h>
#include <string.h>

#define MAX_SIZE 51

int calculate_sum(char max[], char min[], int sum[], int lenofmax, int lenofmin);

int main(){
	//定义两个数组，读入数组
	char arr1[MAX_SIZE] = {0};
	char arr2[MAX_SIZE] = {0};
	int sum[MAX_SIZE] = {0};
	int len1 = 0;
	int len2 = 0;
	int lenofsum = 0;
	int i;
	
	fgets(arr1, MAX_SIZE, stdin);
	arr1[strcspn(arr1, "\n")] = '\0';
	len1 = strlen(arr1);

	
	fgets(arr2, MAX_SIZE, stdin);
	arr2[strcspn(arr2, "\n")] = '\0';	
	len2 = strlen(arr2);

		
//  test	
//	for(i = 0; i < len1; i++){
//		printf("%c", arr1[i]);
//	}
//	printf("%d", len1);
	
	if(len1 > len2){
		lenofsum = calculate_sum(arr1, arr2, sum, len1, len2);
	}else{
		lenofsum = calculate_sum(arr2, arr1, sum, len2, len1);
	}
	
//	printf("lenofsum = %d\n", lenofsum);
	 
	for(i = 0; i < lenofsum; i++){
		printf("%d", sum[i]);
	}
	
	return 0;
} 

int calculate_sum(char max[], char min[], int sum[], int lenofmax, int lenofmin){
	int lenofsum = 0;
	int carry = 0;
	int i;	
	int digit = 0;

	//从最低位开始相加，结果储存到sum数组尾部 
	int max_idx = lenofmax - 1;
	int min_idx = lenofmin - 1;
	int sum_idx = MAX_SIZE - 1;
	
	//处理较短的部分的相加
	while(min_idx >= 0){
		digit = (max[max_idx] - '0') + (min[min_idx] - '0') + carry;
		sum[sum_idx] = digit % 10;
		carry = digit / 10;
		
		max_idx--;
		min_idx--;
		sum_idx--;
	}

	//处理较长数的剩余部分 
	while(max_idx >= 0){
		digit = (max[max_idx] - '0') + carry;
		sum[sum_idx] = digit % 10;
		carry = digit / 10;
		
		max_idx--;
		sum_idx--;
	}

	//最后的进位
	if(carry > 0){
		sum[sum_idx] = carry;
		sum_idx--;
	} 

	//计算数组长度
	lenofsum = MAX_SIZE - sum_idx - 1;
	 
	//移动到数组开头
	for(i = 0; i < lenofsum; i++){
		sum[i] = sum[i+sum_idx+1];
	}
	
	return lenofsum;
}


