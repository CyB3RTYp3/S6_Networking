#include <stdio.h>
void main(){
    int incoming,outgoing,n,buck_size,store=0;

    printf("Enter the bucket size\n");
    scanf("%d",&buck_size);
    printf("Enter the number of inputs\n");
    scanf("%d",&n);
    printf ("Enter the outgoing rate \n");
    scanf("%d",&outgoing);

    while(n!=0){
        printf("Enter the incoming packet size \n");
        scanf("%d",&incoming);

        if(incoming <= buck_size-store){
            store=store+incoming;
            printf("bucket size %d of %d\n",store,buck_size);
        }else{
            printf("Dropped %d no of packets\n",incoming-(buck_size-store));
            store=buck_size;
            printf("bucket size %d of %d",store,buck_size);
        }

        store=store-outgoing;
        if(store<0)
            store=0;
        printf("After outgoing, buffer size %d of %d \n",store,buck_size);
        n--;
    }
}