#include<stdio.h>

typedef struct {
    char nama[50];
    int quan;
    int price;
}order;

int main(){
    int i = 0, price = 0;
    order orderan[10];
    FILE *fp = fopen("order.txt", "r");
    while(!feof(fp)){
        fscanf(fp, "%[^#]#%d#%d", orderan[i].nama, &orderan[i].quan, &orderan[i].price);
        i++;
    }
    fclose(fp);

    FILE *fo = fopen("bill.txt", "a");
    for(int j = 0; j < i; j++){
        fprintf(fo, "%s\n%d * %d = %d\n", orderan[j].nama, orderan[j].quan, orderan[j].price, orderan[j].quan * orderan[j].price);
        price += orderan[j].quan * orderan[j].price;
    }

    fprintf(fo, "\nTotal = %d", price);
 
    fclose(fo);

}