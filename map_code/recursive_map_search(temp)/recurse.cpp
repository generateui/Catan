#include <QtCore>

void get_digits(double x);

int main(int argc, char *argv[]){
	if (argc == 2){
            QString word = argv[1];
            bool ok = true;
            double value = word.toDouble(&ok);
            get_digits(value);
	}
        else{
            qDebug() << "You didn't enter the right amount of letters!";
        }
    return 0;
}

void get_digits(double x){
    qDebug() << x;
    //QString number = x;
    double digit_1, digit_2, digit_3;
    digit_1 = 0;
    digit_2 = 0;
    digit_3 = 0;
    if (x<7){
        digit_1 = x + 1;
        digit_2 = x - 1;
        digit_3 = x + 10;
        if (digit_2 < 1){
            digit_2 = 6;
        }
        if (digit_1 > 6){
            digit_1 = 1;
        }
    }
    else if (x > 6 && x < 17){
        int y = floor(x);
        if (x - y != 0){
            digit_3 = x + 10;
            double decimal = x % 1;
            double ones_place = (x % 10) - decimal;
            if (decimal == ones_place){
                digit_1 = x + .1;
                digit_2 = x - decimal;
                if (digit_1 > 16.6){
                    digit_1 = 16.1;
                }
            }
            else{
                digit_1 = (x - decimal) + 1;
                digit_2 = x - .1;
                if (digit_1 == 17){
                    digit_1 = 11;
                }
                if (digit_2 == 16){
                    digit_2 = 16.6;
                }
            }
        }
        else{
            digit_3 = x - 10;
            double decimal = x % 10;
            digit_1 = x + decimal;
            digit_2 = (x - 1) + decimal;
            if (digit_2 < 11){
                digit_2 = digit_2 + 6;
            }
        }

    }

    qDebug() << "digit_1: " << digit_1;
    qDebug() << "digit_2: " << digit_2;
    qDebug() << "digit_3: " << digit_3;
}
