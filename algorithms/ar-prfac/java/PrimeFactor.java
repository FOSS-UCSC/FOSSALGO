public class PrimeFactor{

    public static void primeFactors(int number){
        if(number<=1)
            return;
        for(int counter=2;(counter*counter)<=number;counter++){
            while(number%counter==0){
                System.out.println(counter);
                number=number/counter;
            }
        }
        if(number>0){
            System.out.println(number);
        }
    }

    public static void main(String args[]){
        primeFactors(60);
    }
}