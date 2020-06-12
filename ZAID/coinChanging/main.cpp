#include <iostream>

using namespace std;
const int quarter = 25;
const int dime = 10;
const int nickel = 5;
const int penny = 1;

void coinChanging(int num){


    // it will count how many coins in the number inputed
    int totalCoins = 0;

    while(num > 0){
        // it will get how many coins in the number and then store in the variable total coins.
        int numberOfCoins;



    if(num >= quarter){

       numberOfCoins  = num / quarter; // number of coins = 114 / 25 = 4. so, divide = 4;
       // if the number is even, store the value of number coins in total coins.
       if(num % 25 == 0){
            totalCoins = totalCoins + numberOfCoins;


            // print how many quarters in this input.
           cout << "Number inputed is in coins: " << numberOfCoins << " quarter(s) ";
           // substract the inpunted number by number of coins times 25.
           num = num - (numberOfCoins * quarter);






       }

       else{
           // otherwise, store the value of number coins in total coins.
           totalCoins = totalCoins + numberOfCoins;


       num = num - (numberOfCoins * quarter); // num = 114 - (4 * 25) => num = 114 - 100 => num = 14;
      // print out how many quarters in this input number
       cout << "Number inputed is in coins: " << numberOfCoins << " quarter(s) ";

       }




    }

    if(num >= dime){




        numberOfCoins  = num / dime; // divide = 114 / 25 = 4. so, divide = 4;
        // if the number is even, store the value of number coins in total coins.
        if(num % 25 == 0){
           // store the value of number coins in total coins.
            totalCoins = totalCoins + numberOfCoins;

            // print out how many dimes in this input number
            cout << " , " << numberOfCoins << " dime(s) ";
            num = num - (numberOfCoins * dime);



        }

        else{ // otherwise, store the value of number coins in total coins.
            totalCoins = totalCoins + numberOfCoins;


        num = num - (numberOfCoins * dime); // num = 114 - (4 * 25) => num = 114 - 100 => num = 14;
        // print number of dimes.
        cout << " , " << numberOfCoins << " dime(s) ";
        }





    }



    if(num >= nickel){


        numberOfCoins  = num / nickel;
         // if the number is even, store the value of number coins in total coins.
        if(num % nickel == 0){
            totalCoins = totalCoins + numberOfCoins;

            // print nickel
            cout << " , " << numberOfCoins << " nickel(s) " << endl;
            num = num - (numberOfCoins * nickel);

        }

        else{// otherwise, store the value of number coins in total coins.

        totalCoins = totalCoins + numberOfCoins;

        num = num - (numberOfCoins * nickel);

        cout << " , " << numberOfCoins << " nickel(s) " << endl;


        }


    }

    if(num >= penny){


        // same instructions for penny.
        numberOfCoins  = num / penny;
        if(num % penny == 0){
            totalCoins = totalCoins + numberOfCoins;


            cout << " and " << numberOfCoins << " penny(s) " << endl;
            num = num - (numberOfCoins * nickel);

        }

        else{
            totalCoins = totalCoins + numberOfCoins;

            // cout << "the fewest number of coins is " << numberOfCoins << endl;
        num = num - (numberOfCoins * penny);

        cout << " and " << numberOfCoins << " penny(s) " << endl;
       }


  }



    cout << endl;


    // recursively, loop throgh the function untill the statment in while loop is satisfied.
     coinChanging(num);
     cout << endl;
     // finally, print out the total fewest number of coins.
      cout << "the fewest number of coins is "<< totalCoins <<endl ;


}


}




int main()
{

    int inputNum;
    cout << "Input the number you want: ";
    // user input the number.
    cin >> inputNum;
    cout << endl;


    cout << endl;
    coinChanging(inputNum);
    cout << endl;
}
