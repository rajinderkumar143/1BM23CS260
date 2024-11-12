#include <stdio.h>
int maxTwoStacks(int stack1[] , int n1, int stack2[] ,int n2 , int x){
    int sum = 0 , count = 0 , max_count = 0;
    int i = 0 , j = 0;
    while(i < n1 && sum + stack1[i] <= x){
        sum = sum + stack1[i];
        i = i + 1;
        count = count + 1;
    }
    max_count = count;
    
    while(j < n2 && i>=0){
        sum = sum + stack2[j];
        j = j + 1;
        count = count + 1;
        
        while(sum >x && i>0){
            i = i - 1;
            sum = sum - stack1[i];
            count = count - 1;
        }
        
        if(sum <= x && count > max_count){
            max_count = count;
        }
    }
    return max_count;
}

int main(){
    int n1 , n2 , x;
    printf("Enter the size of stack1 and stack2:\n");
    scanf("%d %d",&n1 , &n2);
    int stack1[n1] , stack2[n2];
    printf("Enter the elements of stack1:\n");
    for(int i=0; i<n1; i++){
        scanf("%d",&stack1[i]);
    }
    printf("Enter the elements of stack2:\n");
    for(int i=0; i<n2; i++){
        scanf("%d",&stack2[i]);
    }
    printf("Enter the maximum sum x :\n");
    scanf("%d",&x);
    int result = maxTwoStacks(stack1 ,n1 ,stack2, n2 ,x);
    printf("Maximum number of elements removed:%d\n",result);
}
