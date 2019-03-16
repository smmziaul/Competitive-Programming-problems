#include<stdio.h>
#include<conio.h>
int p=-1, b[500], a[500];


void gen_prime(int start, int end) {
	int i, j;
	for(i=start;i<=end;i++) {
		for(j=2;j<=i/2;j++) {
			if(i%j == 0) {
				break;
			}
		}
		if(j==i/2+1) {
		       //	printf("\nprime no: %d",i);
			a[++p]=i;
		}
	}
}

int reverse(int n) {
	int d, new_no = 0;
	while(n>0) {
		d=n%10;
		new_no=new_no*10 + d;
		n/=10;
	}
	return new_no;
}

void print_arr(int arr[], int p) {
	int i;
	for(i=0;i<=p;i++) {
		printf("%d\t", arr[i]);
	}
}

int check_prime(int n) {
	int i;
	for(i=2;i<=n/2;i++) {
		if(n%i == 0) {
			break;
		}
	}
	if(i==n/2+1) {
	       //	printf("%d\t",n);
		return 1;
	} else {
		return 0;
	}
}



void main() {
	int c_ptr=-1, b_ptr=-1, is_prime, c[500], i, j, check, n,new_no;
	clrscr();
	printf("\nenter N: ");
	scanf("%d",&n);
	gen_prime(13, n);
       //	printf("\na array elements: \n");
       //	print_arr(a,p);
	for(i=0;i<=p;i++) {
	       new_no=reverse(a[i]);
	       if(new_no != a[i]) {
			is_prime = check_prime(new_no);
			if(is_prime == 1) {
				c[++c_ptr]=a[i];
			}
	       }
	       b[++b_ptr]=new_no;
	}
		//printf("\nb array eles: \n");
		//print_arr(b,b_ptr);

		printf("\nemirps are: \n");
		print_arr(c,c_ptr);
		printf("\n\nHit some key to exit...");
	getch();
}