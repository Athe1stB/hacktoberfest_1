//Program to sort the elements of an array using Bubble Sort

import java.util.*;

public class BubbleSort{
    static void BubbleSort(int[] a) {  
        int n = a.length;  
        int temp = 0;  
         for(int i=0; i < n; i++){  
                 for(int j=1; j < (n-i); j++){  
                          if(a[j-1] > a[j]){  
                                 //swap elements  
                                 temp = a[j-1];  
                                 a[j-1] = a[j];  
                                 a[j] = temp;  
                         }  
                          
                 }  
         }
    }  
    public static void main(String[] args) {  
                
                System.out.println("Array before Bubble Sort");  
                for(int i=0; i < a.length; i++){  
                        System.out.print(a[i] + " ");  
                }
                System.out.println();   
                BubbleSort(a);  
                System.out.println("Array after Bubble Sort");  
                for(int i=0; i < a.length; i++){  
                        System.out.print(a[i] + " ");  
                }
        }
}
