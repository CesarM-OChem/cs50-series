def main():
    number = input("Number: ")
    l = len(number)

    if l != 13 and l != 15 and l != 16:
        print("INVALID")
        exit(1)

    number = int(number)
    card = checkPrefix(number, l)

    if card == "INVALID":
        print("INVALID")
        exit(1)
    else:
        sum = calculateSum(number, l)
    
    if sum % 10 == 0:
        print(card)
    else:
        print("INVALID")


def checkPrefix(number, length):
    prefix = int(number / (10 ** (length - 2)))

    if prefix == 34 or prefix == 37:
        if length != 15:
            return "INVALID"
        else:
            return "AMEX"
        
    if prefix > 50 and prefix < 56:
        if length != 16:
            return "INVALID"
        else:
            return "MASTERCARD"
        
    if length != 13 and length != 16:
        return "INVALID"
    
    prefix = int(number / (10 ** (length - 1)))
    if prefix != 4:
        return "INVALID"
    else:
        return "VISA"



def calculateSum(number, length):
    sum = 0
    flag = 1

    for i in range(length):
        if flag == 1:
            sum += number % 10
            number = int(number / 10)
            flag = 0
        else:
            tmp = (number % 10) * 2
            number = int(number / 10)

            if tmp > 9:
                sum += int(tmp / 10) + tmp % 10
            else:
                sum += tmp
            
            flag = 1

    return sum


main()