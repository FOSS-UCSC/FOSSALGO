import java.util.Scanner;

class bubbleSort{
	public static void main(String a[]){

		Scanner sc=new Scanner(System.in);
		System.out.print("Size of array :");
		int n=sc.nextInt();

		int[] num=new int[n];
		int i,j,tmp;

		for(i=0;i<n;i++){
			num[i]=sc.nextInt();
		}
		
		for(i=0;i<n;i++){
			for(j=0;j<(n-i);j++){
				if(j==(n-1)){
					break;
				}
				else{
					if(num[j]>num[j+1]){
						tmp=num[j];
						num[j]=num[j+1];
						num[j+1]=tmp;
					}
				}
			}
		}
		for(i=0;i<n;i++){
			System.out.print(num[i]+"  "  );
		}
	}
}
