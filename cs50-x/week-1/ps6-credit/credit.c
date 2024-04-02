#include <cs50.h>
#include <math.h>
#include <stdio.h>

#define VISA_INIT 4
#define AMEX_INIT_1 34
#define AMEX_INIT_2 37
#define MASTERCARD_LOW_LIMIT 51
#define MASTERCARD_UPPER_LIMIT 55

int main(void){
    long number = 0;

    do{
        number = get_long("Number: ");
    }while(number == 0);

    //check number of digits
    long copy = number;
    int digits = 0;

    do{
        copy /= 10;
        digits++;
    }while(copy != 0);
    
    string flag;

    switch(digits){
        long factor;
        case 13:
            copy = number;
            factor = pow(10, digits - 1);

            if(copy / factor != VISA_INIT){
                printf("INVALID\n");
                return 0;
            }
            flag = "VISA";
        break;
        case 15:
            copy = number;
            factor = pow(10, digits - 2);
            
            if (copy / factor != AMEX_INIT_1 && copy / factor != AMEX_INIT_2){
                printf("INVALID\n");
                return 0;
            }

            flag = "AMEX";
        break;
        case 16:
            copy = number;
            factor = pow(10, digits - 2);

            if(copy / factor < MASTERCARD_LOW_LIMIT || copy / factor > MASTERCARD_UPPER_LIMIT){
                factor = pow(10, digits - 1);

                if(copy / factor != VISA_INIT){
                    printf("INVALID\n");
                    return 0;
                }else{
                    flag = "VISA";
                    break;
                }
                printf("INVALID\n");
                return 0;
            }

            flag = "MASTERCARD";
        break;
        default:
            printf("INVALID\n");
            return 0;
        break;
    }

    int sum = 0;
    copy = number;

    for(int i = digits - 1; i >= 0; i--){
        if((digits - i) % 2 == 0){
            int multiplication = 2 * (copy % 10);
            if(multiplication > 9){
                sum += multiplication % 10;
                sum += multiplication / 10;
            }else{
                sum += 2 * (copy % 10);
            }
            copy /= 10;
        }else{
            sum += copy % 10;
            copy /= 10;
        }
    }
    printf("%i\n", sum);
    if(sum % 10 == 0){
        printf("%s\n", flag);
    }else{
        printf("INVALID\n");
    }
}
